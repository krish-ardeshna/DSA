# Triangle
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/triangle/  
Difficulty: Medium  
Pattern: DP on Grids (Fixed Start, Variable End)

## What I understood
A triangle of numbers is given, where row `i` has `i + 1` elements. Starting at the top, you move down one row at a time. From position `(i, j)` you may go to `(i + 1, j)` (directly below) or `(i + 1, j + 1)` (below and to the right). Find the minimum sum of a path from the top to the bottom row.

## Example
```
Input
triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output
11
```
Explanation: 2 -> 3 -> 5 -> 1 gives 11.

```
Input
triangle = [[-10]]
Output
-10
```

## Idea (shared by all three techniques)
The start is fixed (the top cell), but the end is free (any cell of the last row). Thinking from the bottom up makes this easy.

**State:** `f(i, j)` = minimum path sum from cell `(i, j)` down to the bottom row.

**Recurrence:** from `(i, j)` there are only two moves:
```
f(i, j) = triangle[i][j] + min( f(i + 1, j), f(i + 1, j + 1) )
```

**Base case:** on the last row there is nowhere to go, so `f(n - 1, j) = triangle[n - 1][j]`.

**Answer:** `f(0, 0)`.

Values can be negative (as low as -10^4), so a real path sum can equal `-1`. A `-1` marker for "not computed" in the memo table would be wrong, so `INT_MAX` is used instead.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Start at the top and recurse downward through the two possible moves, caching every `(i, j)` the first time it is solved. Without the cache, the same cells would be recomputed many times (two paths often meet at the same cell).

### Steps
- Create `dp[n][n]` filled with `INT_MAX` (not computed yet).
- Call `f(0, 0)`.
- At the last row, return the cell value directly.
- If `dp[i][j]` is already filled, return it.
- Otherwise compute `down` and `diagonal`, store the smaller in `dp[i][j]`, and return it.

### Complexity
Time: **O(n^2)**, there are about `n * (n + 1) / 2` cells, each solved once         
Space: **O(n^2)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Start from the last row (which is known) and move upward, so each cell finds the two cells it needs below it already computed.

### Steps
- Copy the last row into `dp[n - 1]`.
- For `i = n - 2` down to `0`, for `j = i` down to `0`:
  - `down = triangle[i][j] + dp[i + 1][j]`.
  - `diagonal = triangle[i][j] + dp[i + 1][j + 1]`.
  - `dp[i][j] = min(down, diagonal)`.
- Answer is `dp[0][0]`.

### Complexity
Time: **O(n^2)**            
Space: **O(n^2)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` reads only row `i + 1`. Keep one array for the row below (`front`) and one for the row being built (`curr`).

### Steps
- `front` starts as the last row.
- For each row going upward, fill `curr[j]` for `j = 0..i` using `front[j]` and `front[j + 1]`.
- After each row, `front = curr`.
- Answer is `front[0]`.

Stale entries beyond index `i` in `curr` are never read, because row `i - 1` only reads indices up to `i`.

### Complexity
Time: **O(n^2)**        
Space: **O(n)**, two arrays of size `n`

---

## Key Observation
Going bottom-up removes the need to choose an ending cell: every cell already knows its best cost to the bottom, and the top cell holds the final answer directly. Going top-down would force taking a minimum over the whole last row at the end. The space-optimized version fits especially well because the triangle's rows are already short, and only one row below is ever needed.

## When to use this
If problem involves:
- A path from a fixed top to any bottom cell with a small number of moves per step
→ Think **DP from the bottom up, state = best cost from this cell to the end**, then compress to one row.

## Edge Cases
- Single row triangle (answer is that one value, the loop never runs).
- Negative values (avoid `-1` as a memo marker).
- All elements equal (any path gives the same sum).
- Two rows (answer is the top plus the smaller of the two below).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^2) | O(n^2) + O(n) stack |
| Tabulation | O(n^2) | O(n^2) |
| Tabulation + Space Optimization | O(n^2) | O(n) |

where:
- `n` = number of rows in the triangle

## Related Problems
- Minimum Path Sum
- Minimum Falling Path Sum
- Unique Paths II
- Cherry Pickup II