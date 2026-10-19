# Coin Change
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/coin-change/  
Difficulty: Medium  
Pattern: DP on Subsequences (Unbounded Knapsack, Minimize Count)

## What I understood
Given coins of different denominations and a target `amount`, find the FEWEST number of coins needed to make exactly that amount. Every coin denomination can be used any number of times. If the amount cannot be made, return `-1`.

## Example
```
Input
coins = [1, 2, 5], amount = 11
Output
3
```
Explanation: 11 = 5 + 5 + 1.

```
Input
coins = [2], amount = 3
Output
-1
```
Explanation: only even amounts can be made with a 2-coin.

```
Input
coins = [1], amount = 0
Output
0
```
Explanation: zero coins are needed to make zero.

## Idea (shared by all three techniques)
Greedy (always pick the largest coin) fails here: with coins `[1, 3, 4]` and amount `6`, greedy picks 4 + 1 + 1 (3 coins), but 3 + 3 (2 coins) is better. So every choice must be compared by what it costs later, which is the take / not take DP.

**State:** `f(idx, target)` = minimum coins needed to make `target` using coin types `0..idx`.

**Recurrence:** for coin `idx` there are two choices:
```
notTake = f(idx - 1, target)                    (skip this coin type for good)
take    = 1 + f(idx, target - coins[idx])       (use one coin, but stay at idx)
f(idx, target) = min(take, notTake)
```
The important detail is `take` stays at `idx` instead of moving to `idx - 1`. Coins are unlimited, so after using one, the same coin may be used again. This is the difference from 0/1 knapsack, where taking moves to `idx - 1`.

**Base case (`idx == 0`):** only the first coin type is left. The target can be made only if it is a multiple of `coins[0]`, using `target / coins[0]` coins. Otherwise it is impossible, so return a huge value (`1e9`) as "infinity".

**Answer:** `f(n - 1, amount)`. If it is `>= 1e9`, no combination works, so return `-1`.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, target)` result. A `-1` marker means "not computed yet", which is safe because stored values are never negative.

### Steps
- Handle `amount == 0` (return 0) and empty `coins` (return -1).
- Create `dp[n][amount + 1]` filled with `-1`.
- Call `f(n - 1, amount)`.
- At `idx == 0`, return `target / coins[0]` if divisible, else `1e9`.
- If `dp[idx][target]` is filled, return it.
- Otherwise compute `notTake`, and `take` only if the coin fits, store `min(take, notTake)`, return it.
- If the final answer is `>= 1e9`, return `-1`.

### Complexity
Time: **O(n * amount)**         
Space: **O(n * amount)** for the dp table, plus **O(amount)** recursion stack (the `take` branch can go as deep as `amount` with coin 1)

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill `dp[idx][tar]` row by row from the first coin type. Each value needs the previous row (`notTake`) and the SAME row at a smaller amount (`take`), and both are already computed when `tar` goes upward.

### Steps
- Base row: `dp[0][tar] = tar / coins[0]` if divisible, else `1e9`.
- For `idx = 1 .. n - 1`, for `tar = 0 .. amount`:
  - `notTake = dp[idx - 1][tar]`.
  - `take = 1 + dp[idx][tar - coins[idx]]` if `coins[idx] <= tar`, else `1e9`.
  - `dp[idx][tar] = min(take, notTake)`.
- Answer is `dp[n - 1][amount]`, or `-1` if it is `>= 1e9`.

### Complexity
Time: **O(n * amount)**         
Space: **O(n * amount)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `idx` reads the previous row and the current row only. Keep two arrays: `prev` for the previous coin type and `curr` for the current one.

### Steps
- `prev` holds the base row.
- For each later coin type, fill `curr[tar]` using `prev[tar]` (not take) and `curr[tar - coins[idx]]` (take, same row).
- After each row, `prev = curr`.
- Answer is `prev[amount]`, or `-1` if it is `>= 1e9`.

`curr[tar - coins[idx]]` is already filled in the current row because `tar` goes upward and coin values are at least 1, so the cell read is always at a smaller amount.

### Complexity
Time: **O(n * amount)**         
Space: **O(amount)**, two arrays of size `amount + 1`

---

## Key Observation
This is the unbounded knapsack pattern. The only change from 0/1 knapsack is that `take` stays on the same coin index, which also changes the direction of the loop in the space-optimized version: for 0/1 knapsack the single-row loop must go backward, while here it naturally uses the current row's already-updated values. Using `1e9` as infinity is safe in `int`: values never exceed it, since `f(idx, t) <= f(idx - 1, t)` all the way down to the base case, so `1 + 1e9` never overflows.

## When to use this
If problem involves:
- Making a target using items that can be reused any number of times
- Minimizing the count (or maximizing a value) of items used
→ Think **unbounded knapsack: take stays at the same index, not take moves to the previous index**.

## Edge Cases
- `amount = 0` (answer 0, no coins needed).
- Amount smaller than every coin (answer -1).
- A coin equal to the amount (answer 1).
- Greedy trap like `coins = [1, 3, 4]`, `amount = 6` (answer 2, not 3).
- Large amount with the coin 1 (deep recursion in Approach 1, so Approaches 2 and 3 are safer).

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
- Coin Change II
- Perfect Squares
- Minimum Cost For Tickets
- 0 and 1 Knapsack