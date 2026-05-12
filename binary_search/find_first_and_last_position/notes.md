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

## Idea

### Approach 1 (Brute Force)
Traverse the array and store every index where target appears.

Then:
- first occurrence = first index
- last occurrence = last index

This works but takes O(n).

### Approach 2 (Binary Search)
Since the array is sorted, binary search can be used.

For first occurrence:
- continue searching left even after finding target

For last occurrence:
- continue searching right even after finding target

## Approach
- Run binary search twice:
  - once for first position
  - once for last position
- Update answer whenever target is found

## Mistake I made
Initially stopped binary search immediately after finding target, which misses boundary positions.

## When to use this
If the problem involves:
- sorted arrays
- first/last occurrence
- lower/upper bounds

→ think modified binary search

## Edge Cases
- Target not present
- Single element array
- All elements same

## Complexity

### Brute Force
Time: O(n)  
Space: O(n)

### Binary Search
Time: O(log n)  
Space: O(1)