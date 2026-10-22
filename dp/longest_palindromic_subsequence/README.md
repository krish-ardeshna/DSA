# Longest Palindromic Subsequence
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-palindromic-subsequence/  
Difficulty: Medium  
Pattern: DP on Strings (LCS of a String and Its Reverse)

## What I understood
Given a string `s`, return the length of its longest palindromic subsequence. A subsequence keeps the relative order of characters but may skip some, so the characters do not need to be next to each other.

## Example
```
Input
s = "bbbab"
Output
4
```
Explanation: the longest palindromic subsequence is "bbbb".

```
Input
s = "cbbd"
Output
2
```
Explanation: the longest palindromic subsequence is "bb".

```
Input
s = "a"
Output
1
```

## Idea (shared by all three techniques)
A palindrome reads the same forward and backward. So a palindromic subsequence of `s` shows up in `s` AND in the reverse of `s`. This gives a standard reduction:

```
longest palindromic subsequence of s  =  LCS( s, reverse(s) )
```

That turns a new problem into the Longest Common Subsequence problem, which is already solved.

**State:** `f(i, j)` = length of the LCS of the first `i` characters of `s` and the first `j` characters of `t`, where `t = reverse(s)`.

**Recurrence:** compare the last characters `s[i - 1]` and `t[j - 1]`:
```
if s[i-1] == t[j-1]:  f(i, j) = 1 + f(i - 1, j - 1)
else:                 f(i, j) = max( f(i - 1, j), f(i, j - 1) )
```

**Base case:** `f(0, j) = f(i, 0) = 0`.

**Answer:** `f(n, n)`.

The indices are prefix lengths (1-indexed), which is why characters are read as `s[i - 1]`. The `-1` memo marker is safe because lengths are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the LCS recurrence directly and cache every `(i, j)` result. Without the cache, the same pair of prefixes would be reached through many different paths.

### Steps
- Build `t` as the reverse of `s`.
- Create `dp[n + 1][n + 1]` filled with `-1`.
- Call `f(n, n)`.
- If `i == 0` or `j == 0`, return `0`.
- If `dp[i][j]` is filled, return it.
- Otherwise store and return `1 + f(i - 1, j - 1)` on a match, or `max(f(i - 1, j), f(i, j - 1))` on a mismatch.

### Complexity
Time: **O(n^2)**        
Space: **O(n^2)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table from small prefixes up to the full strings, so every value it needs is already computed.

### Steps
- Create `dp[n + 1][n + 1]` of zeros (row 0 and column 0 stay 0 as the base case).
- For `i = 1 .. n`, for `j = 1 .. n`:
  - Match: `dp[i][j] = 1 + dp[i - 1][j - 1]`.
  - Mismatch: `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`.
- Answer is `dp[n][n]`.

### Complexity
Time: **O(n^2)**        
Space: **O(n^2)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` reads only row `i - 1` (`prev[j]` and `prev[j - 1]`) and the cell just filled in the current row (`curr[j - 1]`). Two arrays are enough.

### Steps
- `prev` and `curr` of size `n + 1`, all zeros.
- For each `i`, set `curr[0] = 0`, then for each `j` use the same match / mismatch rule with `prev` and `curr`.
- After each row, `prev = curr`.
- Answer is `prev[n]`.

### Complexity
Time: **O(n^2)**        
Space: **O(n)**, two arrays of size `n + 1`

---

## Key Observation
The whole problem is the reduction, not new DP logic. Reversing the string turns "palindrome" into "common with its mirror image", and LCS does the rest. There is also a direct interval DP on `dp[l][r]` that works without the reversal, but the LCS route reuses the same code and recurrence as the rest of the two-string DP family. Space optimization only gives the LENGTH, if the palindrome itself must be printed, the full table is needed for the traceback.

## When to use this
If problem involves:
- A palindromic subsequence (not substring) and only its length matters
- A property of a string that can be rephrased as "common part of the string and its reverse"
→ Think **LCS(s, reverse(s))**.

## Edge Cases
- Single character (answer 1).
- Whole string is a palindrome (answer `n`).
- All characters distinct (answer 1).
- All characters equal (answer `n`).
- Even and odd length palindromes (both are covered, the LCS does not care about the middle).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^2) | O(n^2) + O(n) stack |
| Tabulation | O(n^2) | O(n^2) |
| Tabulation + Space Optimization | O(n^2) | O(n) |

where:
- `n` = length of the string

## Related Problems
- Longest Common Subsequence
- Minimum Insertion Steps to Make a String Palindrome
- Longest Palindromic Substring
- Palindromic Substrings