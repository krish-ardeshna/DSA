# Remove Duplicates from Sorted List II

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/  
Difficulty: Medium  
Pattern: Linked List

## What I understood
We are given the head of a sorted linked list.

We need to remove all nodes that have duplicate values, leaving only the distinct values in the original list.

Unlike the previous problem, duplicate values should be removed completely instead of keeping one occurrence.

Example:

head = [1,2,3,3,4,4,5]

Output = [1,2,5]

## Idea
Use a dummy node before the head to simplify deletion, especially when the first few nodes are duplicates.

Traverse the list using two pointers:

- prev points to the last confirmed unique node
- curr explores the current node

Whenever duplicate values are found:
- skip the entire duplicate group
- connect prev directly to the next unique node

## Approach
- Create a dummy node before the head
- Initialize prev and curr pointers
- Traverse the linked list
- Detect consecutive duplicate values
- Skip every node having the duplicate value
- Connect prev to the next unique node
- Otherwise move both pointers forward
- Return dummy.next

## Key Observation
Since the list is sorted, duplicate values always appear consecutively.

This allows us to skip an entire duplicate group in one traversal.

## When to use this
If the problem involves:
- sorted linked lists
- removing all duplicate occurrences
- in-place linked list modification

→ think dummy node with pointer manipulation

## Edge Cases
- Empty list
- Single node list
- All nodes are duplicates
- Duplicates at the beginning
- Duplicates at the end
- No duplicates

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Remove Duplicates from Sorted List
- Remove Duplicates from Sorted Array II
- Remove Linked List Elements
- Delete the Middle Node of a Linked List