# Valid Palindrome

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/valid-palindrome/  
Difficulty: Easy  
Pattern: Strings

## What I understood
We are given a string.

We need to determine whether it is a palindrome after:

- removing all non-alphanumeric characters
- converting all letters to lowercase

Example:

s = "A man, a plan, a canal: Panama"

Output = true

## Idea
Create a new string containing only lowercase alphanumeric characters.

Reverse the filtered string and compare it with the original filtered string.

If both are equal, the string is a palindrome.

## Approach
- Create an empty string
- Traverse the input string
- Keep only lowercase alphanumeric characters
- Create its reversed copy
- Compare both strings
- Return the result

## Key Observation
Non-alphanumeric characters and letter case do not affect the palindrome check.

Filtering the string first makes the comparison straightforward.

## When to use this
If the problem involves:
- palindrome checking
- ignoring special characters
- case-insensitive comparison
- string preprocessing

→ think filtering + palindrome check

## Edge Cases
- Empty string
- String containing only special characters
- Single character
- Mixed uppercase and lowercase letters

## Complexity
Time: O(n)  
Space: O(n)

## Related Problems
- Palindrome Number
- Valid Palindrome II
- Longest Palindromic Substring
- Reverse String