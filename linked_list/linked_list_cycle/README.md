# Linked List Cycle

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/linked-list-cycle/  
Difficulty: Easy  
Pattern: Linked List / Fast & Slow Pointer

## What I understood
We are given the head of a linked list.

We need to determine whether the linked list contains a cycle.

A cycle exists if some node can be reached again by continuously following the next pointers.

Example:

head = [3,2,0,-4]

tail connects to node with value 2

Output = true

## Idea

### Approach 1 (Hash Set)
Traverse the linked list while storing every visited node in a hash set.

If a node is encountered again, a cycle exists.

### Approach 2 (Floyd's Cycle Detection)
Use two pointers:

- slow moves one step
- fast moves two steps

If a cycle exists, both pointers will eventually meet.

If the fast pointer reaches the end, the list has no cycle.

## Approach
- Initialize slow and fast pointers
- Move:
  - slow by one step
  - fast by two steps
- If both pointers meet:
  - return true
- If fast reaches nullptr:
  - return false

## Key Observation
In a cyclic linked list, a faster pointer will eventually catch up with a slower pointer.

This allows cycle detection without using extra memory.

## When to use this
If the problem involves:
- detecting cycles
- linked list traversal
- constant space solutions

→ think Floyd's Cycle Detection

## Edge Cases
- Empty list
- Single node without cycle
- Single node with self-cycle
- Cycle at the beginning
- Cycle in the middle

## Complexity

### Approach 1
Time: O(n)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(1)

## Related Problems
- Linked List Cycle II
- Happy Number
- Find the Duplicate Number
- Middle of the Linked List