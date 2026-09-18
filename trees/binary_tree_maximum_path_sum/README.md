# Binary Tree Maximum Path Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/  
Difficulty: Hard  
Pattern: Tree - DFS (Max Gain + Global Max via Reference)

## What I understood
Find the maximum sum path in a binary tree, where a "path" is any sequence of connected nodes (parent-child links), NOT required to pass through the root or reach a leaf -  any node can be the start, any node can be the end, as long as it's a connected chain. Node values can be negative.

## Example
```
Input
root = [-10,9,20,null,null,15,7]
Output
42
```
```
Input
root = [1,2,3]
Output
6
```

## Idea
Similar to Diameter of Binary Tree, but here values matter (not just edge counts), and NEGATIVE values must be handled carefully. Two related but distinct quantities exist at each node: the best path SUM passing through this node as the "peak" (using both children, for the global answer), and the best "gain" a PARENT could extend upward through this node (using at most ONE child, since a path can only continue in one direction upward). Negative subtree contributions should be clamped to 0 (better to exclude them entirely than include a negative sum).

## Approach: Post-Order DFS, Clamp Negative Gains, Track Global Sum by Reference
- `maxPath(root, sum)`: base case, `nullptr` → 0.
- Recursively get `left` and `right` gains, each clamped to `max(0, ...)` -  a negative-contributing subtree is simply not included (contributes 0 instead of hurting the sum).
- Update global `sum` (passed by reference): `sum = max(sum, left + right + root->val)` -    this is the best "peak path" using BOTH children through this node.
- Return `max(left, right) + root->val` -    the best "extendable gain" for the PARENT to use, which can only take ONE side (a path can't branch in two directions once it continues upward).
- `maxPathSum`: init `sum = INT_MIN` (handles all-negative trees correctly), run DFS, return `sum`.

## Key Observation
The distinction between "return value" (single-direction gain for parent) and "global max" (two-direction peak sum, tracked via reference) is the crux of this problem -     conflating them would either undercount valid paths (missing the two-child peak case) or produce invalid paths (a path can't fork in both directions and still be a simple connected path once it continues past this node).

## When to use this
If problem involves:
- Finding a maximum-sum (or similar optimized) path in a tree that isn't restricted to root-to-leaf
- Values can be negative, requiring "at most one side" continuation logic for upward propagation
→ Think **post-order DFS separating "return value for parent" (one-sided) from "global answer" (two-sided peak), clamping negative contributions to zero**.

## Edge Cases
- All negative values (answer is simply the single largest -     least negative -    node value, since sum init at `INT_MIN` correctly handles this).
- Single node tree.
- Path entirely within one subtree, not touching the root at all.
- Root itself heavily negative but children very positive (path should correctly exclude the root if beneficial).

## Complexity
### Approach
Time: **O(n)**  
Space: **O(h)** -    recursion stack, h = tree height

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Diameter of Binary Tree
- Path Sum
- Path Sum II
- Longest Univalue Path