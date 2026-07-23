# Minimum Size Subarray Sum

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/  
Difficulty: Medium  
Pattern: Sliding Window

## What I understood
Given an array of positive integers and a target, find the minimum length of a contiguous subarray whose sum is at least the target. Return 0 if no such subarray exists.

Example:

nums = [2,3,1,2,4,3]

target = 7

Output = 2

## Idea
Maintain a sliding window and keep expanding it until the sum reaches the target. Then shrink the window from the left to find the smallest valid window.

## Approach
- Initialize two pointers and the current sum.
- Expand the right pointer while adding elements.
- When the sum becomes at least the target, update the answer.
- Shrink the window from the left while the condition remains true.
- Return 0 if no valid subarray is found.

## Key Observation
Since all numbers are positive, increasing the window always increases the sum and shrinking always decreases it. This makes the sliding window approach valid.

## When to use this
If the problem involves:
- positive numbers
- contiguous subarray
- minimum or maximum window

→ think Sliding Window

## Edge Cases
- No valid subarray
- Single element equals target
- Entire array needed
- Single element array

## Complexity
Time: O(n)

Space: O(1)

## Related Problems
- Longest Substring Without Repeating Characters
- Minimum Window Substring
- Subarray Product Less Than K
- Maximum Average Subarray I