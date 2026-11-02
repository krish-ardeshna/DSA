# Partition Array for Maximum Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/partition-array-for-maximum-sum/  
Difficulty: Medium  
Pattern: DP on Partitions (Front Partition, 1D DP, Window of k)

## What I understood
Split the array into contiguous pieces, each of length AT MOST `k`. In every piece, every value is replaced by the maximum of that piece. Return the largest possible sum of the array after this change.

## Example
```
Input
arr = [1,15,7,9,2,5,10], k = 3
Output
84
```
Explanation: split into `[1,15,7] [9] [2,5,10]`. After the change it is `[15,15,15] [9] [10,10,10]`, and the sum is 45 + 9 + 30 = 84.

```
Input
arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output
83
```
Explanation: split into `[1] [4,1,5,7] [3,6,1,9] [9,3]`. The pieces give 1*1 + 7*4 + 9*4 + 9*2 = 1 + 28 + 36 + 18 = 83.

```
Input
arr = [1], k = 1
Output
1
```
Explanation: one piece of length 1, so the sum stays 1.

## Idea (shared by all three techniques)
Stand at index `idx`. Try every first piece `arr[idx..j]` with length at most `k`.

- A piece of length `len` with maximum `maxi` adds `len * maxi` to the sum.
- The rest of the array `arr[j + 1..]` is a smaller subproblem of the same kind.
- While `j` moves right, keep a running `len` and `maxi`, so each piece is evaluated in `O(1)`.

**State:** `f(idx)` = best sum for the suffix `arr[idx..n - 1]`.

**Recurrence:**
```
f(idx) = max over j in [idx .. min(idx + k, n) - 1] of
         (j - idx + 1) * max(arr[idx..j]) + f(j + 1)
```

**Base case:** `f(n) = 0`, the empty suffix adds nothing.

**Answer:** `f(0)`.

The `-1` memo marker is safe because the sums are never negative (`arr[i] >= 0`).

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly. For each `idx`, extend the first piece one element at a time up to `k`, and cache `f(idx)`.

### Steps
- Create `dp[n]` filled with `-1`.
- `f(idx)`: return `0` if `idx == n`. If `dp[idx]` is filled, return it.
- For `j = idx` to `min(idx + k, n) - 1`: update `len` and `maxi`, then take `len * maxi + f(j + 1)`.
- Keep the maximum, store it, return it.
- Call `f(0)`.

### Complexity
Time: **O(n * k)**  
Space: **O(n)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. `dp[idx]` needs `dp[j + 1]` for later positions, so fill `idx` from the end of the array to the start.

### Steps
- Create `dp[n + 1]` filled with `0` (so `dp[n] = 0`).
- For `idx = n - 1` down to `0`, loop `j` from `idx` to `min(idx + k, n) - 1`, keeping a running `len` and `maxi`.
- Candidate is `len * maxi + dp[j + 1]`. `dp[idx]` is the maximum candidate.
- Answer is `dp[0]`.

### Complexity
Time: **O(n * k)**  
Space: **O(n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Circular Buffer)

### Idea
`dp[idx]` only reads `dp[idx + 1 .. idx + k]`, which is a window of `k` values. So the full array is not needed. Keep only `k + 1` slots and reuse them in a circle: index `i` lives in slot `i % (k + 1)`.

### Steps
- Create `dp[k + 1]` filled with `0`. Slot `n % (k + 1)` is `0`, which is the base case `dp[n] = 0`.
- For `idx = n - 1` down to `0`, loop `j` from `idx` to `min(idx + k, n) - 1`.
- Read the next value from slot `(j + 1) % (k + 1)`.
- After the loop, write the result into slot `idx % (k + 1)`. That slot held index `idx + k + 1`, which no later step needs.
- Answer is `dp[0]`.

### Complexity
Time: **O(n * k)**  
Space: **O(k)**, one circular buffer of `k + 1` values

---

## Key Observation
The piece value `len * maxi` can be built while the piece grows, so no extra scan for the maximum is needed. That keeps the transition at `O(k)` per index. The only difference from Palindrome Partitioning II is the piece rule: there a piece must be a palindrome, here it only needs a length of at most `k`. The circular buffer saves real space only when `k` is much smaller than `n`. When `k` is close to `n`, it is about the same as the full array.

## When to use this
If problem involves:
- Splitting an array into contiguous pieces with a size limit
- The value of a piece depends on a running aggregate (max, min, sum)
→ Think **front partition DP**: try every first piece up to the limit, carry the aggregate, and recurse on the suffix. If each state reads only the next `k` states, a circular buffer of size `k + 1` is enough.

## Edge Cases
- `k = 1` (every element is its own piece, the answer is the array sum, and the buffer has 2 slots).
- `k = n` (the whole array can be one piece, but a split can still be better).
- Single element array.
- Array with zeros.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * k) | O(n) + O(n) stack |
| Tabulation | O(n * k) | O(n) |
| Tabulation + Space Optimization | O(n * k) | O(k) |

where:
- `n` = length of the array
- `k` = maximum piece length

## Related Problems
- Palindrome Partitioning II
- Filling Bookcase Shelves
- Split Array Largest Sum
- Word Break