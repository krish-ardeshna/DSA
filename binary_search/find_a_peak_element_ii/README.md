# Find a Peak Element II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-a-peak-element-ii/  
Difficulty: Medium  
Pattern: Binary Search on Columns + Row Max Search

## What I understood
Given an `m x n` matrix, find any peak element — a cell strictly greater than all its adjacent neighbors (up, down, left, right). Matrix edges are treated as `-1` (always smaller). Multiple peaks may exist; return any one. Must run faster than O(n*m), targeting O(n log m) or O(m log n).

## Example
```
Input
mat = [[1,4],[3,2]]
Output
[0,1]
```
```
Input
mat = [[10,20,15],[21,30,14],[7,16,32]]
Output
[1,1]
```

## Idea
Binary search over columns instead of a 1D array. For a given middle column, find the row with the maximum value in that column — this specific cell is guaranteed to be `>=` its up/down neighbors (since it's the column max). Then only need to compare it against its left/right neighbors to decide direction: if it's a peak in all 4 directions, done; otherwise move toward whichever side neighbor is larger (guaranteed peak exists in that direction, similar to 1D peak-finding logic).

## Approach: Binary Search on Column, Max Element in that Column
- Binary search `mid` over column range `[0, m-1]`.
- Find row index with max value in column `mid` via linear scan (`findMaxIndex`) — guarantees vertical neighbors are already satisfied.
- Compare that cell to its immediate left and right neighbors (bounds-checked, defaulting to -1 at edges).
- If greater than both → return `{row, mid}` as peak.
- If left neighbor is greater → peak must exist to the left, `high = mid - 1`.
- Else → peak must exist to the right, `low = mid + 1`.

## Key Observation
Finding column max first eliminates the need to separately verify up/down neighbors — that check is guaranteed by construction. This reduces the 2D peak problem to a 1D-style peak search purely along the horizontal axis, using the classic "move toward the larger neighbor" guarantee that a peak must exist in that direction.

## When to use this
If problem involves:
- 2D peak/local-maximum search with adjacency constraints
- Need better than O(n*m) time
→ Think **binary search on one dimension + linear scan on the other to establish a guaranteed-satisfied direction**, reducing to 1D peak-finding logic on the remaining dimension.

## Edge Cases
- Single row or single column matrix.
- Single cell matrix (trivially a peak).
- Multiple valid peaks (any one acceptable).
- Peak located at matrix boundary (edges treated as -1, simplifying comparisons).

## Complexity
### Approach
Time: **O(n log m)** — binary search over m columns, O(n) column-max scan per iteration     
Space: **O(1)** extra

where:
- `n` = number of rows
- `m` = number of columns

## Related Problems
- Find Peak Element
- Search a 2D Matrix
- Search a 2D Matrix II
- Peak Index in a Mountain Array