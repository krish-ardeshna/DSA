# Construct Binary Search Tree from Preorder Traversal
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/  
Difficulty: Medium  
Pattern: BST - Recursive Build with Upper Bound

## What I understood
Given an array representing the PREORDER traversal of a BST (all values distinct), reconstruct and return the original tree.

## Example
```
Input
preorder = [8,5,1,7,10,12]
Output
[8,5,10,1,7,null,12]
```
```
Input
preorder = [1,3]
Output
[1,null,3]
```

## Idea
Unlike a generic binary tree, a BST doesn't need a separate inorder array to reconstruct, its own ordering property already encodes enough information. Since preorder visits root, then left subtree, then right subtree, and every value in the left subtree must be smaller than the root while every value in the right subtree must be smaller than whatever BOUND was inherited from above, a single pass through preorder with a shared index and a shrinking upper bound is enough to rebuild the whole tree.

## Approach: Recursive Construction Using an Upper Bound Per Subtree
- `build(preorder, i, bound)`: if index `i` has exhausted the array, or the next value exceeds `bound`, this subtree is empty, return `nullptr`.
- Otherwise, consume `preorder[i]` as the current root, advance `i`.
- Build the LEFT subtree first, passing the current root's value as its bound (everything in the left subtree must stay below it).
- Build the RIGHT subtree next, passing the SAME bound this call received (right subtree can go up to whatever the parent allowed).
- Index `i` is passed by reference so it advances consistently across the whole recursion, since the array is only ever read left to right, in preorder order.

## Key Observation
The bound isn't recomputed from scratch, it's inherited and tightened only when descending left, this single value is enough to decide exactly where each subtree ends, without ever looking ahead in the array or using a second traversal.

## When to use this
If problem involves:
- Rebuilding a BST from just one traversal order
→ Think **shrinking bound recursion**, a BST's ordering makes a second traversal (like inorder) unnecessary, unlike general binary tree reconstruction.

## Edge Cases
- Single node tree.
- Strictly increasing preorder (degenerates into a right-only chain).
- Strictly decreasing preorder (degenerates into a left-only chain).
- Preorder with a mix of small left values needing a tight bound followed by larger right values.

## Complexity
### Approach
Time: **O(n)** - each element consumed exactly once         
Space: **O(h)** - recursion stack, h = tree height

where:
- `n` = number of elements
- `h` = height of the tree

## Related Problems
- Construct Binary Tree from Preorder and Inorder Traversal
- Convert Sorted Array to Binary Search Tree
- Validate Binary Search Tree
- Verify Preorder Sequence in Binary Search Tree