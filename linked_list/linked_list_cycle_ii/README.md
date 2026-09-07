# Linked List Cycle II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/  
Difficulty: Medium  
Pattern: Linked List - Floyd's Cycle Detection (Tortoise and Hare)

## What I understood
Given a linked list, determine if it contains a cycle, and if so, return the node where the cycle begins (not just whether a cycle exists). Return null if no cycle. Must be done without extra space (no visited-node set).

## Example
```
Input
head = [3,2,0,-4], cycle starts at node with value 2
Output
Reference to node with value 2
```
```
Input
head = [1,2], no cycle
Output
null
```

## Idea
Phase 1 (detect): use two pointers, `slow` moving 1 step and `fast` moving 2 steps at a time. If a cycle exists, they're guaranteed to meet inside the cycle (fast "laps" slow). Phase 2 (locate start): once they meet, reset `slow` to `head`, keep `fast` at the meeting point, then move both 1 step at a time — they'll meet exactly at the cycle's starting node. This works due to a mathematical property relating the distance from head-to-cycle-start and meeting-point-to-cycle-start.

## Approach: Fast/Slow Pointer Meet + Reset One to Head
- Phase 1: `slow` and `fast` both start at `head`. Loop while `fast` and `fast->next` are non-null: advance `slow` by 1, `fast` by 2.
- If `slow == fast` at any point → cycle detected, proceed to Phase 2.
- Phase 2: reset `slow = head`, keep `fast` at meeting point. Move both one step at a time until they meet again — that meeting point is the cycle's start node.
- If loop exits without `slow == fast` ever triggering → no cycle, return `NULL`.

## Key Observation
The distance relationship works out mathematically: if `L` = distance from head to cycle start, and the pointers meet some distance `k` into the cycle, then moving `slow` from head and `fast` (now moving 1 step) from the meeting point, both will reach the cycle start after exactly `L` more steps — this is the classic Floyd's algorithm cycle-start-finding trick, not something obvious without the underlying math derivation.

## When to use this
If problem involves:
- Cycle detection in a linked list (or similar pointer-chasing structure)
- Need the exact cycle start node, not just yes/no cycle existence
→ Think **Floyd's Tortoise and Hare, phase 2 reset-to-head trick** for finding cycle start specifically.

## Edge Cases
- No cycle at all (fast reaches null, loop exits normally).
- Cycle starts at the head node itself.
- Single node with self-loop (cycle start is that single node).
- Very short cycle (2-3 nodes).

## Complexity
### Approach
Time: **O(n)**      
Space: **O(1)**

where:
- `n` = number of nodes

## Related Problems
- Linked List Cycle
- Find the Duplicate Number
- Happy Number
- Circular Array Loop