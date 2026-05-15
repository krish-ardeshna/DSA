# Best Time to Buy and Sell Stock

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/  
Difficulty: Easy  
Pattern: Arrays / Greedy

## What I understood
We need to maximize profit by:
- buying stock on one day
- selling it on a later day

Only one transaction is allowed.

## Idea
Keep track of the minimum stock price seen so far.

For every day:
- calculate possible profit
- update maximum profit if better

## Approach
- Initialize:
  - minimum price
  - maximum profit
- Traverse array
- Update minimum price
- Calculate current profit:
  prices[i] - minimum price
- Update answer

## Key Observation
The best selling day depends on the minimum buying price seen before it.

Instead of checking every pair,
we continuously maintain the best buying opportunity.

## When to use this
If the problem involves:
- maximizing profit
- maintaining minimum/maximum values
- one-pass optimization

→ think greedy traversal

## Edge Cases
- Prices always decreasing
- Single day price
- Profit becomes 0

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Best Time to Buy and Sell Stock II
- Maximum Subarray
- Kadane’s Algorithm