# Twisted Mirror Path Count
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/twisted-mirror-path-count/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: DP on Grids (State = Cell + Direction We Entered With, Mirrors Force a Turn)

## What I understood
(Reconstructed from the accepted code, recheck against the LC statement.)  
Given an `m x n` grid with `0` (empty cell) and `1` (mirror). Start at the top-left cell, moving right. On an empty cell you may continue RIGHT or DOWN. A mirror cell does not let you choose: it reflects you. If you entered it moving right you leave moving down, and if you entered it moving down you leave moving right. A path that would leave the grid is dead. Count the paths that reach the bottom-right cell, modulo `10^9 + 7`.

## Example
(Hand-traced and checked by brute force, not copied from the LC page.)
```
Input
grid = [[0,0],
        [0,0]]
Output
2
```
Explanation: no mirrors, so it is the usual right-then-down or down-then-right.

```
Input
grid = [[0,1,1],
        [1,1,0]]
Output
1
```
Explanation: going right from (0,0) enters the mirror (0,1) moving right, so it turns down into the mirror (1,1) moving down, which turns right into (1,2), the target. That is a valid path. Going down from (0,0) enters the mirror (1,0) moving down, so it turns right into the mirror (1,1) moving right, which turns down. That leaves the grid, so the path is dead. Total is 1.

```
Input
grid = [[0,1,0],
        [0,0,1],
        [1,0,0]]
Output
5
```
Explanation: the 5 paths are (a capital letter is a free choice, a lowercase letter is a forced turn at a mirror):
- `R d R d`: (0,0) right, mirror (0,1) turns down, (1,1) right, mirror (1,2) turns down, target.
- `R d D R`: (0,0) right, mirror (0,1) turns down, (1,1) down, (2,1) right, target.
- `D R R d`: (0,0) down, (1,0) right, (1,1) right, mirror (1,2) turns down, target.
- `D R D R`: (0,0) down, (1,0) right, (1,1) down, (2,1) right, target.
- `D D r R`: (0,0) down, (1,0) down, mirror (2,0) turns right, (2,1) right, target.

## Idea (shared by all three techniques)
In a normal grid path problem, the cell is enough as a state. Here the move out of a mirror depends on HOW we entered it, so we also track the entry direction.

**State:** `(i, j, dir)`
- `dir = 0`: we entered `(i, j)` moving right (from the left).
- `dir = 1`: we entered `(i, j)` moving down (from above).

**Transition** at cell `(i, j)`:
```
empty cell (0):                 ways go right (entering (i, j+1) with dir 0)
                                and down      (entering (i+1, j) with dir 1)
mirror cell (1), dir = 0:       forced down   -> (i+1, j) with dir 1
mirror cell (1), dir = 1:       forced right  -> (i, j+1) with dir 0
```
Moves that leave the grid count as `0` ways.

**Base case:** the start cell `(0, 0)` is entered with `dir = 0` (one way). Reaching the bottom-right cell counts as one finished path.

**Answer:** the number of ways to reach `(m - 1, n - 1)`, summed over both entry directions, modulo `10^9 + 7`.

The `-1` memo marker is safe because all counts are non-negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Ask from the front: standing in `(i, j)` after entering with direction `dir`, how many ways lead to the target? Cache every `(i, j, dir)` answer.

### Steps
- Create `dp[m][n][2]` filled with `-1`.
- `f(i, j, dir)`: return `0` if outside the grid. Return `1` at the bottom-right cell.
- If `dp[i][j][dir]` is filled, return it.
- Empty cell: `f(i, j + 1, 0) + f(i + 1, j, 1)`.
- Mirror and `dir == 0`: `f(i + 1, j, 1)`. Mirror and `dir == 1`: `f(i, j + 1, 0)`.
- Take the result modulo `10^9 + 7`, store it, return it.
- Call `f(0, 0, 0)`.

### Complexity
Time: **O(m * n)**  
Space: **O(m * n)** for the dp table, plus **O(m + n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the grid row by row and PUSH the number of ways forward from each cell: `dp[i][j][0]` counts the ways that arrive moving right, `dp[i][j][1]` the ways that arrive moving down.

### Steps
- Create `dp[m][n][2]` filled with `0`. Set `dp[0][0][0] = 1`.
- For each cell, let `right = dp[i][j][0]` and `down = dp[i][j][1]`.
- Empty cell: `ways = right + down`. Add `ways` to `dp[i][j + 1][0]` and to `dp[i + 1][j][1]`.
- Mirror cell: add `right` to `dp[i + 1][j][1]` (right turns down) and add `down` to `dp[i][j + 1][0]` (down turns right).
- Skip a push when it would leave the grid.
- Answer is `dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]`.

### Complexity
Time: **O(m * n)**  
Space: **O(m * n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Two Rows)

### Idea
A cell only pushes into its right neighbour (same row) and the cell below it (next row). So only the current row and the next row are needed.

### Steps
- `cur` holds the current row, `nxt` holds the row below. Both have `n` pairs of `{right, down}`. Set `cur[0][0] = 1`.
- For each row, clear `nxt`.
- Process each cell exactly like Approach 2, but a push to the right goes into `cur[j + 1][0]` and a push down goes into `nxt[j][1]`.
- After the last row, the answer is `cur[n - 1][0] + cur[n - 1][1]`. Save it before the swap.
- After each row, `swap(cur, nxt)`.

### Complexity
Time: **O(m * n)**  
Space: **O(n)**, two rows

---

## Key Observation
The only new idea compared to Unique Paths II is the direction in the state. Without it, the answer for a mirror cell cannot be computed, because "turn" means something different for each entry direction. Two numbers per cell (`right`, `down`) are enough.

Every mirror removes a choice. A path through a mirror has no branching there, so mirrors do not multiply the number of paths, they can only redirect or kill them.

Each stored value is below `10^9 + 7`, so the sum of two values stays below `2 * 10^9 + 14`, which fits in `int`.

## When to use this
If problem involves:
- Counting grid paths where a cell changes your movement (mirror, teleport, forced turn)
- The effect depends on how you entered the cell
→ Think **DP on (cell, entry direction)**, usually just 2 or 4 states per cell.

## Edge Cases
- `1 x 1` grid (one path).
- Mirror at the top-left (the start is entered moving right, so it turns down).
- A mirror in the last row or last column that pushes the path outside the grid (that path is dead).
- A grid full of mirrors (paths are forced all the way, so there is at most one).
- Large grids (take the modulus at every addition).

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
- Unique Paths II
- Minimum Path Sum
- Minimum XOR Path in a Grid
- Minimum Falling Path Sum