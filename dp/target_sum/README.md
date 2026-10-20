# Target Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/target-sum/  
Difficulty: Medium  
Pattern: DP on Subsequences (Count Subsets with Sum K, Zeros Handled)

## What I understood
Given an array `nums` and an integer `target`, put either a `+` or a `-` in front of every number, then add everything up. Count how many different sign assignments give a total exactly equal to `target`.

## Example
```
Input
nums = [1, 1, 1, 1, 1], target = 3
Output
5
```
Explanation: exactly one of the five 1s must get a `-` (so four `+` and one `-` gives 3), and that one can be any of the 5 positions.

```
Input
nums = [1], target = 1
Output
1
```

```
Input
nums = [0, 0, 0, 0, 0, 0, 0, 0, 1], target = 1
Output
256
```
Explanation: the 1 must be `+`, and each of the eight zeros can be `+` or `-` without changing the total, so 2^8 = 256 ways.

## Idea (shared by all three techniques)
Trying every sign assignment is `2^n`. The trick is to see that the signs just split the array into two groups:
- `P` = sum of the numbers that get a `+`
- `N` = sum of the numbers that get a `-`

Then:
```
P + N = totalSum
P - N = target
```
Adding the two equations gives `P = (totalSum + target) / 2`. So the problem becomes: **count the subsets whose sum is exactly `tar = (totalSum + target) / 2`**. Every such subset is the `+` group, and the rest is automatically the `-` group.

Two quick exits first:
- `abs(target) > totalSum`: the target is out of reach, return 0.
- `(totalSum + target)` is odd: `tar` would not be a whole number, return 0.

**State:** `f(ind, sum)` = number of subsets of `nums[0..ind]` with sum exactly `sum`.

**Recurrence:** take or skip the current number:
```
notTake = f(ind - 1, sum)
take    = f(ind - 1, sum - nums[ind])     (only if nums[ind] <= sum)
f(ind, sum) = (notTake + take) % MOD
```

**Base case (`ind == 0`), where zeros matter:**
- `sum == 0` and `nums[0] == 0`: both the empty subset and `{0}` have sum 0, so return **2**.
- `sum == 0` or `sum == nums[0]`: exactly one way, return **1**.
- Otherwise return 0.

**Answer:** `f(n - 1, tar)`.

Why zeros need care: a zero adds nothing to the sum, so it can go to either group (`+0` or `-0`) without changing anything. Every zero therefore DOUBLES the count.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the take / skip recurrence directly and cache every `(ind, sum)` result so each state is solved once. A `-1` marker for "not computed" is safe because counts are never negative.

### Steps
- Run the two quick exits and compute `tar`.
- Create `dp[n][tar + 1]` filled with `-1`.
- Call `f(n - 1, tar)`.
- At `ind == 0`, return the base case values above (2, 1 or 0).
- If `dp[ind][sum]` is filled, return it.
- Otherwise compute `notTake` and (if allowed) `take`, store `(notTake + take) % MOD`, return it.

### Complexity
Time: **O(n * tar)**        
Space: **O(n * tar)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion and fill `dp[ind][s]` row by row from the first number. Every value reads only the previous row.

### Steps
- Create `dp[n][tar + 1]` of zeros.
- Base row: `dp[0][0] = 2` if `nums[0] == 0`, else `1`. If `nums[0] != 0` and `nums[0] <= tar`, set `dp[0][nums[0]] = 1`.
- For `ind = 1 .. n - 1`, for `s = 0 .. tar`:
  - `notTake = dp[ind - 1][s]`.
  - `take = dp[ind - 1][s - nums[ind]]` if `nums[ind] <= s`, else `0`.
  - `dp[ind][s] = (notTake + take) % MOD`.
- Answer is `dp[n - 1][tar]`.

Looping `s` from 0 handles zeros automatically: for a zero, `take` reads `dp[ind - 1][s]`, which doubles the value.

### Complexity
Time: **O(n * tar)**        
Space: **O(n * tar)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Single Row, Reverse Loop)

### Idea
Row `ind` reads only row `ind - 1`, so a single array is enough, if it is updated from the largest sum down to the smallest. When `dp[s]` is updated, the cell it reads, `dp[s - num]`, is at a smaller index and has not been overwritten yet, so it still holds the previous number's value.

### Steps
- `dp[0] = 1` (one way to make sum 0 before looking at any number).
- For each `num`, loop `s` from `tar` down to `num`: `dp[s] = (dp[s] + dp[s - num]) % MOD`.
- Answer is `dp[tar]`.

### Complexity
Time: **O(n * tar)**        
Space: **O(tar)**, a single array

---

## Key Observation
The problem looks like "try all sign combinations", but the sign split collapses it into the same "count subsets with sum K" pattern used in Count Partitions with Given Difference. The reverse loop in Approach 3 is what keeps each number to a single use. A forward loop would let `dp[s - num]` already include the current number, counting the same number several times, which would turn this into an unbounded-use problem. In Approach 3, a zero is handled without any special case: since `s >= 0` is allowed, `dp[s] += dp[s]` doubles every count, one doubling per zero. Under LC's constraints (`n <= 20`) the count is at most about 2^20, so the modulo never changes the answer; it is only a safeguard.

## When to use this
If problem involves:
- Assigning `+` or `-` to every element and hitting a target total
- Counting the number of ways (not just checking if it is possible)
→ Think **convert to "count subsets with sum `(total + target) / 2`"**, then use take / skip DP and handle zeros in the base case.

## Edge Cases
- `abs(target) > totalSum` (answer 0).
- `totalSum + target` odd (answer 0).
- Array of zeros only (each zero doubles the count, answer `2^n` if the target is 0).
- `target = 0` (both groups must sum to `total / 2`).
- Negative target (works the same, `abs(target)` is used for the range check).
- Single element array.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * tar) | O(n * tar) + O(n) stack |
| Tabulation | O(n * tar) | O(n * tar) |
| Tabulation + Space Optimization | O(n * tar) | O(tar) |

where:
- `n` = number of elements
- `tar` = `(totalSum + target) / 2`

## Related Problems
- Count Partitions with Given Difference
- Partition Equal Subset Sum
- Last Stone Weight II
- Subsets with Sum K