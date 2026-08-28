# Delete Node in a Linked List
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/delete-node-in-a-linked-list/  
Difficulty: Medium  
Pattern: Linked List - Value Copy Trick

## What I understood
Given direct access ONLY to the node that needs to be deleted (not the head, not the previous node), remove it from the linked list. Guaranteed: the node to delete is not the last node in the list.

## Example
```
Input
head = [4,5,1,9], node = 5 (the node with value 5)
Output
[4,1,9]
```
```
Input
head = [4,5,1,9], node = 1 (the node with value 1)
Output
[4,5,9]
```

## Idea
Since the previous node isn't accessible, physically unlinking the given node from the list (which normally requires the predecessor) isn't directly possible. Instead, sidestep the constraint: copy the next node's value into the current node, then skip over the next node — this makes the current node effectively "become" its successor, so the original node's identity/position is deleted in terms of list content and structure.

## Approach: Copy Next Node's Value, Skip Next Node
- Overwrite `node->val` with `node->next->val`.
- Relink `node->next` to `node->next->next`, bypassing the (now duplicate-valued) next node.
- Net effect: the original node's value is gone, list length decreases by 1, list content matches the intended deletion.

## Key Observation
This trick only works because the last node is guaranteed to never be the target — if it were, there'd be no next node to copy from, making the trick impossible without predecessor access.

## When to use this
If problem involves:
- Deleting/modifying a node with only a direct reference to that node itself (no head or predecessor access)
→ Think **copy the next node's data forward, then bypass the next node**, effectively deleting the successor's node object while preserving the target's logical value/position removal.

## Edge Cases
- Node to delete is the second-to-last node (still has a valid next to copy from).
- List with only 2 nodes, deleting the first one.
- Cannot handle deleting the actual last node with this trick (problem guarantees this won't happen).

## Complexity
### Approach
Time: **O(1)**          
Space: **O(1)**

where:
- Operation is constant time regardless of list length, since no traversal is needed

## Related Problems
- Remove Linked List Elements
- Delete the Middle Node of a Linked List
- Remove Nth Node From End of List
- Merge Two Sorted Lists