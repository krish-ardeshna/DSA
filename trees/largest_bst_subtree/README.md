# Largest BST Subtree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/largest-bst-subtree/  
Difficulty: Medium  
Pattern: Tree - Post-Order DFS (Bottom-Up Range Validation)

## What I understood
Given a binary tree (not necessarily a BST), find the size (node count) of the LARGEST subtree within it that IS a valid BST.

## Example
```
Input
root = [10,5,15,1,8,null,7]
Output
3
```
```
Input
root = [4,2,7,2,3,5,null]
Output
2
```

## Idea
Bottom-up post-order DFS, where each node reports back three pieces of information about its own subtree: the MINIMUM value in it, the MAXIMUM value in it, and its SIZE if it's a valid BST (otherwise, a sentinel marking it invalid). A node is a valid BST root only if its own value is strictly greater than its left subtree's reported max AND strictly less than its right subtree's reported min, AND both children subtrees were themselves valid.

## Approach: Post-Order DFS Returning (min, max, size) Per Subtree
- Base case: `nullptr` returns `NodeValue(INT_MAX, INT_MIN, 0)`, an "empty" subtree that will never block a parent's validity check (since any real value is both `<= INT_MAX` and `>= INT_MIN`).
- Recurse into left and right, collecting their `NodeValue` results.
- If `left.maxNode < root->data < right.minNode` (both children were valid BSTs, AND this node's value correctly fits between them): this subtree IS a valid BST, return `NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1)`.
- Otherwise: this subtree is NOT a valid BST, return a poisoned result `NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize))`, the swapped bounds (`INT_MIN` as min, `INT_MAX` as max) guarantee that ANY parent checking against this subtree will automatically fail its own validity check, correctly propagating the "broken" status upward. The size still carries forward the best valid BST SEEN SO FAR within this invalid subtree.
- `largestBST`: just reads the final `maxSize` field from the root call.

## Key Observation
The poisoned bounds trick (returning `INT_MIN`/`INT_MAX` swapped on failure) is what makes a single bottom-up pass sufficient, without it, a parent node would need a separate validity flag to know whether to trust the child's min/max at all, swapping the bounds achieves the same effect implicitly, any real comparison against them is guaranteed to fail.

## When to use this
If problem involves:
- Finding the largest valid substructure (BST, balanced subtree, etc.) within a larger invalid structure
→ Think **post-order DFS returning a bundle of range info + validity-encoding sentinel values**, letting invalidity propagate automatically through comparisons rather than needing an explicit boolean flag.

## Edge Cases
- Entire tree is already a valid BST (answer equals total node count).
- No valid BST subtree larger than a single node exists.
- Single node tree (trivially a valid BST of size 1).
- Root itself invalid, but one of its subtrees is a large valid BST (correctly captured via `max(left.maxSize, right.maxSize)` in the failure branch).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(h)** - recursion stack, h = tree height

where:
- `n` = number of nodes
- `h` = height of the tree

## Related Problems
- Validate Binary Search Tree
- Maximum Binary Tree
- Count Complete Tree Nodes
- Unique Binary Search Trees