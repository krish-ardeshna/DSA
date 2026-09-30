# Delete Node in a BST
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/delete-node-in-a-bst/  
Difficulty: Medium  
Pattern: BST - Iterative Search + Splice-Out Deletion

## What I understood
Given a BST and a key, delete the node with that value (if it exists) and return the root of the resulting BST, which must still satisfy BST ordering.

## Example
```
Input
root = [5,3,6,2,4,null,7], key = 3
Output
[5,4,6,2,null,null,7]
```
```
Input
root = [5,3,6,2,4,null,7], key = 0
Output
[5,3,6,2,4,null,7]
```

## Idea
Deleting a node with two children is the only tricky case, and it's handled without ever explicitly finding an "inorder successor/predecessor value" to copy. Instead, the entire RIGHT subtree gets grafted onto the RIGHTMOST node of the LEFT subtree, then the left subtree becomes the new subtree root. This preserves BST ordering because every value in the left subtree is still smaller than every value in the right subtree, and the rightmost node of the left subtree has no right child to conflict with.

## Approach: Locate Parent Iteratively, Splice Left Subtree Under Predecessor
- `helper(root)`: handles deletion AT this node.
  - No left child → just return `root->right` (right subtree takes its place).
  - No right child → return `root->left`.
  - Both children exist → find the rightmost node in the left subtree (`findLastRight`), attach the original right subtree there, then return the left subtree as the replacement.
- `deleteNode`: if `root` itself is the target, delegate directly to `helper`.
  - Otherwise, walk down iteratively comparing `key` against `root->val`, but stop ONE STEP EARLY, checking if the NEXT node (`root->left` or `root->right`) is the target, so the parent's pointer can be reassigned directly via `helper`.
  - Return `dummy` (root saved before the walk began), since `root` itself gets reassigned during traversal.

## Key Observation
Stopping one step early (checking the CHILD before moving into it) is essential, since deletion requires modifying the PARENT's pointer, and once you've moved `root` past the parent, there's no way back to fix that pointer without extra bookkeeping.

## When to use this
If problem involves:
- Deleting a node from a BST while preserving its structure and ordering
→ Think **splice the left subtree's rightmost node onto the right subtree**, avoiding the need to explicitly find and copy a successor value, and walk down checking the NEXT node rather than the current one so the parent link can be updated directly.

## Edge Cases
- Key not present in tree (tree returned unchanged).
- Deleting the root itself.
- Deleting a leaf node (both children null, `helper` returns `nullptr` naturally).
- Deleting a node with only one child (left or right).

## Complexity
### Approach
Time: **O(h)** - height of tree to locate node, plus height of left subtree to find rightmost node      
Space: **O(1)** - iterative descent (recursion in `findLastRight` uses O(h) stack in the worst case)

where:
- `h` = height of the tree (O(log n) if balanced, O(n) if skewed)

## Related Problems
- Insert into a Binary Search Tree
- Search in a Binary Search Tree
- Validate Binary Search Tree
- Kth Smallest Element in a BST