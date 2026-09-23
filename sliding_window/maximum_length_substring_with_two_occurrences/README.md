# Maximum Length Substring With Two Occurrences
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/  
Difficulty: Easy  
Pattern: Sliding Window + Frequency Array

## What I understood
Find length of the longest substring of `s` where every character appears at most 2 times.

## Example
```
Input
s = "bcbbbcba"
Output
4
```
```
Input
s = "aaaa"
Output
2
```

## Idea
Same variable-size sliding window pattern used for "at most k frequency" style problems, just applied to lowercase string characters instead of array elements. Fixed 26-size array replaces hashmap since alphabet is bounded (lowercase a-z only) — faster constant-factor access.

## Approach: Variable-Size Sliding Window with Fixed-Size Freq Array
- Expand window by incrementing `freq[s[right] - 'a']` each step.
- If that character's frequency exceeds 2, shrink from `left`, decrementing frequencies, until it's back to 2.
- After shrink, update `ans = max(ans, right - left + 1)`.

## Key Observation
Only the character just added at `right` can push a frequency past the limit — every other character in the window was already valid before this step, so the `while` check only needs to examine `freq[s[right]]`, not the whole array.

## When to use this
If problem involves:
- Longest/shortest substring under a per-character frequency constraint
- Bounded alphabet (lowercase letters, digits, etc.) — use fixed array over hashmap for speed
→ Think **variable-size sliding window + fixed-size frequency array**.

## Edge Cases
- All same character (`"aaaa"` → answer capped at 2).
- Single character string.
- String where every character is unique (answer = string length).
- Empty string (edge case, loop naturally returns 0).

## Complexity
### Approach
Time: **O(n)** — each character added and removed from window at most once      
Space: **O(1)** — fixed 26-size array regardless of input size

where:
- `n` = length of string

## Related Problems
- Length of Longest Subarray With at Most K Frequency
- Longest Substring Without Repeating Characters
- Fruit Into Baskets
- Max Consecutive Ones III