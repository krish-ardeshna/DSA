# Find Peak Element

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-peak-element/  
Difficulty: Medium  
Pattern: Binary Search

## What I understood
A peak element is an element greater than its neighbors.

We need to return the index of any peak element.

The array does not need to be fully sorted,
but the increasing/decreasing pattern helps eliminate half of the search space.

## Idea
Check the relationship between:
nums[mid] and nums[mid + 1]

- if nums[mid] < nums[mid + 1]
  → peak lies on right side
- otherwise
  → peak lies on left side (including mid)

This allows binary search without needing a fully sorted array.

## Approach
- Initialize low and high
- Run binary search while low < high
- Compare nums[mid] with nums[mid + 1]
- Move toward the side that must contain a peak
- Return final index

## Key Observation
If the array is increasing at mid,
a peak must exist on the right side.

If it is decreasing,
a peak must exist on the left side.

## When to use this
If the problem involves:
- local maximum/minimum
- mountain-like patterns
- directional elimination

→ think binary search on slope behavior

## Edge Cases
- Single element array
- Peak at beginning
- Peak at end

## Complexity
Time: O(log n)  
Space: O(1)

## Related Problems
- Find Minimum in Rotated Sorted Array
- Peak Index in Mountain Array
- Search in Rotated Sorted Array