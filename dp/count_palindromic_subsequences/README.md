# Count Palindromic Subsequences
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-palindromic-subsequences/  
Difficulty: Hard  
Pattern: DP on Strings (Distinct Subsequences, Run for Each of 1000 Patterns)

## What I understood
Given a string `s` of digits, return the number of palindromic subsequences of length exactly 5. Two subsequences are different if they use different positions, even when they spell the same string. Return the count modulo `10^9 + 7`.

## Example
```
Input
s = "103301"
Output
2
```
Explanation: "10301" can be taken in two ways, using either of the two 3s in the middle.

```
Input
s = "0000000"
Output
21
```
Explanation: every choice of 5 positions out of 7 spells "00000", and C(7, 5) = 21.

```
Input
s = "9999900000"
Output
2
```
Explanation: "99999" and "00000", one way each.

## Idea (shared by all three techniques)
**Step 1: there are only 1000 possible palindromes.** A palindrome of length 5 has the shape `a b c b a`: the first and fifth digits are equal, the second and fourth are equal, and the middle one is free. Each of `a`, `b`, `c` is one of 10 digits, so there are `10 * 10 * 10 = 1000` such strings (`00000`, `00100`, `01010`, ..., `99999`).

**Step 2: count each pattern separately.** Every set of 5 positions that spells a palindrome spells exactly one of those 1000 strings. So:
```
answer = sum over all 1000 patterns t of ( number of times t appears as a subsequence of s )
```

**Step 3: counting a pattern is Distinct Subsequences.** "How many times does `t` appear as a subsequence of `s`" is exactly the Distinct Subsequences problem, with `t` of length 5.

**State:** `ways(i, j)` = number of ways the first `j` characters of `t` appear as a subsequence of the first `i` characters of `s`.

**Recurrence:**
```
if s[i-1] == t[j-1]:  ways(i, j) = ways(i - 1, j - 1) + ways(i - 1, j)     (use it, or skip it)
else:                 ways(i, j) = ways(i - 1, j)                          (skip it)
```

**Base cases:**
- `ways(i, 0) = 1`: nothing left to match, one way.
- `ways(0, j) = 0` for `j > 0`: no characters left in `s`.

**Answer for one pattern:** `ways(n, 5)`. The final answer adds this up over all 1000 patterns, modulo `10^9 + 7`.

Note: the version most people first write fills the same table from the END of the strings (suffixes). It gives the same numbers, and here the table is built from the start (prefixes), the same way as in Distinct Subsequences.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
For each pattern, write the recurrence directly and cache every `(i, j)` result in a table that is rebuilt for that pattern. The `-1` marker means "not computed yet", which is safe because counts are never negative.

### Steps
- Loop `a`, `b`, `c` from 0 to 9, building `t = a b c b a`.
- `countWays(s, t)`: create `dp[n + 1][6]` filled with `-1` and call `f(n, 5)`.
- `j == 0` returns 1, `i == 0` returns 0.
- If `dp[i][j]` is filled, return it.
- Otherwise `skip = f(i - 1, j)`, and `take = f(i - 1, j - 1)` only when the characters match. Store `(skip + take) % MOD`.
- Add each pattern's count to `ans`, modulo `MOD`.

### Complexity
Time: **O(1000 * 5 * n)**, which is O(n) with a large constant          
Space: **O(5 * n)** for the table, plus **O(n)** recursion stack (the recursion goes about `n` levels deep, so the other two approaches are safer for long strings)

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. For each pattern, fill a table of size `(n + 1) x 6` from small prefixes up.

### Steps
- Create `dp[n + 1][6]` of zeros and set `dp[i][0] = 1` for every `i`.
- For `i = 1 .. n`, for `j = 1 .. 5`: on a match `dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD`, otherwise `dp[i][j] = dp[i - 1][j]`.
- The pattern's count is `dp[n][5]`.
- Sum over all 1000 patterns.

### Complexity
Time: **O(1000 * 5 * n)**       
Space: **O(5 * n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` reads only row `i - 1`, so two arrays of size 6 are enough for each pattern.

### Steps
- `prev[0] = curr[0] = 1`, everything else 0.
- For each character of `s`, fill `curr[j]` for `j = 1 .. 5` with the same rule, using `prev`.
- After each character, `prev = curr`.
- The pattern's count is `prev[5]`. Sum over all 1000 patterns.

### Complexity
Time: **O(1000 * 5 * n)**        
Space: **O(1)**, two arrays of 6 numbers (the best one to submit)

---

## Key Observation
The problem looks like it needs a palindrome-specific DP, but fixing the length to 5 shrinks the number of palindromes to just 1000, and each one is a plain "count a pattern as a subsequence" question. The `+` in the recurrence is what handles repeated digits correctly: when several equal digits could play the same role, each choice is counted as a different way. A faster method exists (count the digit pairs before and after each middle position, about `100 * n` work), but this one is built directly from Distinct Subsequences, so it is the easiest to follow.

## When to use this
If problem involves:
- Counting subsequences of a fixed small length with a symmetric or restricted shape
- A small alphabet (here 10 digits), so every possible shape can be listed
→ Think **list all the shapes, then count each shape with the Distinct Subsequences DP**.

## Edge Cases
- String shorter than 5 (every pattern count is 0, answer 0).
- All digits the same (answer is `C(n, 5)` modulo `10^9 + 7`).
- All digits different (answer 0, since a palindrome needs repeated digits).
- Very long string (counts get huge, hence the modulo at every step).
- The same pattern reachable in many ways (all counted, since positions matter).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(5000 * n) | O(5 * n) + O(n) stack |
| Tabulation | O(5000 * n) | O(5 * n) |
| Tabulation + Space Optimization | O(5000 * n) | O(1) |

where:
- `n` = length of `s`

## Related Problems
- Distinct Subsequences
- Longest Palindromic Subsequence
- Number of Matching Subsequences
- Count Different Palindromic Subsequences