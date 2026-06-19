# Find the Highest Altitude

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-highest-altitude/  
Difficulty: Easy  
Pattern: Prefix Sum

## What I understood
A biker starts at altitude 0.

The array gain represents the change in altitude between consecutive points.

We need to find the highest altitude reached during the trip.

Example:

gain = [-5,1,5,0,-7]

Altitudes:

0 → -5 → -4 → 1 → 1 → -6

Answer = 1

## Idea
Maintain the current altitude while traversing the gain array.

At each step:
- update the current altitude
- update the maximum altitude reached so far

This is essentially a running prefix sum problem.

## Approach
- Initialize current altitude as 0
- Initialize highest altitude as 0
- Traverse the gain array
- Add the current gain to the current altitude
- Update the highest altitude
- Return the highest altitude

## Key Observation
The altitude at any point is simply the prefix sum of all gains encountered so far.

Therefore, the highest altitude is the maximum prefix sum during traversal.

## When to use this
If the problem involves:
- cumulative sums
- running totals
- tracking maximum value during traversal

→ think prefix sum

## Edge Cases
- All gains are negative
- All gains are positive
- Single element array
- Highest altitude is the starting altitude (0)

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Running Sum of 1d Array
- Find Pivot Index
- Range Sum Query
- Maximum Subarray