# Best Time to Buy and Sell Stock with Cooldown
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/  
Difficulty: Medium  
Pattern: DP on Stocks (Buy / Sell State, One-Day Cooldown After Sell)

## What I understood
`prices[i]` is the price of a stock on day `i`. You may trade as many times as you like, holding at most one share at a time, with one extra rule: after you SELL, you cannot buy on the very next day (a one-day cooldown). Return the maximum profit.

## Example
```
Input
prices = [1, 2, 3, 0, 2]
Output
3
```
Explanation: buy at 1, sell at 2, cooldown on day 2, buy at 0, sell at 2. Profit (2 - 1) + (2 - 0) = 3.

```
Input
prices = [1]
Output
0
```

```
Input
prices = [6, 1, 3, 2, 4, 7]
Output
6
```
Explanation: buy at 1, sell at 7, profit 6. Trading in between would cost cooldown days and earn less.

## Idea (shared by all the DP techniques)
This is Stock II (unlimited transactions) with one change: after a sell, the next day is blocked for buying. The state does not need a new flag, because the cooldown is handled by **jumping two days ahead** after a sell.

**State:** `f(idx, buy)` = the maximum profit from day `idx` to the end, where
- `buy = 1` means you hold nothing and may buy today,
- `buy = 0` means you hold a share and may sell today.

**Recurrence:**
```
if buy == 1:  f(idx, 1) = max( -prices[idx] + f(idx + 1, 0),         (buy today)
                               f(idx + 1, 1) )                       (skip today)
if buy == 0:  f(idx, 0) = max( prices[idx] + f(idx + 2, 1),          (sell today, skip tomorrow, may buy again the day after)
                               f(idx + 1, 0) )                       (keep holding)
```
The only difference from Stock II is `idx + 2` in the sell branch. Day `idx + 1` is the cooldown day, so it is skipped entirely.

**Base case:** `idx >= n` gives `0`. The check is `>=`, not `==`, because `idx + 2` can jump past the end.

**Answer:** `f(0, 1)`.

Profit is never negative (doing nothing is always possible), so `-1` is a safe "not computed yet" marker.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, buy)` result. There are only `2n` states, so each is solved once.

### Steps
- Create `dp[n + 1][2]` filled with `-1`.
- Call `f(0, 1)`.
- If `idx >= n`, return `0`. If `dp[idx][buy]` is filled, return it.
- Otherwise compute the two options for the current state (act or skip), store the larger, return it. The sell option calls `f(idx + 2, 1)`.

### Complexity
Time: **O(n)**      
Space: **O(n)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table from the LAST day backward. The sell branch reads two days ahead, so the table gets two extra rows of zeros.

### Steps
- Create `dp[n + 2][2]` of zeros. Rows `n` and `n + 1` are the base case, and they also make the `i + 2` read safe when `i = n - 1`.
- For `i = n - 1` down to `0`, for `buy = 0, 1`:
  - `buy == 1`: `max(-prices[i] + dp[i + 1][0], dp[i + 1][1])`.
  - `buy == 0`: `max(prices[i] + dp[i + 2][1], dp[i + 1][0])`.
- Answer is `dp[0][1]`.

### Complexity
Time: **O(n)**      
Space: **O(n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Day `i` reads day `i + 1` and day `i + 2`. So only the last two days must be remembered. Two versions do the same thing.

### Version 3a: Three Small Arrays
- `f1` holds day `i + 1`, `f2` holds day `i + 2`, `cur` is built for day `i`. Each array has 2 slots (`buy = 0` and `buy = 1`).
- For each day from last to first: `cur[1] = max(-prices[i] + f1[0], f1[1])` and `cur[0] = max(prices[i] + f2[1], f1[0])`.
- Shift: `f2 = f1`, `f1 = cur`.
- Answer is `f1[1]`.

### Version 3b: Five Variables
- The same numbers with names: `aheadBuy`, `aheadNotBuy` (day `i + 1`), `ahead2Buy` (day `i + 2`, only the `buy = 1` value is ever read from it), and `currBuy`, `currNotBuy` (day `i`).
- Shift in this order: `ahead2Buy = aheadBuy`, then `aheadBuy = currBuy`, `aheadNotBuy = currNotBuy`. The order matters, so `ahead2Buy` picks up the OLD `aheadBuy` before it is overwritten.
- Answer is `aheadBuy`.

### Complexity
Time: **O(n)**      
Space: **O(1)**

---

## Key Observation
The cooldown does not need a third state. A "jump two days ahead" in the sell branch is enough, which is the cheapest way to say "tomorrow is blocked". That also explains the space optimization: the recurrence now looks two days ahead, so two days of history are kept instead of one. The same problem is also solved with a three-state machine (holding, just sold, resting), which is the other common way to write this DP.

## When to use this
If problem involves:
- Unlimited trading with a forced waiting period after some action
- A decision that depends on whether you currently hold a share
→ Think **DP on `(day, holding or not)`**, and model the cooldown by jumping extra days after the action that causes it.

## Edge Cases
- Single day (answer 0).
- Strictly decreasing prices (answer 0).
- Strictly increasing prices (answer is last minus first, one long hold).
- Prices that rise and fall every day (the cooldown makes the greedy "sell every peak" wrong).
- `idx + 2` going past the end (handled by `idx >= n` in the recursion and the two extra rows in the table).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n) | O(n) + O(n) stack |
| Tabulation | O(n) | O(n) |
| Space Optimization (Three Arrays) | O(n) | O(1) |
| Space Optimization (Five Variables) | O(n) | O(1) |

where:
- `n` = number of days

## Related Problems
- Best Time to Buy and Sell Stock II
- Best Time to Buy and Sell Stock with Transaction Fee
- Best Time to Buy and Sell Stock III
- House Robber