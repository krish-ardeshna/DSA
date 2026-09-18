# Balanced Binary Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/balanced-binary-tree/  
Difficulty: Easy  
Pattern: Tree - DFS (Height + Early Termination via Sentinel)

## What I understood
A binary tree is height-balanced if, for EVERY node in the tree, the height difference between its left and right subtrees is at most 1. Determine if the given tree satisfies this property.

## Example
```
Input
root = [3,9,20,null,null,15,7]
Output
true
```
```
Input
root = [1,2,2,3,3,null,null,4,4]
Output
false
```

## Idea
Naive approach would compute height separately at every node (O(n) per node, O(n²) overall) since checking balance requires height, and checking every node's balance requires recomputing heights repeatedly. Instead, compute height and check balance SIMULTANEOUSLY in one post-order pass: use `-1` as a special sentinel return value meaning "this subtree is already imbalanced," which propagates up immediately and short-circuits further unnecessary computation.

## Approach: Post-Order DFS Returning -1 as Imbalance Signal
- `dfsHeight(root)`: base case, `nullptr` → height 0.
- Recurse into left subtree; if it returns `-1` (already imbalanced somewhere below), immediately propagate `-1` upward without checking right subtree at all.
- Recurse into right subtree; same early-exit check.
- If both heights obtained, check `abs(lh - rh) > 1` — if imbalanced at this node, return `-1`.
- Otherwise, return actual height: `max(lh, rh) + 1`.
- `isBalanced`: simply check if the root-level call returns anything other than `-1`.

## Key Observation
Overloading the return value (using `-1` as an error/imbalance sentinel, valid heights are always `>= 0`) is what enables single-pass O(n) computation — height computation and balance verification happen together, and the moment any subtree is found imbalanced, that information propagates up through every ancestor without wasted extra work.

## When to use this
If problem involves:
- Tree property verification that depends on height/depth at every node
→ Think **post-order DFS with sentinel value encoding "already failed"**, avoiding separate height computation and verification passes.

## Edge Cases
- Empty tree (trivially balanced, height 0).
- Single node tree (trivially balanced).
- Skewed tree (all left or all right children — height difference grows, likely imbalanced quickly).
- Imbalance occurring deep in the tree, far from root (early-exit sentinel still propagates correctly all the way up).

## Complexity
### Approach
Time: **O(n)** — each node visited exactly once             
Space: **O(h)** — recursion stack, h = tree height

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Maximum Depth of Binary Tree
- Diameter of Binary Tree
- Minimum Depth of Binary Tree
- Convert Sorted Array to Binary Search Tree