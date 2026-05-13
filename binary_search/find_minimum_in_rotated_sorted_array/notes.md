# Find Minimum in Rotated Sorted Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/  
Difficulty: Medium  
Pattern: Binary Search

## What I understood
The array was originally sorted in increasing order, but then rotated at some pivot.

Even after rotation, one side of the array still remains sorted.  
That property can be used to eliminate half of the search space.

## Idea
Compare the middle element with the last element:
- if nums[mid] > nums[high]
  → minimum lies in right half
- otherwise
  → minimum lies in left half (including mid)

Instead of checking every element, we keep shrinking the range using binary search.

## Approach
- Initialize low and high
- Run binary search while low < high
- Find middle element
- Compare nums[mid] with nums[high]
- Move search space accordingly
- At the end, low points to minimum element

## Key Observation
Even though the array is rotated, one half always stays sorted.

That makes binary search possible.

## When to use this
If the problem involves:
- rotated sorted arrays
- finding pivot/minimum
- searching in partially sorted structures

→ think modified binary search

## Edge Cases
- Array not rotated
- Single element array
- Minimum element at index 0

## Complexity
Time: O(log n)  
Space: O(1)

## Related Problems
- Search in Rotated Sorted Array
- Find Peak Element
- Search Insert Position