# Factorial Trailing Zeroes

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/factorial-trailing-zeroes/  
Difficulty: Medium  
Pattern: Math

## What I understood
Trailing zeroes in a factorial are formed by multiples of 10.

Since:
10 = 2 × 5

and factorials already contain many 2s, we only need to count how many 5s are present.

## Idea
Count all factors of 5 in the factorial.

Example:
25 contributes two 5s:
25 = 5 × 5

So we repeatedly divide by 5 and keep adding the quotient.

## Approach
- Initialize count = 0
- While n > 0:
  - divide n by 5
  - add result to count
- Return count

## Mistake I made
Initially thought about calculating the factorial directly, but that becomes very large and inefficient.

## When to use this
If the problem involves:
- trailing zeroes
- factorial properties
- counting factors

→ think about prime factorization instead of actual multiplication

## Edge Cases
- n = 0 → 0 trailing zeroes
- large values of n

## Complexity
Time: O(log₅ n)  
Space: O(1)