import math
from collections import defaultdict, namedtuple
import heapq
import copy

# Define structures
Resource = namedtuple(
    "Resource", ["RI", "RA", "RP", "RW", "RM", "RL", "RU", "RT", "RE"]
)
Turn = namedtuple("Turn", ["TM", "TX", "TR"])


class ActiveResource:
    def __init__(self, base, purchase_turn=0):
        self.base = base
        self.remaining_life = base.RL
        self.active_time_left = base.RW
        self.maintenance_time_left = 0
        self.is_active = True
        self.accumulated_buildings = 0  # For E-type resources
        self.purchase_turn = purchase_turn

    def clone(self):
        new_resource = ActiveResource(self.base, self.purchase_turn)
        new_resource.remaining_life = self.remaining_life
        new_resource.active_time_left = self.active_time_left
        new_resource.maintenance_time_left = self.maintenance_time_left
        new_resource.is_active = self.is_active
        new_resource.accumulated_buildings = self.accumulated_buildings
        return new_resource


def parse_input(input_text):
    lines = input_text.strip().split("\n")

    # Parse first line
    parts = lines[0].split()
    D = int(parts[0])  # Initial budget
    R = int(parts[1])  # Number of resources
    T = int(parts[2])  # Number of turns

    # Parse resources
    resources = []
    for i in range(1, R + 1):
        parts = lines[i].split()
        RI = int(parts[0])
        RA = int(parts[1])
        RP = int(parts[2])
        RW = int(parts[3])
        RM = int(parts[4])
        RL = int(parts[5])
        RU = int(parts[6])
        RT = parts[7]
        RE = int(parts[8]) if len(parts) > 8 and RT != "X" else 0

        resources.append(Resource(RI, RA, RP, RW, RM, RL, RU, RT, RE))

    # Parse turns
    turns = []
    for i in range(R + 1, R + T + 1):
        parts = lines[i].split()
        TM = int(parts[0])
        TX = int(parts[1])
        TR = int(parts[2])
        turns.append(Turn(TM, TX, TR))

    return D, R, T, resources, turns


def calculate_resource_value(
    resource, budget, current_turn, future_turns, current_resources, remaining_turns
):
    """Calculate a more comprehensive value metric for each resource"""
    # Base efficiency calculation
    if resource.RL == 0 or resource.RU == 0:
        return -float("inf")

    # Calculate basic ROI
    initial_cost = resource.RA
    total_maintenance = resource.RP * resource.RL
    total_cost = initial_cost + total_maintenance

    # Calculate approximate buildings powered over lifetime
    active_turns = (resource.RL // (resource.RW + resource.RM)) * resource.RW
    if resource.RL % (resource.RW + resource.RM) > 0:
        active_turns += min(resource.RL % (resource.RW + resource.RM), resource.RW)

    total_buildings = active_turns * resource.RU

    # Base value is buildings per cost
    if total_cost == 0:
        base_value = float("inf")
    else:
        base_value = total_buildings / total_cost

    # Adjust for remaining turns
    effective_lifetime = min(resource.RL, remaining_turns)
    lifetime_ratio = effective_lifetime / resource.RL if resource.RL > 0 else 0
    base_value *= lifetime_ratio

    # Budget constraint factor (prefer cheaper resources when budget is tight)
    budget_factor = 1.0
    if budget < 2 * resource.RA:
        budget_factor = 0.5
    elif budget < resource.RA:
        return -float("inf")  # Can't afford it

    # Special effect bonuses
    effect_bonus = 1.0

    # Type A (Smart Meter) - prioritize early for compounding benefits
    if resource.RT == "A" and resource.RE > 0:
        effect_bonus += (resource.RE / 100.0) * 2.0

    # Type B (Distribution Facility) - more valuable when close to thresholds
    if resource.RT == "B" and resource.RE > 0:
        # Calculate average threshold expansion benefit
        avg_tm = (
            sum(turn.TM for turn in future_turns) / len(future_turns)
            if future_turns
            else current_turn.TM
        )
        avg_tx = (
            sum(turn.TX for turn in future_turns) / len(future_turns)
            if future_turns
            else current_turn.TX
        )

        # More valuable if it expands capacity to meet thresholds
        current_capacity = sum(r.base.RU for r in current_resources if r.is_active)
        if current_capacity < avg_tm * 1.2:  # If we're close to minimum threshold
            effect_bonus += (resource.RE / 100.0) * 2.5

    # Type C (Maintenance Plan) - more valuable early in the game
    if resource.RT == "C" and resource.RE > 0:
        turns_factor = remaining_turns / (
            remaining_turns + 1
        )  # Higher value for more remaining turns
        effect_bonus += (resource.RE / 100.0) * turns_factor * 2.0

    # Type D (Renewable Plant) - directly increases profit
    if resource.RT == "D" and resource.RE > 0:
        # Calculate average profit potential
        avg_tr = (
            sum(turn.TR for turn in future_turns) / len(future_turns)
            if future_turns
            else current_turn.TR
        )
        effect_bonus += (resource.RE / 100.0) * (avg_tr / 10.0) * 3.0

    # Type E (Accumulator) - more valuable with high variance in requirements
    if resource.RT == "E":
        if future_turns:
            tm_variance = sum(
                (turn.TM - current_turn.TM) ** 2 for turn in future_turns
            ) / len(future_turns)
            tx_variance = sum(
                (turn.TX - current_turn.TX) ** 2 for turn in future_turns
            ) / len(future_turns)
            variance_factor = (tm_variance + tx_variance) / 100
            effect_bonus += 1.0 + min(variance_factor, 2.0)  # Cap the bonus
        else:
            effect_bonus += 1.0

    # Need factor - more urgent if we can't meet minimum requirements
    current_capacity = sum(r.base.RU for r in current_resources if r.is_active)
    need_factor = 1.0
    if current_capacity < current_turn.TM:
        shortfall = current_turn.TM - current_capacity
        # Urgently need power - prioritize resources that can fill the gap
        if resource.RU >= shortfall:
            need_factor += 3.0
        else:
            need_factor += (resource.RU / shortfall) * 2.0

    # Calculate final score
    final_value = base_value * budget_factor * effect_bonus * need_factor

    return final_value


def apply_special_effects(active_resources, current_turn):
    # Store original values
    original_TM = current_turn.TM
    original_TX = current_turn.TX
    original_TR = current_turn.TR

    # Apply effects from active resources
    effect_A = 1.0
    effect_B_min = 1.0
    effect_B_max = 1.0
    effect_D = 1.0

    for resource in active_resources:
        if not resource.is_active:
            continue

        if resource.base.RT == "A":  # Smart Meter
            effect = resource.base.RE / 100.0
            if effect >= 0:  # Green resource
                effect_A *= 1 + effect
            else:  # Non-green resource
                effect_A *= max(0, 1 + effect)

        elif resource.base.RT == "B":  # Distribution Facility
            effect = resource.base.RE / 100.0
            if effect >= 0:  # Green resource
                effect_B_min *= 1 + effect
                effect_B_max *= 1 + effect
            else:  # Non-green resource
                effect_B_min *= max(0, 1 + effect)
                effect_B_max *= max(0, 1 + effect)

        elif resource.base.RT == "D":  # Renewable Plant
            effect = resource.base.RE / 100.0
            if effect >= 0:  # Green resource
                effect_D *= 1 + effect
            else:  # Non-green resource
                effect_D *= max(0, 1 + effect)

    # Calculate modified values
    modified_TM = max(0, math.floor(original_TM * effect_B_min))
    modified_TX = max(0, math.floor(original_TX * effect_B_max))
    modified_TR = max(0, original_TR * effect_D)

    # Apply A-type effect to all active resources
    modified_resources = []
    for resource in active_resources:
        if resource.is_active and resource.base.RT != "E":
            # Create a modified base with updated RU
            original_RU = resource.base.RU
            modified_RU = math.floor(original_RU * effect_A)

            # Only modify the RU value for this calculation without changing the original
            modified_base = resource.base._replace(RU=modified_RU)

            # Create a clone of the resource with the modified base
            modified_resource = resource.clone()
            modified_resource.base = modified_base
            modified_resources.append(modified_resource)
        else:
            modified_resources.append(resource.clone())

    return Turn(modified_TM, modified_TX, modified_TR), modified_resources


def find_resource_by_id(resources, id):
    for res in resources:
        if res.RI == id:
            return res
    return None


def get_total_powered_buildings(active_resources):
    total = 0
    for resource in active_resources:
        if resource.is_active and resource.base.RT != "E":
            total += resource.base.RU
    return total


def use_accumulators(active_resources, shortage):
    if shortage <= 0:
        return 0

    total_used = 0
    for resource in active_resources:
        if (
            resource.is_active
            and resource.base.RT == "E"
            and resource.accumulated_buildings > 0
        ):
            used = min(shortage - total_used, resource.accumulated_buildings)
            resource.accumulated_buildings -= used
            total_used += used

            if total_used >= shortage:
                break

    return total_used


def store_in_accumulators(active_resources, excess):
    if excess <= 0:
        return 0

    total_stored = 0
    for resource in active_resources:
        if resource.is_active and resource.base.RT == "E":
            resource.accumulated_buildings += excess
            total_stored = excess
            break  # Store all excess in first active accumulator

    return total_stored


def transfer_accumulated_buildings(active_resources):
    # Identify accumulators about to die
    dying_accumulators = []
    for i, resource in enumerate(active_resources):
        if resource.base.RT == "E" and resource.remaining_life == 1:
            dying_accumulators.append(i)

    # Transfer accumulated buildings
    for index in dying_accumulators:
        to_transfer = active_resources[index].accumulated_buildings
        if to_transfer > 0:
            transfer_complete = False
            for resource in active_resources:
                if (
                    resource.is_active
                    and resource.base.RT == "E"
                    and resource.remaining_life > 1
                ):
                    resource.accumulated_buildings += to_transfer
                    active_resources[index].accumulated_buildings = 0
                    transfer_complete = True
                    break

            # If no active accumulator to transfer to, the buildings are lost
            if not transfer_complete:
                active_resources[index].accumulated_buildings = 0


def update_resource_lifecycles(active_resources):
    # Transfer accumulated buildings from dying accumulators
    transfer_accumulated_buildings(active_resources)

    # Update each resource's lifecycle
    i = 0
    while i < len(active_resources):
        if active_resources[i].remaining_life <= 1:
            # Resource has reached end of life
            active_resources.pop(i)
        else:
            active_resources[i].remaining_life -= 1

            if active_resources[i].is_active:
                active_resources[i].active_time_left -= 1
                if active_resources[i].active_time_left <= 0:
                    # Resource enters maintenance period
                    active_resources[i].is_active = False
                    active_resources[i].maintenance_time_left = active_resources[
                        i
                    ].base.RM
            else:
                active_resources[i].maintenance_time_left -= 1
                if active_resources[i].maintenance_time_left <= 0:
                    # Resource returns to active state
                    active_resources[i].is_active = True
                    active_resources[i].active_time_left = min(
                        active_resources[i].base.RW, active_resources[i].remaining_life
                    )

            i += 1


def apply_C_type_effects(active_resources, new_resource):
    modified_resource = new_resource

    for resource in active_resources:
        if resource.is_active and resource.base.RT == "C":
            effect = resource.base.RE / 100.0
            if effect >= 0:  # Green resource
                modified_RL = math.floor(modified_resource.RL * (1 + effect))
            else:  # Non-green resource
                modified_RL = max(1, math.floor(modified_resource.RL * (1 + effect)))
            modified_resource = modified_resource._replace(RL=modified_RL)

    return modified_resource


def predict_future_state(active_resources, turns, current_turn_idx, lookahead=3):
    """Predict the state of resources and building capacity for future turns"""
    max_turns = min(lookahead, len(turns) - current_turn_idx)
    if max_turns <= 0:
        return []

    future_states = []

    # Clone current resources for simulation
    resources_copy = [resource.clone() for resource in active_resources]

    for i in range(max_turns):
        turn_idx = current_turn_idx + i
        if turn_idx >= len(turns):
            break

        # Apply special effects to get modified turn
        modified_turn, modified_resources = apply_special_effects(
            resources_copy, turns[turn_idx]
        )

        # Calculate buildings powered
        powered_buildings = get_total_powered_buildings(modified_resources)

        # Calculate total accumulated buildings in accumulators
        total_accumulator_capacity = sum(
            r.accumulated_buildings
            for r in modified_resources
            if r.is_active and r.base.RT == "E"
        )

        future_states.append(
            {
                "turn_idx": turn_idx,
                "modified_turn": modified_turn,
                "powered_buildings": powered_buildings,
                "accumulator_capacity": total_accumulator_capacity,
                "min_required": modified_turn.TM,
                "max_allowed": modified_turn.TX,
                "deficit": max(0, modified_turn.TM - powered_buildings),
                "excess": max(0, powered_buildings - modified_turn.TX),
            }
        )

        # Update resource lifecycles for next turn simulation
        update_resource_lifecycles(resources_copy)

    return future_states


def simulate_turn(budget, active_resources, turn, purchased_resources=None):
    """Simulate a single turn to calculate profit and budget changes"""
    if purchased_resources is None:
        purchased_resources = []

    # Apply special effects
    modified_turn, modified_resources = apply_special_effects(active_resources, turn)

    # Calculate maintenance costs
    maintenance_cost = sum(resource.base.RP for resource in active_resources)

    # Calculate buildings powered
    powered_buildings = get_total_powered_buildings(modified_resources)

    # Handle accumulators if we don't meet minimum requirements
    actual_powered = powered_buildings
    if powered_buildings < modified_turn.TM:
        shortage = modified_turn.TM - powered_buildings
        from_accumulators = use_accumulators(modified_resources, shortage)
        actual_powered += from_accumulators
    elif powered_buildings > modified_turn.TX:
        # Store excess in accumulators
        excess = powered_buildings - modified_turn.TX
        stored = store_in_accumulators(modified_resources, excess)
        actual_powered = modified_turn.TX

    # Calculate profit
    turn_profit = 0
    if actual_powered >= modified_turn.TM:
        turn_profit = min(actual_powered, modified_turn.TX) * modified_turn.TR

    # Update budget
    new_budget = budget - maintenance_cost + turn_profit

    return new_budget, turn_profit, modified_resources


def optimize_purchases(D, resources, turns, T):
    budget = D
    active_resources = []
    total_profit = 0
    output = []

    # Pre-calculate resource statistics and sort by efficiency
    resource_stats = []
    for res in resources:
        # Calculate rough efficiency (buildings per cost over lifetime)
        active_turns = (res.RL // (res.RW + res.RM)) * res.RW
        if res.RL % (res.RW + res.RM) > 0:
            active_turns += min(res.RL % (res.RW + res.RM), res.RW)

        total_buildings = active_turns * res.RU
        total_cost = res.RA + (res.RP * res.RL)

        if total_cost == 0:
            efficiency = float("inf")
        else:
            efficiency = total_buildings / total_cost

        resource_stats.append((res, efficiency, total_buildings, active_turns))

    # Simulate each turn
    for turn_idx in range(T):
        current_turn = turns[turn_idx]
        remaining_turns = T - turn_idx
        purchased_resources = []

        # Predict future state
        future_states = predict_future_state(active_resources, turns, turn_idx)
        future_turns = turns[turn_idx + 1 : turn_idx + 4] if turn_idx + 1 < T else []

        # Check if we need to buy more resources to meet current and upcoming needs
        current_capacity = get_total_powered_buildings(active_resources)
        future_capacity_trend = []

        # Calculate predicted capacity for next few turns
        active_resource_count = sum(1 for r in active_resources if r.is_active)
        turn_requirements = [current_turn.TM]

        for state in future_states:
            turn_requirements.append(state["min_required"])
            future_capacity_trend.append(state["powered_buildings"])

        # Calculate average and maximum requirements
        avg_requirement = (
            sum(turn_requirements) / len(turn_requirements)
            if turn_requirements
            else current_turn.TM
        )
        max_requirement = (
            max(turn_requirements) if turn_requirements else current_turn.TM
        )

        # Determine how many new resources to purchase
        purchase_urgency = 1.0

        # Increase urgency if we're below minimum threshold
        if current_capacity < current_turn.TM:
            purchase_urgency = 2.0

        # Increase urgency if we predict deficits in upcoming turns
        predicted_deficits = sum(1 for state in future_states if state["deficit"] > 0)
        if predicted_deficits > 0:
            purchase_urgency += 0.5 * predicted_deficits

        # Calculate how many resources to purchase based on budget and needs
        target_capacity = max(current_turn.TM, avg_requirement) * (
            1.0 + 0.1 * purchase_urgency
        )
        capacity_needed = max(0, target_capacity - current_capacity)

        # Prioritize resources based on comprehensive value
        resource_priorities = []
        for res in resources:
            value = calculate_resource_value(
                res,
                budget,
                current_turn,
                future_turns,
                active_resources,
                remaining_turns,
            )

            # Prioritize certain types in early game
            if turn_idx < T // 3:
                # Boost C-type resources early (lifespan extenders)
                if res.RT == "C" and res.RE > 0:
                    value *= 1.5
                # Boost A-type resources early (building multipliers)
                if res.RT == "A" and res.RE > 0:
                    value *= 1.3

            # In middle game, prioritize power generation and accumulators
            elif turn_idx < 2 * T // 3:
                if res.RT == "E":  # Accumulators
                    value *= 1.2
                if res.RU > avg_requirement / 3:  # High-capacity resources
                    value *= 1.1

            # In late game, focus on short-term returns
            else:
                if res.RL <= remaining_turns:  # Resources that don't outlive the game
                    value *= 1.2
                if res.RT == "D" and res.RE > 0:  # Profit multipliers
                    value *= 1.3

            resource_priorities.append(
                (-value, res.RI)
            )  # Negative for max-heap behavior

        # Convert to heap for efficient extraction
        heapq.heapify(resource_priorities)

        # Keep purchasing until we reach desired capacity or run out of budget
        remaining_to_purchase = []

        while resource_priorities and budget > 0 and capacity_needed > 0:
            _, res_id = heapq.heappop(resource_priorities)
            res = find_resource_by_id(resources, res_id)

            # Check if we can afford it and if it's worth buying
            if budget >= res.RA:
                # Apply C-type effects to new resource
                modified_res = apply_C_type_effects(active_resources, res)

                # Only purchase if it actually contributes to our capacity or strategy
                if modified_res.RT != "X" or modified_res.RU > 0:
                    remaining_to_purchase.append(res_id)
                    budget -= modified_res.RA

                    # Update our capacity tracking
                    if modified_res.RT != "E" and modified_res.RT != "C":
                        capacity_needed -= modified_res.RU

        # Finalize purchases for this turn
        for res_id in remaining_to_purchase:
            res = find_resource_by_id(resources, res_id)
            modified_res = apply_C_type_effects(active_resources, res)

            purchased_resources.append(res_id)

            # Activate the resource
            active_resources.append(ActiveResource(modified_res, turn_idx))

        # Simulate the turn with our purchases
        new_budget, turn_profit, updated_resources = simulate_turn(
            budget, active_resources, current_turn, purchased_resources
        )

        # Update active resources with any state changes from the simulation
        active_resources = updated_resources

        # Update budget and profit tracking
        budget = new_budget
        total_profit += turn_profit

        # Output purchases for this turn
        if purchased_resources:
            output.append(
                f"{turn_idx} {len(purchased_resources)} {' '.join(map(str, purchased_resources))}"
            )

        # Update resource lifecycles
        update_resource_lifecycles(active_resources)

    return output, total_profit


def solve_green_revolution(input_text):
    D, R, T, resources, turns = parse_input(input_text)
    output, total_profit = optimize_purchases(D, resources, turns, T)
    return "\n".join(output), total_profit


if __name__ == "__main__":
    # Read input from file or use example input
    test_files = [
        "0-demo.txt",
        "1-thunberg.txt",
        "2-attenborough.txt",
        "4-maathai.txt",
        "5-carson.txt",
        "6-earle.txt",
        "7-mckibben.txt",
        "8-shiva.txt",
    ]

    for filename in test_files:
        with open(filename, "r") as f:
            input_text = f.read()

        solution_text, total_profit = solve_green_revolution(input_text)

        # Print total profit
        print(f"File: {filename}, Total profit: {total_profit}")

        # Write solution to file
        with open(filename + "out.txt", "w") as f:
            f.write(solution_text)
