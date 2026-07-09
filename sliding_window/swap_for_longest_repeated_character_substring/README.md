# Swap For Longest Repeated Character Substring

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/  
Difficulty: Medium  
Pattern: Sliding Window

## What I understood
We are given a string.

We may swap at most one character with another occurrence of the same character.

We need to find the maximum length of a substring consisting of only one repeated character after at most one swap.

Example:

text = "ababa"

Output = 3

## Idea
Count the total frequency of every character.

For each character:
- use a sliding window
- allow at most one different character inside the window

If the window becomes larger than the total frequency of that character, limit the answer to its total occurrences.

## Approach
- Count the frequency of every character
- For each character:
  - maintain a sliding window
  - allow at most one different character
  - shrink the window when needed
- Update the maximum valid window length
- Return the answer

## Key Observation
A valid window can contain at most one different character because only one swap is allowed.

The answer also cannot exceed the total occurrences of that character in the string.

## When to use this
If the problem involves:
- longest substring
- one modification or swap
- character frequencies
- sliding window

→ think Sliding Window

## Edge Cases
- Single character string
- All characters are the same
- All characters are different
- Only one occurrence of a character

## Complexity
Time: O(26 × n) = O(n)  
Space: O(26) = O(1)

## Related Problems
- Longest Repeating Character Replacement
- Longest Substring Without Repeating Characters
- Max Consecutive Ones III
- Minimum Window Substring