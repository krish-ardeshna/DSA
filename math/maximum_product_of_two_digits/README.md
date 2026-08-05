# Maximum Product of Two Digits

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-product-of-two-digits/  
Difficulty: Easy  
Pattern: Math

## What I understood
Given an integer `n`, find the maximum product that can be obtained by multiplying any two digits of the number.

Example:

n = 43152

Output = 20

## Idea
Traverse every digit once while keeping track of the largest and second largest digits seen so far.

Their product gives the maximum possible answer.

## Approach
- Initialize `largest` and `secondLargest`.
- Extract digits one by one using modulo.
- Update the two largest digits accordingly.
- Return their product.

## Key Observation
Only the two largest digits affect the answer, so sorting or storing all digits is unnecessary.

## When to use this
If the problem involves:
- digit extraction
- maximum values
- one-pass traversal

→ think Math

## Edge Cases
- Repeated largest digits
- Number with exactly two digits
- Digits containing zero

## Complexity
Time: O(d), where `d` is the number of digits.

Space: O(1)

## Related Problems
- Maximum 69 Number
- Add Digits
- Plus One
- Find Greatest Common Divisor of Array