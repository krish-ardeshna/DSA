# Middle of the Linked List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/  
Difficulty: Easy  
Pattern: Linked List / Fast & Slow Pointer

## What I understood
We are given the head of a singly linked list.

We need to return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example:

head = [1,2,3,4,5]

Output = [3,4,5]

## Idea
Use two pointers:

- slow moves one node at a time
- fast moves two nodes at a time

When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.

For even-length lists, this naturally returns the second middle node.

## Approach
- Initialize slow and fast pointers at the head
- Move:
  - slow by one step
  - fast by two steps
- Continue until fast reaches the end
- Return the slow pointer

## Key Observation
Since the fast pointer moves twice as quickly as the slow pointer, the slow pointer reaches the middle when the fast pointer reaches the end of the list.

## When to use this
If the problem involves:
- finding the middle of a linked list
- two-speed traversal
- single-pass linked list problems

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
- Delete the Middle Node of a Linked List
- Remove Nth Node From End of List
- Linked List Cycle
- Palindrome Linked List