# Palindrome Partitioning II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/palindrome-partitioning-ii/  
Difficulty: Hard  
Pattern: DP on Partitions (Front Partition, 1D DP), Expand Around Center

## What I understood
Given a string `s`, split it into pieces so that every piece is a palindrome. Return the minimum number of cuts needed.

## Example
```
Input
s = "aab"
Output
1
```
Explanation: split into `["aa", "b"]`. That needs one cut.

```
Input
s = "a"
Output
0
```
Explanation: the whole string is already a palindrome, so no cut is needed.

```
Input
s = "ab"
Output
1
```
Explanation: `"ab"` is not a palindrome, so split into `["a", "b"]`.

## Idea (shared by the first two techniques)
Count PIECES instead of cuts, then subtract `1` at the end, because `k` pieces need `k - 1` cuts.

Look at the suffix starting at index `i`. Try every end `j >= i`. If `s[i..j]` is a palindrome, it can be the first piece, and the rest `s[j + 1..]` is a smaller subproblem of the same kind.

**State:** `f(i)` = minimum number of palindromic pieces for the suffix `s[i..n - 1]`.

**Recurrence:**
```
f(i) = min over j in [i..n-1] where s[i..j] is a palindrome of
       1 + f(j + 1)
```

**Base case:** `f(n) = 0`, the empty suffix needs no pieces.

**Answer:** `f(0) - 1`.

A single character is always a palindrome, so `j = i` is always a valid choice and the minimum always exists.

The `-1` memo marker is safe because the number of pieces is never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly. For each start `i`, try every end `j`, check the substring with two pointers, and cache `f(i)`.

### Steps
- Create `dp[n]` filled with `-1`.
- `f(i)`: return `0` if `i == n`. If `dp[i]` is filled, return it.
- For `j = i` to `n - 1`: if `s[i..j]` is a palindrome, take `1 + f(j + 1)`.
- Keep the minimum, store it, return it.
- Return `f(0) - 1`.

### Complexity
Time: **O(n^3)** (O(n) states, O(n) choices of `j`, O(n) palindrome check that exits early on a mismatch)  
Space: **O(n)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. `dp[i]` needs `dp[j + 1]` for later positions, so fill `i` from the end of the string to the start.

### Steps
- Create `dp[n + 1]`, with `dp[n] = 0`.
- For `i = n - 1` down to `0`, for `j = i` to `n - 1`: if `s[i..j]` is a palindrome, candidate is `1 + dp[j + 1]`.
- `dp[i]` is the minimum candidate.
- Answer is `dp[0] - 1`.

### Complexity
Time: **O(n^3)**  
Space: **O(n)**, no recursion stack

---

## Why There Is No Space-Optimized Version
`dp[i]` reads `dp[j + 1]` for EVERY `j >= i`, so every later value of the array is needed. The array is already 1D with `O(n)` space, so there is nothing left to shrink.

---

## Approach 3: Expand Around Center (Prefix DP)

### Idea
Flip the direction. Instead of asking "is `s[i..j]` a palindrome?" for every pair, FIND the palindromes directly by expanding outward from every possible center. Each palindrome `s[l..r]` that is found gives one DP update:
```
cuts[r + 1] = min(cuts[r + 1], cuts[l] + 1)
```
where `cuts[i]` = minimum cuts for the prefix `s[0..i - 1]`.

This only works if `cuts[l]` is already final when it is used. Centers are processed from left to right, and every palindrome that ends before `l` has a smaller center, so `cuts[l]` is always final in time.

### Steps
- Create `cuts[n + 1]` with `cuts[i] = i - 1`. This is the worst case (cut between every pair of characters). `cuts[0] = -1` is on purpose: a palindrome that starts at index `0` then gives `-1 + 1 = 0` cuts.
- For every `center` from `0` to `n - 1`:
  - Odd palindromes: expand `k = 0, 1, 2, ...` while `s[center - k] == s[center + k]`, and update `cuts[center + k + 1]` using `cuts[center - k]`.
  - Even palindromes: expand `k = 1, 2, ...` while `s[center - k + 1] == s[center + k]`, and update `cuts[center + k + 1]` using `cuts[center - k + 1]`.
- Answer is `cuts[n]`.

### Complexity
Time: **O(n^2)**, there are `2n - 1` centers and each expansion is at most `O(n)`  
Space: **O(n)**, only the `cuts` array, no palindrome table

---

## Key Observation
The slow part of Approaches 1 and 2 is the repeated palindrome check, not the DP shape. Expand around center removes that check completely: palindromes are discovered once, as the expansion goes, and each one feeds the DP in `O(1)`. That drops the time from `O(n^3)` to `O(n^2)` with no extra table. A different way to reach the same `O(n^2)` is to precompute `isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1]`, but that needs `O(n^2)` space.

## When to use this
If problem involves:
- Splitting a string (or array) into pieces where each piece must satisfy a property
- Minimizing or counting the number of pieces
→ Think **front partition DP**: try every first piece, recurse on the suffix, and keep a 1D `dp` over the start index. If the property is "is a palindrome", find palindromes by **expanding around centers** instead of testing every pair.

## Edge Cases
- A single character (answer `0`).
- The whole string is a palindrome (answer `0`).
- All characters different (answer `n - 1`).
- All characters the same (answer `0`, and the slowest case for the early-exit palindrome check in Approaches 1 and 2).
- Even length palindromes such as `"aa"` (need the second expansion loop).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^3) | O(n) + O(n) stack |
| Tabulation | O(n^3) | O(n) |
| Expand Around Center | O(n^2) | O(n) |

where:
- `n` = length of the string

## Related Problems
- Palindrome Partitioning
- Palindrome Partitioning III
- Longest Palindromic Substring
- Word Break