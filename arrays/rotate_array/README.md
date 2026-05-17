# Rotate Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/rotate-array/  
Difficulty: Medium  
Pattern: Arrays / Reversal Technique

## What I understood
We need to rotate the array to the right by k positions.

Instead of shifting elements one by one,
the array can be rearranged efficiently using reversals.

## Idea

### Approach 1
- Reverse first part
- Reverse second part
- Reverse complete array

### Approach 2
- Reverse complete array first
- Reverse first k elements
- Reverse remaining elements

Both approaches achieve rotation in-place.

## Approach
- Calculate effective rotation:
  k = k % n
- Perform reversals in correct order
- Final arrangement becomes rotated array

## Key Observation
Reversing sections of the array changes element positions in a controlled way.

Using three reversals avoids extra space and repeated shifting.

## When to use this
If the problem involves:
- array rotation
- in-place rearrangement
- reversing sections of arrays

→ think reversal technique

## Edge Cases
- k > array size
- k = 0
- Single element array

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Rotate Image
- Reverse String
- Move Zeroes