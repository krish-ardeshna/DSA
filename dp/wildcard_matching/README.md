# Wildcard Matching
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/wildcard-matching/  
Difficulty: Hard  
Pattern: DP on Strings (Pattern Matching with '?' and '*')

## What I understood
Given a string `s` and a pattern `p`, decide whether the pattern matches the WHOLE string. In the pattern, `'?'` matches any single character, and `'*'` matches any sequence of characters, including the empty sequence. Every other character matches only itself.

## Example
```
Input
s = "aa", p = "a"
Output
false
```
Explanation: the pattern covers only one 'a', but the string has two.

```
Input
s = "aa", p = "*"
Output
true
```
Explanation: `'*'` matches the whole string "aa".

```
Input
s = "cb", p = "?a"
Output
false
```
Explanation: `'?'` matches 'c', but 'a' does not match 'b'.

## Idea (shared by all three techniques)
**State:** `f(i, j)` = does the first `i` characters of `s` match the first `j` characters of `p`?

**Recurrence:** look at the last pattern character `p[j - 1]`:
```
if p[j-1] == s[i-1] or p[j-1] == '?':   f(i, j) = f(i - 1, j - 1)             (one character matched one character)
if p[j-1] == '*':                       f(i, j) = f(i, j - 1) || f(i - 1, j)  (star matches empty OR absorbs one more character)
otherwise:                              f(i, j) = false                       (two different plain characters)
```
The `'*'` case is the important one:
- `f(i, j - 1)`: the star matches **nothing**, so drop the star from the pattern.
- `f(i - 1, j)`: the star matches the last character `s[i - 1]` (and may keep matching more), so drop that character from the string but KEEP the star in the pattern.

**Base cases:**
- `f(0, 0) = true`: empty string against empty pattern.
- `f(i, 0) = false` for `i > 0`: a non-empty string can never match an empty pattern.
- `f(0, j) = true` only if the first `j` pattern characters are ALL `'*'`, because stars can match the empty string.

**Answer:** `f(n, m)`.

The `-1` memo marker is safe because stored values are only `0` or `1`.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(i, j)` result. Without the cache, the star case branches twice at every step and repeats the same pairs of prefixes many times.

### Steps
- Create `dp[n + 1][m + 1]` filled with `-1`.
- Call `f(n, m)`.
- Handle the three base cases (the `i == 0` case scans the first `j` pattern characters for stars).
- If `dp[i][j]` is filled, return it.
- A matching character or `'?'` moves diagonally. A `'*'` tries both `f(i, j - 1)` and `f(i - 1, j)`. Anything else is `false`.

### Complexity
Time: **O(n * m + m^2)**, the `m^2` is the star scan in the `i == 0` base case      
Space: **O(n * m)** for the dp table, plus **O(n + m)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion and fill the table from small prefixes up, with the same three cases.

### Steps
- Create `dp[n + 1][m + 1]` of `false`.
- `dp[0][0] = true`. For `j = 1 .. m`: `dp[0][j] = dp[0][j - 1] && p[j - 1] == '*'`, which marks a prefix of pattern as "matches empty" while it is all stars. The first column stays `false`.
- For `i = 1 .. n`, for `j = 1 .. m` use the recurrence above.
- Answer is `dp[n][m]`.

### Complexity
Time: **O(n * m)**      
Space: **O(n * m)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` reads only row `i - 1` (`prev[j - 1]`, `prev[j]`) and the cell just computed in the current row (`curr[j - 1]`), so two arrays are enough.

### Steps
- `prev` is the row for the empty string: `prev[0] = true`, and `prev[j] = prev[j - 1] && p[j - 1] == '*'`.
- For each `i`, set `curr[0] = false`, then fill `curr[j]` with the recurrence, reading `prev` and `curr`.
- After each row, `prev = curr`.
- Answer is `prev[m]`.

### Complexity
Time: **O(n * m)**      
Space: **O(m)**, two arrays of size `m + 1`

---

## Key Observation
Greedy matching with a star ("match as little as possible, then retry") works, but the DP is easier to reason about: the star simply has two options, and both are already-solved smaller subproblems. Be careful with the empty string: it can still match a pattern that is only stars, which is exactly what the first row of the table records.

## When to use this
If problem involves:
- Matching a pattern that has wildcards against a string
- A wildcard that can stand for a variable number of characters
→ Think **DP on (string prefix, pattern prefix)**, where the "any length" wildcard has a "match empty" branch and a "absorb one more character" branch.

## Edge Cases
- Empty string with an all-star pattern (true).
- Empty string with a non-star pattern (false).
- Pattern is just `"*"` (matches anything, even the empty string).
- Several stars in a row (they behave like a single star).
- Pattern longer than the string, but made of stars that can match empty.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * m + m^2) | O(n * m) + O(n + m) stack |
| Tabulation | O(n * m) | O(n * m) |
| Tabulation + Space Optimization | O(n * m) | O(m) |

where:
- `n` = length of `s`
- `m` = length of `p`

## Related Problems
- Regular Expression Matching
- Edit Distance
- Distinct Subsequences
- Is Subsequence