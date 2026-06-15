# Delete the Middle Node of a Linked List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/  
Difficulty: Medium  
Pattern: Linked List / Fast & Slow Pointer

## What I understood
We are given the head of a linked list.

We need to delete the middle node and return the modified list.

The middle node is the ⌊n / 2⌋th node using 0-based indexing.

Example:

1 → 3 → 4 → 7 → 1 → 2 → 6

Middle node = 7

Answer:

1 → 3 → 4 → 1 → 2 → 6

## Idea
Use two pointers:

- slow moves one step at a time
- fast moves two steps at a time

When fast reaches the end:
- slow will be at the middle node

Keep track of the node before slow so that the middle node can be removed.

## Approach
- Handle the single-node case
- Initialize slow and fast pointers
- Maintain a previous pointer
- Move:
  - slow by one step
  - fast by two steps
- When traversal ends:
  - slow points to the middle node
  - prev points to the node before it
- Remove the middle node
- Return the head

## Key Observation
When one pointer moves twice as fast as the other, the slower pointer reaches the middle when the faster pointer reaches the end.

## When to use this
If the problem involves:
- finding the middle of a linked list
- deleting the middle node
- two-speed traversal

→ think fast and slow pointers

## Edge Cases
- Single node list
- Two node list
- Odd length list
- Even length list

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Middle of the Linked List
- Linked List Cycle
- Palindrome Linked List
- Remove Nth Node From End of List