# Rotate Image

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/rotate-image/  
Difficulty: Medium  
Pattern: Matrix Manipulation (Transpose + Reverse)

## What I understood
We need to rotate the matrix 90 degrees clockwise "in-place".  
Using extra space is possible, but the goal is to do it without extra memory.

## Idea
A 90° clockwise rotation can be achieved in two steps:
1. Transpose the matrix (swap rows with columns)
2. Reverse each row

## Approach
- Step 1: Transpose
  - Swap matrix[i][j] with matrix[j][i] for j >= i
- Step 2: Reverse each row
  - Reverse every row of the matrix

## Mistake I made
Initially tried to rotate layer by layer manually, which was more complex and error-prone.

## When to use this
If the problem involves:
- rotating a square matrix
- in-place transformation

→ think "transpose + reverse"

## Edge Cases
- 1x1 matrix
- Matrix with identical elements

## Complexity
Time: O(n^2)  
Space: O(1)