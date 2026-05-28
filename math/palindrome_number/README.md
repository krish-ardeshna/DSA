# Palindrome Number

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/palindrome-number/  
Difficulty: Easy  
Pattern: Math

## What I understood
A palindrome number reads the same forward and backward.

Example:
121 → palindrome  
123 → not palindrome

## Idea
Instead of reversing the entire number,
reverse only half of it.

This avoids:
- extra space
- overflow issues
- unnecessary computation

## Approach
- Negative numbers cannot be palindrome
- Numbers ending with 0 cannot be palindrome
  (except 0 itself)
- Keep extracting digits from end
- Build reversed half
- Stop when reversed half becomes greater than or equal to remaining number
- Compare both halves

## Key Observation
We only need half reversal.

For odd length numbers:
- middle digit does not matter

That is why:
rev / 10

is used.

## When to use this
If the problem involves:
- digit reversal
- palindrome checking
- avoiding extra space

→ think partial reversal

## Edge Cases
- Negative numbers
- Number ending with 0
- Single digit numbers
- Odd length numbers

## Complexity
Time: O(log n)  
Space: O(1)

## Related Problems
- Reverse Integer
- Add Digits
- String Palindrome