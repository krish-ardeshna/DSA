# Minimum Falling Path Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/  
Difficulty: Medium  
Pattern: DP on Grids (Variable Start / Variable End)

## What I understood
Given an `n x n` matrix, a falling path starts at ANY cell in the first row and moves down one row at a time. From cell `(i, j)` the next cell must be `(i + 1, j - 1)`, `(i + 1, j)` or `(i + 1, j + 1)` (directly below, or diagonally left or right, staying inside the matrix). Find the minimum sum over all falling paths.

## Example
```
Input
matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output
13
```
Explanation: 1 -> 5 -> 7 gives 13.

```
Input
matrix = [[-19,57],[-40,-5]]
Output
-59
```
Explanation: -19 -> -40 gives -59.

## Idea (shared by all three techniques)
Unlike earlier grid problems, both the START (any cell of row 0) and the END (any cell of the last row) are free. The trick is to think backward: ask for the best path sum ENDING at a given cell, then take the best over the last row.

**State:** `f(i, j)` = minimum falling path sum that ends at cell `(i, j)`.

**Recurrence:** the previous cell was directly above, above-left or above-right:
```
f(i, j) = matrix[i][j] + min( f(i-1, j), f(i-1, j-1), f(i-1, j+1) )
```

**Base cases:**
- `i == 0`: the path starts here, `f(0, j) = matrix[0][j]`.
- Column outside the matrix (`j < 0` or `j >= m`): return a huge value (`1e9`) so that move is never chosen.

**Answer:** `min over j of f(n - 1, j)`.

Values can be negative, so a `-1` marker in the memo table would be ambiguous. Use `INT_MAX` as the "not computed" marker.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Start from every cell of the last row, recurse upward through the 3 possible predecessors, and cache each `(i, j)` result.

### Steps
- Create `dp[n][m]` filled with `INT_MAX` (not computed yet).
- For each `j` in the last row call `f(n - 1, j)` and keep the minimum.
- In `f`: out-of-range column returns `1e9`, row 0 returns `matrix[0][j]`.
- If `dp[i][j]` is already filled, return it.
- Otherwise compute `up`, `leftDiag`, `rightDiag`, store `dp[i][j] = matrix[i][j] + min(...)`, return it.

### Complexity
Time: **O(n * m)**, each cell computed once with 3 transitions          
Space: **O(n * m)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Fill the table top to bottom. Row 0 is just the matrix values, and every later row reads three cells from the row above.

### Steps
- Set `dp[0][j] = matrix[0][j]` for every column.
- For `i = 1 .. n - 1`, for each `j`:
  - `up = dp[i - 1][j]`.
  - `leftDiag = dp[i - 1][j - 1]` if `j > 0`, else `1e9`.
  - `rightDiag = dp[i - 1][j + 1]` if `j < m - 1`, else `1e9`.
  - `dp[i][j] = matrix[i][j] + min(up, leftDiag, rightDiag)`.
- Answer is the minimum of the last row `dp[n - 1]`.

### Complexity
Time: **O(n * m)**      
Space: **O(n * m)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` reads only row `i - 1`, so keep a single previous row instead of the full table.

### Steps
- `prev = matrix[0]` (the first row, exactly as in the base case).
- For each later row, build `curr` from `prev` using the same up / left-diagonal / right-diagonal rule.
- After each row, `prev = curr`.
- Answer is the minimum element of `prev`.

### Complexity
Time: **O(n * m)**      
Space: **O(m)**, two rows only

---

## Key Observation
Because the end is free, the answer is not a single cell like in Unique Paths, it is the minimum over the whole last row. The `1e9` placeholder for out-of-range columns is what handles the left and right edges without any extra branching in the recurrence. Also note this is a different move set from Minimum Path Sum (which moves right/down only): here each step has 3 choices going down.

## When to use this
If problem involves:
- A path that moves one row at a time with a few column choices
- Free start and free end (any cell in the first row / last row)
→ Think **DP with state = (row, col) meaning "best path ending here"**, then take the min over the final row.

## Edge Cases
- `n = 1`: the answer is the smallest value in that single row.
- All negative values (the path sum can be very negative, hence the INT_MAX sentinel).
- First or last column (one diagonal option is out of range, handled by `1e9`).
- All elements equal (any path gives the same sum).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * m) | O(n * m) + O(n) stack |
| Tabulation | O(n * m) | O(n * m) |
| Tabulation + Space Optimization | O(n * m) | O(m) |

where:
- `n` = number of rows
- `m` = number of columns

## Related Problems
- Minimum Path Sum
- Triangle
- Minimum Falling Path Sum II
- Cherry Pickup