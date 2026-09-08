# Copy List with Random Pointer
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/copy-list-with-random-pointer/  
Difficulty: Medium  
Pattern: Linked List - Interweaving Clone (O(1) Space)

## What I understood
Each node has a `next` pointer (standard linked list traversal) and a `random` pointer (can point to any node in the list, or null). Create a deep copy of the entire list — new nodes with identical values, correctly matching `next` and `random` pointer structure, without reusing any original nodes.

## Example
```
Input
head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output
Deep copy with identical structure, all new node objects
```

## Idea
The core challenge is wiring `random` pointers correctly, since a naive copy (via hashmap) works but uses O(n) extra space. The O(1) space trick: interweave each original node with its copy directly in the list (original → copy → original → copy → ...). This makes finding "the copy of any node" trivial — it's always `originalNode->next`, including for random pointer targets. After wiring, split the interwoven list back into two separate lists.

## Approach: Interweave Copies, Wire Random Pointers, Detach
- **Step 1 (`insertCopyInBetween`)**: traverse original list, insert a copy node right after each original node (`orig1 -> copy1 -> orig2 -> copy2 -> ...`).
- **Step 2 (`connectRandomPointers`)**: traverse again (stepping by 2 to hit only original nodes), set each copy's `random` pointer using `temp->random->next` (the copy of temp's random target) — this works because every original node's copy is always immediately after it.
- **Step 3 (`getDeepCopy`)**: traverse a third time, splitting the interwoven list — extract copy nodes into a separate list while restoring original list's `next` pointers to skip over the copies, using a dummy head to simplify edge handling.
- Return the detached copy list's head.

## Key Observation
Interweaving is what enables O(1) space — instead of a hashmap mapping original-to-copy nodes, the copy is always structurally guaranteed to be `original->next` at the point of setting random pointers, making the mapping implicit rather than explicit storage.

## When to use this
If problem involves:
- Deep copying a linked structure with non-sequential pointers (random, sibling, etc.)
- Need O(1) space instead of O(n) hashmap-based mapping
→ Think **interweave copy nodes directly into the original list**, use structural adjacency instead of explicit lookup, then detach afterward.

## Edge Cases
- Empty list (`head == nullptr`).
- Single node list, with or without self-referencing random pointer.
- All random pointers null.
- Random pointer pointing to itself or forming complex reference patterns.

## Complexity
### Approach
Time: **O(n)** — three linear passes            
Space: **O(1)** extra (excluding output copy list, which is required)

where:
- `n` = number of nodes

## Related Problems
- Clone Graph
- Copy List with Random Pointer (Hashmap variant)
- Flatten a Multilevel Doubly Linked List
- LRU Cache