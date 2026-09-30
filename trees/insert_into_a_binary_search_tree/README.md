# Insert into a Binary Search Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/  
Difficulty: Medium  
Pattern: BST - Iterative Descent to Find Insertion Spot

## What I understood
Given a BST and a value `val`, insert `val` into the tree such that BST ordering is preserved, then return the tree's root. Any valid resulting tree is acceptable — there can be multiple correct trees depending on the insertion path.

## Example
```
Input
root = [4,2,7,1,3], val = 5
Output
[4,2,7,1,3,5]
```
```
Input
root = [], val = 5
Output
[5]
```

## Idea
A new value in a BST always ends up as a LEAF — there's exactly one path down from the root that leads to the correct empty spot for it, decided at every step by comparing `val` against the current node. Walk that path until hitting a `nullptr` child, and attach the new node there.

## Approach: Iterative Walk Down, Attach New Node at First Null Slot
- If tree is empty, the new node itself becomes the root.
- Otherwise, walk from `root`: at each node, if `val >= curr->val`, go right (or attach there if right is null); else go left (or attach there if left is null).
- Stop as soon as the new node is attached, return the unchanged `root`.

## Key Observation
Insertion never needs to restructure existing nodes, it only ever adds one new leaf. This is what keeps the operation simple and iterative, unlike deletion, which can require replacing an internal node.

## When to use this
If problem involves:
- Adding a new value to a BST while preserving its ordering property
→ Think **iterative descent to a null child slot**. No rebalancing is needed unless the problem explicitly asks for a self-balancing tree (AVL, Red-Black).

## Edge Cases
- Empty tree (new node becomes the root).
- Value equal to an existing node's value (this solution routes duplicates to the right subtree via `<=`).
- Value smaller than every node (ends up as the leftmost leaf).
- Value larger than every node (ends up as the rightmost leaf).

## Complexity
### Approach
Time: **O(h)**          
Space: **O(1)**

where:
- `h` = height of the tree (O(log n) if balanced, O(n) if skewed)

## Related Problems
- Search in a Binary Search Tree
- Delete Node in a BST
- Validate Binary Search Tree
- Convert Sorted Array to Binary Search Tree