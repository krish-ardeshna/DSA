# Minimum XOR Path in a Grid
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-xor-path-in-a-grid/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: DP on Grids (State = Cell + XOR So Far, Bitset of Reachable Values)

## What I understood
(Reconstructed from the accepted code, recheck against the LC statement.)  
Given an `m x n` grid of non-negative integers (each below 1024), start at the top-left and move only RIGHT or DOWN until the bottom-right. The cost of a path is the XOR of all the values on it, including both ends. Return the minimum possible cost.

## Example
```
Input
grid = [[1, 2],
        [3, 4]]
Output
6
```
Explanation: the two paths are 1, 2, 4 (XOR 7) and 1, 3, 4 (XOR 6). The minimum is 6.

```
Input
grid = [[1, 2, 3],
        [4, 5, 6]]
Output
0
```
Explanation: the path 1, 2, 5, 6 gives 1 ^ 2 ^ 5 ^ 6 = 0, which cannot be beaten.

```
Input
grid = [[5, 5, 5]]
Output
5
```
Explanation: there is only one path, 5 ^ 5 ^ 5 = 5.

## Idea (shared by all three techniques)
This looks like Minimum Path Sum, but a greedy or "keep only the best value per cell" DP does NOT work for XOR. The smallest XOR of a prefix does not lead to the smallest XOR of the whole path, because the next values can flip the bits in a way that depends on the exact prefix value. For example, a prefix XOR of 3 can become 0 after XOR with 3, while a prefix XOR of 1 can not.

So for each cell we must remember EVERY XOR value that some path can have when it arrives there.

Values are below 1024 = 2^10, and XOR of numbers below 2^10 stays below 2^10. So there are at most 1024 different XOR values per cell, which is small enough to track all of them.

**State:** `(i, j, x)` = is it possible to stand at cell `(i, j)` with the XOR of the path so far (including this cell) equal to `x`?

**Transition:** a path arrives at `(i, j)` from above or from the left. If `x` was reachable at the previous cell, then `x ^ grid[i][j]` is reachable here:
```
reach(i, j)  =  { x ^ grid[i][j]  :  x in reach(i - 1, j)  or  x in reach(i, j - 1) }
```

**Base case:** the start cell has the single value `grid[0][0]`.

**Answer:** the SMALLEST `x` that is reachable at the bottom-right cell.

The set of reachable values for one cell is stored as a `bitset<1024>`: bit `x` is 1 if the value `x` is reachable. That is only 128 bytes per cell.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Flip the question around: standing at `(i, j)` with the XOR collected so far, what is the smallest final XOR that any continuation can reach? Cache every `(i, j, cur)` result. A `-1` marker for "not computed yet" is safe because XOR values are never negative.

### Steps
- Create `dp[m][n][1024]` filled with `-1`.
- `f(i, j, cur)`: first do `cur ^= grid[i][j]`.
- At the bottom-right cell, return `cur` (the full path XOR).
- If `dp[i][j][cur]` is filled, return it.
- Otherwise take the smaller of `f(i + 1, j, cur)` (if there is a row below) and `f(i, j + 1, cur)` (if there is a column to the right), store it, return it.
- Call `f(0, 0, 0)`.

### Complexity
Time: **O(m * n * 1024)**  
Space: **O(m * n * 1024)** integers for the dp table (large, about 4 KB per cell), plus **O(m + n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill a table of bitsets row by row. `dp[i][j]` holds every XOR value that can arrive at `(i, j)`, built from the cell above and the cell to the left.

### Steps
- Create `dp[m][n]` of empty bitsets.
- Set `dp[0][0]` to contain only `grid[0][0]`.
- For every other cell, for every `x` from `0` to `1023`: if `x` is reachable from above (`dp[i - 1][j][x]`) or from the left (`dp[i][j - 1][x]`), set bit `x ^ grid[i][j]` in `dp[i][j]`.
- Answer is the smallest `x` with `dp[m - 1][n - 1][x]` set.

### Complexity
Time: **O(m * n * 1024)**  
Space: **O(m * n * 1024)** bits, about 128 bytes per cell, so far smaller than the memoization table

---

## Approach 3: Tabulation with Space Optimization (Rolling Row)

### Idea
A cell reads only the cell above it and the cell to its left, so only the previous row and the current row are needed. `dp[j]` holds the bitset for column `j` in the row above, and `curr[j]` is built for the current row.

### Steps
- `dp` has `n` bitsets, all empty, except `dp[0]` has the single bit `0` set. This is a virtual "row above the grid" that makes the start cell work: arriving at `(0, 0)` with XOR `0` gives `0 ^ grid[0][0]`.
- For each row, create a fresh `curr` of empty bitsets.
- For each column `j` and each `x`: if `dp[j][x]` (from above) or `curr[j - 1][x]` (from the left), set bit `x ^ grid[i][j]` in `curr[j]`.
- After each row, `dp = move(curr)`.
- Answer is the smallest set bit of `dp[n - 1]`.

### Complexity
Time: **O(m * n * 1024)**  
Space: **O(n * 1024)** bits, two rows of bitsets

---

## Key Observation
The whole difficulty is realizing that XOR does not allow the usual "keep only the minimum per cell". The fix is to change what the DP stores: instead of ONE best number per cell, store the SET of all reachable values, which is small because XOR of values below 1024 stays below 1024. Bitsets make that set cheap to store. The answer is then read from the final set, smallest value first. A neat extra: if the set at the end contains 0, the answer is 0, so the scan stops immediately.

## When to use this
If problem involves:
- A path or sequence cost combined with XOR (or any operation where partial minimums do not compose)
- Values bounded by a small power of two
→ Think **DP over (position, current XOR value)**, keeping the set of reachable values per position, with a bitset to make it compact.

## Edge Cases
- Single cell grid (answer is that cell's value).
- One row or one column (only one path exists).
- All cells equal (the XOR depends only on the parity of the path length).
- A path XOR of 0 exists (answer 0).
- Values of 1024 or larger would break the `bitset<1024>` indexing, so this relies on the constraint.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(m * n * 1024) | O(m * n * 1024) ints + O(m + n) stack |
| Tabulation | O(m * n * 1024) | O(m * n * 1024) bits |
| Tabulation + Space Optimization | O(m * n * 1024) | O(n * 1024) bits |

where:
- `m` = number of rows
- `n` = number of columns

## Related Problems
- Minimum Path Sum
- Unique Paths II
- Triangle
- Subset Sum