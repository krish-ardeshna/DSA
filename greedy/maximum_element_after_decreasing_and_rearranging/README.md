# Maximum Element After Decreasing and Rearranging

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/  
Difficulty: Medium  
Pattern: Greedy / Sorting

## What I understood
We are given an array of positive integers.

We may:
- rearrange the elements in any order
- decrease any element any number of times

The final array must satisfy:

- the first element is 1
- the absolute difference between adjacent elements is at most 1

We need to maximize the largest element in the final array.

Example:

arr = [2,2,1,2,1]

Output = 2

## Idea
Sort the array first.

Make the first element equal to 1.

For every remaining element:
- if it is greater than the previous element + 1, reduce it to previous + 1
- otherwise keep it unchanged

This greedily builds the largest possible valid sequence while satisfying the given conditions.

## Approach
- Sort the array
- Set the first element to 1
- Traverse the remaining elements
- If the current element is too large:
  - reduce it to previous element + 1
- Return the last element of the array

## Key Observation
After sorting, every element should be as large as possible while remaining at most one greater than the previous element.

Reducing only the necessary elements guarantees the maximum possible final value.

## When to use this
If the problem involves:
- maximizing an answer under constraints
- sorting before greedy processing
- adjusting adjacent values

→ think greedy after sorting

## Edge Cases
- Single element array
- All elements equal
- Already valid array
- Large gaps between consecutive elements

## Complexity
Time: O(n log n)  
Space: O(1)

## Related Problems
- Non-decreasing Array
- Assign Cookies
- Wiggle Subsequence
- Minimum Number of Arrows to Burst Balloons