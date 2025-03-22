from itertools import product


def reverse_shift(grid, shift_type, index, shift_amount):
    """Reverse a shift operation on a grid."""
    N = len(grid)
    restored_grid = [row[:] for row in grid]

    if shift_type == "R":  # Row shift
        restored_grid[index] = grid[index][-shift_amount:] + grid[index][:-shift_amount]
    elif shift_type == "C":  # Column shift
        col = [grid[i][index] for i in range(N)]
        col = col[-shift_amount:] + col[:-shift_amount]
        for i in range(N):
            restored_grid[i][index] = col[i]

    return restored_grid


def detect_shifts(grid, S):
    """Detect S shifts in the grid and restore the original."""
    N = len(grid)
    restored_grid = [row[:] for row in grid]
    shifts = []

    for _ in range(S):
        best_shift = None
        best_grid = None
        best_score = float("inf")

        for shift_type, index in product(["R", "C"], range(N)):
            for shift_amount in range(1, N):
                test_grid = reverse_shift(
                    restored_grid, shift_type, index, shift_amount
                )
                score = count_violations(test_grid)
                if score < best_score:
                    best_score = score
                    best_shift = (shift_type, index, shift_amount)
                    best_grid = test_grid

                    # If we found a grid with no violations, stop searching
                    if score == 0:
                        break
            if best_score == 0:
                break

        if best_shift:
            shift_type, index, shift_amount = best_shift
            restored_grid = best_grid
            shifts.append((shift_type, index, shift_amount))

    return shifts, restored_grid


def count_violations(grid):
    """Count how many Sudoku rule violations exist in the grid."""
    N = len(grid)
    violations = 0

    # Check rows
    for row in grid:
        non_empty = [cell for cell in row if cell != "X"]
        violations += len(non_empty) - len(set(non_empty))

    # Check columns
    for col_idx in range(N):
        col = [grid[row_idx][col_idx] for row_idx in range(N)]
        non_empty = [cell for cell in col if cell != "X"]
        violations += len(non_empty) - len(set(non_empty))

    # Check boxes - only if N is a perfect square
    if (N**0.5).is_integer():
        box_size = int(N**0.5)
        for box_row in range(0, N, box_size):
            for box_col in range(0, N, box_size):
                box = []
                for r in range(box_row, box_row + box_size):
                    for c in range(box_col, box_col + box_size):
                        if r < N and c < N and grid[r][c] != "X":
                            box.append(grid[r][c])
                violations += len(box) - len(set(box))

    return violations


def solve_sudoku(grid):
    """Solve a Sudoku grid using backtracking."""
    N = len(grid)

    # Find an empty cell
    empty_found = False
    for i in range(N):
        for j in range(N):
            if grid[i][j] == "X":
                empty_found = True
                # Try placing each number
                for num in map(str, range(1, N + 1)):
                    # Check if it's valid to place this number
                    if is_valid_placement(grid, i, j, num):
                        grid[i][j] = num

                        # Recursive call
                        if solve_sudoku(grid):
                            return True

                        # If placing the number doesn't lead to a solution, backtrack
                        grid[i][j] = "X"

                # If we've tried all numbers and none work, this puzzle is unsolvable
                return False

    # If we've filled all cells, we've solved the puzzle
    return True


def is_valid_placement(grid, row, col, num):
    """Check if it's valid to place a number at a specific position."""
    N = len(grid)

    # Check row
    for j in range(N):
        if grid[row][j] == num:
            return False

    # Check column
    for i in range(N):
        if grid[i][col] == num:
            return False

    # Check box - only if N is a perfect square
    if (N**0.5).is_integer():
        box_size = int(N**0.5)
        box_row, box_col = (row // box_size) * box_size, (col // box_size) * box_size
        for i in range(box_row, box_row + box_size):
            for j in range(box_col, box_col + box_size):
                if grid[i][j] == num:
                    return False

    return True


def print_grid(grid):
    """Print the grid for debugging."""
    for row in grid:
        print(" ".join(row))
    print()


def main():
    try:
        with open("input.txt", "r") as file:
            lines = [line.strip() for line in file.readlines() if line.strip()]

        # Debug - print all lines
        print(f"Total lines in input file: {len(lines)}")
        for i, line in enumerate(lines[:10]):  # Print first 10 lines for debugging
            print(f"Line {i}: {line}")

        # Directly parse what appears to be N and S from the first line
        first_tokens = lines[0].split()

        # Try to identify which values are N and S
        # Based on the context, N should be the size of the grid, and S the number of shifts
        # We'll look for reasonable values (N between 2 and 36, S between 1 and 6)
        N = None
        S = None

        for token in first_tokens:
            try:
                value = int(token)
                if 2 <= value <= 36 and N is None:
                    N = value
                elif 1 <= value <= 6 and S is None:
                    S = value
            except ValueError:
                continue

        # If we couldn't determine N and S, try assuming they're the first two integers
        if N is None or S is None:
            try:
                N = int(first_tokens[0])
                S = int(first_tokens[1])
                print(f"Using first two numbers as N={N} and S={S}")
            except (ValueError, IndexError):
                raise ValueError(
                    "Could not determine grid size N and number of shifts S"
                )

        # Read the grid - assume it starts from the second line
        grid = []
        for i in range(1, min(N + 1, len(lines))):
            row = lines[i].split()
            if len(row) != N:
                print(f"Warning: Row {i} has {len(row)} elements, expected {N}")
                # Pad or truncate the row as needed
                row = (row + ["X"] * N)[:N]
            grid.append(row)

        # If we don't have enough rows, pad with empty rows
        while len(grid) < N:
            grid.append(["X"] * N)

        print(f"Grid size: {len(grid)}x{len(grid[0])}")
        print("Initial grid:")
        print_grid(grid)

        # Process the grid
        shifts, restored_grid = detect_shifts(grid, S)
        print("Shifts detected:", shifts)
        print("Restored grid:")
        print_grid(restored_grid)

        solution = [row[:] for row in restored_grid]
        if solve_sudoku(solution):
            print("Solution found!")
            print_grid(solution)
        else:
            print("No solution found.")

        # Format the output
        case_result = ["Case #1:"]
        for shift_type, index, shift_amount in shifts:
            case_result.append(f"{shift_type} {index} {shift_amount}")

        for row in solution:
            case_result.append(" ".join(row))

        # Write the output
        with open("output.txt", "w") as file:
            file.write("\n".join(case_result))

        print("Processing complete. Results written to output.txt")

    except Exception as e:
        import traceback

        print(f"Error occurred: {e}")
        traceback.print_exc()


if __name__ == "__main__":
    main()
