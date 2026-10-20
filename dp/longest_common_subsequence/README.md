# Longest Common Subsequence
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-common-subsequence/  
Difficulty: Medium  
Pattern: DP on Strings (Two Strings, Match / Skip)

## What I understood
Given two strings `text1` and `text2`, return the length of their longest common subsequence. A subsequence keeps the relative order of characters but may skip some, so the characters do not need to be next to each other. Return 0 if there is no common subsequence.

## Example
```
Input
text1 = "abcde", text2 = "ace"
Output
3
```
Explanation: the longest common subsequence is "ace".

```
Input
text1 = "abc", text2 = "abc"
Output
3
```

```
Input
text1 = "abc", text2 = "def"
Output
0
```
Explanation: the two strings share no characters.

## Idea (shared by all three techniques)
Trying every subsequence of one string against the other is exponential. Instead, compare the strings from the end and look at only the last character of each prefix.

**State:** `f(i, j)` = length of the longest common subsequence of the first `i` characters of `text1` and the first `j` characters of `text2`.

**Recurrence:** look at the last characters `text1[i - 1]` and `text2[j - 1]`:
```
if text1[i-1] == text2[j-1]:  f(i, j) = 1 + f(i - 1, j - 1)           (they match, use both)
else:                         f(i, j) = max( f(i - 1, j), f(i, j - 1) )  (drop one character, keep the better)
```
When the last characters match, taking the match is always at least as good as skipping it, so there is no need to also try the skip branches. When they differ, at least one of the two last characters cannot be part of the answer, so try dropping each in turn.

**Base case:** if either prefix is empty (`i == 0` or `j == 0`), the answer is `0`.

**Answer:** `f(n, m)`.

The indices here are **lengths of prefixes** (1-indexed), which is why the characters are read as `text[i - 1]`. This also gives a free base case at 0, with no negative index to worry about.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(i, j)` result. Many different paths reach the same pair of prefixes, so the cache removes the exponential repeated work. A `-1` marker for "not computed" is safe because lengths are never negative.

### Steps
- Create `dp[n + 1][m + 1]` filled with `-1`.
- Call `f(n, m)`.
- If `i == 0` or `j == 0`, return `0`.
- If `dp[i][j]` is filled, return it.
- If the last characters match, store `1 + f(i - 1, j - 1)`.
- Otherwise store `max(f(i - 1, j), f(i, j - 1))`.

### Complexity
Time: **O(n * m)**          
Space: **O(n * m)** for the dp table, plus **O(n + m)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill `dp[i][j]` row by row from small prefixes up to the full strings. The row and column for the empty prefix are all zeros, which is the base case.

### Steps
- Create `dp[n + 1][m + 1]` of zeros (row 0 and column 0 stay 0).
- For `i = 1 .. n`, for `j = 1 .. m`:
  - If `text1[i - 1] == text2[j - 1]`, then `dp[i][j] = 1 + dp[i - 1][j - 1]`.
  - Else `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`.
- Answer is `dp[n][m]`.

### Complexity
Time: **O(n * m)**          
Space: **O(n * m)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` reads only row `i - 1` (`prev[j]` and `prev[j - 1]`) and the cell just computed in the current row (`curr[j - 1]`). Keep two arrays instead of the full table.

### Steps
- `prev` and `curr` of size `m + 1`, all zeros.
- For each `i = 1 .. n`: set `curr[0] = 0`, then for `j = 1 .. m`:
  - Match: `curr[j] = 1 + prev[j - 1]`.
  - No match: `curr[j] = max(prev[j], curr[j - 1])`.
- After each row, `prev = curr`.
- Answer is `prev[m]`.

### Complexity
Time: **O(n * m)**          
Space: **O(m)**, two arrays of size `m + 1`

---

## Key Observation
LCS is the base pattern for the whole family of two-string DP problems (edit distance, shortest common supersequence, longest palindromic subsequence, and more). The structure is always the same: compare the last characters, and either use the match or drop one character. Note that dropping BOTH characters is never needed, since `f(i - 1, j - 1) <= f(i - 1, j)`, so the max of the two single drops already covers it. Space optimization has a limit here: the length only needs two rows, but if the actual subsequence has to be printed, the full table is required to trace back.

## When to use this
If problem involves:
- Two strings or sequences where the result depends on matching characters in order
- A subsequence, not a substring (characters may be skipped)
→ Think **DP with state = (prefix length of string 1, prefix length of string 2)**, with a match branch and a drop-one-character branch.

## Edge Cases
- One string empty (answer 0).
- Identical strings (answer is the full length).
- No shared characters (answer 0).
- One string is a subsequence of the other (answer is the shorter length).
- Repeated characters (the DP still counts each character once per position, so matching stays correct).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * m) | O(n * m) + O(n + m) stack |
| Tabulation | O(n * m) | O(n * m) |
| Tabulation + Space Optimization | O(n * m) | O(m) |

where:
- `n` = length of `text1`
- `m` = length of `text2`

## Related Problems
- Print Longest Common Subsequence
- Longest Common Substring
- Edit Distance
- Shortest Common Supersequence
- Longest Palindromic Subsequence