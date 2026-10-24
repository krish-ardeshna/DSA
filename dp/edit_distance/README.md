# Edit Distance
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/edit-distance/  
Difficulty: Medium  
Pattern: DP on Strings (Two Strings, Replace / Delete / Insert)

## What I understood
Given two strings `word1` and `word2`, return the minimum number of operations needed to turn `word1` into `word2`. One operation is: insert a character, delete a character, or replace a character.

## Example
```
Input
word1 = "horse", word2 = "ros"
Output
3
```
Explanation: horse -> rorse (replace 'h' with 'r'), rorse -> rose (delete 'r'), rose -> ros (delete 'e').

```
Input
word1 = "intention", word2 = "execution"
Output
5
```

```
Input
word1 = "", word2 = "ab"
Output
2
```
Explanation: two insertions build "ab" from nothing.

## Idea (shared by all three techniques)
**State:** `f(i, j)` = minimum operations to turn the first `i` characters of `word1` into the first `j` characters of `word2`.

**Recurrence:** compare the last characters `word1[i - 1]` and `word2[j - 1]`:
```
if word1[i-1] == word2[j-1]:  f(i, j) = f(i - 1, j - 1)                  (they match, no cost)
else:                         f(i, j) = 1 + min( f(i - 1, j - 1),        (replace)
                                                 f(i - 1, j),            (delete)
                                                 f(i, j - 1) )           (insert)
```
What each branch means:
- **Replace** `word1[i - 1]` with `word2[j - 1]`: both end characters now match, so continue with `(i - 1, j - 1)`.
- **Delete** `word1[i - 1]`: that character is gone, so continue with `(i - 1, j)`.
- **Insert** `word2[j - 1]` at the end of `word1`: it now matches the last character of `word2`, so what is left is `word1[0..i)` against `word2[0..j - 1)`, which is `(i, j - 1)`.

When the last characters already match, using the match is never worse than anything else, so no other branch is tried.

**Base cases:**
- `i == 0`: `word1` is empty, so `j` insertions are needed.
- `j == 0`: `word2` is empty, so `i` deletions are needed.

**Answer:** `f(n, m)`.

The `-1` memo marker is safe because distances are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(i, j)` result so each pair of prefixes is solved once.

### Steps
- Create `dp[n + 1][m + 1]` filled with `-1`.
- Call `f(n, m)`.
- Base cases: return `j` when `i == 0`, return `i` when `j == 0`.
- If `dp[i][j]` is filled, return it.
- On a match, store `f(i - 1, j - 1)`. Otherwise store `1 + min(replace, delete, insert)`.

### Complexity
Time: **O(n * m)**      
Space: **O(n * m)** for the dp table, plus **O(n + m)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion and fill the table from small prefixes up. In the table, replace is the diagonal cell, delete is the cell above, and insert is the cell to the left.

### Steps
- Create `dp[n + 1][m + 1]`.
- First column: `dp[i][0] = i`. First row: `dp[0][j] = j`.
- For `i = 1 .. n`, for `j = 1 .. m`:
  - Match: `dp[i][j] = dp[i - 1][j - 1]`.
  - No match: `dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])`.
- Answer is `dp[n][m]`.

### Complexity
Time: **O(n * m)**      
Space: **O(n * m)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` reads only row `i - 1` and the cell just computed in the current row, so two arrays are enough.

### Steps
- `prev` starts as the base row `0, 1, 2, ..., m`.
- For each `i`, set `curr[0] = i`, then fill `curr[j]` with the same match / no-match rule using `prev[j]`, `prev[j - 1]` and `curr[j - 1]`.
- After each row, `prev = curr`.
- Answer is `prev[m]`.

### Complexity
Time: **O(n * m)**      
Space: **O(m)**, two arrays of size `m + 1`

---

## Key Observation
Edit Distance is the full version of the two-string family. If only deletions were allowed, the answer would be `n + m - 2 * LCS`. Adding replace and insert is what turns that into this three-way min. Remember the table picture: diagonal = replace, up = delete, left = insert.

## When to use this
If problem involves:
- Turning one string into another with a small set of edit operations, each with a cost
→ Think **DP on prefixes of both strings, one branch per operation**, with the "characters already match" case as a free diagonal step.

## Edge Cases
- Both strings empty (answer 0).
- One string empty (answer is the length of the other).
- Identical strings (answer 0).
- Completely different strings of the same length (answer is that length, using replacements).
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
- Delete Operation for Two Strings
- Longest Common Subsequence
- One Edit Distance
- Minimum ASCII Delete Sum for Two Strings