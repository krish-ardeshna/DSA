# Two Sum II - Input Array Is Sorted

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/  
Difficulty: Medium  
Pattern: Two Pointers

## What I understood
We are given a sorted array and a target value. Find two numbers whose sum equals the target and return their 1-based indices.

Example:

numbers = [2,7,11,15]

target = 9

Output = [1,2]

## Idea
Since the array is sorted, place one pointer at the beginning and another at the end.

If the current sum is:
- equal to the target, return the indices.
- smaller than the target, move the left pointer.
- greater than the target, move the right pointer.

## Approach
- Initialize two pointers at both ends.
- Compute their sum.
- Move the appropriate pointer based on the comparison with the target.
- Return the 1-based indices once the target is found.

## Key Observation
The sorted order allows us to eliminate one side of the search space after each comparison, making two pointers optimal.

## When to use this
If the problem involves:
- sorted array
- pair sum
- two pointers

→ think Two Pointers

## Edge Cases
- Two elements only
- Negative numbers
- Duplicate values
- Target formed by first and last element

## Complexity
Time: O(n)

Space: O(1)

## Related Problems
- Two Sum
- 3Sum
- 4Sum
- Container With Most Water