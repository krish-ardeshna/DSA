# Koko Eating Bananas

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/koko-eating-bananas/  
Difficulty: Medium  
Pattern: Binary Search on Answer

## What I understood
Koko has several piles of bananas.

She can choose one pile per hour and eat at a fixed speed.

We need to find the minimum eating speed such that all bananas are eaten within h hours.

Example:

piles = [3,6,7,11]

h = 8

Output = 4

## Idea
The answer is not a pile index but an eating speed.

The minimum possible speed is 1.

The maximum possible speed is the largest pile.

Use binary search on this range.

For every candidate speed:
- calculate the total hours required
- if the hours are within h, try a smaller speed
- otherwise, increase the speed

## Approach
- Set low = 1
- Set high = maximum pile size
- Binary search on the eating speed
- Check whether the current speed is sufficient
- Return the minimum valid speed

## Key Observation
As the eating speed increases, the total hours required never increase.

This monotonic property makes Binary Search on Answer applicable.

## When to use this
If the problem involves:
- minimizing or maximizing a value
- monotonic search space
- feasibility checking

→ think Binary Search on Answer

## Edge Cases
- Single pile
- h equals number of piles
- Very large pile sizes
- Minimum possible speed is 1

## Complexity
Time: O(n log M)

where:
- n = number of piles
- M = maximum pile size

Space: O(1)

## Related Problems
- Capacity To Ship Packages Within D Days
- Split Array Largest Sum
- Minimum Number of Days to Make m Bouquets
- Magnetic Force Between Two Balls