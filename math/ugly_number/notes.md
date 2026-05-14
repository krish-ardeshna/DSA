# Ugly Number

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/ugly-number/  
Difficulty: Easy  
Pattern: Math

## What I understood
An ugly number is a number whose prime factors are limited to:
- 2
- 3
- 5

If after removing all these factors the number becomes 1,
then it is an ugly number.

## Idea
Keep dividing the number by:
- 2
- 3
- 5

as long as it is divisible.

At the end:
- if the remaining number is 1 → ugly number
- otherwise → not ugly

## Approach
- If n <= 0 → return false
- Repeatedly divide by:
  - 2
  - 3
  - 5
- Check final value

## Key Observation
We do not need to generate factors manually.

Removing all valid prime factors is enough to verify the condition.

## When to use this
If the problem involves:
- prime factors
- repeated divisibility
- factor reduction

→ think repeated division approach

## Edge Cases
- n <= 0
- n = 1
- prime numbers other than 2, 3, 5

## Complexity
Time: O(log n)  
Space: O(1)

## Related Problems
- Ugly Number II
- Power of Two
- Add Digits