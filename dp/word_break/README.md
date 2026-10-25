# Word Break
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/word-break/  
Difficulty: Medium  
Pattern: DP on Strings (Prefix Segmentation)

## What I understood
Given a string `s` and a dictionary of words `wordDict`, decide whether `s` can be cut into a sequence of one or more dictionary words. Words may be reused any number of times.

## Example
```
Input
s = "leetcode", wordDict = ["leet", "code"]
Output
true
```
Explanation: "leetcode" is "leet" followed by "code".

```
Input
s = "applepenapple", wordDict = ["apple", "pen"]
Output
true
```
Explanation: "apple" + "pen" + "apple", where "apple" is used twice.

```
Input
s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output
false
```
Explanation: "cats" + "and" leaves "og", and "cat" + "sand" leaves "og" as well, so no cut works.

## Idea (shared by both techniques)
Instead of guessing where to cut, ask a simpler question about every prefix of `s`.

**State:** `f(i)` = can the first `i` characters of `s` be cut into dictionary words?

**Recurrence:** the last word of such a cut ends at position `i` and starts at some position `j < i`. So the prefix works if the first `j` characters work AND `s[j..i)` is a dictionary word:
```
f(i) = OR over j in [0, i) of ( f(j) AND dict contains s[j..i) )
```

**Base case:** `f(0) = true`. The empty prefix needs no words.

**Answer:** `f(n)`.

Words are stored in a hash set, so each "is this a word?" check is a lookup. The `-1` memo marker is safe because stored values are only `0` or `1`.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly: to decide prefix `i`, try every split point `j` and recurse on the shorter prefix `j`. Cache each answer, otherwise the same prefixes are rechecked through many different cuts.

### Steps
- Put all words into an `unordered_set`.
- Create `dp[n + 1]` filled with `-1` (not computed yet).
- Call `f(n)`.
- `f(0)` returns `true`.
- If `dp[i]` is filled, return it.
- Otherwise for each `j` from `0` to `i - 1`: if `s[j..i)` is in the set and `f(j)` is true, store and return `true`.
- If no split works, store and return `false`.

### Complexity
Time: **O(n^3)** in the worst case, since there are about `n^2 / 2` pairs `(j, i)` and each substring is built and hashed in up to `O(n)`       
Space: **O(n)** for the dp array and the recursion stack, plus the dictionary

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Fill `dp[0], dp[1], ..., dp[n]` in order. When `dp[i]` is computed, every `dp[j]` with `j < i` is already known, so each check is a direct lookup.

### Steps
- `dp[0] = true`, everything else `false`.
- For `i = 1 .. n`, for `j = 0 .. i - 1`:
  - If `dp[j]` is true and `s[j..i)` is a dictionary word, set `dp[i] = true` and stop checking this `i` (`break`).
- Answer is `dp[n]`.

### Complexity
Time: **O(n^3)** in the worst case (same reasoning as above)        
Space: **O(n)** for the dp array, plus the dictionary

---

## Why There Is No Space-Optimized Version
The usual space optimization keeps only the previous row of a 2D table. Here the table is already a single row, and `dp[i]` can depend on ANY earlier cell `dp[j]`, not just the last one, so no earlier cell can be thrown away. (An earlier version used two arrays, `prev` and `curr`, but they always held identical values because `prev = curr` copied everything each step, so one array does the same job.)

## Key Observation
Word Break is the basic "segment a sequence" DP. The same shape (`dp[i]` = best answer for the first `i` items, built from `dp[j]` plus one last piece) appears in Word Break II, Palindrome Partitioning and Decode Ways. A cheap speedup is to try only split points where `i - j` is at most the longest word length, since longer substrings can never be in the dictionary. That brings the time down to about `O(n * L)` substring checks, where `L` is the longest word.

## When to use this
If problem involves:
- Cutting a string into pieces that must each belong to a given set
- Asking only whether it is possible (or how many ways, or the minimum pieces)
→ Think **`dp[i]` over prefixes, trying every position for the last piece**.

## Edge Cases
- A single word equal to the whole string (true).
- A word reused several times (allowed).
- A prefix that no word can start (false for any split through it).
- A dictionary with one-letter words (many split points work, memoization keeps it fast).
- Long string of the same letter with a non-matching dictionary (the early `break` helps when matches exist, but the full scan is needed for `false`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^3) worst case | O(n) + dictionary |
| Tabulation | O(n^3) worst case | O(n) + dictionary |

where:
- `n` = length of `s`

## Related Problems
- Word Break II
- Palindrome Partitioning
- Decode Ways
- Concatenated Words