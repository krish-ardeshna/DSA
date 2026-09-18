# Diameter of Binary Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/  
Difficulty: Easy  
Pattern: Tree - DFS (Height + Diameter via Reference Parameter)

## What I understood
The diameter of a binary tree is the length (number of EDGES, not nodes) of the longest path between any two nodes — this path may or may not pass through the root. Find this diameter.

## Example
```
Input
root = [1,2,3,4,5]
Output
3
```
```
Input
root = [1,2]
Output
1
```

## Idea
The longest path through any given node equals `leftHeight + rightHeight` (the path going down the left subtree, through this node, then down the right subtree) — measured in edges. Rather than computing height separately for every node and then separately checking diameters (O(n²)), compute BOTH in a single post-order DFS pass: while computing height bottom-up, simultaneously update a running maximum diameter using the current node's left and right subtree heights.

## Approach: Post-Order DFS, Track Diameter by Reference While Computing Height
- `height(root, diameter)`: base case, `nullptr` → height 0.
- Recursively compute `lh` (left subtree height) and `rh` (right subtree height).
- Update `diameter = max(diameter, lh + rh)` — this checks if the path THROUGH the current node beats the best diameter found so far.
- Return `1 + max(lh, rh)` (this node's own height, for use by its parent).
- `diameterOfBinaryTree`: initialize `diameter = 0`, call `height(root, diameter)` (passed by reference so updates persist across all recursive calls), return final `diameter`.

## Key Observation
Passing `diameter` by reference lets a single post-order traversal compute BOTH the height (needed for the parent's calculation) and check every possible "through this node" diameter candidate — since every node is visited exactly once and its left/right heights are already known at that point (post-order), no separate pass or extra height-lookup is needed.

## When to use this
If problem involves:
- A tree metric depending on combining BOTH subtrees' heights/depths at every node (diameter, longest path, etc.)
→ Think **single post-order DFS pass, using a reference parameter (or return a pair/struct) to track both the local recursive value (height) and the global running answer (diameter) simultaneously**.

## Edge Cases
- Single node tree (diameter = 0, no edges exist).
– Two node tree (diameter = 1).
- Skewed tree (all left or all right children — diameter equals total node count minus 1, since it's just the longest chain).
- Diameter path not passing through the root (e.g., entirely within one subtree — still correctly captured since every node's own left/right combination is checked).

## Complexity
### Approach
Time: **O(n)**              
Space: **O(h)** — recursion stack, h = tree height

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Maximum Depth of Binary Tree
- Balanced Binary Tree
- Binary Tree Maximum Path Sum
- Longest Path With Different Adjacent Characters