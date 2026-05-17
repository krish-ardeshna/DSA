# Perfect Squares

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/perfect-squares/  
Difficulty: Medium  
Pattern: Dynamic Programming / Math

## What I understood
We need to find the minimum number of perfect square numbers whose sum equals n.

Example:
12 = 4 + 4 + 4  
Answer = 3

## Idea

### Approach 1 (Dynamic Programming)
Build answers from smaller values.

For every number:
- try subtracting all possible perfect squares
- choose minimum answer

Transition:
dp[i] = min(dp[i], dp[i - square] + 1)

### Approach 2 (Math Optimization)
Use mathematical properties:

- if n itself is a perfect square → answer = 1
- if n can be written as sum of two perfect squares → answer = 2
- Legendre’s theorem helps determine when answer becomes 4
- otherwise answer is 3

## Approach
- DP:
  - build solution bottom-up
  - store minimum counts
- Math:
  - check special cases
  - reduce problem using number theory

## Key Observation
The answer is always between 1 and 4.

Instead of generating all combinations,
mathematical properties can drastically reduce computation.

## When to use this
If the problem involves:
- minimum combinations
- perfect squares
- repeated subproblems

→ think DP first, then optimize mathematically if possible

## Edge Cases
- n is already a perfect square
- small values of n
- numbers requiring 4 squares

## Complexity

### Dynamic Programming
Time: O(n√n)  
Space: O(n)

### Mathematical Optimization
Time: O(√n)  
Space: O(1)

## Related Problems
- Coin Change
- Fibonacci
- Perfect Number