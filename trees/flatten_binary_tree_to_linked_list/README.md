# Flatten Binary Tree to Linked List
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/  
Difficulty: Medium  
Pattern: Tree - In-Place Threading / Iterative Stack / Recursive Reverse Postorder

## What I understood
Flatten a binary tree into a "linked list" IN-PLACE, using the same `TreeNode` structure - `right` pointer acts as the "next" pointer, `left` is always set to `nullptr`. The resulting order must match PREORDER traversal (root, left, right).

## Example
```
Input
root = [1,2,5,3,4,null,6]
Output
[1,null,2,null,3,null,4,null,5,null,6]
```
```
Input
root = []
Output
[]
```

---

## Approach 1: In-Place Threading (O(1) Space, Morris-style)

### Idea
For each node with a left child, find the RIGHTMOST node in that left subtree (its "predecessor" in preorder terms), and thread the current node's ORIGINAL right subtree onto that rightmost node's right pointer. Then move the left subtree to become the new right, and clear left - no extra space needed.

### Steps
- Traverse with `curr`, starting at root.
- If `curr->left` exists: find rightmost node in left subtree (`prev`), attach `curr->right` there, move `curr->left` to `curr->right`, set `curr->left = nullptr`.
- Move `curr = curr->right` (now correctly following the flattened chain), repeat.

### Complexity
Time: **O(n)** amortized (finding rightmost node can be O(n) worst case per call, but amortizes to O(n) total across whole traversal)       
Space: **O(1)**

---

## Approach 2: Iterative Stack-Based

### Idea
Use an explicit stack to simulate preorder traversal (push right before left, so left pops first). After popping each node, connect it to whatever's now on top of the stack (the next node in preorder order) via its right pointer.

### Steps
- Push root onto stack.
- Pop a node; push its right child then left child (ensures left is processed next, matching preorder).
- Set popped node's `right` to the new stack top (next in preorder), clear its `left`.

### Complexity
Time: **O(n)**      
Space: **O(n)** - stack storage

---

## Approach 3: Recursive Reverse Postorder (Right, Left, Root)

### Idea
Process the tree in REVERSE preorder fashion (right subtree first, then left, then current node) - this builds the flattened list from the BACK forward, using a `prev` pointer (class member) to track "what comes next" as recursion unwinds.

### Steps
- Recurse into `root->right` first, then `root->left` (reverse of normal preorder).
- After both recursive calls return, set `root->right = prev` (the previously processed node, which is what should come AFTER root in the final list), clear `root->left`.
- Update `prev = root` before returning.

### Complexity
Time: **O(n)**      
Space: **O(h)** - recursion stack, h = tree height

---

## Key Observation
All three approaches achieve the same preorder-linked-list result via fundamentally different mechanics: Approach 1 exploits tree structure directly (no extra memory), Approach 2 explicitly simulates the traversal order via a stack, and Approach 3 cleverly builds the list backward using recursion's natural unwind order combined with a persistent `prev` reference.

## When to use this
If problem involves:
- In-place tree-to-list flattening/threading
→ Think **Morris-style threading** for true O(1) space, **stack-based iteration** for straightforward simulation, or **reverse postorder recursion** for an elegant backward-construction trick.

## Edge Cases
- Empty tree.
- Single node tree.
- Tree with only left children (no right subtrees at all).
- Tree with only right children (already "flattened" in structure, minimal work needed).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| In-Place Threading | O(n) | O(1) |
| Iterative Stack | O(n) | O(n) |
| Recursive Reverse Postorder | O(n) | O(h) |

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Construct Binary Tree from Preorder and Inorder Traversal
- Binary Tree Preorder Traversal
- Convert Binary Search Tree to Sorted Doubly Linked List
- Increasing Order Search Tree