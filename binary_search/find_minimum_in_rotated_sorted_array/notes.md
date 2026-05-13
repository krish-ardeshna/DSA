# Find Minimum in Rotated Sorted Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/  
Difficulty: Medium  
Pattern: Binary Search

## What I understood
The array was originally sorted but then rotated.

We need to find the minimum element in O(log n) time.

## Idea
In a rotated sorted array:
- one half is always sorted
- the minimum lies in the unsorted half

Compare middle element with high pointer:
- if nums[mid] > nums[high]
  → minimum is in right half
- otherwise
  → minimum is in left half (including mid)

## Approach
- Initialize low and high
- Run binary search while low < high
- Compare nums[mid] with nums[high]
- Narrow search space accordingly
- Return nums[low]

## Mistake I made
Initially tried checking every element linearly, which ignores the sorted structure.

## When to use this
If the problem involves:
- rotated sorted arrays
- finding pivot/minimum
- sorted structure with rotation

→ think modified binary search

## Edge Cases
- Array not rotated
- Array with one element
- Minimum at first index

## Complexity
Time: O(log n)  
Space: O(1)