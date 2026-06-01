# Minimum Cost of Buying Candies With Discount

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/  
Difficulty: Easy  
Pattern: Greedy

## What I understood
For every three candies purchased:
- pay for the two most expensive candies
- get the cheapest candy for free

The goal is to minimize the total amount paid.

## Idea
To maximize the discount,
the free candy should be as expensive as possible.

Sorting candies in descending order naturally groups:
- two expensive candies (paid)
- one cheaper candy (free)

## Approach
- Sort candies in descending order
- Traverse the array
- For every group of three:
  - add first candy
  - add second candy
  - skip third candy
- Return total cost

## Key Observation
The discount depends on the cheapest candy among every group of three.

By sorting in descending order, we ensure the free candy is as valuable as possible.

## When to use this
If the problem involves:
- maximizing discounts
- grouping items
- choosing an optimal order

→ think greedy after sorting

## Edge Cases
- Less than three candies
- Exactly three candies
- Multiple candies with same cost

## Complexity
Time: O(n log n)
- Sorting dominates

Space: O(1)
- Ignoring sorting space

## Related Problems
- Destroying Asteroids
- Assign Cookies
- Maximum Units on a Truck