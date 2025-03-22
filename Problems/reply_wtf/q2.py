from itertools import permutations


def shift_row(grid, row_idx, shift):
    """Shifts a row to the left by `shift` positions."""
    return grid[row_idx][-shift:] + grid[row_idx][:-shift]


def shift_column(grid, col_idx, shift):
    """Shifts a column upwards by `shift` positions."""
    N = len(grid)
    col = [grid[i][col_idx] for i in range(N)]
    col = col[-shift:] + col[:-shift]
    for i in range(N):
        grid[i][col_idx] = col[i]
    return grid


def is_valid_sudoku(grid, N):
    """Checks if the given grid satisfies Sudoku rules."""

    def unique(lst):
        nums = [x for x in lst if x != "X"]
        return len(nums) == len(set(nums))

    for i in range(N):
        if not unique(grid[i]):
            return False
        if not unique([grid[j][i] for j in range(N)]):
            return False
    return True


def brute_force_restore(grid, N):
    """Tries all possible row and column shifts to restore the original Sudoku."""
    for r in range(N):
        for s in range(1, N):
            temp_grid = [row[:] for row in grid]
            temp_grid[r] = shift_row(temp_grid, r, s)
            if is_valid_sudoku(temp_grid, N):
                return ("R", r, s), temp_grid

    for c in range(N):
        for s in range(1, N):
            temp_grid = [row[:] for row in grid]
            temp_grid = shift_column(temp_grid, c, s)
            if is_valid_sudoku(temp_grid, N):
                return ("C", c, s), temp_grid

    return None, None


def solve_sudoku_brute_force(N, grid):
    """Main function to find the original grid and solve it."""
    shift_info, restored_grid = brute_force_restore(grid, N)
    if not restored_grid:
        return "No solution found"

    # Solve the restored Sudoku using backtracking
    solved_grid = solve_sudoku(restored_grid, N)
    return shift_info, solved_grid


def solve_sudoku(grid, N):
    """Solves the Sudoku using backtracking."""

    def is_safe(grid, row, col, num):
        if num in grid[row]:
            return False
        if num in [grid[i][col] for i in range(N)]:
            return False
        return True

    def solve():
        for i in range(N):
            for j in range(N):
                if grid[i][j] == "X":
                    for num in map(str, range(1, N + 1)):
                        if is_safe(grid, i, j, num):
                            grid[i][j] = num
                            if solve():
                                return True
                            grid[i][j] = "X"
                    return False
        return True

    solve()
    return grid


def parse_input():
    """Parses input in the required format."""
    cases = int(input().strip())
    for case in range(1, cases + 1):
        N, shifts = map(int, input().strip().split())
        grid = []
        for _ in range(N):
            grid.append(input().strip().split())

        shift_info, solved_grid = solve_sudoku_brute_force(N, grid)
        print(f"Case #{case}: {shift_info[0]} {shift_info[1] + 1} {shift_info[2]}")
        for row in solved_grid:
            print(" ".join(row))


if __name__ == "__main__":
    parse_input()
