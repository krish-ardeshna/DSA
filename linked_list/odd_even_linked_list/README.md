# Odd Even Linked List
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/odd-even-linked-list/  
Difficulty: Medium  
Pattern: Linked List - Two Pointer (Interleaved Rewiring)

## What I understood
Given a singly linked list, group all nodes at odd positions together, followed by all nodes at even positions (positions are 1-indexed, based on original order — not by node value). Must be done in-place, O(1) extra space, preserving relative order within each group.

## Example
```
Input
head = [1,2,3,4,5]
Output
[1,3,5,2,4]
```
```
Input
head = [2,1,3,5,6,4,7]
Output
[2,3,6,7,1,5,4]
```

## Idea
Maintain two separate pointer chains simultaneously while traversing once: `odd` collects nodes at positions 1,3,5,... and `even` collects nodes at positions 2,4,6,... Since both chains interleave in the original list, advancing both pointers by "skipping one" (via `->next->next`) naturally separates them without needing extra memory. After separation, splice the even chain onto the end of the odd chain.

## Approach: Separate Odd/Even Chains, Reconnect
- Handle trivial cases: empty list or single node, return as-is.
- Init `odd = head`, `even = head->next`, save `evenHead = head->next` (needed later to reconnect, since `even` pointer will move).
- Loop while `even` and `even->next` both exist: relink `odd->next` to skip the even node (`odd->next->next`), relink `even->next` similarly, then advance both pointers.
- After loop, odd chain ends at its last node — attach `evenHead` there to complete the odd-then-even ordering.
- Return original `head` (now restructured).

## Key Observation
Saving `evenHead` before the loop begins is essential — once the loop starts modifying `next` pointers, the only way to find where the even chain starts again is through this saved reference, since `even` pointer itself will have moved far past it by the time reconnection happens.

## When to use this
If problem involves:
- Reordering/regrouping linked list nodes by position parity or similar interleaved pattern
- In-place restructuring with O(1) space constraint
→ Think **two simultaneous pointer chains built via double-skip traversal**, save the second chain's head before it moves.

## Edge Cases
- Empty list.
- Single node list.
- Two node list (loop condition `even->next` fails immediately, direct reconnect).
- Odd total node count vs even total node count (loop naturally terminates correctly either way).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = number of nodes

## Related Problems
- Reorder List
- Rotate List
- Swap Nodes in Pairs
- Split Linked List in Parts