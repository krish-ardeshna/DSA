# Sequential Digits

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sequential-digits/  
Difficulty: Medium  
Pattern: String Generation

## What I understood
We are given two integers:

- low
- high

We need to return all numbers within this range whose digits are sequential.

A sequential digit number has every digit exactly one greater than the previous digit.

Example:

low = 100

high = 300

Output = [123,234]

## Idea
Use the string:

123456789

Every sequential digit number is simply a substring of this string.

Generate substrings of all possible lengths and convert them into integers.

Keep only those lying within the required range.

## Approach
- Store "123456789"
- Find the minimum and maximum digit lengths
- Generate every valid substring
- Convert it to an integer
- If it lies within the range, add it to the answer
- Return the final list

## Key Observation
Every valid sequential number already exists as a contiguous substring of "123456789".

Instead of checking every number in the range, directly generate only valid candidates.

## When to use this
If the problem involves:
- generating numbers
- digit patterns
- consecutive digits

→ think String Generation

## Edge Cases
- low and high have the same number of digits
- Single valid answer
- No valid answer
- Entire range of sequential numbers

## Complexity
Time: O(1)

Space: O(1)

The number of generated candidates is constant (at most 36).

## Related Problems
- Lexicographical Numbers
- Numbers With Same Consecutive Differences
- Count Numbers with Unique Digits
- Monotone Increasing Digits