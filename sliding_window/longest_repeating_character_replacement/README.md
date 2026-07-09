# Longest Repeating Character Replacement

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-repeating-character-replacement/  
Difficulty: Medium  
Pattern: Sliding Window

## What I understood
We are given a string consisting of uppercase English letters and an integer k.

We can replace at most k characters.

We need to find the length of the longest substring that can be made of the same character after performing at most k replacements.

Example:

s = "AABABBA"

k = 1

Output = 4

because replacing one character gives the substring "AABA" or "ABBA".

## Idea
Use a sliding window to maintain a valid substring.

Track:
- the frequency of every character
- the highest frequency inside the current window

If the number of characters to replace becomes greater than k, shrink the window from the left.

## Approach
- Initialize a frequency array
- Expand the window using the right pointer
- Update the maximum character frequency
- If replacements needed exceed k:
  - shrink the window
- Update the maximum window length
- Return the answer

## Key Observation
The number of replacements needed is:

Window Size − Maximum Character Frequency

If this value is greater than k, the current window is invalid and must be reduced.

## When to use this
If the problem involves:
- longest substring
- limited replacements
- character frequencies
- expanding and shrinking windows

→ think Sliding Window

## Edge Cases
- Empty string
- k = 0
- All characters are the same
- k greater than the string length
- All characters are different

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Longest Substring Without Repeating Characters
- Max Consecutive Ones III
- Fruit Into Baskets
- Minimum Window Substring