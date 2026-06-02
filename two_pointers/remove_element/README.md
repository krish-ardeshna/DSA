# Remove Element

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-element/  
Difficulty: Easy  
Pattern: Two Pointers

## What I understood
We need to remove all occurrences of a given value from the array in-place.

The relative order of the remaining elements should stay the same.

## Idea
Use one pointer to traverse the array and another pointer to track where the next valid element should be placed.

Whenever we find an element different from the target value:
- place it at the write position
- move the write pointer forward

## Approach
- Initialize k = 0
- Traverse the array
- If current element is not equal to val:
  - place it at nums[k]
  - increment k
- Return k

## Key Observation
We do not need to physically delete elements.

We only need to move valid elements to the front and keep track of the new length.

## When to use this
If the problem involves:
- in-place filtering
- removing specific values
- maintaining order

→ think two pointers

## Edge Cases
- Empty array
- All elements equal to val
- No element equal to val

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Remove Duplicates from Sorted Array
- Move Zeroes
- Remove Duplicates from Sorted Array II