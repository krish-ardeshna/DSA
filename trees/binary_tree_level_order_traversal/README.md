# Binary Tree Level Order Traversal
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/  
Difficulty: Medium  
Pattern: Tree - BFS (Level-by-Level Queue Processing)

## What I understood
Given a binary tree, return the values of nodes grouped by level (top to bottom), left to right within each level.

## Example
```
Input
root = [3,9,20,null,null,15,7]
Output
[[3],[9,20],[15,7]]
```
```
Input
root = [1]
Output
[[1]]
```

## Idea
Standard BFS naturally processes nodes level by level if the queue's SIZE is captured at the start of each level's processing — since children pushed during the current level's processing land at the back of the queue, they won't be dequeued until the current level's fixed-size batch is fully drained, cleanly separating levels.

## Approach: BFS with Size-Bounded Level Extraction
- Handle empty tree edge case (`root == nullptr`), return empty result.
- Push `root` into queue.
- While queue isn't empty: capture current `size = q.size()` (this is exactly how many nodes belong to the current level).
- Process exactly `size` nodes: pop each, record its value into `level`, push its non-null children (they'll belong to the NEXT level).
- After the inner loop, push completed `level` into `ans`.
- Repeat until queue empties.

## Key Observation
Capturing `size` BEFORE the inner loop starts is the critical detail — since children get pushed during the loop, the queue's size changes dynamically; using the captured (frozen) size ensures exactly one level's worth of nodes is processed per outer iteration, not an ever-growing/shrinking count.

## When to use this
If problem involves:
- Level-by-level (breadth-first) tree traversal requiring level grouping/boundaries
→ Think **BFS with queue-size snapshot at the start of each level** to cleanly separate levels without extra markers or sentinel values.

## Edge Cases
- Empty tree (`root == nullptr`).
- Single node tree.
- Skewed tree (all left or all right children, each level has exactly 1 node).
- Complete/balanced tree (levels double in size each time).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(n)** — queue can hold up to one full level, output storage

where:
- `n` = number of nodes

## Related Problems
- Binary Tree Zigzag Level Order Traversal
- Binary Tree Level Order Traversal II
- Average of Levels in Binary Tree
- N-ary Tree Level Order Traversal