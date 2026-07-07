# Rotate List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/rotate-list/  
Difficulty: Medium  
Pattern: Linked List

## What I understood
We are given the head of a linked list and an integer k.

We need to rotate the list to the right by k positions.

Example:

head = [1,2,3,4,5]

k = 2

Output = [4,5,1,2,3]

## Idea
First find the length of the linked list.

Since rotating by the list length results in the same list, compute:

k %= length

Connect the tail to the head to form a circular linked list.

Then locate the new tail and break the circle to obtain the rotated list.

## Approach
- Find the length of the linked list
- Compute k modulo the length
- If k is 0, return the original list
- Connect the tail to the head
- Find the new tail
- Set the next node as the new head
- Break the circular link
- Return the new head

## Key Observation
Forming a circular linked list avoids repeatedly rotating the list.

After making the list circular, the problem reduces to finding the correct breaking point.

## When to use this
If the problem involves:
- rotating a linked list
- circular linked lists
- pointer manipulation

→ think circular linked list

## Edge Cases
- Empty list
- Single node list
- k = 0
- k greater than the list length
- k is a multiple of the list length

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Reverse Linked List
- Rotate Array
- Split Linked List in Parts
- Remove Nth Node From End of List