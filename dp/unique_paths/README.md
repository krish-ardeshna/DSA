# Unique Paths
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/unique-paths/  
Difficulty: Medium  
Pattern: DP on Grids

## What I understood
A robot sits at the top-left corner of an `m x n` grid. It can only move RIGHT or DOWN. Count the number of distinct paths that reach the bottom-right corner.

## Example
```
Input
m = 3, n = 7
Output
28
```

```
Input
m = 3, n = 2
Output
3
```
Explanation: the 3 paths are Right -> Down -> Down, Down -> Down -> Right, Down -> Right -> Down.

```
Input
m = 1, n = 1
Output
1
```

## Idea (shared by all three techniques)
**State:** `f(i, j)` = number of ways to reach cell `(i, j)` from the start `(0, 0)`.

**Recurrence:** a cell can only be entered from the cell above it or the cell to its left, so:
```
f(i, j) = f(i - 1, j) + f(i, j - 1)
```

**Base cases:**
- `f(0, 0) = 1` (already at the start, one way: do nothing).
- Any cell outside the grid (`i < 0` or `j < 0`) = 0 ways.

**Answer:** `f(m - 1, n - 1)`.

There are only `m * n` distinct cells, but plain recursion would recompute the same cell many times, which is why the three techniques below all exist.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence as a recursive function starting from the destination and walking back toward the start. Cache the result of every `(i, j)` in a `dp` table so each cell is computed only once.

### Steps
- Create `dp[m][n]` filled with `-1` (meaning "not computed yet").
- Call `f(m - 1, n - 1, dp)`.
- If `(i, j)` is the start, return 1. If out of the grid, return 0.
- If `dp[i][j]` is already filled, return it.
- Otherwise compute `up = f(i - 1, j)` and `left = f(i, j - 1)`, store `dp[i][j] = up + left`, return it.
- Important: pass `dp` **by reference**. Passing it by value copies the table on every call and the cache never gets used.

### Complexity
Time: **O(m * n)**          
Space: **O(m * n)** for the dp table, plus **O(m + n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table from the start `(0, 0)` forward, so the two cells a cell depends on (above and left) are always already computed.

### Steps
- Create `dp[m][n]`.
- For every cell `(i, j)` in row-major order:
  - If it is `(0, 0)`, set `dp = 1`.
  - Else `up = dp[i - 1][j]` if `i > 0` (otherwise 0), `left = dp[i][j - 1]` if `j > 0` (otherwise 0).
  - `dp[i][j] = up + left`.
- Answer is `dp[m - 1][n - 1]`.

### Complexity
Time: **O(m * n)**          
Space: **O(m * n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` only reads row `i - 1` (the `up` value) and the cell just filled in the same row (the `left` value). Older rows are never touched again, so keep just one previous row (`prev`) and build the current row (`curr`) from it.

### Steps
- `prev` of size `n` holds the previous row (all 0 before the first row).
- For each row `i`, create `curr` of size `n`:
  - `curr[0..]` filled using `up = prev[j]` and `left = curr[j - 1]`.
  - Cell `(0, 0)` is set to 1.
- After the row is done, `prev = curr`.
- Answer is `prev[n - 1]` after the last row.

### Complexity
Time: **O(m * n)**          
Space: **O(n)**, only two rows of size `n`

---

## Key Observation
All three techniques solve the same recurrence. The only difference is how much memory they spend remembering past answers:

- Memoization is the most natural to write, but pays for the table plus recursion stack.
- Tabulation keeps the same table without the stack.
- Space optimization notices each row depends only on the row above, so one row is enough.

This also has a closed form: the robot makes `m - 1` downs and `n - 1` rights in some order, so the answer is `C(m + n - 2, m - 1)`. The DP version is the one that generalizes (obstacles, minimum path sum), which is why it is the one practiced here.

## When to use this
If problem involves:
- Counting paths or minimizing cost on a grid with fixed move directions
- A cell value that depends only on the cells just before it (above, left)
→ Think **DP with state = (row, col)**, then compress to a rolling row when only the previous row is read.

## Edge Cases
- `m = 1` or `n = 1`: only one path (a straight line).
- `m = 1, n = 1`: answer 1 (already at the destination).
- Large grids: Approach 1 recursion depth is `m + n`, still fine, but Approach 3 is the lightest on memory.
- Answer fits in `int` per LeetCode constraints (at most about 2 * 10^9).

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
- Unique Paths II
- Minimum Path Sum
- Triangle
- Dungeon Game