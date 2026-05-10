# Remove Duplicates from Sorted Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/  
Difficulty: Easy  
Pattern: Two Pointers

## What I understood
The array is already sorted, so duplicate elements will always be adjacent.

We need to remove duplicates in-place and return the count of unique elements.

## Idea
Use two pointers:
- One pointer traverses the array
- Another pointer keeps track of where the next unique element should be placed

## Approach
- Start k = 1
- Traverse array from index 1
- If current element is different from previous:
  - place it at nums[k]
  - increment k
- Return k

## Mistake I made
Initially thought about using another array, but the problem asks for in-place modification.

## When to use this
If the problem involves:
- sorted arrays
- removing duplicates
- in-place updates

→ think two pointers

## Edge Cases
- Empty array
- Array with all duplicates
- Array with no duplicates

## Complexity
Time: O(n)  
Space: O(1)