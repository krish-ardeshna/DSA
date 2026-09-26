# Construct Binary Tree from Inorder and Postorder Traversal
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/  
Difficulty: Medium  
Pattern: Tree - Recursive Index Range / Iterative Stack

## What I understood
Given `inorder` and `postorder` traversal arrays of a binary tree (no duplicate values), reconstruct and return the original tree.

## Example
```
Input
inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output
[3,9,20,null,null,15,7]
```

---

## Approach 1: Recursive Index Range + Hashmap

### Idea
Postorder's LAST element is always the current subtree's root (opposite of preorder, where it's the FIRST). Inorder still splits into left/right around the root's position. Using a hashmap for O(1) root-position lookup, recursively construct RIGHT subtree first conceptually (since postorder's structure naturally works right-to-left when picking roots from the end), building both subtrees via computed index ranges.

### Steps
- Build `inMap[value] = index`.
- `construct(is, ie, ps, pe)`: root = `postorder[pe]` (last element in current range), find `inRoot` in inorder, compute `leftsize = inRoot - is`.
- Recurse: left subtree uses `inorder[is, inRoot-1]` and `postorder[ps, ps+leftsize-1]`; right subtree uses `inorder[inRoot+1, ie]` and `postorder[ps+leftsize, pe-1]`.

### Complexity
Time: **O(n)**
Space: **O(n)** - hashmap + recursion stack

---

## Approach 2: Iterative Stack-Based

### Idea
Mirror image of the preorder+inorder iterative approach - process postorder from the END backward, and inorder from the END backward too. Since postorder is (left, right, root) and we're going backward, we effectively see (root, right, left) - the reverse mirrors preorder's (root, left, right) pattern, so the same stack logic applies with left/right roles swapped.

### Steps
- Push root (`postorder.back()`) onto stack, `inIndex = inorder.size()-1`.
- Iterate postorder BACKWARD from second-to-last: if stack top's value `!= inorder[inIndex]`, new node is the RIGHT child of stack top (mirrored from preorder's LEFT), push it.
- Else, pop stack (decrementing `inIndex` each pop) while top matches - attach new value as LEFT child (mirrored from preorder's RIGHT) of last popped node, push it.

### Complexity
Time: **O(n)**      
Space: **O(n)** - stack storage

---

## Key Observation
This problem is essentially the MIRROR of "Preorder+Inorder" - postorder's root position (last vs first) and the natural traversal direction (backward vs forward) are flipped, which correspondingly flips which child (left vs right) gets attached in each step of both approaches.

## When to use this
If problem involves:
- Reconstructing a tree from two traversal orders where one gives root position at an END (first for preorder, last for postorder)
→ Think **recursive index-range with hashmap**, or **iterative stack processed in the direction matching the root-first structure** (forward for preorder, backward for postorder), swapping left/right roles accordingly.

## Edge Cases
- Single node tree.
- Skewed tree (all left or all right children).
- Empty input (return nullptr).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursive Index Range | O(n) | O(n) |
| Iterative Stack | O(n) | O(n) |

where:
- `n` = number of nodes

## Related Problems
- Construct Binary Tree from Preorder and Inorder Traversal
- Construct Binary Tree from Preorder and Postorder Traversal
- Serialize and Deserialize Binary Tree
- Maximum Binary Tree