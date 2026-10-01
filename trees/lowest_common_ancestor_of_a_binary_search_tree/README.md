# Lowest Common Ancestor of a Binary Search Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/  
Difficulty: Medium  
Pattern: BST - Recursive Descent Using Ordering

## What I understood
Given a BST and two nodes `p` and `q` guaranteed to exist in it, find their Lowest Common Ancestor, exploiting BST ordering rather than treating it as a generic binary tree.

## Example
```
Input
root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output
2
```
```
Input
root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output
6
```

## Idea
In a plain binary tree, finding the LCA requires searching both subtrees since there's no ordering to guide the search. A BST removes that ambiguity, at any node, comparing its value against `p->val` and `q->val` immediately tells you whether both targets lie entirely to one side, in which case the LCA must be further down THAT side, or whether they straddle the current node, in which case this node itself is the LCA.

## Approach: Follow Single Path Determined by BST Property
- If current node's value is smaller than BOTH `p->val` and `q->val`, both targets are in the right subtree, recurse right.
- If current node's value is larger than BOTH, both targets are in the left subtree, recurse left.
- Otherwise, the current node splits `p` and `q` (or equals one of them), so it IS the LCA, return it.

## Key Observation
Only ONE recursive call is ever made per level, since BST ordering already tells you which single side to descend into, this is what makes the BST version strictly simpler and faster than the general binary tree LCA problem, which must explore both sides.

## When to use this
If problem involves:
- Finding a common ancestor of two nodes specifically in a BST (not a general binary tree)
→ Think **single-direction recursive/iterative descent using value comparisons**, never both subtrees.

## Edge Cases
- `p` is an ancestor of `q` (or vice versa), the ancestor node itself is the answer.
- `p` and `q` are the same node.
- `p` and `q` are on opposite sides of the root, root is the answer.
- Skewed BST (degenerates into a linked-list-like search path).

## Complexity
### Approach
Time: **O(h)**          
Space: **O(h)** - recursion stack (can be converted to O(1) iteratively)

where:
- `h` = height of the tree (O(log n) if balanced, O(n) if skewed)

## Related Problems
- Lowest Common Ancestor of a Binary Tree
- Lowest Common Ancestor of a Binary Tree II
- Lowest Common Ancestor of a Binary Tree III
- Search in a Binary Search Tree