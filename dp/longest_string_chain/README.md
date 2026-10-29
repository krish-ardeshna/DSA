# Longest String Chain
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-string-chain/  
Difficulty: Medium  
Pattern: DP on Subsequences (LIS Variant, "Is One Letter Longer Subsequence")

## What I understood
Given a list of words, a word `a` is a **predecessor** of word `b` if `b` can be made by inserting exactly ONE letter anywhere into `a` (without reordering the other letters). A word chain is a sequence `w1, w2, ..., wk` where each word is the predecessor of the next. Return the length of the longest possible chain using words from the list.

## Example
```
Input
words = ["a", "b", "ba", "bca", "bda", "bdca"]
Output
4
```
Explanation: one longest chain is "a" -> "ba" -> "bda" -> "bdca".

```
Input
words = ["xbc", "pcxbcf", "xb", "cxbc", "pcxbc"]
Output
5
```
Explanation: "xb" -> "xbc" -> "cxbc" -> "pcxbc" -> "pcxbcf".

```
Input
words = ["abcd", "dbqca"]
Output
1
```
Explanation: the two words are not related, so each is a chain of length 1.

## Idea (shared by both techniques)
This is the LIS pattern again: a chain is a sequence where each element relates to the previous one. The relation here is "the previous word is the current word with one letter removed".

Since a predecessor is always exactly ONE letter shorter, sort the words by length first. Then every possible predecessor of `words[i]` sits earlier in the array.

**State:** `dp[i]` = length of the longest chain that ENDS at `words[i]`.

**Recurrence:**
```
dp[i] = 1 + max( dp[prev] )   over all prev < i where words[prev] is a predecessor of words[i]
```
(and `dp[i] = 1` if there is none).

**Predecessor check `check(s1, s2)`:** is `s2` equal to `s1` with one letter removed? Compare with two pointers: lengths must differ by exactly 1, then scan `s1`; when letters match, advance both pointers, otherwise advance only the pointer in the longer word `s1` (that letter is the one inserted). `s2` is a predecessor if all its letters got matched.

**Answer:** the maximum `dp[i]` over all words.

Lengths are never negative, so `-1` is a safe "not computed yet" marker.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Compute `dp[i]` with a recursive function that asks for `dp[prev]` of every valid predecessor, caching each result.

### Steps
- Sort the words by length.
- Create `dp` of size `n` filled with `-1`.
- `f(i)`: if `dp[i]` is filled, return it. Otherwise `best = 1`, and for every `prev < i` where `check(words[i], words[prev])` is true, `best = max(best, 1 + f(prev))`.
- Store and return `best`.
- Answer is the maximum of `f(i)` over all `i`.

### Complexity
Time: **O(n^2 * L)**, where `L` is the length of a word (each `check` costs O(L))  
Space: **O(n)** for `dp`, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Fill `dp` left to right. When `dp[i]` is computed, every `dp[prev]` with `prev < i` is already known.

### Steps
- Sort by length. `dp[i] = 1` for all `i`.
- For each `i`, for each `prev < i`: if `check(words[i], words[prev])` and `1 + dp[prev] > dp[i]`, then `dp[i] = 1 + dp[prev]`.
- Keep the running maximum of `dp[i]`.

### Complexity
Time: **O(n^2 * L)**  
Space: **O(n)**

---

## Why There Is No Space-Optimized Version
Each `dp[i]` can depend on ANY earlier `dp[prev]`, not just the previous one, so no cell can be discarded. The array is only `O(n)` already.

## Key Observation
Sorting by length is the step that makes the problem a clean LIS: after it, a word only ever needs to look backward. Words of the same length can never be predecessors of each other, and `check` returns `false` for them immediately because the length difference is not exactly 1. A faster version, `O(n * L^2)`, drops each letter of a word in turn and looks the shorter word up in a hash map, which beats the `O(n^2)` pair loop when `n` is large and words are short.

## When to use this
If problem involves:
- Chains where each step transforms a word slightly (insert, delete, or replace one letter)
→ Think **sort by length, then LIS-style DP**, with a small helper that tests the "one step" relation.

## Edge Cases
- Single word (answer 1).
- No two words are related (answer 1).
- Several words of the same length (they can never be adjacent in a chain).
- Duplicate-looking structures such as `"a", "ab", "abc"` (a chain of length 3).
- A word that is a predecessor of several different words (each chain is counted on its own).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^2 * L) | O(n) + O(n) stack |
| Tabulation | O(n^2 * L) | O(n) |

where:
- `n` = number of words
- `L` = maximum word length

## Related Problems
- Longest Increasing Subsequence
- Largest Divisible Subset
- Number of Longest Increasing Subsequence
- Edit Distance