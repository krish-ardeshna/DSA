# Boundary Traversal of Binary Tree
Platform: Not confirmed on LeetCode (GFG-style problem)  
Problem Link: Not confirmed - this is not LC #545 (that ID belongs to N-ary Tree Postorder Traversal); verify the intended source before relying on this link
Difficulty: Medium  
Pattern: Tree - DFS (Left Boundary + Leaves + Right Boundary Combined)

## What I understood
Return the "boundary" of a binary tree in anticlockwise order: root, then all left-boundary nodes (top to bottom, excluding leaves), then all leaf nodes (left to right), then all right-boundary nodes (bottom to top, excluding leaves).

## Example
```
Input
root = [1,2,3,4,5,6,7]
Output
[1,2,4,5,6,7,3]
```
```
Input
root = [1]
Output
[1]
```

## Idea
Boundary traversal is naturally split into 3 distinct sub-traversals, each handled with different logic:
- **Left boundary**: walk down from `root->left`, always preferring left child; skip leaves (they'll be captured separately).
- **Leaves**: standard DFS collecting every leaf node, left to right.
- **Right boundary**: walk down from `root->right`, always preferring right child; skip leaves; since this naturally collects bottom-to-top order when reversed for anticlockwise output, collect into a temp list then reverse before appending.

## Approach: Three-Part Traversal (Left Boundary, Leaves, Reversed Right Boundary)
- Handle edge cases: empty tree → empty result; single-leaf root → just that value.
- Push root's value first.
- `leftBoundary`: traverse from `root->left`, prefer left child at each step (fallback to right if no left child exists), pushing non-leaf values directly (correct order emerges naturally top-to-bottom).
- `leaves`: standard recursive DFS, push value only at true leaf nodes, recursing left then right.
- `rightBoundary`: traverse from `root->right`, prefer right child (fallback to left), collect non-leaf values into a TEMPORARY list (since this traversal is naturally top-to-bottom, but the boundary needs bottom-to-top) - reverse the temp list before appending to final result.
- Combine: root + left boundary + leaves + reversed right boundary.

## Key Observation
The right boundary needs a temporary list + explicit reversal specifically because its natural top-down traversal order is the OPPOSITE of what the final anticlockwise boundary output needs (bottom-to-top) - this asymmetry between left and right boundary handling is the key detail that's easy to get wrong.

## When to use this
If problem involves:
- Combining multiple partial traversals of a tree into one ordered boundary/outline sequence
→ Think **split into left-boundary, leaves, right-boundary as separate sub-problems**, paying attention to which sub-traversal needs reversal to match the desired final order.

## Edge Cases
- Single node tree (root is also the only leaf, returns just that value).
- Tree with no leaves other than at the boundary itself (fully skewed tree).
- Left subtree missing entirely (left boundary contributes nothing beyond root).
- Right subtree missing entirely (right boundary contributes nothing beyond root).

## Complexity
### Approach
Time: **O(n)** - each node visited a bounded number of times across the three traversals            
Space: **O(h)** - recursion stack for leaves DFS, h = tree height; O(1) extra for iterative boundary walks

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Binary Tree Right Side View
- Binary Tree Left Side View
- N-ary Tree Postorder Traversal
- Binary Tree Level Order Traversal