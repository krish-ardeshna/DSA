# Best Time to Buy and Sell Stock II

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/  
Difficulty: Medium  
Pattern: Greedy

## What I understood
We are given the stock price for each day.

We can complete as many buy and sell transactions as we want, but we must sell the stock before buying again.

Find the maximum possible profit.

Example:

prices = [7,1,5,3,6,4]

Output = 7

## Idea
Whenever today's price is greater than yesterday's price, take that profit.

Adding all positive price differences is equivalent to buying at every local minimum and selling at every local maximum.

## Approach
- Initialize profit as 0.
- Traverse the array from the second day.
- If today's price is greater than yesterday's, add the difference to the profit.
- Return the total profit.

## Key Observation
Every increasing price segment contributes to the final answer.

Instead of finding every buy and sell point explicitly, simply add every positive difference between consecutive days.

## When to use this
If the problem involves:
- unlimited transactions
- maximizing cumulative profit
- local increases
- stock buy and sell

→ think Greedy

## Edge Cases
- Only one day
- Prices always decreasing
- Prices always increasing
- All prices equal

## Complexity
Time: O(n)

Space: O(1)

## Related Problems
- Best Time to Buy and Sell Stock
- Best Time to Buy and Sell Stock III
- Best Time to Buy and Sell Stock IV
- Best Time to Buy and Sell Stock with Cooldown