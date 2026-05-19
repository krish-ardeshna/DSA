# Minimum Common Value

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-common-value/  
Difficulty: Easy  
Pattern: Two Pointers

## What I understood
We need to find the smallest value present in both sorted arrays.

Since both arrays are already sorted,
we can avoid checking every pair.

## Idea
Use two pointers:
- one for nums1
- one for nums2

Compare elements:
- if equal → common value found
- move the pointer pointing to smaller value

This gradually aligns both arrays.

## Approach
- Initialize two pointers:
  - i for nums1
  - j for nums2
- Traverse both arrays together
- Compare current elements
- Move smaller pointer forward
- Return first common value found

## Key Observation
Because arrays are sorted,
smaller values can never match larger values later unless moved forward.

That allows linear traversal without nested loops.

## When to use this
If the problem involves:
- two sorted arrays
- common elements
- merging-like traversal

→ think two pointers

## Edge Cases
- No common value
- Same arrays
- One array much smaller than other

## Complexity
Time: O(n + m)  
Space: O(1)

## Related Problems
- Merge Sorted Array
- Intersection of Two Arrays
- Remove Duplicates from Sorted Array