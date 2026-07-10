# Sort Colors

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sort-colors/  
Difficulty: Medium  
Pattern: Arrays / Two Pointers

## What I understood
We are given an array containing only:

- 0
- 1
- 2

We need to sort the array in-place without using the library sort function.

Example:

nums = [2,0,2,1,1,0]

Output = [0,0,1,1,2,2]

## Idea

### Approach 1 (Counting Sort)
Count the occurrences of:

- 0
- 1
- 2

Then overwrite the array using these counts.

### Approach 2 (Dutch National Flag Algorithm)
Maintain three pointers:

- low → next position for 0
- mid → current element
- high → next position for 2

Traverse the array once:

- swap 0 to the front
- keep 1 in the middle
- swap 2 to the end

## Approach
- Initialize low, mid and high
- Traverse while mid ≤ high
- If current element is:
  - 0 → swap with low
  - 1 → move mid
  - 2 → swap with high
- Continue until the array is sorted

## Key Observation
Since there are only three distinct values, we can partition the array into three regions and sort it in a single traversal.

The Dutch National Flag Algorithm achieves this in-place.

## When to use this
If the problem involves:
- three distinct values
- in-place partitioning
- one-pass sorting
- multiple pointers

→ think Dutch National Flag Algorithm

## Edge Cases
- Empty array
- Single element
- All elements are the same
- Already sorted array
- Reverse sorted array

## Complexity

### Approach 1
Time: O(n)  
Space: O(1)

### Approach 2
Time: O(n)  
Space: O(1)

## Related Problems
- Partition Array According to Given Pivot
- Move Zeroes
- Remove Element
- Wiggle Sort