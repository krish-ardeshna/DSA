# Find Minimum in Rotated Sorted Array II

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/  
Difficulty: Hard  
Pattern: Binary Search

## What I understood
This problem is similar to the rotated sorted array minimum problem,
but now duplicate values are also present.

Duplicates make binary search slightly harder because:
nums[mid] and nums[high] can become equal.

## Idea
Use binary search to eliminate half of the array.

Cases:
- if nums[mid] > nums[high]
  → minimum lies in right half
- if nums[mid] < nums[high]
  → minimum lies in left half
- if nums[mid] == nums[high]
  → cannot decide safely, reduce search space by one

## Approach
- Initialize low and high
- Run binary search while low < high
- Compare nums[mid] with nums[high]
- Handle three cases accordingly
- Return nums[low]

## Key Observation
Duplicates remove the guarantee of identifying the sorted side immediately.

In ambiguous cases,
we shrink the search space carefully using high--.

## When to use this
If the problem involves:
- rotated sorted arrays
- duplicate elements
- ambiguous binary search conditions

→ think modified binary search with duplicate handling

## Edge Cases
- Array with all same elements
- Array not rotated
- Single element array

## Complexity
Average: O(log n)  
Worst Case: O(n)  
Space: O(1)

## Related Problems
- Find Minimum in Rotated Sorted Array
- Search in Rotated Sorted Array
- Find Peak Element