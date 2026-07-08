# Longest Substring Without Repeating Characters

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/  
Difficulty: Medium  
Pattern: Sliding Window / Hash Map

## What I understood
We are given a string.

We need to find the length of the longest substring that contains no repeated characters.

A substring consists of consecutive characters.

Example:

s = "abcabcbb"

Output = 3

because "abc" is the longest substring without repeating characters.

## Idea
Use a sliding window to maintain the current substring without duplicates.

Store the last index of every character in a hash map.

When a repeated character is found:
- move the left pointer just after its previous occurrence

Continue expanding the window and update the maximum length.

## Approach
- Initialize the left pointer at 0
- Traverse the string using the right pointer
- Store the last occurrence of each character
- If a duplicate is found:
  - move the left pointer forward
- Update the maximum window length
- Return the maximum length

## Key Observation
The left pointer never moves backward.

Each character is processed at most twice, making the algorithm linear.

## When to use this
If the problem involves:
- longest substring
- unique characters
- expanding and shrinking windows
- character frequency or indices

→ think Sliding Window + Hash Map

## Edge Cases
- Empty string
- Single character
- All characters are the same
- All characters are unique
- Repeated characters at the beginning or end

## Complexity
Time: O(n)  
Space: O(min(n, charset))

## Related Problems
- Longest Repeating Character Replacement
- Minimum Window Substring
- Permutation in String
- Longest Substring with At Most K Distinct Characters