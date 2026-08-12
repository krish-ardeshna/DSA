# Set Matrix Zeroes
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/set-matrix-zeroes/  
Difficulty: Medium  
Pattern: Matrix - In-Place Marker (First Row/Col as Flags)

## What I understood
Given an `m x n` matrix, if an element is 0, set its entire row and column to 0. Must be done in-place. Optimal solution targets O(1) extra space (not counting output).

## Example
```
Input
matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output
[[1,0,1],[0,0,0],[1,0,1]]
```
```
Input
matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output
[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

## Idea
Instead of using extra row/col boolean arrays (O(m+n) space), reuse the matrix's own first row and first column as marker space. Since first row/col overlap at `matrix[0][0]`, need one separate flag (`col0`) to track whether first column itself needs zeroing — because `matrix[0][0]` alone can't represent both "first row has a zero" and "first column has a zero" at once.

## Approach: Use First Row/Column as Marker Space
- First pass: scan full matrix, whenever `matrix[i][j] == 0`, mark `matrix[i][0] = 0` (row flag) and `matrix[0][j] = 0` (col flag). Special-case `j == 0` using separate `col0` flag since `matrix[0][0]` is shared.
- Second pass: for all cells except first row/col, zero out `matrix[i][j]` if its row flag (`matrix[i][0]`) or col flag (`matrix[0][j]`) is 0.
- Handle first row separately using `matrix[0][0]` flag.
- Handle first column separately using `col0` flag.

## Key Observation
The overlap cell `matrix[0][0]` can only carry one bit of information, but two flags are needed (first row zero? first column zero?) — hence the extra `col0` variable sidesteps that conflict without needing extra array space.

## When to use this
If problem involves:
- In-place matrix marking/propagation with O(1) space constraint
- Need to remember "should this row/col be affected" without extra structures
→ Think **reuse matrix's own border (first row/col) as flag storage**.

## Edge Cases
- Zero already present in first row or first column (handled via `col0` / `matrix[0][0]`).
- Entire matrix is zero.
- Single row or single column matrix.
- No zeroes present at all (matrix unchanged).

## Complexity
### Approach
Time: **O(n * m)** — two full passes over matrix
Space: **O(1)** — only matrix itself used as marker storage, no extra array

where:
- `n` = number of rows
- `m` = number of columns

## Related Problems
- Game of Life
- Rotate Image
- Spiral Matrix
- Valid Sudoku