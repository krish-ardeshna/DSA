# Binary Tree Zigzag Level Order Traversal
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/  
Difficulty: Medium  
Pattern: Tree - BFS (Level Order with Direction Flip)

## What I understood
Return level-order traversal of a binary tree, but alternating direction per level - first level left-to-right, second level right-to-left, third left-to-right, and so on (zigzag pattern).

## Example
```
Input
root = [3,9,20,null,null,15,7]
Output
[[3],[20,9],[15,7]]
```
```
Input
root = [1]
Output
[[1]]
```

## Idea
Standard BFS naturally processes nodes level by level (queue size snapshot per level, same as regular level order traversal). The zigzag effect is achieved not by changing traversal order in the queue itself, but by controlling WHERE each node's value gets WRITTEN into the current level's result row - using a direction flag that flips after every level, placing values from the front or the back of the row array as appropriate.

## Approach: BFS with Index Placement Based on Direction Flag
- Standard BFS setup: queue starts with root, `LtoR = true` (tracks current level's direction).
- For each level: capture `size = q.size()`, pre-allocate a `row` vector of that size.
- Process each node: dequeue it, compute placement `index = LtoR ? i : size - i - 1` - normal left-to-right index if going forward, MIRRORED index if going backward.
- Write `node->val` at `row[index]`, push children as usual (children pushing order is ALWAYS left-then-right, regardless of current level's zigzag direction - only the WRITE position changes, not traversal order).
- After processing the level, flip `LtoR`, push completed `row` into `res`.

## Key Observation
Children are always pushed in the same left-to-right order regardless of the current level's zigzag direction - it's crucial to NOT reverse the push order, only the index at which values are WRITTEN into the result row. This keeps BFS traversal logic simple and unchanged; only the output formatting differs.

## When to use this
If problem involves:
- Level order traversal with an alternating or otherwise modified per-level output arrangement
→ Think **standard BFS + index-based placement using a direction flag**, rather than trying to reverse the actual traversal/queue order (which would complicate the children-pushing logic unnecessarily).

## Edge Cases
- Empty tree.
- Single node tree (only one level, direction flip irrelevant since output only has index 0).
- Skewed tree (each level has exactly 1 node, direction flip has no visible reordering effect).
- Tree with varying level sizes (row pre-allocated to exact size each time, indices always valid).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(n)** - queue can hold up to one full level, output storage

where:
- `n` = number of nodes

## Related Problems
- Binary Tree Level Order Traversal
- Binary Tree Level Order Traversal II
- Average of Levels in Binary Tree
- N-ary Tree Level Order Traversal