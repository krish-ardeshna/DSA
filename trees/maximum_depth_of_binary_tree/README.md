# Maximum Depth of Binary Tree

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/  
Difficulty: Easy  
Pattern: Tree, DFS, BFS

## What I understood

Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root to a leaf.

## Example

```
Input
root = [3,9,20,null,null,15,7]

Output
3
```

## Idea

The depth of a node equals:

- 1 (for the current node)
- plus the maximum depth of its left and right subtrees.

The same result can also be obtained by traversing the tree level by level.

## Approach 1: Recursive DFS

- If the node is null, return 0.
- Recursively compute the depths of the left and right subtrees.
- Return `1 + max(leftDepth, rightDepth)`.

## Approach 2: Iterative DFS (Stack)

- Store each node along with its current depth in a stack.
- Traverse the tree using DFS.
- Track the maximum depth encountered.

## Approach 3: BFS (Level Order)

- Traverse the tree level by level using a queue.
- After processing each level, increment the depth.
- The number of levels equals the maximum depth.

## Key Observation

The maximum depth is determined by the longest root-to-leaf path.

DFS computes it recursively or iteratively, while BFS counts tree levels.

## When to use this

- Tree height
- Root-to-leaf traversal
- DFS recursion
- BFS level traversal

→ Think **DFS for recursive tree properties, BFS for level-based calculations**.

## Edge Cases

- Empty tree.
- Single-node tree.
- Left-skewed tree.
- Right-skewed tree.
- Balanced tree.

## Complexity

### Approach 1

Time: **O(n)**

Space: **O(h)**

### Approach 2

Time: **O(n)**

Space: **O(h)**

### Approach 3

Time: **O(n)**

Space: **O(w)**

where:
- `n` = number of nodes
- `h` = height of the tree
- `w` = maximum width of the tree

## Related Problems

- Minimum Depth of Binary Tree
- Balanced Binary Tree
- Diameter of Binary Tree
- Binary Tree Level Order Traversal