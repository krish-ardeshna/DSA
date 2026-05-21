# Perfect Number

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/perfect-number/  
Difficulty: Easy  
Pattern: Math

## What I understood
A perfect number is a number equal to the sum of its positive divisors excluding itself.

Example:
28 → 1 + 2 + 4 + 7 + 14 = 28

## Idea
Instead of checking every number till n,
divisors can be found in pairs.

If:
i divides num

then:
num / i also becomes a divisor.

This reduces unnecessary iterations.

## Approach
- If num <= 1:
  return false
- Initialize sum = 1
- Traverse from 2 to √num
- If divisor found:
  - add i
  - add paired divisor
- Compare final sum with original number

## Key Observation
Divisors always appear in pairs around the square root.

That allows the search space to shrink from n to √n.

## When to use this
If the problem involves:
- divisors
- factor pairs
- mathematical optimization

→ think square root traversal

## Edge Cases
- num = 1
- perfect square numbers
- prime numbers

## Complexity
Time: O(√n)  
Space: O(1)

## Related Problems
- Count Primes
- Ugly Number
- Perfect Squares