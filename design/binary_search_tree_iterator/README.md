# Binary Search Tree Iterator
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-search-tree-iterator/  
Difficulty: Medium  
Pattern: Design - Controlled Inorder Traversal (Stack-Based Lazy Expansion)

## What I understood
Design an iterator over a BST that returns values in ASCENDING (inorder) order, one at a time via `next()`, with `hasNext()` checking whether more values remain. Both operations should average O(1) time, and the whole structure should use O(h) space, not O(n).

## Example
```
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]
```

## Idea
A full inorder traversal upfront would give the right order, but storing all `n` values violates the O(h) space requirement. Instead, maintain a stack that always holds the LEFT SPINE from wherever the traversal currently stands, this is exactly the state a recursive inorder traversal's call stack would hold at any given moment, so popping the top always gives the next smallest unvisited value.

## Approach: Stack of Left Spine, Expand Right Subtree Lazily on next()
- Constructor: push the entire left spine starting from `root` (`pushAll`), so the smallest value sits on top.
- `next()`: pop the top (smallest remaining value), then push the ENTIRE left spine of its right child, this lazily expands exactly the part of the tree that becomes relevant only once this node has been consumed.
- `hasNext()`: simply check if the stack is non-empty.
- `pushAll(node)`: walk left from `node`, pushing every node along the way, until hitting `nullptr`.

## Key Observation
The stack never holds more than O(h) nodes at once, each `next()` call only pushes the left spine of ONE node's right subtree, and that spine's total length across the WHOLE iterator's lifetime sums to O(n) pushes overall, giving amortized O(1) per `next()` call, even though a single call can occasionally push several nodes.

## When to use this
If problem involves:
- Iterating a tree in a specific order (inorder, etc.) without materializing the full traversal upfront
→ Think **stack holding the active traversal path**, expanding lazily on each step, this mirrors what recursion would do implicitly, but gives explicit, poll-able, incremental access.

## Edge Cases
- Single node tree (`next()` called once, `hasNext()` false afterward).
- Fully left-skewed tree (constructor pushes the entire tree at once).
- Fully right-skewed tree (each `next()` call pushes exactly one new node).
- Calling `next()` more times than there are nodes (not expected per problem's guarantee that `next()` is only called when `hasNext()` is true).

## Complexity
### Approach
Time: **O(1)** amortized per `next()` and `hasNext()` call          
Space: **O(h)** - stack holds at most the height of the tree at any point

where:
- `h` = height of the tree
- `n` = total number of nodes (amortized bound across all calls)

## Related Problems
- Binary Tree Inorder Traversal
- Flatten Binary Tree to Linked List
- Kth Smallest Element in a BST
- Peeking Iterator