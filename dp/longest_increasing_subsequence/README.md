# Longest Increasing Subsequence
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/  
Difficulty: Medium  
Pattern: DP on Subsequences (Take / Not Take with Previous Index), Binary Search Shortcut

## What I understood
Given an integer array `nums`, return the length of the longest STRICTLY increasing subsequence. A subsequence keeps the order of elements but may skip some.

## Example
```
Input
nums = [10, 9, 2, 5, 3, 7, 101, 18]
Output
4
```
Explanation: one longest increasing subsequence is [2, 3, 7, 101].

```
Input
nums = [0, 1, 0, 3, 2, 3]
Output
4
```

```
Input
nums = [7, 7, 7, 7, 7, 7, 7]
Output
1
```
Explanation: the subsequence must be strictly increasing, so equal values cannot be chained.

## Idea (shared by the first three techniques)
Go through the array left to right and, for each element, decide: take it or skip it. To take it, we need to know the LAST element already taken, because the new one must be bigger.

**State:** `f(idx, prev_idx)` = length of the longest increasing subsequence that can be built from `nums[idx..]`, given that the last element taken so far is `nums[prev_idx]` (`prev_idx = -1` means nothing has been taken yet).

**Recurrence:**
```
notTake = f(idx + 1, prev_idx)
take    = 1 + f(idx + 1, idx)        (only allowed if prev_idx == -1 or nums[idx] > nums[prev_idx])
f(idx, prev_idx) = max(notTake, take)
```

**Base case:** `idx == n` (nothing left) gives `0`.

**Answer:** `f(0, -1)`.

The table is indexed by `prev_idx + 1`, because an index of `-1` cannot be used directly. Lengths are never negative, so `-1` is a safe "not computed yet" marker.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the take / not take recurrence directly and cache every `(idx, prev_idx)` result. There are only `n * (n + 1)` distinct states.

### Steps
- Create `dp[n][n + 1]` filled with `-1`.
- Call `f(0, -1)`.
- If `idx == n`, return `0`. If `dp[idx][prev_idx + 1]` is filled, return it.
- `len = f(idx + 1, prev_idx)` (skip). If taking is allowed, `len = max(len, 1 + f(idx + 1, idx))`.
- Store and return `len`.

### Complexity
Time: **O(n^2)**  
Space: **O(n^2)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table from the last index backward, so `dp[idx + 1][...]` is always ready.

### Steps
- Create `dp[n + 1][n + 1]` of zeros (row `n` is the base case).
- For `idx = n - 1` down to `0`, for `prev_idx = idx - 1` down to `-1`:
  - `len = dp[idx + 1][prev_idx + 1]` (skip).
  - If taking is allowed, `len = max(len, 1 + dp[idx + 1][idx + 1])`.
  - `dp[idx][prev_idx + 1] = len`.
- Answer is `dp[0][0]`.

`prev_idx` only runs up to `idx - 1`, because the previous element always comes before the current one.

### Complexity
Time: **O(n^2)**  
Space: **O(n^2)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `idx` reads only row `idx + 1`. Keep two arrays: `next` for the row below and `curr` for the row being built.

### Steps
- `next` and `curr` of size `n + 1`, all zeros.
- For each `idx` from last to first, fill `curr[prev_idx + 1]` from `next[prev_idx + 1]` and `next[idx + 1]`.
- After each row, `next = curr`.
- Answer is `next[0]`.

### Complexity
Time: **O(n^2)**  
Space: **O(n)**

---

## Approach 4: 1D DP (Longest Subsequence Ending at Each Index)

### Idea
A simpler way to see the same problem: let `dp[i]` be the length of the longest increasing subsequence that ENDS exactly at `nums[i]`. It is one more than the best `dp[prev]` over all earlier, smaller elements.

### Steps
- `dp[i] = 1` at the start (the element alone).
- For each `i`, for each `prev < i`: if `nums[prev] < nums[i]`, then `dp[i] = max(dp[i], 1 + dp[prev])`.
- Answer is the maximum value in `dp` (the subsequence can end anywhere).

### Complexity
Time: **O(n^2)**  
Space: **O(n)**

---

## Approach 5: Binary Search (Patience Sorting)

### Idea
Keep a list `temp` where `temp[k]` is the SMALLEST possible last element of an increasing subsequence of length `k + 1`. This list is always sorted, so each new number can be placed with a binary search.
- If the number is bigger than every entry, it extends the longest subsequence: append it.
- Otherwise it can make some subsequence end on a smaller value: replace the first entry that is `>=` it.

### Steps
- Start with `temp = [nums[0]]`.
- For each later number: if `nums[i] > temp.back()`, push it. Otherwise `lower_bound` finds the first entry `>= nums[i]` and overwrites it.
- Answer is the size of `temp`.

### Complexity
Time: **O(n log n)**  
Space: **O(n)**

---

## Key Observation
`temp` is NOT itself a valid increasing subsequence of the input after replacements, only its LENGTH is meaningful (it equals the LIS length). It is a bookkeeping array for "best possible endings". Using `lower_bound` (first entry `>=`) and not `upper_bound` is what makes the subsequence STRICTLY increasing: an equal number replaces its twin instead of extending the list. This approach also does not directly give the actual subsequence, for that, use Approach 4 with a parent array.

## When to use this
If problem involves:
- A longest chain or sequence where each element depends on the previous chosen one
→ Think **LIS**: `dp[i]` = best chain ending at `i` (O(n^2)), or the sorted-endings list with binary search (O(n log n)) when `n` is large.

## Edge Cases
- Single element (answer 1).
- Strictly increasing array (answer `n`).
- Strictly decreasing array (answer 1).
- All elements equal (answer 1, since increasing must be strict).
- Negative numbers (no problem for any approach).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^2) | O(n^2) + O(n) stack |
| Tabulation | O(n^2) | O(n^2) |
| Tabulation + Space Optimization | O(n^2) | O(n) |
| 1D DP | O(n^2) | O(n) |
| Binary Search | O(n log n) | O(n) |

where:
- `n` = number of elements

## Related Problems
- Largest Divisible Subset
- Longest String Chain
- Number of Longest Increasing Subsequence
- Russian Doll Envelopes