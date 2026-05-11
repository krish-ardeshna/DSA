# Separate the Digits in an Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/separate-the-digits-in-an-array/  
Difficulty: Easy  
Pattern: Arrays / Simulation

## What I understood
We need to separate every digit from each number and store them individually while maintaining the original order.

## Idea

### Approach 1 (String Conversion)
Convert each number into a string and traverse every character.

Each character digit can be converted into integer using:
ch - '0'

This approach is simpler and easier to read.

### Approach 2 (Manual Digit Extraction)
Extract digits using modulo and division:
- digit = x % 10
- x /= 10

Since digits come in reverse order, reverse them before adding to final result.

## Approach
- Traverse every number in array
- Convert or extract digits
- Store digits individually in answer vector

## Mistake I made
Initially forgot that manual extraction gives digits in reverse order.

## When to use this
If the problem involves:
- digit separation
- preserving digit order
- digit traversal

→ string conversion can simplify implementation

## Edge Cases
- Number = 0
- Single digit numbers
- Multiple numbers in array

## Complexity
Time: O(total digits)  
Space: O(total digits)