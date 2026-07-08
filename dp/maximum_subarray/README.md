# Maximum Subarray

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-subarray/  
Difficulty: Medium  
Pattern: Dynamic Programming / Kadane's Algorithm

## What I understood
We are given an integer array.

We need to find the contiguous subarray that has the largest sum and return that sum.

Example:

nums = [-2,1,-3,4,-1,2,1,-5,4]

Output = 6

because the subarray:

[4,-1,2,1]

has the maximum sum.

## Idea
Maintain the maximum subarray sum ending at the current index.

For every element:
- either start a new subarray from the current element
- or extend the previous subarray

Keep updating the overall maximum sum.

## Approach
- Initialize the current sum and maximum sum with the first element
- Traverse the array
- Update the current sum
- Update the maximum sum
- Return the final answer

## Key Observation
If the current subarray sum becomes worse than the current element itself, it is better to start a new subarray.

This is the core idea behind Kadane's Algorithm.

## When to use this
If the problem involves:
- maximum contiguous sum
- subarrays
- dynamic programming
- choosing between extending or restarting

→ think Kadane's Algorithm

## Edge Cases
- Single element array
- All negative numbers
- All positive numbers
- Array containing zeros

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Maximum Product Subarray
- Maximum Sum Circular Subarray
- Best Time to Buy and Sell Stock
- House Robber