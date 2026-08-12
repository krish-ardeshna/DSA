# Spiral Matrix
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/spiral-matrix/  
Difficulty: Medium  
Pattern: Matrix - Boundary Traversal (Four Pointers)

## What I understood
Given an `m x n` matrix, return all elements in spiral order — starting top-left, moving right, then down, then left, then up, repeating with a progressively shrinking boundary until all elements are visited.

## Example
```
Input
matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output
[1,2,3,6,9,8,7,4,5]
```
```
Input
matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output
[1,2,3,4,8,12,11,10,9,5,6,7]
```

## Idea
Maintain four boundary pointers (`top`, `bottom`, `left`, `right`) representing the current unvisited rectangle. Traverse each of the four edges in order (right along top, down along right, left along bottom, up along left), shrinking the corresponding boundary after each edge. Extra `if` checks before the bottom and left traversals prevent revisiting rows/columns already covered when matrix isn't square.

## Approach: Shrinking Boundary Simulation
- Traverse `top` row left→right, then `top++`.
- Traverse `right` column top→bottom, then `right--`.
- If `top <= bottom` still valid, traverse `bottom` row right→left, then `bottom--`.
- If `left <= right` still valid, traverse `left` column bottom→top, then `left++`.
- Repeat while `left <= right && top <= bottom`.

## Key Observation
The guard checks (`if top<=bottom`, `if left<=right`) before the third and fourth edges are essential — without them, a single-row or single-column matrix would have its one row/column traversed twice (once forward, once backward), producing duplicate elements.

## When to use this
If problem involves:
- Traversing a 2D grid in a specific geometric pattern (spiral, diagonal, boundary)
- Shrinking/expanding bounds control the traversal region
→ Think **four-pointer boundary simulation**.

## Edge Cases
- Single row matrix (`1 x n`).
- Single column matrix (`m x 1`).
- Single element matrix (`1 x 1`).
- Non-square matrix (`m != n`).

## Complexity
### Approach
Time: **O(n * m)** — every element visited exactly once     
Space: **O(1)** extra (excluding output array)

where:
- `n` = number of rows
- `m` = number of columns

## Related Problems
- Spiral Matrix II
- Spiral Matrix III
- Rotate Image
- Set Matrix Zeroes