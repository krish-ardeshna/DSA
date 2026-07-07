# Concatenate Non-Zero Digits and Multiply by Sum I

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/  
Difficulty: Easy  
Pattern: Math / Strings

## What I understood
We are given an integer.

We need to:

- remove all zero digits
- form a new number using the remaining digits
- calculate the sum of the remaining digits
- return the product of the sum and the newly formed number

Example:

n = 102304

Remaining digits = 1234

Sum = 10

Answer = 12340

## Idea
Convert the number into a string.

Traverse each character:
- ignore zeros
- build the new number using the remaining digits
- simultaneously compute the digit sum

Finally, multiply the sum by the newly formed number.

## Approach
- Convert the number to a string
- Traverse every digit
- Ignore zeros
- Form the new number
- Calculate the digit sum
- Return sum × new number

## Key Observation
Both the new number and the digit sum can be computed in a single traversal.

There is no need for multiple passes.

## When to use this
If the problem involves:
- digit manipulation
- removing specific digits
- constructing a new number

→ think string traversal or digit extraction

## Edge Cases
- Number containing only one non-zero digit
- Number with multiple zeros
- Number without zeros
- Trailing or leading zeros after conversion

## Complexity
Time: O(d)

Space: O(d)

where:
- d = number of digits

## Related Problems
- Add Digits
- Self Dividing Numbers
- Count Digits That Divide a Number
- Reverse Integer