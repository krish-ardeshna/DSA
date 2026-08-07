# Remove Duplicates from Sorted Array II

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/  
Difficulty: Medium  
Pattern: Two Pointers

## What I understood
Given a sorted array, remove duplicates in-place such that each unique element appears at most twice. Return the new length of the array.

Example:

nums = [1,1,1,2,2,3]

Output = 5

Modified array = [1,1,2,2,3]

## Idea
Since the array is sorted, duplicates appear together.

Keep the first two elements by default. For every next element, compare it with the element two positions before the current insertion index. If they are different, include the current element.

## Approach
- If the array has at most two elements, return its size.
- Initialize the write index `k` as 2.
- Traverse the array from index 2.
- If `nums[i]` differs from `nums[k-2]`, copy it to `nums[k]`.
- Increment `k`.
- Return `k`.

## Key Observation
Comparing with `nums[k-2]` guarantees that no value is written more than twice.

## When to use this
If the problem involves:
- sorted array
- removing duplicates
- in-place modification
- limited occurrences

→ think Two Pointers

## Edge Cases
- Empty array
- One element
- Two elements
- All elements identical
- No duplicates

## Complexity
Time: O(n)

Space: O(1)

## Related Problems
- Remove Duplicates from Sorted Array
- Remove Element
- Move Zeroes
- Sort Colors