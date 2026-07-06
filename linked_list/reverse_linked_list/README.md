# Reverse Linked List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/reverse-linked-list/  
Difficulty: Easy  
Pattern: Linked List

## What I understood
We are given the head of a singly linked list.

We need to reverse the linked list and return the new head.

Example:

head = [1,2,3,4,5]

Output = [5,4,3,2,1]

## Idea
Traverse the linked list while reversing the direction of each pointer.

Maintain three pointers:

- prev
- curr
- nextTemp

At each step:
- save the next node
- reverse the current link
- move all pointers forward

## Approach
- Initialize prev as nullptr
- Initialize curr as head
- While curr is not nullptr:
  - store the next node
  - reverse the current node's pointer
  - move prev forward
  - move curr forward
- Return prev as the new head

## Key Observation
While reversing a linked list, the reference to the next node must be saved before changing the current node's next pointer.

Otherwise, the remaining list would be lost.

## When to use this
If the problem involves:
- reversing a linked list
- pointer manipulation
- in-place linked list modification

→ think three pointers

## Edge Cases
- Empty list
- Single node list
- Two node list
- Long linked list

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Reverse Linked List II
- Palindrome Linked List
- Reverse Nodes in k-Group
- Swap Nodes in Pairs