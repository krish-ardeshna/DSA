# Distinct Subsequences II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/distinct-subsequences-ii/  
Difficulty: Hard  
Pattern: DP (Running Total + Last-Occurrence Correction)

## What I understood
Given string `s`, count the total number of distinct non-empty subsequences of `s` (as distinct strings, not distinct index-selections — duplicate resulting strings from different index choices count only once). Return the count modulo `10^9 + 7`.

## Example
```
Input
s = "abc"
Output
7
```
```
Input
s = "aba"
Output
6
```

## Idea
Track `dp` = total distinct subsequences count (including the empty one, adjusted at the end) after processing characters so far. Each new character `c` can be appended to every existing subsequence (including the empty one) to form new subsequences — doubling the count (`2 * dp`). However, this double-counts subsequences that were already created by appending `c` after its LAST previous occurrence — subtract that overcounted contribution (`last[idx]`, the dp value right before `c`'s previous occurrence was processed) to correct for duplicates.

## Approach: DP with Duplicate Removal via Last Character Tracking
- Init `dp = 1` (represents the empty subsequence as a baseline count).
- For each character `c` in `s`: compute `newDp = 2*dp - last[idx] + MOD) % MOD` — doubling represents "all existing subsequences, with and without appending c", subtracting `last[idx]` removes duplicates created since c's last occurrence.
- Update `last[idx] = dp` (the dp value BEFORE this character's processing, needed for future duplicate correction).
- Set `dp = newDp`.
- Final answer: `dp - 1` (subtract the baseline empty subsequence, since only non-empty subsequences should be counted), adjusted for negative modulo.

## Key Observation
The subtraction of `last[idx]` (not the current `dp`, but its value from the previous occurrence of the same character) is the crucial duplicate-elimination step — without it, subsequences ending in a repeated character would be counted multiple times across different "starting points" internally, since doubling assumes every existing subsequence is genuinely distinct when extended.

## When to use this
If problem involves:
- Counting distinct subsequences/subsets as strings (not as index selections), where duplicate values must not be double-counted
→ Think **running total doubling + subtract last-occurrence's pre-update value** to eliminate duplicate-string overcounting.

## Edge Cases
- All characters identical (e.g. `"aaa"` → only 3 distinct subsequences: "a", "aa", "aaa").
- All characters distinct (`2^n - 1` distinct non-empty subsequences).
- Single character string.
- Large string requiring modulo arithmetic throughout (negative intermediate values handled via `+ MOD`).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)** — fixed 26-size array

where:
- `n` = length of string s

## Related Problems
- Distinct Subsequences
- Count Different Palindromic Subsequences
- Number of Distinct Substrings in a String
- Unique Paths III