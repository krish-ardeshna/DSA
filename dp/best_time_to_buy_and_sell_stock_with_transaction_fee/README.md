# Best Time to Buy and Sell Stock with Transaction Fee
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/  
Difficulty: Medium  
Pattern: DP on Stocks (Buy / Sell State, Fee Charged on Sell)

## What I understood
`prices[i]` is the price of a stock on day `i`, and `fee` is a fixed cost paid for every transaction. You may trade as many times as you like, but you can hold at most one share at a time, so you must sell before buying again. Return the maximum profit. The fee is paid once per transaction (buy plus sell).

## Example
```
Input
prices = [1, 3, 2, 8, 4, 9], fee = 2
Output
8
```
Explanation: buy at 1, sell at 8 (profit 8 - 1 - 2 = 5), then buy at 4, sell at 9 (profit 9 - 4 - 2 = 3). Total 8.

```
Input
prices = [1, 3, 7, 5, 10, 3], fee = 3
Output
6
```
Explanation: buy at 1, sell at 10, profit 10 - 1 - 3 = 6.

```
Input
prices = [5, 4, 3], fee = 1
Output
0
```
Explanation: the price only falls, so the best choice is to never trade.

## Idea (shared by all three techniques)
This is Stock II (unlimited transactions) with one change: every sell costs an extra `fee`. The fee is paid once per transaction, and it does not matter whether it is charged at the buy or at the sell, so it is charged at the sell.

**State:** `f(idx, buy)` = the maximum profit from day `idx` to the end, where
- `buy = 1` means you hold nothing and may buy today,
- `buy = 0` means you hold a share and may sell today.

**Recurrence:**
```
if buy == 1:  f(idx, 1) = max( -prices[idx] + f(idx + 1, 0),             (buy today)
                               f(idx + 1, 1) )                           (skip today)
if buy == 0:  f(idx, 0) = max( prices[idx] - fee + f(idx + 1, 1),        (sell today, pay the fee)
                               f(idx + 1, 0) )                           (keep holding)
```

**Base case:** `idx == n` (no days left) gives `0`.

**Answer:** `f(0, 1)`.

Profit is never negative (doing nothing is always possible), so `-1` is a safe "not computed yet" marker. The answer fits in `int`: under the constraints the largest possible profit is about `1.25 * 10^9`.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, buy)` result. There are only `2n` states, so each is solved once.

### Steps
- Create `dp[n][2]` filled with `-1`.
- Call `f(0, 1)`.
- If `idx == n`, return `0`. If `dp[idx][buy]` is filled, return it.
- Otherwise compute the two options for the current state (act or skip), store the larger, return it. The sell option includes `- fee`.

### Complexity
Time: **O(n)**      
Space: **O(n)** for the dp table, plus **O(n)** recursion stack. Here `n` can be 50,000, so deep recursion is a risk and the next two approaches are safer.

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table from the LAST day backward, so `dp[idx + 1][...]` is always ready.

### Steps
- Create `dp[n + 1][2]` of zeros (row `n` is the base case).
- For `idx = n - 1` down to `0`, for `buy = 0, 1`: apply the same two-option recurrence using row `idx + 1`.
- Answer is `dp[0][1]`.

### Complexity
Time: **O(n)**      
Space: **O(n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

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

## Key Observation
The fee is exactly why the Stock II greedy ("collect every rise") breaks: that greedy trades on every small upward step, and here each trade costs `fee`. A rise smaller than the fee must be ignored, and several small rises sometimes have to be merged into one trade. The DP handles that automatically, because "sell now" and "keep holding" are compared on their real values. The same state works for the cooldown variant too, only the transition after a sell changes.

## When to use this
If problem involves:
- Unlimited trading with a cost attached to each trade
- A decision that depends on whether you currently hold a share
→ Think **DP on `(day, holding or not)`**, with the cost added in the buy or sell branch.

## Edge Cases
- Single day (answer 0).
- Strictly decreasing prices (answer 0).
- `fee = 0` (same as Stock II, every rise is collected).
- A fee larger than any possible gain (answer 0).
- Small rises that are each smaller than the fee (they must not be traded one by one).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n) | O(n) + O(n) stack |
| Tabulation | O(n) | O(n) |
| Tabulation + Space Optimization | O(n) | O(1) |

where:
- `n` = number of days

## Related Problems
- Best Time to Buy and Sell Stock II
- Best Time to Buy and Sell Stock with Cooldown
- Best Time to Buy and Sell Stock III
- Best Time to Buy and Sell Stock IV