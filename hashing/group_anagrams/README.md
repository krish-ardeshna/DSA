# Group Anagrams

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/group-anagrams/  
Difficulty: Medium  
Pattern: Hashing / Strings

## What I understood
Anagrams are words that contain the same characters but in different order.

Example:
- eat
- tea
- ate

All become:
aet

after sorting.

## Idea
If two strings are anagrams,
their sorted versions will always be identical.

Use the sorted string as a key in hashmap:
- key → sorted string
- value → list of matching anagrams

## Approach
- Traverse every string
- Create sorted version of string
- Store original string in hashmap using sorted string as key
- Extract all groups from hashmap

## Key Observation
Sorting normalizes all anagrams into the same representation.

That makes grouping possible using a hashmap.

## When to use this
If the problem involves:
- grouping similar strings
- character frequency matching
- anagrams

→ think normalized key + hashmap

## Edge Cases
- Empty strings
- Single word
- Duplicate strings

## Complexity
Time: O(n × k log k)  
- n = number of strings
- k = average string length

Space: O(n × k)

## Related Problems
- Valid Anagram
- Find All Anagrams in a String
- Top K Frequent Words