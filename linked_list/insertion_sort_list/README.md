# Insertion Sort List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/insertion-sort-list/  
Difficulty: Medium  
Pattern: Linked List / Sorting

## What I understood
We are given the head of a linked list.

We need to sort the linked list using the insertion sort algorithm.

Example:

head = [4,2,1,3]

Output = [1,2,3,4]

## Idea

### Approach 1 (Store Values and Sort)
Copy all node values into a vector.

Sort the vector and write the sorted values back into the linked list.

This is simple but does not perform insertion sort on the linked list itself.

### Approach 2 (Insertion Sort on Linked List)
Maintain a sorted portion of the linked list.

For every node:
- find its correct position in the sorted list
- insert it there

Use a dummy node to simplify insertion at the beginning.

## Approach
- Create a dummy node
- Traverse the original list
- Find the correct insertion position
- Insert the current node
- Continue until all nodes are processed
- Return the sorted list

## Key Observation
Insertion Sort works well on linked lists because inserting a node only requires updating pointers.

Unlike arrays, no element shifting is required.

## When to use this
If the problem involves:
- sorting linked lists
- repeated insertion into a sorted sequence
- pointer manipulation

→ think insertion sort with a dummy node

## Edge Cases
- Empty list
- Single node
- Already sorted list
- Reverse sorted list
- Duplicate values

## Complexity

### Approach 1
Time: O(n log n)  
Space: O(n)

### Approach 2
Time: O(n²)  
Space: O(1)

## Related Problems
- Sort List
- Merge Two Sorted Lists
- Merge k Sorted Lists
- Remove Duplicates from Sorted List