# Partition List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/partition-list/  
Difficulty: Medium  
Pattern: Linked List

## What I understood
We are given the head of a linked list and an integer x.

We need to rearrange the list so that:

- all nodes with values less than x appear first
- all nodes with values greater than or equal to x appear afterwards

The relative order of nodes in each partition must remain the same.

Example:

head = [1,4,3,2,5,2]

x = 3

Output = [1,2,2,4,3,5]

## Idea

### Approach 1 (Store Values and Rewrite List)
Store all node values in a vector.

Create another vector by:
- adding values smaller than x
- then adding values greater than or equal to x

Finally, overwrite the linked list with the reordered values.

### Approach 2 (Two Dummy Lists)
Create two separate linked lists:

- one for nodes smaller than x
- one for nodes greater than or equal to x

Traverse the original list and append each node to the appropriate list.

Finally, connect both lists.

## Approach
- Create two dummy nodes
- Traverse the linked list
- Append nodes to either the "before" list or the "after" list
- Connect both lists
- Return the head of the combined list

## Key Observation
Using two dummy nodes preserves the relative order of nodes while avoiding complicated pointer updates.

No new data nodes need to be created.

## When to use this
If the problem involves:
- partitioning a linked list
- preserving relative order
- pointer manipulation

→ think two dummy lists

## Edge Cases
- Empty list
- All nodes smaller than x
- All nodes greater than or equal to x
- Duplicate values
- x not present in the list

## Complexity

### Approach 1
Time: O(n)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(1)

## Related Problems
- Merge Two Sorted Lists
- Sort List
- Reorder List
- Remove Duplicates from Sorted List