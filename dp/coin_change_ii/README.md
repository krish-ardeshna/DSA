# Coin Change II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/coin-change-ii/  
Difficulty: Medium  
Pattern: DP on Subsequences (Unbounded Knapsack, Count Combinations)

## What I understood
Given coins of different denominations (each denomination can be used any number of times) and a target `amount`, count the number of COMBINATIONS of coins that add up to exactly that amount. Two combinations are the same if they use the same number of each denomination, the order of the coins does not matter. Return 0 if the amount cannot be made.

## Example
```
Input
amount = 5, coins = [1, 2, 5]
Output
4
```
Explanation: 5 = 5, 5 = 2 + 2 + 1, 5 = 2 + 1 + 1 + 1, 5 = 1 + 1 + 1 + 1 + 1.

```
Input
amount = 3, coins = [2]
Output
0
```
Explanation: only even amounts can be made with a 2-coin.

```
Input
amount = 10, coins = [10]
Output
1
```

## Idea (shared by all three techniques)
**State:** `f(idx, target)` = number of combinations that make `target` using coin types `0..idx`.

**Recurrence:** for coin `idx` there are two choices:
```
notTake = f(idx - 1, target)                    (never use this coin type)
take    = f(idx, target - coins[idx])           (use one, and stay on the same type)
f(idx, target) = take + notTake
```
The `take` branch stays at `idx` because coins are unlimited, so after using one the same coin may be used again. This is the difference from 0/1 knapsack, where taking moves on to `idx - 1`.

**Base case (`idx == 0`):** only the first coin type is left. The target can be made in exactly 1 way if it is a multiple of `coins[0]` (including `target = 0`), otherwise in 0 ways.

**Answer:** `f(n - 1, amount)`.

**Why this counts combinations, not permutations:** coin types are decided in a fixed order (index by index), so for a given multiset of coins the DP builds it in only one order. If the loops were reversed (amount outside, coins inside), the same coins in a different order would be counted again, which is the Combination Sum IV problem.

**Overflow guard:** counts for smaller amounts can exceed `INT_MAX` even when the final answer fits. Every sum is computed in `long long` and capped at `INT_MAX`. A capped state can never feed into a final answer that fits in `int`, so the cap is safe. The `-1` memo marker is also safe, since stored values are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, target)` result. Pass the `dp` table **by reference**, otherwise each call copies the whole table and nothing is ever cached.

### Steps
- Handle `amount == 0` (return 1) and empty `coins` (return 0).
- Create `dp[n][amount + 1]` filled with `-1`.
- Call `f(n - 1, amount)`.
- At `idx == 0`, return `1` if `target % coins[0] == 0`, else `0`.
- If `dp[idx][target]` is filled, return it.
- Otherwise compute `notTake`, and `take` only if the coin fits, store `min(INT_MAX, take + notTake)`, return it.

### Complexity
Time: **O(n * amount)**             
Space: **O(n * amount)** for the dp table, plus **O(amount)** recursion stack (the `take` branch can go as deep as `amount` with a coin of value 1)

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill `dp[idx][tar]` row by row. Each value needs the previous row (`notTake`) and the SAME row at a smaller amount (`take`), and both are already computed when `tar` goes upward.

### Steps
- Base row: `dp[0][tar] = 1` if `tar % coins[0] == 0`, else `0`.
- For `idx = 1 .. n - 1`, for `tar = 0 .. amount`:
  - `notTake = dp[idx - 1][tar]`.
  - `take = dp[idx][tar - coins[idx]]` if `coins[idx] <= tar`, else `0`.
  - `dp[idx][tar] = min(INT_MAX, take + notTake)`.
- Answer is `dp[n - 1][amount]`.

### Complexity
Time: **O(n * amount)**         
Space: **O(n * amount)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `idx` reads only the previous row and the current row. Keep two arrays: `prev` for the previous coin type and `curr` for the current one.

### Steps
- `prev` holds the base row.
- For each later coin type, fill `curr[tar]` using `prev[tar]` (not take) and `curr[tar - coins[idx]]` (take, same row).
- After each row, `prev = curr`.
- Answer is `prev[amount]`.

`curr[tar - coins[idx]]` is already filled in the current row, because `tar` goes upward and coin values are at least 1, so the cell read is always at a smaller amount.

### Complexity
Time: **O(n * amount)**         
Space: **O(amount)**, two arrays of size `amount + 1`

---

## Key Observation
This is the unbounded knapsack pattern, but counting instead of minimizing. Compare it with Coin Change (minimum number of coins): the structure is identical, only `min(take + 1, notTake)` becomes `take + notTake`, and the base case returns 1 or 0 instead of a coin count. The order of the loops (coin types on the outside) is what makes it count combinations rather than orderings.

## When to use this
If problem involves:
- Counting the number of ways to reach a total using reusable items
- Different orders of the same items counting as ONE way
→ Think **unbounded knapsack with `take` staying on the same index, and item types as the outer loop**.

## Edge Cases
- `amount = 0` (answer 1, the empty combination).
- No coin divides or sums to the amount (answer 0).
- A single coin equal to the amount (answer 1).
- Large amount with a coin of value 1 (deep recursion in Approach 1, so Approaches 2 and 3 are safer).
- Intermediate counts larger than `int` (handled by the `long long` cap).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * amount) | O(n * amount) + O(amount) stack |
| Tabulation | O(n * amount) | O(n * amount) |
| Tabulation + Space Optimization | O(n * amount) | O(amount) |

where:
- `n` = number of coin denominations
- `amount` = target amount

## Related Problems
- Coin Change
- Combination Sum IV
- Target Sum
- Partition Equal Subset Sum