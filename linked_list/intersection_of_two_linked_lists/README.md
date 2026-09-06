# Intersection of Two Linked Lists
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/  
Difficulty: Easy  
Pattern: Linked List - Two Pointer (Switch Heads)

## What I understood
Given heads of two singly linked lists, find the node at which they intersect (share the same node reference, not just same value). Return null if no intersection exists. Lists may have different lengths before the intersection point.

## Example
```
Input
listA = [4,1,8,4,5], listB = [5,6,1,8,4,5] (intersecting at node with value 8)
Output
Reference to node with value 8
```
```
Input
listA = [2,6,4], listB = [1,5] (no intersection)
Output
null
```

## Idea
Length difference between the two lists is the core obstacle to a naive simultaneous traversal. The trick: when a pointer reaches the end of its own list, redirect it to the head of the OTHER list. This equalizes the total distance both pointers travel before reaching the intersection point — since `lenA + lenB` is the same total distance for both pointers regardless of starting list, they arrive at the intersection point (or both reach null) simultaneously.

## Approach: Two Pointer, Switch to Other List's Head on Reaching End
- Init `temp1 = headA`, `temp2 = headB`.
- Loop while `temp1 != temp2`: advance each pointer normally (`->next`), but if a pointer hits `nullptr`, redirect it to the OTHER list's head instead of stopping.
- Since both pointers traverse the exact same total distance (`lenA + lenB`), they either meet exactly at the intersection node, or both simultaneously become `nullptr` (no intersection case), satisfying the loop's exit condition either way.
- Return `temp1` (whichever value it holds at exit — the intersection node or `nullptr`).

## Key Observation
No length calculation or extra space needed — the pointer-switching trick implicitly equalizes traversal distance by having each pointer "absorb" the other list's extra length difference through the redirect, elegant alternative to explicitly computing `lenA - lenB` and pre-advancing the longer list.

## When to use this
If problem involves:
- Finding a common node/meeting point between two sequences of potentially different lengths, using node identity (not value) to determine matches
→ Think **two pointer with redirect-to-other-head-on-end**, avoids needing separate length computation pass.

## Edge Cases
- No intersection at all (both pointers reach null simultaneously after full switch).
- One list is entirely a suffix of the other (intersection at the very first node of the shorter list's counterpart).
- Lists of equal length.
- One or both lists empty (handled via initial null check).

## Complexity
### Approach
Time: **O(m + n)** — each pointer traverses at most both lists once         
Space: **O(1)**

where:
- `m`, `n` = lengths of the two lists

## Related Problems
- Linked List Cycle
- Linked List Cycle II
- Merge Two Sorted Lists
- Palindrome Linked List