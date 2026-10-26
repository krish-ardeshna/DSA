# Best Time to Buy and Sell Stock III
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/  
Difficulty: Hard  
Pattern: DP on Stocks (Buy / Sell State + Transaction Limit)

## What I understood
`prices[i]` is the price of a stock on day `i`. You may complete at most TWO transactions (one transaction = one buy followed by one sell), and you can hold at most one share at a time, so the first sell must come before the second buy. Return the maximum profit.

## Example
```
Input
prices = [3, 3, 5, 0, 0, 3, 1, 4]
Output
6
```
Explanation: buy at 0, sell at 3 (profit 3), then buy at 1, sell at 4 (profit 3). Total 6.

```
Input
prices = [1, 2, 3, 4, 5]
Output
4
```
Explanation: one transaction (buy at 1, sell at 5) is already the best, a second one adds nothing.

```
Input
prices = [7, 6, 4, 3, 1]
Output
0
```
Explanation: the price only falls, so no transaction helps.

## Idea (shared by all three techniques)
This is Stock II (unlimited transactions) with one extra number in the state: how many transactions are still allowed.

**State:** `f(idx, buy, cap)` = the maximum profit from day `idx` to the end, where
- `buy = 1` means you hold nothing and may buy today, `buy = 0` means you hold a share and may sell today,
- `cap` = how many transactions you may still complete.

**Recurrence:**
```
if buy == 1:  f(idx, 1, cap) = max( -prices[idx] + f(idx + 1, 0, cap),        (buy today)
                                    f(idx + 1, 1, cap) )                      (skip today)
if buy == 0:  f(idx, 0, cap) = max( prices[idx] + f(idx + 1, 1, cap - 1),     (sell today, one transaction done)
                                    f(idx + 1, 0, cap) )                      (keep holding)
```
The important detail: `cap` goes down only when you SELL. A transaction is finished at the sell, so a buy followed by a sell uses up exactly one of the two.

**Base case:** `idx == n` (no days left) or `cap == 0` (no transactions left) gives `0`.

**Answer:** `f(0, 1, 2)`.

Profit is never negative (doing nothing is always possible), so `-1` is a safe "not computed yet" marker.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, buy, cap)` result. There are only `n * 2 * 3` states, so the cache removes all repeated work.

### Steps
- Create `dp[n][2][3]` filled with `-1`.
- Call `f(0, 1, 2)`.
- Return `0` when `idx == n` or `cap == 0`.
- If `dp[idx][buy][cap]` is filled, return it.
- Otherwise compute the two options for the current state, store the larger, return it. The sell branch passes `cap - 1`.

### Complexity
Time: **O(n)** (6 states per day, each O(1))        
Space: **O(n)** for the dp table, plus **O(n)** recursion stack. Here `n` can be 100,000, so deep recursion is a risk and the next two approaches are safer.

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill the table from the LAST day backward, so everything a day needs from `i + 1` is already computed.

### Steps
- Create `dp[n + 1][2][3]` of zeros. Row `n` (no days left) and the `cap = 0` layer stay 0, which is exactly the base case.
- For `i = n - 1` down to `0`, for `buy = 0, 1`, for `cap = 1, 2`: apply the recurrence, reading day `i + 1`.
- Answer is `dp[0][1][2]`.

When `cap = 1`, the sell branch reads `dp[i + 1][1][0]`, which is the untouched `0` layer, so no special case is needed.

### Complexity
Time: **O(n)**          
Space: **O(n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Day `i` reads only day `i + 1`. Keep one `2 x 3` table for the next day (`ahead`) and one for the current day (`curr`).

### Steps
- `ahead` and `curr` are `2 x 3` tables of zeros (the `cap = 0` column is never changed, so it stays 0).
- For each day from last to first, fill `curr[buy][cap]` for `cap = 1, 2` from `ahead`.
- After each day, `ahead = curr`.
- Answer is `ahead[1][2]`.

### Complexity
Time: **O(n)**          
Space: **O(1)**, two tables of 6 numbers

---

## Key Observation
The whole stock family is ONE recurrence with a different limit on `cap`: Stock I is `cap = 1`, Stock II is unlimited, Stock III is `cap = 2`, and Stock IV just replaces the 2 with `k`. If you unroll `cap = 2` by hand, you also get a famous four-variable version (best profit after the first buy, first sell, second buy, second sell), which is this same DP with the loops written out.

## When to use this
If problem involves:
- Trading with a limited number of transactions
- A decision that depends on whether you currently hold a share
→ Think **DP on `(day, holding or not, transactions left)`**, reducing `cap` on the sell.

## Edge Cases
- Single day (answer 0).
- Strictly decreasing prices (answer 0).
- Strictly increasing prices (one transaction is enough, answer is last minus first).
- Only one profitable range (the second transaction is simply unused).
- Two separate rises (both transactions are used).

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
- Best Time to Buy and Sell Stock IV
- Best Time to Buy and Sell Stock with Cooldown
- Best Time to Buy and Sell Stock with Transaction Fee