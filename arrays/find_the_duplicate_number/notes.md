# Find the Duplicate Number

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-duplicate-number/  
Difficulty: Medium  
Pattern: Hashing / Floyd's Cycle Detection

## What I understood
The array contains:
- numbers from 1 to n
- one duplicate number

The duplicate may appear multiple times.

## Idea

### Approach 1 (Hash Map)
Store frequencies using a hash map.
If a number appears more than once,
return it.

Simple and easy to understand.

### Approach 2 (Floyd's Cycle Detection)
Treat the array like a linked list:
- value = next pointer

Because one number repeats,
a cycle forms.

Use:
- slow pointer
- fast pointer

to detect the cycle and find duplicate number.

## Approach
- Hashing:
  - store frequency
  - return repeated value
- Floyd's Algorithm:
  - move slow by 1 step
  - move fast by 2 steps
  - detect meeting point
  - reset slow pointer
  - move both one step
  - meeting point becomes duplicate number

## Key Observation
The array behaves like a linked list where repeated values create a cycle.

That allows cycle detection techniques to work even without actual linked list nodes.

## When to use this
If the problem involves:
- duplicate numbers
- restricted space
- cycle-like traversal

→ think Floyd’s Cycle Detection

## Edge Cases
- Duplicate appears multiple times
- Small array size
- Duplicate at beginning

## Complexity

### Hash Map
Time: O(n)  
Space: O(n)

### Floyd's Cycle Detection
Time: O(n)  
Space: O(1)

## Related Problems
- Linked List Cycle
- Find Missing Number
- Happy Number