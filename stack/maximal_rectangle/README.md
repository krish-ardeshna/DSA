# Maximal Rectangle
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximal-rectangle/  
Difficulty: Hard  
Pattern: Monotonic Stack (Histogram Reduction per Row)

## What I understood
Given a binary matrix (`'0'`/`'1'` characters), find the area of the largest rectangle containing only `1`s.

## Example
```
Input
matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output
6
```
```
Input
matrix = [["0"]]
Output
0
```

## Idea
Reduce this 2D problem to a series of 1D "Largest Rectangle in Histogram" problems. For each row, compute a "height" array where `height[j]` = number of consecutive `1`s ending at the current row in column `j` (running vertical count, resets to 0 on a `'0'`). Treating each row's height array as a histogram, the largest rectangle in that histogram represents the best rectangle whose BOTTOM edge is at the current row — running this for every row and taking the overall max covers all possible rectangles.

## Approach: Column Height Accumulation + Largest Rectangle in Histogram per Row
- Build `prefixSum[i][j]` = height of consecutive 1s ending at row `i` in column `j` (reset to 0 whenever `matrix[i][j] == '0'`, else increment from previous row's value).
- For each row `i`, treat `prefixSum[i]` as a histogram and compute its largest rectangle area via the standard monotonic stack technique (`largestRectangle` helper).
- Track the maximum area found across all rows.

## Key Observation
Every valid all-1s rectangle in the matrix has SOME specific row as its bottom edge — by computing the histogram-based largest rectangle for every possible "bottom row," every candidate rectangle gets considered exactly once, reducing the 2D search to n independent 1D histogram problems.

## When to use this
If problem involves:
- Finding largest all-same-value rectangle/submatrix in a 2D grid
→ Think **row-by-row height accumulation + largest rectangle in histogram**, reducing 2D to repeated 1D subproblems.

## Edge Cases
- All zeros matrix (answer 0).
- All ones matrix (answer = full matrix area).
- Single row or single column matrix.
- Matrix with isolated 1s (no rectangle larger than 1x1).

## Complexity
### Approach
Time: **O(n * m)** - building prefix sums O(n*m), plus O(m) largest-rectangle computation per row × n rows = O(n*m) total           
Space: **O(n * m)** - prefix sum storage

where:
- `n` = number of rows
- `m` = number of columns

## Related Problems
- Largest Rectangle in Histogram
- Maximal Square
- Count Submatrices With All Ones
- Number of Submatrices That Sum to Target