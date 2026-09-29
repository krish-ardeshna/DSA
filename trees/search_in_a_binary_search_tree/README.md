# Search in a Binary Search Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/search-in-a-binary-search-tree/  
Difficulty: Easy  
Pattern: BST - Iterative Binary Search Descent

## What I understood
Given the root of a BST and an integer `val`, find the node whose value equals `val` and return the subtree rooted at that node. Return `null` if no such node exists.

## Example
```
Input
root = [4,2,7,1,3], val = 2
Output
[2,1,3]
```
```
Input
root = [4,2,7,1,3], val = 5
Output
[]
```

## Idea
A BST keeps everything smaller than a node in its left subtree and everything larger in its right subtree. Each comparison therefore discards one whole subtree, the same way binary search discards half an array. No recursion or extra structure is needed, just walk down one path.

## Approach: Iterative Descent Using BST Ordering
- Start at `root`.
- While the current node exists and its value differs from `val`: go left if `val < root->val`, otherwise go right.
- When the loop ends, `root` is either the matching node or `nullptr` (fell off the tree), so return it directly.

## Key Observation
Returning `root` itself handles both outcomes. If the loop exits on a match, `root` is the target node. If it exits because `root` became null, that null is exactly the "not found" answer.

## When to use this
If problem involves:
- Lookup, insertion, or deletion in a BST
- Following one root-to-node path using ordering comparisons
→ Think **iterative descent**. It gives O(1) space, where recursion would use O(h) stack.

## Edge Cases
- Empty tree (returns `nullptr` immediately).
- Target is the root (loop never runs).
- Target smaller than every node (walks the full left spine, returns `nullptr`).
- Skewed BST, where the path length equals the node count.

## Complexity
### Approach
Time: **O(h)**              
Space: **O(1)**

where:
- `h` = height of the tree (O(log n) if balanced, O(n) if skewed)

## Related Problems
- Insert into a Binary Search Tree
- Delete Node in a BST
- Validate Binary Search Tree
- Closest Binary Search Tree Value