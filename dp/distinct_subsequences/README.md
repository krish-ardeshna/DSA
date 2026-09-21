# Distinct Subsequences
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/distinct-subsequences/  
Difficulty: Hard  
Pattern: DP (1D Rolling Array, Right-to-Left Update)

## What I understood
Given strings `s` and `t`, count the number of distinct ways `t` appears as a subsequence of `s` (characters of `t` must appear in `s` in the same relative order, not necessarily contiguous). Different index choices in `s` that produce the same characters still count as distinct ways.

## Example
```
Input
s = "rabbbit", t = "rabbit"
Output
3
```
```
Input
s = "babgbag", t = "bag"
Output
5
```

## Idea
Classic 2D DP where `dp[i][j]` = number of ways `t[0..j-1]` appears as a subsequence of `s[0..i-1]`. Recurrence: if `s[i-1] == t[j-1]`, `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]` (either use this matching character, or skip it); if they differ, `dp[i][j] = dp[i-1][j]` (must skip). Since each row only depends on the previous row, space can be compressed to a single 1D array — but updates must go right-to-left within each row to avoid overwriting `dp[j-1]` before it's used for `dp[j]` in the same iteration.

## Approach: Space-Optimized DP (1D Array, Reverse Inner Loop)
- Init `dp[0] = 1` (empty `t` has exactly 1 way to be a subsequence — the empty selection), rest 0.
- Outer loop over `s` characters (`i` from 1 to n).
- Inner loop over `t` characters in REVERSE (`j` from m down to 1) — critical for correctness, since `dp[j-1]` must still hold the previous row's value when used, not the current row's already-updated value.
- If `s[i-1] == t[j-1]`, update `dp[j] += dp[j-1]` (with overflow-safe cap via `min` against `INT_MAX`, though this caps rather than truly prevents overflow behavior—verify against problem's actual constraints).
- Return `dp[m]` after processing all of `s`.

## Key Observation
The reverse inner loop is the single most important detail — a forward loop would incorrectly use the current row's updated `dp[j-1]` instead of the previous row's, effectively allowing characters to be reused within the same position of `s`, overcounting the actual number of distinct subsequences.

## When to use this
If problem involves:
- Counting subsequence matches or alignments between two strings
- 2D DP where each row only depends on the row directly above it
→ Think **1D rolling array with reverse (right-to-left) inner loop update** to safely compress space.

## Edge Cases
- `t` longer than `s` (impossible to match, `dp[m]` stays 0).
- `t` is empty string (always 1 way — matches the base case).
- `s` and `t` identical (exactly 1 way).
- Repeated characters in `s` allowing multiple matching paths for the same `t`.

## Complexity
### Approach
Time: **O(n * m)**              
Space: **O(m)** — 1D dp array (compressed from O(n*m) 2D table)

where:
- `n` = length of s
- `m` = length of t

## Related Problems
- Edit Distance
- Longest Common Subsequence
- Interleaving String
- Delete Operation for Two Strings