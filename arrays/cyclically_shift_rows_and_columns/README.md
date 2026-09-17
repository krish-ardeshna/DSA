# Cyclically Shift Rows and Columns
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/cyclically-shift-rows-and-columns/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Matrix - Modular Index Shifting

## What I understood
Given an `n x n` grid, each row `i` is cyclically shifted by `rowShift[i]` positions, and each column `j` is cyclically shifted by `colShift[j]` positions. Apply row shifts first, then column shifts on the result, returning the final transformed grid.

## Example
```
Input
n = 3, grid = [[1,2,3],[4,5,6],[7,8,9]], rowShift = [1,0,2], colShift = [0,1,2]
Output
(grid after applying row shifts, then column shifts)
```

## Idea
Cyclic shifting an array by `k` positions can be expressed directly via modular indexing — the element that ends up at position `j` after a right-cyclic-shift by `k` was originally at position `(j + k) % n`. Apply this row-wise first (each row independently shifted by its own `rowShift[i]`), store in a temporary grid, then apply the same modular shift logic column-wise on the temporary grid using `colShift[j]`.

## Approach: Row Shift Pass Then Column Shift Pass, Using Modular Indexing
- First pass: for each row `i`, compute `k = rowShift[i] % n` (handles shift values `>= n` safely), fill `temp[i][j] = grid[i][(j+k) % n]` for every column `j`.
- Second pass: for each column `j`, compute `k = colShift[j] % n`, fill `ans[i][j] = temp[(i+k) % n][j]` for every row `i`.
- Return `ans` — the fully row-and-column-shifted grid.

## Key Observation
Row and column shifts are independent operations applied in sequence — row shifts only rearrange elements WITHIN each row (columns don't move relative to each other yet), and column shifts only rearrange elements WITHIN each column of the already-row-shifted result. Using `% n` on the shift amount itself (not just the index) correctly handles shift values that exceed the grid dimension.

## When to use this
If problem involves:
- Cyclic shifting of rows/columns (or any sequence) by a given amount
→ Think **modular indexing** (`(index + shift) % n`) to directly compute the shifted position without simulating individual shift-by-1 rotations.

## Edge Cases
- Shift amount equal to or exceeding `n` (handled via `% n`).
- Shift amount of 0 (no change for that row/column).
- All rows/columns shifted by the same amount.
- Single row/column grid (`n = 1`, all shifts are no-ops).

## Complexity
### Approach
Time: **O(n²)** — two full passes over the grid     
Space: **O(n²)** — temporary grid storage

where:
- `n` = grid dimension (n x n)

## Related Problems
- Rotate Image
- Rotate Array
- Set Matrix Zeroes
- Spiral Matrix