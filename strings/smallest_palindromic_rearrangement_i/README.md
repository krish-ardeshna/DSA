# Smallest Palindromic Rearrangement I

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/  
Difficulty: Medium  
Pattern: String, Frequency Counting

## What I understood
A palindrome reads the same from both ends.

Given a palindromic string, rearrange its characters to form the lexicographically smallest possible palindrome.

Example:
```
Input: s = "daccad"
Output: "acddca"
```

## Idea
To obtain the lexicographically smallest palindrome:
- Place the smallest available characters in the left half.
- If a character has an odd frequency, place one occurrence in the middle.
- Mirror the left half to form the right half.

## Approach: Frequency Counting
- Count the frequency of each character.
- Build the left half by taking half of each character's occurrences in alphabetical order.
- Store the odd-frequency character (if any) as the middle.
- Reverse the left half to create the right half.
- Concatenate `left + middle + right`.

## Key Observation
The left half determines the lexicographical order of the entire palindrome.

Placing smaller characters as early as possible automatically produces the smallest valid palindrome.

## When to use this
If the problem involves:
- Palindrome construction
- Character frequencies
- Lexicographically smallest string
- Rearranging characters

→ Think **Frequency Counting**.

## Edge Cases
- Single-character string.
- No middle character (all frequencies are even).
- Exactly one odd-frequency character.
- Multiple occurrences of the same character.

## Complexity

### Approach
Time: **O(n + 26)** ≈ **O(n)**  
Space: **O(26)** ≈ **O(1)**

## Related Problems
- Longest Palindrome
- Palindrome Permutation
- Valid Anagram