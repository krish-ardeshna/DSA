# Self Dividing Numbers

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/self-dividing-numbers/  
Difficulty: Easy  
Pattern: Math

## What I understood
We are given a range of integers.

A self-dividing number is a number that:

- is divisible by each of its digits
- does not contain the digit 0

We need to return all self-dividing numbers within the given range.

Example:

left = 1

right = 22

Output = [1,2,3,4,5,6,7,8,9,11,12,15,22]

## Idea
Create a helper function to check whether a number is self-dividing.

Extract each digit one by one:

- if the digit is 0, the number is invalid
- if the number is not divisible by the digit, it is invalid

Otherwise, include the number in the answer.

## Approach
- Traverse every number from left to right
- Extract each digit
- Check divisibility by every digit
- Ignore numbers containing 0
- Add valid numbers to the answer
- Return the final list

## Key Observation
Each number can be checked independently.

Digit extraction using modulo and division is sufficient to determine whether a number is self-dividing.

## When to use this
If the problem involves:
- digit extraction
- divisibility checks
- processing numbers independently

→ think modulo (%) and division (/)

## Edge Cases
- Single-digit numbers
- Numbers containing 0
- Numbers with repeated digits
- left equals right

## Complexity
Time: O((right − left + 1) × d)

where:
- d = number of digits

Space: O(1) (excluding the output array)

## Related Problems
- Add Digits
- Count Digits That Divide a Number
- Palindrome Number
- Reverse Integer