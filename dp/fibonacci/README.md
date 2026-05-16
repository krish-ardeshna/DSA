# Fibonacci Number

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/fibonacci-number/  
Difficulty: Easy  
Pattern: Recursion / Dynamic Programming

## What I understood
Fibonacci is a sequence where each number is the sum of the previous two numbers.

F(0) = 0  
F(1) = 1  
F(n) = F(n-1) + F(n-2)

## Idea

### Approach 1 (Recursion)
Break the problem into smaller subproblems:
- Compute fib(n-1) and fib(n-2)
- Add them

### Problem
This approach recalculates the same values multiple times, making it slow.

### Approach 2 (Dynamic Programming - Iterative)
Instead of recalculating:
- Store previous results
- Build solution from bottom up

## Approach
- If n <= 1 → return n
- Recursion:
  - return fib(n-1) + fib(n-2)
- Iterative:
  - Start with 0 and 1
  - Loop till n and keep updating

## Mistake I made
Initially used recursion without realizing it causes repeated calculations.

## When to use this
If problem involves:
- overlapping subproblems
- repeated calculations  

→ think dynamic programming

## Edge Cases
- n = 0 → 0  
- n = 1 → 1  

## Complexity
Recursion:  
Time: O(2^n)  
Space: O(n)

Dynamic Programming:  
Time: O(n)  
Space: O(1)