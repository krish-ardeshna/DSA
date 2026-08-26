# Search a 2D Matrix II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/  
Difficulty: Medium  
Pattern: Matrix - Staircase Search (Top-Right / Bottom-Left Start)

## What I understood
Matrix has each row sorted left-to-right ascending, and each column sorted top-to-bottom ascending — but unlike "Search a 2D Matrix I", there's no guarantee the matrix is fully end-to-end sorted (last of one row can be greater than first of next row). Determine if `target` exists.

## Example
```
Input
matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output
true
```
```
Input
matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output
false
```

## Idea
Starting from the top-right corner gives a unique property: moving left decreases value, moving down increases value — a natural "staircase" structure. At each step, compare current cell to target: if too big, eliminate that column (move left); if too small, eliminate that row (move down). Each comparison eliminates exactly one row or one column, giving linear-ish overall traversal, not needing full binary search per row/column.

## Approach: Staircase Search from Top-Right Corner
- Start at `row = 0`, `col = m-1` (top-right corner).
- While within bounds: compare `matrix[row][col]` to target.
- If equal → found, return true.
- If current value `< target` → target must be further down this column (since row is fully smaller here), move `row++`.
- If current value `> target` → target must be further left this row (since column is fully bigger here), move `col--`.
- Exit loop (return false) once out of bounds.

## Key Observation
Top-right (or equivalently bottom-left) corner is the only position where both a "definitely smaller" direction (left) and "definitely larger" direction (down) exist simultaneously — starting from top-left or bottom-right wouldn't allow this clean elimination since both directions there move in the same relative direction (both increasing or both decreasing).

## When to use this
If problem involves:
- Matrix sorted row-wise AND column-wise independently (not necessarily fully end-to-end sorted)
→ Think **staircase search starting from top-right or bottom-left corner**, eliminating one row/column per comparison.

## Edge Cases
- Target smaller than all elements or larger than all elements (search exits immediately without match).
- Single row or single column matrix.
- Target equals a corner element.
- Square vs rectangular matrix (approach works identically either way).

## Complexity
### Approach
Time: **O(n + m)** — at most n row moves + m column moves before exiting            
Space: **O(1)**

where:
- `n` = number of rows
- `m` = number of columns

## Related Problems
- Search a 2D Matrix
- Kth Smallest Element in a Sorted Matrix
- Find in Mountain Array
- Younger Than Older Employee (staircase pattern variants)