# Remove Duplicates from Sorted List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/  
Difficulty: Easy  
Pattern: Linked List

## What I understood
We are given the head of a sorted linked list.

We need to remove all duplicate nodes so that each value appears only once.

The linked list should remain sorted.

Example:

head = [1,1,2,3,3]

Output = [1,2,3]

## Idea
Since the linked list is already sorted, duplicate values always appear next to each other.

Traverse the list and compare each node with its next node.

If both values are the same:
- skip the duplicate node

Otherwise:
- move to the next node

## Approach
- Start from the head node
- Traverse the linked list
- Compare the current node with the next node
- If both values are equal:
  - remove the duplicate by updating the next pointer
- Otherwise:
  - move to the next node
- Return the modified list

## Key Observation
The sorted property guarantees that all duplicate nodes are adjacent.

Therefore, we only need to compare each node with its immediate next node.

## When to use this
If the problem involves:
- sorted linked lists
- removing duplicates
- in-place linked list modification

→ think pointer manipulation

## Edge Cases
- Empty list
- Single node list
- No duplicates
- All nodes have the same value
- Duplicates only at the beginning or end

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Remove Duplicates from Sorted Array
- Remove Duplicates from Sorted List II
- Delete the Middle Node of a Linked List
- Remove Linked List Elements