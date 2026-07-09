# Search Insert Position

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/search-insert-position/  
Difficulty: Easy  
Pattern: Binary Search

## What I understood
We are given a sorted array of distinct integers and a target value.

If the target exists, return its index.

Otherwise, return the index where it should be inserted to keep the array sorted.

Example:

nums = [1,3,5,6]

target = 2

Output = 1

## Idea

### Approach 1 (Linear Search)
Traverse the array from left to right.

The first element greater than or equal to the target is the required position.

If no such element exists, insert at the end.

### Approach 2 (Binary Search)
Since the array is sorted, use binary search.

Keep narrowing the search space until the target is found.

If it is not found, the left pointer represents the correct insertion position.

## Approach
- Initialize left and right pointers
- Find the middle element
- Compare it with the target
- Move left or right accordingly
- If the target is not found, return left

## Key Observation
After binary search finishes, the left pointer always points to the correct insertion index.

No additional checks are required.

## When to use this
If the problem involves:
- sorted arrays
- searching
- insertion position
- logarithmic search

→ think Binary Search

## Edge Cases
- Empty array
- Insert at the beginning
- Insert at the end
- Target already exists
- Single element array

## Complexity

### Approach 1
Time: O(n)  
Space: O(1)

### Approach 2
Time: O(log n)  
Space: O(1)

## Related Problems
- Binary Search
- Search in Rotated Sorted Array
- First Bad Version
- Guess Number Higher or Lower