# Best Time to Buy and Sell Stock IV
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/  
Difficulty: Hard  
Pattern: DP on Stocks (At Most k Transactions, State = Operations Done)

## What I understood
`prices[i]` is the price of a stock on day `i`. You may complete at most `k` transactions (one transaction = one buy followed by one sell), and you can hold at most one share at a time, so you must sell before buying again. Return the maximum profit.

## Example
```
Input
k = 2, prices = [2, 4, 1]
Output
2
```
Explanation: buy at 2, sell at 4, profit 2. A second transaction cannot add anything.

```
Input
k = 2, prices = [3, 2, 6, 5, 0, 3]
Output
7
```
Explanation: buy at 2, sell at 6 (profit 4), then buy at 0, sell at 3 (profit 3). Total 7.

```
Input
k = 1, prices = [7, 6, 4, 3, 1]
Output
0
```
Explanation: the price only falls, so the best choice is to never trade.

## Idea (shared by the first four techniques)
This is Stock III with `2` replaced by `k`. Stock III tracked two things, "can I buy" and "how many transactions are left". Here both are merged into ONE number.

**State:** `f(idx, trans)` = the maximum profit from day `idx` to the end, where `trans` is how many operations (buys AND sells) have already been done, from `0` to `2k`.
- `trans` even: the next operation is a **buy** (you hold nothing).
- `trans` odd: the next operation is a **sell** (you hold a share).
- One transaction is two operations, so `k` transactions are `2k` operations.

**Recurrence:**
```
if trans is even:  f(idx, trans) = max( -prices[idx] + f(idx + 1, trans + 1),    (buy today)
                                       f(idx + 1, trans) )                      (skip today)
if trans is odd:   f(idx, trans) = max( prices[idx] + f(idx + 1, trans + 1),     (sell today)
                                       f(idx + 1, trans) )                      (skip today)
```

**Base case:** `idx == n` (no days left) or `trans == 2k` (no operations left) gives `0`.

**Answer:** `f(0, 0)`.

Profit is never negative (doing nothing is always possible), so `-1` is a safe "not computed yet" marker in the memo table.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, trans)` result. Without the cache, every day branches twice (act or skip), which is `2^n`. With it there are only `n * 2k` states.

### Steps
- Create `dp[n][2k]` filled with `-1`. The second index never reaches `2k`, because that case returns early.
- Call `f(0, 0)`.
- Return `0` when `idx == n` or `trans == 2k`.
- If `dp[idx][trans]` is filled, return it.
- Otherwise pick the buy form (even `trans`) or the sell form (odd `trans`), store the larger of "act today" and "skip today", and return it.

### Complexity
Time: **O(n * k)**          
Space: **O(n * k)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table from the LAST day backward, so everything day `i` needs from day `i + 1` is already computed.

### Steps
- Create `dp[n + 1][2k + 1]` of zeros. Row `n` (no days left) and column `2k` (no operations left) stay 0, which is exactly the base case.
- For `i = n - 1` down to `0`, for `trans = 2k - 1` down to `0`: apply the buy or sell form, reading row `i + 1`.
- Answer is `dp[0][0]`.

### Complexity
Time: **O(n * k)**          
Space: **O(n * k)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Two Rows)

### Idea
Day `i` reads only day `i + 1`. Keep one array `ahead` for the next day and one array `curr` for the current day.

### Steps
- `ahead` and `curr` are arrays of size `2k + 1`, all zeros (the last slot stays 0 as the base case).
- For each day from last to first, fill `curr[trans]` for every `trans` from `ahead`.
- After each day, `ahead = curr`.
- Answer is `ahead[0]`.

### Complexity
Time: **O(n * k)**          
Space: **O(k)**

---

## Approach 4 (Extra): Space Optimization with a Single Array

### Idea
Even `curr` is not needed. Update one array `dp` in place, but loop `trans` in **ascending** order. When `dp[trans]` is computed, the cell it reads, `dp[trans + 1]`, has not been updated yet today, so it still holds the next day's value.

### Steps
- `dp` of size `2k + 1`, all zeros.
- For each day from last to first, for `trans = 0 .. 2k - 1`: `dp[trans] = max(act today using dp[trans + 1], dp[trans])`.
- Answer is `dp[0]`.

### Complexity
Time: **O(n * k)**          
Space: **O(k)**, a single array

---

## Approach 5 (Extra): Forward Buy/Sell Arrays + `k >= n / 2` Shortcut

### Idea
Instead of working backward from the last day, sweep the days forward and keep, for each `j` from `1` to `k`:
- `buy[j]` = the best profit while holding a share bought as the `j`-th buy (the buy price is already subtracted).
- `sell[j]` = the best profit after completing the `j`-th sell.

This is the well-known four-variable Stock III solution, generalized to `k` pairs.

### Steps
- Shortcut: each transaction needs at least 2 days, so at most `n / 2` transactions can ever be made. If `k >= n / 2` the limit does not matter, and the answer is the Stock II greedy (sum of every positive day-to-day rise).
- Otherwise `buy[j] = INT_MIN`, `sell[j] = 0` for all `j`.
- For each price `p`, for `j = 1 .. k`:
  - `buy[j] = max(buy[j], sell[j - 1] - p)`
  - `sell[j] = max(sell[j], buy[j] + p)`
- Answer is `sell[k]`.

### Complexity
Time: **O(n * k)**, or just **O(n)** when the shortcut applies          
Space: **O(k)**

---

## Key Observation
The whole stock family is ONE recurrence with different limits: Stock I is `k = 1`, Stock II is `k = infinity`, Stock III is `k = 2`, and this problem is the general `k`. Packing "buy or sell" and "how many left" into the single number `trans` is what makes the table two-dimensional instead of three-dimensional. The shortcut matters in practice because `k` can be larger than `n / 2`, and then the table would be bigger than needed for no reason.

## When to use this
If problem involves:
- Trading with a limit of `k` transactions
- A decision that depends on whether you currently hold a share
→ Think **DP on `(day, operations done)`**, where even means "buy next" and odd means "sell next". Use the Stock II greedy when `k >= n / 2`.

## Edge Cases
- `k = 0` (answer 0).
- Single day (answer 0).
- Strictly decreasing prices (answer 0).
- `k` larger than `n / 2` (acts like unlimited transactions, the shortcut handles it).
- Strictly increasing prices (one transaction is enough).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * k) | O(n * k) + O(n) stack |
| Tabulation | O(n * k) | O(n * k) |
| Space Optimization (Two Rows) | O(n * k) | O(k) |
| Space Optimization (Single Array) | O(n * k) | O(k) |
| Forward Buy/Sell Arrays + Shortcut | O(n * k), O(n) with shortcut | O(k) |

where:
- `n` = number of days
- `k` = maximum number of transactions

## Related Problems
- Best Time to Buy and Sell Stock II
- Best Time to Buy and Sell Stock III
- Best Time to Buy and Sell Stock with Cooldown
- Best Time to Buy and Sell Stock with Transaction Fee