# Partition Equal Subset Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/  
Difficulty: Medium  
Pattern: DP on Subsequences (Subset Sum / 0-1 Knapsack Style)

## What I understood
Given an array of positive integers, decide whether it can be split into two subsets with EQUAL sums. Every element must go into exactly one of the two subsets.

## Example
```
Input
nums = [1,5,11,5]
Output
true
```
Explanation: the array splits into [1,5,5] and [11], both summing to 11.

```
Input
nums = [1,2,3,5]
Output
false
```
Explanation: the total is 11, which is odd, so two equal halves are impossible.

```
Input
nums = [2,2,3,5]
Output
false
```
Explanation: the total is 12 so each half would need 6, but no subset sums to 6.

## Idea (shared by all three techniques)
Splitting into two equal subsets is the same as finding ONE subset whose sum is exactly half of the total, because whatever is left over automatically sums to the other half.

- If the total sum is odd, the answer is immediately `false`.
- Otherwise set `target = totalSum / 2` and ask: does some subset sum to `target`? This is the classic subset sum problem.

**State:** `f(ind, target)` = can we form the sum `target` using some of the elements `0..ind`?

**Recurrence:** each element is either taken or skipped:
```
notTake = f(ind - 1, target)
take    = f(ind - 1, target - arr[ind])     (only if arr[ind] <= target)
f(ind, target) = take OR notTake
```

**Base cases:**
- `target == 0`: the empty choice already forms the sum, return `true`.
- `ind == 0`: only the first element is left, so return `arr[0] == target`.

**Answer:** `f(n - 1, target)`.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the take / not take recurrence directly, and cache each `(ind, target)` result so no state is solved twice. Without the cache, the same state would be reached through many different take / skip combinations.

### Steps
- Check the total sum, return `false` if it is odd.
- Create `dp[n][target + 1]` filled with `-1` (not computed yet).
- Call `f(n - 1, target)`.
- Base cases as above.
- If `dp[ind][target]` is filled, return it.
- Otherwise compute `notTake` and (if allowed) `take`, store `take || notTake`, and return it.

### Complexity
Time: **O(n * target)**         
Space: **O(n * target)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill a table `dp[ind][tar]` (true if sum `tar` can be formed using elements `0..ind`) row by row, so every needed previous-row value is already known.

### Steps
- Create `dp[n][target + 1]` of `false`.
- Base column: `dp[i][0] = true` for every `i` (sum 0 is always possible).
- Base row: `dp[0][nums[0]] = true` if `nums[0] <= target` (the first element alone forms its own value).
- For `ind = 1 .. n - 1`, for `tar = 1 .. target`:
  - `notTake = dp[ind - 1][tar]`.
  - `take = dp[ind - 1][tar - nums[ind]]` if `nums[ind] <= tar`, else `false`.
  - `dp[ind][tar] = take || notTake`.
- Answer is `dp[n - 1][target]`.

### Complexity
Time: **O(n * target)**         
Space: **O(n * target)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `ind` reads only row `ind - 1`. So keep just two rows: `prev` for the previous element and `curr` for the current one.

### Steps
- `prev` holds the base row (`prev[0] = true`, and `prev[arr[0]] = true` if it fits).
- For each later element, build `curr` using `prev[tar]` (skip) and `prev[tar - arr[ind]]` (take). Set `curr[0] = true` each time.
- After each row, `prev = curr`.
- Answer is `prev[target]`.

### Complexity
Time: **O(n * target)**         
Space: **O(target)**, two rows of size `target + 1`

---

## Key Observation
The problem looks like it needs partitioning two ways, but the "equal halves" condition collapses it into a single yes or no question: is there a subset with sum exactly `total / 2`? The odd-total check is a free early exit. The recurrence is the standard take / not take pattern, which is the foundation of almost every subset-sum and knapsack variant. The `-1` memo marker is safe here, because stored results are only `0` or `1`.

## When to use this
If problem involves:
- Splitting a set into two groups with a balanced sum
- Asking whether a target total is reachable using some elements, each at most once
→ Think **subset sum DP with take / not take, state = (index, remaining target)**, then compress to one or two rows.

## Edge Cases
- Odd total sum (answer `false` right away).
- Single element array (never splittable, since the element is positive).
- One element equal to the target (the rest sums to the target as well).
- A very large element bigger than the target (it can never be taken, the `arr[ind] <= tar` guard handles that).
- Many equal elements (still efficient, since the table size depends only on `target`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * target) | O(n * target) + O(n) stack |
| Tabulation | O(n * target) | O(n * target) |
| Tabulation + Space Optimization | O(n * target) | O(target) |

where:
- `n` = number of elements
- `target` = half of the total sum

## Related Problems
- Subset Sum Problem
- Target Sum
- Last Stone Weight II
- Partition to K Equal Sum Subsets