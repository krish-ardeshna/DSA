# Cherry Pickup II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/cherry-pickup-ii/  
Difficulty: Hard  
Pattern: DP on Grids (3D DP, Two Moving Robots)

## What I understood
A grid of cherries has `rows` rows and `cols` columns. Robot 1 starts at the top-left `(0, 0)` and Robot 2 starts at the top-right `(0, cols - 1)`. Both move down one row at a time, and from column `j` each can go to column `j - 1`, `j`, or `j + 1` in the next row (staying inside the grid). Each robot collects the cherries in every cell it visits, and if both robots stand on the same cell, the cherries are counted only once. Find the maximum total cherries both robots can collect together.

## Example
```
Input
grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output
24
```
Explanation: Robot 1 collects 3 + 2 + 5 + 2 = 12, Robot 2 collects 1 + 5 + 5 + 1 = 12, total 24.

```
Input
grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output
28
```

## Idea (shared by all three techniques)
Two robots moving independently would be hard to plan. But both always move down exactly one row per step, so at any moment they are in the SAME row. That means the whole situation is described by just three numbers: the row, and the column of each robot.

**State:** `f(i, j1, j2)` = maximum cherries collectable from row `i` to the last row, with Robot 1 at column `j1` and Robot 2 at column `j2`.

**Recurrence:** collect the cherries at the current cell(s), then try all `3 * 3 = 9` combinations of next moves:
```
current = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]
f(i, j1, j2) = current + max over (dj1, dj2) in {-1,0,1}^2 of f(i + 1, j1 + dj1, j2 + dj2)
```

**Base cases:**
- A column outside the grid is invalid, return a huge negative (`-1e8`) so that move is never chosen.
- On the last row there are no more moves, return just the current cell value(s).

**Answer:** `f(0, 0, cols - 1)`.

Cherry counts are never negative, so `-1` is safe as the "not computed yet" marker in the memo table (invalid states return `-1e8` before anything is stored).

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Walk down from row 0 with the two robots at their starting columns. Cache every `(i, j1, j2)` state so each is solved only once.

### Steps
- Create `dp[rows][cols][cols]` filled with `-1`.
- Call `f(0, 0, cols - 1)`.
- Out-of-range column: return `-1e8`.
- Last row: return the cell value (counted once if both robots share the cell).
- If `dp[i][j1][j2]` is already filled, return it.
- Otherwise try the 9 move pairs, take the best `current + f(next state)`, store and return it.

### Complexity
Time: **O(rows * cols * cols * 9)**         
Space: **O(rows * cols * cols)** for the dp table, plus **O(rows)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Fill the same 3D table starting from the last row, so each state's 9 possible next states (one row below) are already computed.

### Steps
- Base: for the last row, `dp[n - 1][j1][j2]` = the cell value(s) for every column pair.
- For `i = n - 2` down to `0`, for every `(j1, j2)`:
  - Try all 9 `(dj1, dj2)` pairs, skip any that leave the grid.
  - `value = current cell(s) + dp[i + 1][nj1][nj2]`, keep the max.
  - Store the max in `dp[i][j1][j2]`.
- Answer is `dp[0][0][cols - 1]`.

### Complexity
Time: **O(rows * cols * cols * 9)**         
Space: **O(rows * cols * cols)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` only reads row `i + 1`. So instead of a 3D table, keep a single 2D layer `dp[j1][j2]` for the row below and build `curr[j1][j2]` for the current row.

### Steps
- `dp` starts as the last row's layer.
- For each row going upward, compute a fresh `curr` of size `cols * cols` from `dp` with the same 9-move rule.
- After each row, `dp = curr`.
- Answer is `dp[0][cols - 1]`.

### Complexity
Time: **O(rows * cols * cols * 9)**     
Space: **O(cols * cols)**, one layer at a time

---

## Key Observation
The big insight is moving both robots together row by row. That turns a hard two-path problem into a clean state of `(row, col1, col2)`. It also handles the "same cell counts once" rule for free, since both robots are always in the same row and the check is just `j1 == j2`. The 9-way inner loop is the cost of tracking two independent choices at once.

## When to use this
If problem involves:
- Two agents moving simultaneously, one step per row (or per time unit)
- Their positions interact (shared cell, shared resource)
→ Think **one DP state holding both agents' positions at the same step**, with the transition being the product of both agents' moves.

## Edge Cases
- Single column grid (both robots always share the one column, cherries counted once).
- Robots meeting in the same cell (counted once).
- Robots never able to meet (columns far apart).
- Single row grid (answer is just the two starting cells, or one if `cols == 1`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(rows * cols^2 * 9) | O(rows * cols^2) + O(rows) stack |
| Tabulation | O(rows * cols^2 * 9) | O(rows * cols^2) |
| Tabulation + Space Optimization | O(rows * cols^2 * 9) | O(cols^2) |

where:
- `rows` = number of rows in the grid
- `cols` = number of columns in the grid

## Related Problems
- Cherry Pickup
- Minimum Falling Path Sum
- Triangle
- Unique Paths II