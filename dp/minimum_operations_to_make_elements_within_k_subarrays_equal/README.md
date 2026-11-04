# Minimum Operations to Make Elements Within K Subarrays Equal
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/  
Difficulty: Hard  
Pattern: Sliding Window Median (Two Multisets) + DP on Choosing K Non-Overlapping Windows

## What I understood
Given an integer array `nums` and two integers `x` and `k`. In one operation you can add `1` to or subtract `1` from any element. Return the minimum total number of operations so that there are at least `k` NON-OVERLAPPING subarrays of size exactly `x`, where every element inside each of those subarrays is equal.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2
Output
8
```
Explanation: the cost of a window is the sum of distances to its median. The 7 windows of size 3 cost `7, 5, 6, 4, 4, 3, 7` (by start index `0` to `6`). The windows `[-2,1,3]` (start 1, cost 5) and `[3,6,4]` (start 5, cost 3) do not overlap, and 5 + 3 = 8 is the best pair.

```
Input
nums = [9,-2,-2,-2,1,5], x = 2, k = 2
Output
3
```
Explanation: the windows of size 2 cost `11, 0, 0, 3, 4`. The best non-overlapping pair is `[-2,-2]` (start 1, cost 0) and `[-2,1]` (start 3, cost 3), so 0 + 3 = 3.

```
Input
nums = [1,1,1,1], x = 2, k = 2
Output
0
```
Explanation: both windows `[1,1]` are already equal.

## Idea (shared by all three techniques)
The problem has two separate parts.

**Part 1: the cost of ONE window.** To make a window of `x` numbers all equal with `+1 / -1` operations, the best target is the MEDIAN of the window. The cost is the sum of distances to the median (the same fact as in Minimum Moves to Equal Array Elements II):
```
cost[s] = sum of |a - median|  over the window nums[s .. s + x - 1]
```
All `n - x + 1` window costs are computed once with a sliding window median (details below).

**Part 2: choose `k` non-overlapping windows with the smallest total cost.** This is a DP over the array.

**State:** `dp[j][i]` = minimum total cost using only the first `i` elements to build exactly `j` non-overlapping windows.

**Recurrence:** look at the last element `i - 1`:
```
dp[j][i] = min( dp[j][i - 1],                     (element i - 1 is not the end of a window)
                dp[j - 1][i - x] + cost[i - x] )   (a window ends at i - 1, so it starts at i - x)
```
The second option is only possible when `i >= x`.

**Base cases:**
- `dp[0][i] = 0` (no windows needed, no cost).
- `dp[j][i] = INF` for `j > 0` when `i < x` (not enough elements).

**Answer:** `dp[k][n]`.

Choosing exactly `k` windows is enough, because more windows can only add cost (costs are never negative).

The `-1` memo marker is safe because every stored value is non-negative.

### Part 1 in detail: sliding window median with two multisets
- `low` holds the smaller half of the window, `high` holds the larger half. The maximum of `low` is the median.
- Keep `lowSum` and `highSum`. Then the cost is `median * |low| - lowSum + highSum - median * |high|`.
- A new value goes to `low` if it is `<=` the current median, otherwise to `high`.
- When the window is full, remove the value that left. Search `low` first, then `high`. Only ONE copy is erased, so duplicates are safe.
- `balance()` moves one element between the halves until `|low| = ceil(size / 2)`.

Time for this part: **O(n log x)**.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly, going from the full array backwards: `f(i, j)` = best cost for the first `i` elements with `j` windows. Cache every `(i, j)`.

### Steps
- Compute `cost[]` with the sliding window median.
- Create `dp[n + 1][k + 1]` filled with `-1`.
- `f(i, j)`: return `0` if `j == 0`. Return `INF` if `i < x`. Return the cached value if filled.
- `best = f(i - 1, j)`. Then if `f(i - x, j - 1)` is not `INF`, `best = min(best, f(i - x, j - 1) + cost[i - x])`.
- Store and return `best`.
- Call `f(n, k)`.

### Complexity
Time: **O(n log x + n * k)**  
Space: **O(n * k)** for the dp table, plus **O(n)** recursion stack (the recursion can go `n` calls deep)

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table `j` by `j`, and inside each row `i` from left to right.

### Steps
- Compute `cost[]`.
- Create `dp[k + 1][n + 1]` filled with `INF`, and set the whole row `dp[0]` to `0`.
- For `j = 1` to `k`, for `i = 1` to `n`: `dp[j][i] = dp[j][i - 1]`. If `i >= x` and `dp[j - 1][i - x]` is not `INF`, try `dp[j - 1][i - x] + cost[i - x]`.
- Answer is `dp[k][n]`.

### Complexity
Time: **O(n log x + n * k)**  
Space: **O(n * k)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Two Rows)

### Idea
Row `j` only reads row `j - 1`, so the full `k + 1` rows are not needed. Keep two rows: `prev` (row `j - 1`) and `curr` (row `j`).

### Steps
- Compute `cost[]`.
- `prev` starts as the row for `j = 0`: all zeros. `curr` is filled with `INF`.
- For each `j` from `1` to `k`: reset `curr` to `INF`, then for `i = 1..n` fill `curr[i]` with the same rule as Approach 2, reading from `prev`.
- After each `j`, `prev.swap(curr)`.
- Answer is `prev[n]`.

### Complexity
Time: **O(n log x + n * k)**  
Space: **O(n)**, two rows plus the `cost` array

---

## Key Observation
The problem looks hard because it mixes two ideas, but each one is known on its own:
1. "Make a window equal" is "move everything to the median", and a sliding window median is done with two balanced multisets.
2. "Choose `k` non-overlapping windows of fixed size with minimum total cost" is the classic pick-or-skip DP, the same shape as Maximum Sum of 3 Non-Overlapping Subarrays.

The DP only costs `O(n * k)`, which is fine because `k` is small (the constraint `k <= 15` as I remember it, with `k * x <= n`). The sliding median could also be done with a Fenwick tree or two heaps with lazy deletion, but that is the same idea with a different data structure.

All sums use `long long`. One window can cost up to about `x * 2 * 10^6`.

## When to use this
If problem involves:
- Choosing a fixed number of non-overlapping segments with a cost for each segment
- The cost of a segment is a sum of absolute differences
→ Think **precompute the cost of every window** (median with two multisets), then **DP on (position, windows chosen)**.

## Edge Cases
- `k = 1` (the answer is the smallest single window cost).
- `k * x == n` (the windows must tile the whole array).
- `x == n` (one window, `k` must be `1`).
- All elements already equal (answer `0`).
- Negative numbers (distances to the median still work).
- Duplicate values (remove one copy only, not all copies).
- Large values (use `long long` for costs and sums).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n log x + n * k) | O(n * k) + O(n) stack |
| Tabulation | O(n log x + n * k) | O(n * k) |
| Tabulation + Space Optimization | O(n log x + n * k) | O(n) |

where:
- `n` = length of `nums`
- `x` = window size
- `k` = number of windows

## Related Problems
- Sliding Window Median
- Minimum Moves to Equal Array Elements II
- Maximum Sum of 3 Non-Overlapping Subarrays
- Find Two Non-overlapping Sub-arrays Each With Target Sum