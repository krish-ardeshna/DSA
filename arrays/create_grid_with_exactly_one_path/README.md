# Create Grid With Exactly One Path
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Construction (Open an L-Shaped Corridor, Block Everything Else)

## What I understood
(Reconstructed from the accepted code, recheck against the LC statement.)  
Given `m` and `n`, build an `m x n` grid where each cell is open (`.`) or blocked (`#`), so that there is exactly ONE path from the top-left cell to the bottom-right cell. Any valid grid is accepted.

## Example
```
Input
m = 3, n = 4
Output
....
###.
###.
```
Explanation: the only way through is along the top row to the right edge, then down the last column.

```
Input
m = 1, n = 3
Output
...
```
Explanation: a single row, the only path is straight across.

```
Input
m = 3, n = 1
Output
.
.
.
```
Explanation: a single column, the only path is straight down.

## Idea
To get exactly one path, make the open cells form a single line with no branches and no loops. Then there is only one way to walk along it.

The simplest line from the top-left to the bottom-right is an "L" shape:
- the whole **first row** (from the top-left cell to the top-right cell), then
- the whole **last column** (from the top-right cell down to the bottom-right cell).

Every other cell is blocked, so there is nowhere else to go.

## Approach: Open the First Row and the Last Column, Block All Other Cells
- Create an `m x n` grid filled with `'#'` (all blocked).
- Set the first row to all `'.'`.
- Set the last cell of every row to `'.'` (this opens the last column).
- Return the grid.

## Key Observation
The open cells form a chain where every cell has at most two open neighbours (the one before and the one after it), so there is no place to branch and no loop to go around. That makes the path unique, whether moves are limited to right and down, or allowed in all four directions: with no loops, any path that never repeats a cell has to follow the chain. The corner cell `(0, n - 1)` is where the row turns into the column, and it is set open by both steps, which is harmless.

## When to use this
If problem involves:
- Constructing an example (not searching for one) that satisfies a path-count condition
→ Think **the simplest shape that cannot branch**, such as a straight line or an L, and block everything else.

## Edge Cases
- `m = 1` (a single open row, the path goes straight across).
- `n = 1` (a single open column, the path goes straight down).
- `m = 1` and `n = 1` (one open cell, the start is also the end).
- Large `m` and `n` (the construction is the same, only the output is bigger).

## Complexity
### Approach
Time: **O(m * n)**, to fill the grid  
Space: **O(m * n)** for the output grid

where:
- `m` = number of rows
- `n` = number of columns

## Related Problems
- Unique Paths
- Unique Paths II
- Spiral Matrix II
- Number of Closed Islands