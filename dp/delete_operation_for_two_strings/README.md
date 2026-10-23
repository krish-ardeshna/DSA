# Delete Operation for Two Strings
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/delete-operation-for-two-strings/  
Difficulty: Medium  
Pattern: DP on Strings (n + m - 2 * LCS)

## What I understood
Given two strings `word1` and `word2`, one step deletes exactly one character from either string. Return the minimum number of steps to make the two strings identical.

## Example
```
Input
word1 = "sea", word2 = "eat"
Output
2
```
Explanation: delete 's' from "sea" to get "ea", then delete 't' from "eat" to get "ea".

```
Input
word1 = "leetcode", word2 = "etco"
Output
4
```
Explanation: delete 'l', 'e', 'o' and 'e' from "leetcode" to get "etco".

```
Input
word1 = "abc", word2 = "def"
Output
6
```
Explanation: nothing is shared, so both strings must be deleted completely.

## Idea (shared by all three techniques)
After all deletions, the two strings are equal, so what remains in each is the SAME string, and it is a subsequence of both original strings. Everything not in that common subsequence must be deleted. To delete as little as possible, keep the LONGEST common subsequence:
```
deletions from word1 = n - LCS
deletions from word2 = m - LCS
total steps = n + m - 2 * LCS
```

**State:** `f(i, j)` = LCS length of the first `i` characters of `word1` and the first `j` characters of `word2`.

**Recurrence:**
```
if word1[i-1] == word2[j-1]:  f(i, j) = 1 + f(i - 1, j - 1)
else:                         f(i, j) = max( f(i - 1, j), f(i, j - 1) )
```

**Base case:** `f(0, j) = f(i, 0) = 0`.

**Answer:** `n + m - 2 * f(n, m)`.

The `-1` memo marker is safe because lengths are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the LCS recurrence directly and cache every `(i, j)` result, then apply the formula to the final length.

### Steps
- Create `dp[n + 1][m + 1]` filled with `-1`.
- `lcsLen = f(n, m)`.
- Return `n + m - 2 * lcsLen`.

### Complexity
Time: **O(n * m)**      
Space: **O(n * m)** for the dp table, plus **O(n + m)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion and fill the LCS table from small prefixes up. Row 0 and column 0 stay 0 as the base case.

### Steps
- Create `dp[n + 1][m + 1]` of zeros.
- For `i = 1 .. n`, for `j = 1 .. m`: match gives `1 + dp[i - 1][j - 1]`, mismatch gives `max(dp[i - 1][j], dp[i][j - 1])`.
- Return `n + m - 2 * dp[n][m]`.

### Complexity
Time: **O(n * m)**      
Space: **O(n * m)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Each row reads only the previous row and the current row's last cell, so two arrays are enough.

### Steps
- `lcs(text1, text2)` keeps `prev` and `curr` of size `m + 1`, using the same match / mismatch rule, and swaps rows after each `i`.
- Return `word1.size() + word2.size() - 2 * lcs(word1, word2)`.

### Complexity
Time: **O(n * m)**      
Space: **O(m)**, two arrays of size `m + 1`

---

## Key Observation
Minimizing deletions and maximizing what is kept are the same goal, and what is kept must be a common subsequence. The formula needs `LCS` counted twice because both strings lose their non-shared characters. Space optimization only gives the length, which is all this problem needs.

## When to use this
If problem involves:
- Making two strings equal using only deletions (no replacements)
→ Think **n + m - 2 * LCS**. If replacements are allowed too, it becomes Edit Distance, which is a different recurrence.

## Edge Cases
- Identical strings (answer 0).
- No shared characters (answer `n + m`).
- One string is a subsequence of the other (answer is the length difference).
- Single character strings (answer 0 if equal, 2 if different).
- Very different lengths (the answer is at least the length difference).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * m) | O(n * m) + O(n + m) stack |
| Tabulation | O(n * m) | O(n * m) |
| Tabulation + Space Optimization | O(n * m) | O(m) |

where:
- `n` = length of `word1`
- `m` = length of `word2`

## Related Problems
- Longest Common Subsequence
- Edit Distance
- Minimum ASCII Delete Sum for Two Strings
- Shortest Common Supersequence