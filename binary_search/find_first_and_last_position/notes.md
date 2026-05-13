# Find First and Last Position of Element in Sorted Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/  
Difficulty: Medium  
Pattern: Binary Search

## What I understood
We need to find:
- first occurrence
- last occurrence

of a target element in a sorted array.

A normal binary search can find the target, but here we also need boundary positions.

## Idea

### Approach 1 (Brute Force)
Traverse the entire array and store indices where target appears.

Then:
- first position = first index
- last position = last index

Simple but inefficient.

### Approach 2 (Binary Search)
Since the array is sorted, binary search can be modified:
- for first occurrence:
  keep searching on left side
- for last occurrence:
  keep searching on right side

This helps find boundaries efficiently.

## Approach
- Run binary search twice:
  - once for first occurrence
  - once for last occurrence
- Update answer whenever target is found
- Continue searching instead of stopping immediately

## Key Observation
Finding the target is not enough.

The important part is:
- finding the leftmost occurrence
- finding the rightmost occurrence

## When to use this
If the problem involves:
- sorted arrays
- first/last occurrence
- lower bound or upper bound

→ think modified binary search

## Edge Cases
- Target not present
- Single element array
- All elements same
- Target appears once

## Complexity

### Brute Force
Time: O(n)  
Space: O(n)

### Binary Search
Time: O(log n)  
Space: O(1)

## Related Problems
- Binary Search
- Search Insert Position
- Find Minimum in Rotated Sorted Array