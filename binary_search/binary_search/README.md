# Binary Search

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-search/  
Difficulty: Easy  
Pattern: Binary Search

## What I understood
We are given a sorted array and a target value.

We need to find the index of the target.

If the target is not present, return -1.

Example:

nums = [-1,0,3,5,9,12]

target = 9

Output = 4

## Idea
Since the array is sorted, we can eliminate half of the search space after every comparison.

Compare the target with the middle element:
- if equal, return its index
- if smaller, search the left half
- if larger, search the right half

Repeat until the target is found or the search space becomes empty.

## Approach
- Initialize low and high pointers
- Compute the middle index
- Compare the target with the middle element
- Update the search range accordingly
- Return the index if found
- Otherwise return -1

## Key Observation
A sorted array allows us to discard half of the remaining elements after each comparison.

This reduces the search time from linear to logarithmic.

## When to use this
If the problem involves:
- searching in a sorted array
- finding an element efficiently
- repeatedly halving the search space

→ think binary search

## Edge Cases
- Empty array
- Single element array
- Target is the first element
- Target is the last element
- Target is not present

## Complexity
Time: O(log n)  
Space: O(1)

## Related Problems
- Search Insert Position
- First Bad Version
- Guess Number Higher or Lower
- Search in Rotated Sorted Array