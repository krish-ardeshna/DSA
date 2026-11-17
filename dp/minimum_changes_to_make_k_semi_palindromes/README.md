# Minimum Changes to Make K Semi-palindromes
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/  
Difficulty: Hard  
Pattern: Precompute Substring Costs (Divisors of the Length) + Partition DP

## What I understood
Given a string `s` and an integer `k`. Split `s` into exactly `k` substrings, and change as few characters as possible, so that every substring is a SEMI-PALINDROME. Return the minimum number of changes.

A string of length `len` is a semi-palindrome if there is an integer `d` with `1 <= d < len` and `len % d == 0` such that, for every residue `r` in `[0, d)`, the characters at positions `r, r + d, r + 2d, ...` form a palindrome. With `d = 1` this is a normal palindrome. A string of length `1` is never a semi-palindrome (no valid `d` exists).

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
s = "abcac", k = 2
Output
1
```
Explanation: split into `"ab"` and `"cac"`. `"cac"` is a palindrome (`d = 1`), cost 0. `"ab"` needs 1 change (`d = 1`, make it `"aa"`). Total is 1.

```
Input
s = "abcdef", k = 2
Output
2
```
Explanation: split into `"abc"` and `"def"`. Each has length 3, so only `d = 1` is allowed, and each needs 1 change to become a palindrome. Total is 2. Other splits cost more (for example `"ab"` + `"cdef"` costs 1 + 2 = 3).

```
Input
s = "aabbaa", k = 3
Output
0
```
Explanation: split into `"aa"`, `"bb"`, `"aa"`. Each is already a palindrome, so the cost is 0.

## Idea (shared by all three techniques)
The problem has two separate parts.

**Part 1: the cost of ONE substring.** `cost[l][r]` = the minimum changes to make `s[l..r]` a semi-palindrome. Try every proper divisor `d` of the length. For a given `d`, split the substring into `d` groups (positions with the same index modulo `d`). In each group, count the mismatched pairs from the two ends (this is the cost to make that group a palindrome). The cost for this `d` is the sum over the groups. Take the minimum over all valid `d`. A substring of length 1 has no valid `d`, so its cost is `INF`.

**Part 2: split the string into `k` parts.**

**State:** `dp[j][i]` = minimum total changes to split the first `i` characters into exactly `j` semi-palindromes.

**Recurrence:** the last part is `s[start..i-1]`. Because every part needs at least 2 characters, `start <= i - 2`.
```
dp[j][i] = min over start of  dp[j - 1][start] + cost[start][i - 1]
```
with `start` from `2 * (j - 1)` to `i - 2`.

**Base cases:** `dp[0][0] = 0`. `dp[j][i] = INF` when `i < 2 * j` (not enough characters).

**Answer:** `dp[k][n]`.

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence as `f(i, j)` and cache every `(i, j)`.

### Steps
- Compute the `cost` table (Part 1).
- Create `dp[n + 1][k + 1]` filled with `-1`.
- `f(0, 0) = 0`. `f(i, 0) = INF` for `i > 0`. `f(i, j) = INF` if `i < 2 * j`.
- Return the cached value if it is filled.
- Try every `start` from `2 * (j - 1)` to `i - 2`. If `f(start, j - 1)` is not `INF`, take `f(start, j - 1) + cost[start][i - 1]`. Keep the minimum.
- Store and return it. Call `f(n, k)`.

### Complexity
Time: **O(n^3)** for the cost table (each of the `O(n^2)` substrings tries its divisors and scans its length), plus **O(n^2 * k)** for the DP  
Space: **O(n^2)** for the cost table, plus **O(n * k)** for the dp table and **O(k)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill `dp` part by part: row `j` needs row `j - 1`.

### Steps
- Compute the `cost` table.
- Create `dp[k + 1][n + 1]` filled with `INF`, and set `dp[0][0] = 0`.
- For `j = 1` to `k`, for `i = 2 * j` to `n`, for `start = 2 * (j - 1)` to `i - 2`: if `dp[j - 1][start]` is not `INF`, `dp[j][i] = min(dp[j][i], dp[j - 1][start] + cost[start][i - 1])`.
- Answer is `dp[k][n]`.

### Complexity
Time: **O(n^3)** for the cost table, plus **O(n^2 * k)** for the DP  
Space: **O(n^2 + n * k)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Two Rows)

### Idea
Row `j` only reads row `j - 1`, so keep two rows: `prev` (row `j - 1`) and `curr` (row `j`). The `cost` table is still needed in full.

### Steps
- Compute the `cost` table.
- `prev` is row `0`: `INF` everywhere except `prev[0] = 0`.
- For each `parts` from `1` to `k`: reset `curr` to `INF`, fill it with the same rule as Approach 2 using `prev`, then `prev.swap(curr)`.
- Answer is `prev[n]`.

### Complexity
Time: **O(n^3)** for the cost table, plus **O(n^2 * k)** for the DP  
Space: **O(n^2)** (the cost table dominates, the dp rows are only **O(n)**)

---

## Key Observation
The cost of a substring does not depend on how the rest of the string is split, so it can be computed once for all `O(n^2)` substrings. After that, the problem is the classic "split into exactly `k` parts with a cost for each part" DP. Each part needs at least 2 characters, so the loop bounds `start <= i - 2` and `i >= 2 * j` also keep the table from reading invalid states.

For `n <= 200` the `O(n^3)` cost table and the `O(n^2 * k)` DP are both fast. Only proper divisors `d < len` are tried, which is why a substring of length 1 stays at `INF`.

## When to use this
If problem involves:
- Splitting a string into exactly `k` parts with a cost per part
- A cost per part that can be precomputed for all substrings
→ Think **precompute `cost[l][r]`, then partition DP over (parts, end position)**.

## Edge Cases
- `k = 1` (the whole string is one part, the answer is `cost[0][n - 1]`).
- `n = 2 * k` (every part has exactly 2 characters).
- A part of length 1 is never allowed (`cost` stays `INF`, and the loop bounds skip it).
- A part that is already a semi-palindrome (cost 0).
- A substring with several valid `d` values (take the minimum over them, not the first valid one).
- Prime length (only `d = 1` is possible, which is the normal palindrome cost).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^3 + n^2 * k) | O(n^2) + O(n * k) + O(k) stack |
| Tabulation | O(n^3 + n^2 * k) | O(n^2 + n * k) |
| Tabulation + Space Optimization | O(n^3 + n^2 * k) | O(n^2) |

where:
- `n` = length of `s`
- `k` = number of parts

## Related Problems
- Palindrome Partitioning II
- Palindrome Partitioning III
- Minimum Cost to Cut a Stick
- Palindrome Partitioning IV