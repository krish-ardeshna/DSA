# Unique Paths II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/unique-paths-ii/  
Difficulty: Medium  
Pattern: DP on Grids (With Obstacles)

## What I understood
A robot sits at the top-left of an `m x n` grid and wants to reach the bottom-right. It can only move RIGHT or DOWN. Some cells hold an obstacle (`1`) and cannot be stepped on, free cells are `0`. Count the number of distinct paths to the destination.

## Example
```
Input
obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output
2
```
Explanation: the obstacle in the middle leaves two paths: Right -> Right -> Down -> Down, and Down -> Down -> Right -> Right.

```
Input
obstacleGrid = [[0,1],[0,0]]
Output
1
```

```
Input
obstacleGrid = [[1,0]]
Output
0
```
Explanation: the start cell itself is blocked, so no path exists.

## Idea (shared by all three techniques)
**State:** `f(i, j)` = number of ways to reach cell `(i, j)` from `(0, 0)`.

**Recurrence:** same as Unique Paths, except a blocked cell contributes nothing:
```
if cell (i, j) is an obstacle:  f(i, j) = 0
else:                           f(i, j) = f(i - 1, j) + f(i, j - 1)
```

**Base cases:**
- Obstacle cell: 0 ways (this check must come BEFORE the start-cell check, otherwise a blocked start would wrongly return 1).
- `f(0, 0) = 1` when the start is free.
- Outside the grid (`i < 0` or `j < 0`): 0 ways.

**Answer:** `f(m - 1, n - 1)`.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Walk backward from the destination. Each cell asks its upper and left neighbours how many ways they have, and stores the result so no cell is computed twice.

### Steps
- Create `dp[m][n]` filled with `-1` (not computed yet).
- Call `f(m - 1, n - 1)`.
- If the cell is an obstacle, return 0. If it is the start, return 1. If outside the grid, return 0.
- If `dp[i][j]` is filled, return it.
- Otherwise `dp[i][j] = f(i - 1, j) + f(i, j - 1)`, and return it.

### Complexity
Time: **O(m * n)**      
Space: **O(m * n)** for the dp table, plus **O(m + n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Fill the table from the start forward so the up and left cells are always ready.

### Steps
- Create `dp[m][n]`.
- For every cell in row-major order:
  - Obstacle: `dp = 0`.
  - Start cell: `dp = 1`.
  - Otherwise `dp = up + left`, where `up = dp[i - 1][j]` if `i > 0` and `left = dp[i][j - 1]` if `j > 0`.
- Answer is `dp[m - 1][n - 1]`.

### Complexity
Time: **O(m * n)**      
Space: **O(m * n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Each row only needs the row above (`prev`) and the cell just computed in the current row (`curr[j - 1]`). Keep two rows instead of the whole table.

### Steps
- `prev` holds the previous row, `curr` is built for the current row.
- Same rules as tabulation: obstacle gives 0, start gives 1, else `up = prev[j]` plus `left = curr[j - 1]`.
- After each row, `prev = curr`.
- Answer is `prev[n - 1]`.

### Complexity
Time: **O(m * n)**      
Space: **O(n)**

---

## Key Observation
An obstacle simply zeroes a cell, and the zero then flows naturally to everything that would have come through it, no special path-blocking logic is needed. The obstacle check must come before the start check, since the start cell can itself be an obstacle. The `long long` temporaries guard the `up + left` addition, the final answer is guaranteed to fit in `int` by the problem.

## When to use this
If problem involves:
- Counting grid paths with blocked cells
- Moves in fixed directions only
→ Think **same DP as Unique Paths, with an obstacle check that forces the cell value to 0**.

## Edge Cases
- Start cell is an obstacle (answer 0).
- Destination cell is an obstacle (answer 0).
- Obstacle in the first row or column (everything after it in that line becomes 0).
- Single cell grid, free (answer 1) or blocked (answer 0).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(m * n) | O(m * n) + O(m + n) stack |
| Tabulation | O(m * n) | O(m * n) |
| Tabulation + Space Optimization | O(m * n) | O(n) |

where:
- `m` = number of rows
- `n` = number of columns

## Related Problems
- Unique Paths
- Minimum Path Sum
- Unique Paths III
- Minimum Falling Path Sum