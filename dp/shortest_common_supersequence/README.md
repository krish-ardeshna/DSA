# Shortest Common Supersequence
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/shortest-common-supersequence/  
Difficulty: Hard  
Pattern: DP on Strings (LCS Table + Traceback to Build the String)

## What I understood
Given two strings `str1` and `str2`, return the shortest string that has BOTH as subsequences. If several answers exist, any one of them is accepted.

## Example
```
Input
str1 = "abac", str2 = "cab"
Output
"cabac"
```
Explanation: "cabac" contains "abac" (positions 2, 3, 4, 5... as a subsequence) and "cab" (its first three letters). Length is 5, which is the minimum.

```
Input
str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output
"aaaaaaaa"
```

```
Input
str1 = "abc", str2 = "def"
Output
"abcdef"
```
Explanation: the strings share nothing, so the shortest supersequence just puts them one after the other. Any shortest answer is valid, this one is what the code produces.

## Idea (shared by both techniques)
Characters that both strings share, in the same order (a common subsequence), only need to appear ONCE in the answer. Everything else must appear. So the longer the common subsequence we reuse, the shorter the result:
```
length of shortest supersequence = n + m - LCS
```

The length alone comes from the LCS table. To build the actual string, walk back through the table from the bottom-right corner and decide at each step which character goes into the answer.

**State:** `f(i, j)` = LCS length of the first `i` characters of `str1` and the first `j` characters of `str2`.

**Recurrence:**
```
if str1[i-1] == str2[j-1]:  f(i, j) = 1 + f(i - 1, j - 1)
else:                       f(i, j) = max( f(i - 1, j), f(i, j - 1) )
```

**Base case:** `f(0, j) = f(i, 0) = 0`.

**Traceback (building the string backward, from `(n, m)`):**
- Characters equal: it is a shared character, add it ONCE, move to `(i - 1, j - 1)`.
- Characters differ and `f(i - 1, j) > f(i, j - 1)`: the LCS did not use `str1[i - 1]`, so it must be added on its own, move to `(i - 1, j)`.
- Otherwise: add `str2[j - 1]`, move to `(i, j - 1)`.
- When one string runs out, add everything left of the other.
- The characters were collected from the end, so reverse the result.

The `-1` memo marker is safe because lengths are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down), Then Traceback

### Idea
Fill the LCS values with the memoized recursion, then trace back using the cached values. The traceback only reads cells the recursion already computed: from `(i, j)` with equal characters it moves to `(i - 1, j - 1)`, which the recursion computed, and with different characters both neighbours `(i - 1, j)` and `(i, j - 1)` were computed. Calling `f` again in the traceback is just a cache lookup.

### Steps
- Create `dp[n + 1][m + 1]` filled with `-1`.
- Call `f(n, m)` to fill the table.
- Walk back from `(n, m)` with the three traceback rules above, reading values through `f`.
- Append leftover characters, reverse, return.

### Complexity
Time: **O(n * m)** for the table, plus **O(n + m)** for the traceback       
Space: **O(n * m)** for the dp table, plus **O(n + m)** recursion stack and output

---

## Approach 2: Tabulation (Bottom-Up), Then Traceback

### Idea
Fill the same LCS table iteratively from small prefixes to the full strings, then trace back through it with the same rules.

### Steps
- Create `dp[n + 1][m + 1]` of zeros.
- For `i = 1 .. n`, for `j = 1 .. m`: match gives `1 + dp[i - 1][j - 1]`, mismatch gives `max(dp[i][j - 1], dp[i - 1][j])`.
- Trace back from `(n, m)`, append leftovers, reverse, return.

### Complexity
Time: **O(n * m)** for the table, plus **O(n + m)** for the traceback       
Space: **O(n * m)**, no recursion stack

---

## Why There Is No Space-Optimized Version
Space optimization keeps only the last row or two, which is enough to know the LCS LENGTH. The traceback needs to compare `dp[i - 1][j]` with `dp[i][j - 1]` at every step along a path that crosses all rows, so every row must still be available. (Reconstructing with less memory is possible with Hirschberg's divide and conquer, but that is a different algorithm and is not needed here.)

## Key Observation
This problem teaches the standard "LCS table plus traceback" pattern: the table gives the optimal length, and the traceback converts that into the actual string. The same trick prints the LCS itself, and it also applies to Edit Distance. Equal characters are written once, and in the unequal case the character kept is the one that the LCS did NOT use, which is the one belonging to the side with the larger neighbour value.

## When to use this
If problem involves:
- Merging two sequences so both stay as subsequences, with minimum total length
- Needing the actual string, not just its length
→ Think **LCS table, then traceback from the corner**, and remember that shared characters are written only once.

## Edge Cases
- Identical strings (answer is the string itself).
- No shared characters (answer is `str1 + str2` in some order, as in the third example).
- One string is a subsequence of the other (answer is the longer string).
- One string empty (the other is the answer, covered by the leftover loops).
- Several valid answers (any is accepted, the tie-break here prefers adding `str2`'s character).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization + Traceback | O(n * m) | O(n * m) + O(n + m) stack |
| Tabulation + Traceback | O(n * m) | O(n * m) |

where:
- `n` = length of `str1`
- `m` = length of `str2`

## Related Problems
- Longest Common Subsequence
- Print Longest Common Subsequence
- Delete Operation for Two Strings
- Edit Distance