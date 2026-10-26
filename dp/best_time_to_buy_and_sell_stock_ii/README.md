# Best Time to Buy and Sell Stock II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/  
Difficulty: Medium  
Pattern: DP on Stocks (Buy / Sell State), Greedy Shortcut

## What I understood
`prices[i]` is the price of a stock on day `i`. You may buy and sell any number of times, but you can hold at most ONE share at a time, so you must sell before buying again (buying and selling on the same day is allowed). Return the maximum total profit.

## Example
```
Input
prices = [7, 1, 5, 3, 6, 4]
Output
7
```
Explanation: buy at 1, sell at 5 (profit 4), buy at 3, sell at 6 (profit 3). Total 7.

```
Input
prices = [1, 2, 3, 4, 5]
Output
4
```
Explanation: buy at 1 and sell at 5, profit 4 (the same as selling and rebuying every day).

```
Input
prices = [7, 6, 4, 3, 1]
Output
0
```
Explanation: the price only falls, so the best choice is to never trade.

## Idea (shared by the four DP techniques)
The only thing that matters on a given day is whether you currently hold a share or not. That is the DP state.

**State:** `f(idx, buy)` = the maximum profit you can still make from day `idx` to the end, where
- `buy = 1` means you hold nothing, so you are allowed to buy today,
- `buy = 0` means you hold a share, so you are allowed to sell today.

**Recurrence:** on each day you either act or do nothing:
```
if buy == 1:  f(idx, 1) = max( -prices[idx] + f(idx + 1, 0),     (buy today, now holding)
                               f(idx + 1, 1) )                   (skip today)
if buy == 0:  f(idx, 0) = max( prices[idx] + f(idx + 1, 1),      (sell today, now free)
                               f(idx + 1, 0) )                   (keep holding)
```
Buying costs `prices[idx]` (negative profit), selling earns it.

**Base case:** `idx == n` means no days left, so profit is `0`.

**Answer:** `f(0, 1)` (start on day 0, holding nothing).

Profit is never negative (doing nothing is always possible), so `-1` is a safe "not computed yet" marker in the memo table.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, buy)` result. Many different buy / sell histories reach the same day in the same state, so the cache removes all repeated work.

### Steps
- Create `dp[n + 1][2]` filled with `-1`.
- Call `f(0, 1)`.
- If `idx == n`, return `0`. If `dp[idx][buy]` is filled, return it.
- Compute the two options for the current state (act or skip), store the larger, return it.

### Complexity
Time: **O(n)**, there are only `2n` states and each takes O(1)          
Space: **O(n)** for the dp table, plus **O(n)** recursion stack (up to 30,000 levels deep here)

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table from the LAST day backward, so `dp[idx + 1][...]` is always ready when day `idx` is computed.

### Steps
- Create `dp[n + 1][2]` of zeros (row `n` is the base case).
- For `idx = n - 1` down to `0`, for `buy = 0, 1`: apply the same two-option recurrence using row `idx + 1`.
- Answer is `dp[0][1]`.

### Complexity
Time: **O(n)**          
Space: **O(n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Two Small Arrays)

### Idea
Day `idx` reads only day `idx + 1`. Keep one array `ahead` of size 2 for day `idx + 1` and one array `curr` of size 2 for day `idx`.

### Steps
- `ahead = {0, 0}`.
- For each day from last to first, compute `curr[0]` and `curr[1]` from `ahead`.
- After each day, `ahead = curr`.
- Answer is `ahead[1]`.

### Complexity
Time: **O(n)**          
Space: **O(1)**

---

## Approach 4: Tabulation with Space Optimization (Four Variables)

### Idea
The two small arrays hold exactly four numbers, so name them instead. `aheadBuy` / `aheadNotBuy` are the values for state `buy = 1` and `buy = 0` on the next day, and `currBuy` / `currNotBuy` are the ones being computed. (Here "NotBuy" means "holding a share, may sell".)

### Steps
- `aheadBuy = aheadNotBuy = 0`.
- For each day from last to first:
  - `currNotBuy = max(prices[idx] + aheadBuy, aheadNotBuy)`
  - `currBuy = max(-prices[idx] + aheadNotBuy, aheadBuy)`
  - shift: `aheadBuy = currBuy`, `aheadNotBuy = currNotBuy`.
- Answer is `aheadBuy`.

### Complexity
Time: **O(n)**          
Space: **O(1)**

---

## Approach 5: Greedy (Sum of Every Upward Step)

### Idea
There is no limit on the number of transactions, so any rise over several days can be split into its day-to-day rises: buying at 1 and selling at 5 earns the same as collecting `+1, +1, +1, +1` one day at a time. So collect EVERY positive day-to-day difference and ignore the drops.

### Steps
- `ans = 0`.
- For `i = 1 .. n - 1`: if `prices[i] > prices[i - 1]`, add the difference to `ans`.
- Return `ans`.

### Complexity
Time: **O(n)**          
Space: **O(1)**

---

## Key Observation
The DP is the general template: the same `(day, can-buy)` state with a transaction counter gives Stock III and IV, and with a cooldown or fee gives the later variants. The greedy is only a shortcut that works here BECAUSE transactions are unlimited and there is no fee. Once a limit, a cooldown or a fee appears, the greedy breaks and the DP is needed.

## When to use this
If problem involves:
- Buying and selling over time, with limits on what you can do each day
- A decision that depends on whether you currently hold something
→ Think **DP on `(day, holding or not)`**. If there is no limit on transactions and no fee, the greedy "sum of positive differences" also works.

## Edge Cases
- Single day (answer 0).
- Strictly decreasing prices (answer 0).
- Strictly increasing prices (answer is last price minus first price).
- All equal prices (answer 0).
- Zigzag prices (every up-step is collected).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n) | O(n) + O(n) stack |
| Tabulation | O(n) | O(n) |
| Space Optimization (Two Arrays) | O(n) | O(1) |
| Space Optimization (Four Variables) | O(n) | O(1) |
| Greedy | O(n) | O(1) |

where:
- `n` = number of days

## Related Problems
- Best Time to Buy and Sell Stock
- Best Time to Buy and Sell Stock III
- Best Time to Buy and Sell Stock with Cooldown
- Best Time to Buy and Sell Stock with Transaction Fee