# Minimum Insertion Steps to Make a String Palindrome
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/  
Difficulty: Hard  
Pattern: DP on Strings (n - Longest Palindromic Subsequence)

## What I understood
Given a string `s`, you may insert any character at any position, any number of times. Return the minimum number of insertions needed to turn `s` into a palindrome.

## Example
```
Input
s = "zzazz"
Output
0
```
Explanation: the string is already a palindrome.

```
Input
s = "mbadm"
Output
2
```
Explanation: for example "mbdadbm" or "mdbabdm" (insert 2 characters).

```
Input
s = "leetcode"
Output
5
```
Explanation: for example "leetcodocteel" (insert 5 characters).

## Idea (shared by all three techniques)
Think about which characters of `s` do NOT need a partner. If some subsequence of `s` is already a palindrome, those characters can stay as they are. Every OTHER character needs exactly one inserted mirror copy to match it.

So the fewer characters we leave unmatched, the better, which means keeping the LONGEST palindromic subsequence:
```
minimum insertions = n - (length of longest palindromic subsequence)
```

And the longest palindromic subsequence is `LCS(s, reverse(s))`.

**State:** `f(i, j)` = LCS length of the first `i` characters of `s` and the first `j` characters of `t`, where `t = reverse(s)`.

**Recurrence:**
```
if s[i-1] == t[j-1]:  f(i, j) = 1 + f(i - 1, j - 1)
else:                 f(i, j) = max( f(i - 1, j), f(i, j - 1) )
```

**Base case:** `f(0, j) = f(i, 0) = 0`.

**Answer:** `n - f(n, n)`.

The `-1` memo marker is safe because lengths are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the LCS recurrence directly on `s` and its reverse, cache every `(i, j)` result, then subtract the final length from `n`.

### Steps
- Build `t` as the reverse of `s`.
- Create `dp[n + 1][n + 1]` filled with `-1`.
- `lps = f(n, n)`.
- Return `n - lps`.

### Complexity
Time: **O(n^2)**        
Space: **O(n^2)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion and fill the LCS table from small prefixes up. Row 0 and column 0 stay 0 as the base case.

### Steps
- Create `dp[n + 1][n + 1]` of zeros.
- For `i = 1 .. n`, for `j = 1 .. n`: match gives `1 + dp[i - 1][j - 1]`, mismatch gives `max(dp[i - 1][j], dp[i][j - 1])`.
- Return `n - dp[n][n]`.

### Complexity
Time: **O(n^2)**        
Space: **O(n^2)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Each row reads only the previous row and the current row's last cell, so two arrays are enough.

### Steps
- `lcs(text1, text2)` keeps `prev` and `curr` of size `m + 1`, using the same match / mismatch rule, and swaps rows after each `i`.
- `longestPalindromeSubseq(s) = lcs(s, reverse(s))`.
- Return `n - longestPalindromeSubseq(s)`.

### Complexity
Time: **O(n^2)**        
Space: **O(n)**, two arrays of size `n + 1`

---

## Key Observation
This is the same table as Longest Palindromic Subsequence with one extra subtraction. The insight is the pairing argument: a character that is part of the kept palindrome already has its partner, and every other character needs exactly one inserted partner, so the cost is `n - LPS`. The same number also equals the minimum number of DELETIONS to make the string a palindrome, since deleting a character and inserting its mirror fix the same imbalance.

## When to use this
If problem involves:
- Making a string a palindrome by adding (or removing) characters
→ Think **n minus the longest palindromic subsequence**, computed as `LCS(s, reverse(s))`.

## Edge Cases
- Already a palindrome (answer 0).
- Single character (answer 0).
- All characters distinct (answer `n - 1`).
- Two different characters, for example "ab" (answer 1).
- Long string with many repeated characters (the LPS is long, so few insertions are needed).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^2) | O(n^2) + O(n) stack |
| Tabulation | O(n^2) | O(n^2) |
| Tabulation + Space Optimization | O(n^2) | O(n) |

where:
- `n` = length of the string

## Related Problems
- Longest Palindromic Subsequence
- Longest Common Subsequence
- Valid Palindrome III
- Minimum Number of Moves to Make Palindrome