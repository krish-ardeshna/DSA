# Search in Rotated Sorted Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/  
Difficulty: Medium  
Pattern: Binary Search

## What I understood
The array is originally sorted in ascending order but is rotated at an unknown pivot.

We need to find the index of the target value.

If the target is not present, return -1.

Example:

[4,5,6,7,0,1,2], target = 0

Answer = 4

## Idea

### Approach 1 (Linear Search)
Traverse the entire array.

For every element:
- compare with target
- return index if found

If traversal finishes, return -1.

### Approach 2 (Modified Binary Search)
Use Binary Search while identifying which half of the array is sorted.

At every step:
- find middle element
- determine the sorted half
- check whether target lies inside that half
- discard the other half

This allows us to reduce the search space by half every time.

## Approach
- Initialize low and high pointers
- Find middle element
- If target is found, return index
- Identify the sorted half
- Check whether target belongs to that half
- Move low or high accordingly
- Continue until target is found or search space becomes empty

## Key Observation
Even after rotation, at least one half of the array remains sorted.

Using this property, we can decide which half can be safely ignored.

## When to use this
If the problem involves:
- rotated sorted arrays
- searching for an element
- logarithmic time requirements

→ think modified binary search

## Edge Cases
- Single element array
- Array not rotated
- Target is first element
- Target is last element
- Target does not exist

## Complexity

### Approach 1
Time: O(n)  
Space: O(1)

### Approach 2
Time: O(log n)  
Space: O(1)

## Related Problems
- Find Minimum in Rotated Sorted Array
- Search in Rotated Sorted Array II
- Binary Search
- Find Peak Element