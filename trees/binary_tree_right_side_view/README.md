# Binary Tree Right Side View
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-tree-right-side-view/  
Difficulty: Medium  
Pattern: Tree - DFS (Right-First Traversal, First Visit Per Level)

## What I understood
Given a binary tree, return the values visible when viewing the tree from the RIGHT side — essentially, the rightmost node at each level, ordered top to bottom.

## Example
```
Input
root = [1,2,3,null,5,null,4]
Output
[1,3,4]
```
```
Input
root = [1,null,3]
Output
[1,3]
```

## Idea
Instead of BFS (level-order, tracking last node per level), use DFS but visit RIGHT child before LEFT child at every node — this guarantees that the FIRST node encountered at any given depth/level during this modified traversal is always the rightmost node at that level. A simple check (`res.size() == level`) determines if this is the first time reaching this level, and if so, records the value.

## Approach: Recursive DFS, Visit Right Before Left, Record First Node Per Level
- `recursion(root, level, res)`: base case, `nullptr` → return immediately.
- Check `if (res.size() == level)` — this means no node has been recorded for this level yet (since `res` grows exactly one entry per level, in order), so record `root->val`.
- Recurse into RIGHT child first (`level+1`), then LEFT child (`level+1`) — right-first ordering ensures the rightmost node at each level is always visited before any left-side node at the same level.
- `rightSideView`: start recursion at `level = 0`, return final `res`.

## Key Observation
The right-before-left recursion order is the entire trick — it transforms what could be a more complex level-tracking BFS solution into a simple DFS where "first visit at this depth" always coincides with "rightmost node at this depth," due to the traversal order guaranteeing the right subtree is always fully explored (at each level) before the left subtree gets a chance to reach that same level.

## When to use this
If problem involves:
- Selecting one representative node per level based on left/right positioning (rightmost, leftmost)
→ Think **DFS with directional traversal order (right-first for rightmost, left-first for leftmost) + first-visit-per-level tracking**, avoiding the need for explicit BFS level grouping.

## Edge Cases
- Empty tree (`root == nullptr`, returns empty result).
- Single node tree.
- Skewed tree (all left children — right side view still correctly shows each level's single node, since traversal reaches every level regardless of missing right children).
- Tree where right subtree is shorter than left subtree (some levels' rightmost visible node might actually come from the left branch, correctly handled since right-first traversal still explores left branches for those deeper levels).

## Complexity
### Approach
Time: **O(n)**                          
Space: **O(h)** — recursion stack, h = tree height

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Binary Tree Left Side View
- Binary Tree Level Order Traversal
- Populating Next Right Pointers in Each Node
- Find Largest Value in Each Tree Row