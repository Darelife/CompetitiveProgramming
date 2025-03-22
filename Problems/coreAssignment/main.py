import os
import random

# Create directories for input and output files if they don't already exist.
os.makedirs("input", exist_ok=True)
os.makedirs("output", exist_ok=True)

# ---------------------------
# Helper functions for solving the problem
# ---------------------------


def is_valid_threshold(arr, D, candidate):
    """
    Check if there is at least one contiguous subarray of length D
    in which every element is >= candidate.
    """
    count = 0
    for num in arr:
        if num >= candidate:
            count += 1
        else:
            count = 0
        if count >= D:
            return True
    return False


def find_best_threshold(arr, D):
    """
    Use binary search over the range [0, max(arr)] to find the maximum x
    such that there is a contiguous subarray of length D with all elements >= x.
    """
    lo = 0
    hi = max(arr)
    best = 0
    while lo <= hi:
        mid = (lo + hi) // 2
        if is_valid_threshold(arr, D, mid):
            best = mid
            lo = mid + 1
        else:
            hi = mid - 1
    return best


def compute_max_avg(arr, D, threshold):
    """
    Given that a valid subarray must have all elements >= threshold,
    find the maximum average (over subarrays of length D) among all valid contiguous blocks.
    """
    N = len(arr)
    best_avg = 0.0
    i = 0
    while i < N:
        if arr[i] < threshold:
            i += 1
            continue
        # Find the contiguous block of valid numbers (>= threshold)
        j = i
        while j < N and arr[j] >= threshold:
            j += 1
        block = arr[i:j]
        if len(block) >= D:
            # Compute maximum sum for any window of length D in this block
            current_sum = sum(block[:D])
            best_sum = current_sum
            for k in range(D, len(block)):
                current_sum += block[k] - block[k - D]
                if current_sum > best_sum:
                    best_sum = current_sum
            candidate_avg = best_sum / D
            if candidate_avg > best_avg:
                best_avg = candidate_avg
        i = j
    return best_avg


def solve_case(arr, D):
    """
    Given an array and required window length D, compute:
      - the maximum threshold x such that there is a full D-length window with values >= x,
      - and the highest average among those valid subarrays.
    Returns (x, avg).
    """
    threshold = find_best_threshold(arr, D)
    avg = compute_max_avg(arr, D, threshold)
    return threshold, avg


# ---------------------------
# Test case definitions
# ---------------------------
# We'll generate 11 test cases.
# Test case 0 is the sample test case.
# The remaining 10 cases are randomly generated.

test_cases = []

# Sample test case: input00.txt
# Format:
#   First line: "N D"
#   Second line: N space-separated integers.
sample_N = 8
sample_D = 3
sample_arr = [5, 3, 8, 6, 7, 2, 9, 4]
test_cases.append((sample_N, sample_D, sample_arr))

# Generate 10 additional test cases.
# We'll vary N and D and use random integers in the range [0, 10000].

# For reproducibility, you can set a seed:
random.seed(42)

# Define parameters for 10 additional test cases.
additional_params = [
    (5, 2),
    (10, 3),
    (15, 5),
    (20, 10),
    (50, 7),
    (100, 10),
    (100, 50),
    (200, 20),
    (1000, 100),
    (1000, 500),
]

for N, D in additional_params:
    arr = [random.randint(0, 10000) for _ in range(N)]
    test_cases.append((N, D, arr))

# ---------------------------
# Generate files for each test case.
# ---------------------------
for idx, (N, D, arr) in enumerate(test_cases):
    # Create the file names: inputXX.txt and outputXX.txt (with 00, 01, ... format)
    file_index = f"{idx:02d}"
    input_filename = os.path.join("input", f"input{file_index}.txt")
    output_filename = os.path.join("output", f"output{file_index}.txt")

    # Write the test case to the input file.
    with open(input_filename, "w") as fin:
        fin.write(f"{N} {D}\n")
        fin.write(" ".join(map(str, arr)) + "\n")

    # Compute the answer for the test case.
    best_threshold, best_avg = solve_case(arr, D)
    # Format the average to six decimal places.
    answer = f"{best_threshold} {best_avg:.6f}\n"

    # Write the answer to the output file.
    with open(output_filename, "w") as fout:
        fout.write(answer)

print("Test case generation complete. Files are in the 'input' and 'output' folders.")
