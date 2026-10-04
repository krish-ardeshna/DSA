# Check if There Is a Valid Parentheses String Path
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/  
Difficulty: Hard  
Pattern: Grid DP (Reachable Balance Values, Row-Rolling Array)

## What I understood
Grid of `(` and `)` characters. Starting at top-left, moving only right or down, reach bottom-right such that the concatenated path of characters forms a VALID parentheses string (balance never goes negative mid-path, ends at exactly zero).

## Example
```
Input
grid = [["(","(","("],[")","(",")"],["(","(",")"]]
Output
true
```
```
Input
grid = [[")"]]
Output
false
```

## Idea
At any cell, track every possible "balance" value (open count minus close count) achievable by SOME valid-so-far path reaching that cell. A path is invalid the moment balance goes negative, so those states are simply never marked reachable. Since path length to any cell `(i,j)` is fixed (`i+j+1`), and balance parity must match that length's parity, the total distinct balance values per cell is bounded by `m+n`, keeping the DP small. Use a rolling array over columns to avoid storing the full grid's DP table.

## Approach: DP Over (Column, Balance) Rolled Row by Row
- Early exits: total path length `m+n-1` must be even (can't have balance 0 on an odd-length path), start cell must be `(`, end cell must be `)`.
- `dp[j][balance]` represents: is `balance` achievable at the CURRENT row's column `j` (rolled - gets overwritten each row).
- Initialize `dp[0][1] = true` (cell (0,0) is `(`, contributing balance 1).
- For each cell `(i,j)` (skipping the already-initialized origin): current cell changes balance by `+1` (if `(`) or `-1` (if `)`). For every possible resulting `balance`, check if `balance - change` was reachable from ABOVE (`dp[j]`, still holding previous row's data since not yet overwritten) or from LEFT (`dp[j-1]`, already updated to current row since processed earlier in this row's iteration).
- After computing `cur` for this cell, overwrite `dp[j] = cur`.
- Final answer: `dp[n-1][0]` - is balance 0 reachable at the bottom-right cell.

## Key Observation
The rolling trick relies on iteration ORDER: since `j` increases within a row, `dp[j-1]` has ALREADY been updated to reflect the current row by the time cell `j` is processed, while `dp[j]` (before this cell overwrites it) still correctly holds the PREVIOUS row's value - this dual-state trick lets a single 1D-per-column array serve as both "row above" and "row so far" sources without needing a full 2D table.

## When to use this
If problem involves:
- Grid path validity depending on a running "balance" or similar accumulated state (not just position)
→ Think **DP tracking the set of reachable state values per cell** (using a boolean array indexed by state), with a rolling array to reduce space when only the previous row/column is needed.

## Edge Cases
- Grid with odd total path length (`m+n-1` odd) → immediately false.
- Start cell is `)` or end cell is `(` → immediately false (no valid path possible).
- Single cell grid (`m=n=1`) → path length 1, always odd, always false.
- Grid where balance can reach 0 through multiple different paths (any one being valid is enough).

## Complexity
### Approach
Time: **O(m * n * (m+n))** - for each cell, iterate up to `m+n` possible balance values         
Space: **O(n * (m+n))** - rolling dp array across all columns

where:
- `m` = number of rows
- `n` = number of columns

## Related Problems
- Valid Parentheses
- Unique Paths
- Minimum Path Sum
- Out of Boundary Paths