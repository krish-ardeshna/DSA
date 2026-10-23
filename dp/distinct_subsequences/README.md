# Distinct Subsequences
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/distinct-subsequences/  
Difficulty: Hard  
Pattern: DP on Strings (Count Subsequence Matches)

## What I understood
Given two strings `s` and `t`, count how many different ways `t` can be formed as a subsequence of `s`. Two ways are different if they pick different positions in `s`, even when the picked letters are the same. Return the count modulo `10^9 + 7`.

## Example
```
Input
s = "rabbbit", t = "rabbit"
Output
3
```
Explanation: there are three 'b' characters in `s` and `t` needs two of them, so there are 3 ways to choose which 'b' to skip.

```
Input
s = "babgbag", t = "bag"
Output
5
```

```
Input
s = "a", t = "ab"
Output
0
```
Explanation: `t` is longer than `s`, so it can never be a subsequence.

## Idea (shared by all three techniques)
**State:** `ways(i, j)` = number of ways the first `j` characters of `t` appear as a subsequence of the first `i` characters of `s`.

**Recurrence:** look at the last characters `s[i - 1]` and `t[j - 1]`:
```
if s[i-1] == t[j-1]:  ways(i, j) = ways(i - 1, j - 1) + ways(i - 1, j)
else:                 ways(i, j) = ways(i - 1, j)
```
- `ways(i - 1, j - 1)`: use `s[i - 1]` as the match for `t[j - 1]`.
- `ways(i - 1, j)`: skip `s[i - 1]` and look for the match further left.
- When the characters differ, skipping is the only option.

**Base cases:**
- `ways(i, 0) = 1`: the empty `t` can be formed in exactly one way (pick nothing).
- `ways(0, j) = 0` for `j > 0`: an empty `s` cannot form a non-empty `t`.

**Answer:** `ways(n, m)`.

Convention note: the memoization version walks by **index** (`i` from `n - 1` down to `-1`, base `j < 0` returns 1 and `i < 0` returns 0). Tabulation and space optimization walk by **prefix length**. They describe the same table shifted by one, so `f(i, j)` in the memoization equals `dp[i + 1][j + 1]` in the table.

Overflow: every stored value is below `10^9 + 7`, so the sum of two of them stays below `2^31` and fits in `int` before the modulo.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache each `(i, j)` result. The `-1` marker means "not computed yet", which is safe because counts are never negative.

### Steps
- If `t` is longer than `s`, return 0 immediately.
- Create `dp[n][m]` filled with `-1`.
- Call `f(n - 1, m - 1)`.
- `j < 0`: all of `t` is matched, return 1. `i < 0` (with `t` left over): return 0.
- If `dp[i][j]` is filled, return it.
- On a match, store `(f(i - 1, j - 1) + f(i - 1, j)) % MOD`, otherwise store `f(i - 1, j)`.

### Complexity
Time: **O(n * m)**      
Space: **O(n * m)** for the dp table, plus **O(n + m)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion and fill the table from small prefixes up.

### Steps
- Create `dp[n + 1][m + 1]`. Column 0 is all 1 (empty `t`), row 0 is 0 for every `j >= 1`.
- For `i = 1 .. n`, for `j = 1 .. m`:
  - Match: `dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD`.
  - No match: `dp[i][j] = dp[i - 1][j]`.
- Answer is `dp[n][m]`.

### Complexity
Time: **O(n * m)**      
Space: **O(n * m)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` reads only row `i - 1`, so two arrays are enough: `prev` for the previous character of `s` and `curr` for the current one.

### Steps
- `prev[0] = curr[0] = 1`, everything else 0.
- For each `i`, fill `curr[j]` for `j = 1 .. m` with the same match / no-match rule, using `prev`.
- After each row, `prev = curr`.
- Answer is `prev[m]`.

### Complexity
Time: **O(n * m)**      
Space: **O(m)**, two arrays of size `m + 1`

---

## Key Observation
Compare this with Longest Common Subsequence. In LCS, a match forces you to use the pair. Here a match gives BOTH options, because different positions in `s` count as different ways, so the two counts are added. That one change turns "longest" into "count".

## When to use this
If problem involves:
- Counting how many times one string appears as a subsequence of another
- Different index choices counting as different answers
→ Think **DP on prefixes where a match adds "use it" and "skip it"**.

## Edge Cases
- `t` longer than `s` (answer 0).
- `t` equal to `s` (answer 1).
- Many repeated characters in `s` (large counts, which is why the modulo is needed).
- No shared characters (answer 0).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * m) | O(n * m) + O(n + m) stack |
| Tabulation | O(n * m) | O(n * m) |
| Tabulation + Space Optimization | O(n * m) | O(m) |

where:
- `n` = length of `s`
- `m` = length of `t`

## Related Problems
- Edit Distance
- Longest Common Subsequence
- Distinct Subsequences II
- Count Palindromic Subsequences