# Longest Palindromic Substring

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-palindromic-substring/  
Difficulty: Medium  
Pattern: Strings / Expand Around Center

## What I understood
We need to find the longest substring that is a palindrome.

A palindrome reads the same forward and backward.

## Idea
Every palindrome expands from its center.

There are two possible cases:
- Odd length palindrome → center is one character
- Even length palindrome → center is between two characters

Expand outward while characters match.

## Approach
- Traverse every index in the string
- For each index:
  - Expand considering odd length palindrome
  - Expand considering even length palindrome
- Keep updating the longest palindrome found

## Mistake I made
Initially thought about checking every substring separately, which becomes very slow.

## When to use this
If the problem involves:
- palindromes
- symmetric expansion
- substring matching around center

→ think expand around center

## Edge Cases
- Single character string
- Entire string is palindrome
- Multiple palindromes of same length

## Complexity
Time: O(n²)  
Space: O(1)