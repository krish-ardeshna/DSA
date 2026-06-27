# Remove Nth Node From End of List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/  
Difficulty: Medium  
Pattern: Linked List / Two Pointers

## What I understood
We need to remove the nth node from the end of a linked list and return the updated list.

The removal should be done in a single traversal.

Example:

head = [1,2,3,4,5]

n = 2

Output = [1,2,3,5]

## Idea
Use two pointers with a dummy node.

Move the fast pointer n + 1 steps ahead.

Then move both pointers together until the fast pointer reaches the end.

At that point:
- slow points to the node just before the one that needs to be removed

Update the links to skip the target node.

## Approach
- Create a dummy node pointing to the head
- Initialize fast and slow pointers at the dummy node
- Move the fast pointer n + 1 steps ahead
- Move both pointers together until fast reaches the end
- Remove the target node by updating the next pointer
- Return dummy->next

## Key Observation
Maintaining a gap of n + 1 nodes between the fast and slow pointers ensures that when the fast pointer reaches the end, the slow pointer is exactly one node before the node to be deleted.

The dummy node handles edge cases such as deleting the head node.

## When to use this
If the problem involves:
- removing a node from the end
- single-pass linked list traversal
- maintaining a fixed distance between pointers

→ think fast and slow pointers

## Edge Cases
- Single node list
- Removing the head node
- Removing the last node
- Two node list
- n equals the length of the list

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Middle of the Linked List
- Delete the Middle Node of a Linked List
- Linked List Cycle
- Remove Linked List Elements