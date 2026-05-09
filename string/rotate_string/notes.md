# Rotate String

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/rotate-string/  
Difficulty: Easy  
Pattern: Strings

## What I understood
We need to check if one string can become another after some rotations.

Instead of manually rotating again and again, there is a simpler observation.

## Idea
If a string is rotated, it will always appear inside the original string concatenated with itself.

Example:
s = "abcde"

s + s = "abcdeabcde"

All possible rotations exist inside this combined string.

## Approach
- Check if lengths are equal
  - If not → return false
- Concatenate string with itself
- Use find() to check if goal exists inside it

## Mistake I made
Initially thought about rotating the string one step at a time, which is unnecessary.

## When to use this
If the problem involves:
- cyclic rotations
- repeated string shifts
- rotation validation

→ think about concatenating the string with itself

## Edge Cases
- Different length strings
- Empty strings
- Same strings

## Complexity
Time: O(n)  
Space: O(n)