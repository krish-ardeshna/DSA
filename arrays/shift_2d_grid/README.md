# Shift 2D Grid

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/shift-2d-grid/  
Difficulty: Easy  
Pattern: Matrix

## What I understood
We are given an `m × n` grid and an integer `k`.

In one shift:
- Every element moves one position to the right.
- The last element of a row becomes the first element of the next row.
- The last element of the grid becomes the first element.

We need to return the grid after `k` shifts.

Example:

grid = [[1,2,3],[4,5,6],[7,8,9]]

k = 1

Output = [[9,1,2],[3,4,5],[6,7,8]]

## Idea
Treat the 2D grid as a single 1D array.

For every element:
- compute its 1D index
- shift the index by `k`
- convert the shifted index back into row and column

## Approach
- Compute the total number of cells.
- Reduce `k` using modulo.
- Traverse every cell.
- Convert `(row, col)` into a 1D index.
- Compute the shifted index.
- Convert it back into `(row, col)` and place the value.
- Return the shifted grid.

## Key Observation
A 2D grid can be viewed as a linear array of size `m × n`.

Index conversion makes shifting simple without simulating each move.

## When to use this
If the problem involves:
- matrix rotation or shifting
- index transformation
- cyclic movement
- 2D to 1D mapping

→ think Index Mapping

## Edge Cases
- k = 0
- k greater than total cells
- Single row
- Single column
- 1 × 1 grid

## Complexity
Time: O(m × n)  
Space: O(m × n)

## Related Problems
- Rotate Image
- Spiral Matrix
- Reshape the Matrix
- Set Matrix Zeroes