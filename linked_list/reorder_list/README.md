# Reorder List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/reorder-list/  
Difficulty: Medium  
Pattern: Linked List

## What I understood
We are given the head of a singly linked list.

We need to reorder it in the following pattern:

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 ...

The node values cannot be modified. Only the links between nodes can be changed.

Example:

head = [1,2,3,4,5]

Output = [1,5,2,4,3]

## Idea
Break the problem into three steps:

- Find the middle of the linked list.
- Reverse the second half.
- Merge the first half and reversed second half alternately.

Each step is performed in-place using pointer manipulation.

## Approach
- Find the middle using fast and slow pointers
- Split the list into two halves
- Reverse the second half
- Merge both halves alternately
- Finish when all nodes are connected

## Key Observation
After reversing the second half, the required order can be obtained simply by alternating nodes from the first and second halves.

This avoids using any extra data structure.

## When to use this
If the problem involves:
- rearranging a linked list
- reversing part of a list
- alternating node connections

→ think find middle + reverse + merge

## Edge Cases
- Empty list
- Single node
- Two node list
- Even length list
- Odd length list

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Reverse Linked List
- Palindrome Linked List
- Rotate List
- Reverse Linked List II