# Ugly Number II

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/ugly-number-ii/  
Difficulty: Medium  
Pattern: Dynamic Programming

## What I understood
An ugly number is a positive integer whose prime factors are only:

- 2
- 3
- 5

We need to return the nth ugly number.

Example:

n = 10

Output = 12

## Idea

### Approach 1 (Brute Force)
Check every positive integer.

For each number:
- repeatedly divide by 2, 3 and 5
- if the remaining value becomes 1, it is an ugly number

Count ugly numbers until reaching the nth one.

### Approach 2 (Dynamic Programming)
Generate ugly numbers in increasing order.

Maintain three pointers:

- i2
- i3
- i5

Each pointer generates the next multiple of:

- 2
- 3
- 5

Choose the minimum among them and move the corresponding pointer(s).

## Approach
- Initialize the ugly number list with 1
- Maintain three pointers
- Generate the next ugly number
- Update all matching pointers
- Return the nth ugly number

## Key Observation
Every ugly number is obtained by multiplying a previous ugly number by:

- 2
- 3
- 5

Using three pointers generates the sequence in sorted order without duplicates.

## When to use this
If the problem involves:
- sequence generation
- multiple pointers
- dynamic programming
- merging sorted sequences

→ think Dynamic Programming with Multiple Pointers

## Edge Cases
- n = 1
- Duplicate candidates
- Large values of n

## Complexity

### Approach 1
Time: Depends on how many numbers are checked (much slower than optimal)

Space: O(1)

### Approach 2
Time: O(n)

Space: O(n)

## Related Problems
- Ugly Number
- Super Ugly Number
- Fibonacci Number
- Climbing Stairs