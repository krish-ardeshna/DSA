# Construct Binary Tree from Preorder and Inorder Traversal
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/  
Difficulty: Medium  
Pattern: Tree - Recursive Index Range / Iterative Stack

## What I understood
Given `preorder` and `inorder` traversal arrays of a binary tree (no duplicate values), reconstruct and return the original tree.

## Example
```
Input
preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output
[3,9,20,null,null,15,7]
```

---

## Approach 1: Recursive Index Range + Hashmap

### Idea
Preorder's FIRST element is always the current subtree's root. Inorder traversal splits at the root's position: everything to its LEFT in inorder belongs to the left subtree, everything to the RIGHT belongs to the right subtree. Using a hashmap for O(1) root-position lookup in inorder, recursively construct left and right subtrees using computed index ranges.

### Steps
- Build `inMap[value] = index` for O(1) inorder position lookup.
- `construct(ps, pe, is, ie)`: root = `preorder[ps]`, find its position in inorder (`inRoot`), compute `leftsize = inRoot - is`.
- Recurse: left subtree uses `preorder[ps+1, ps+leftsize]` and `inorder[is, inRoot-1]`; right subtree uses the remaining ranges.

### Complexity
Time: **O(n)**          
Space: **O(n)** - hashmap + recursion stack

---

## Approach 2: Iterative Stack-Based

### Idea
Simulate the construction using a stack representing the current "spine" of unfinished left-children. Walk through preorder; if the current stack top doesn't match the current inorder position, it means we're still going left. If it DOES match, pop the stack (finishing left subtrees) until it no longer matches, then attach as a right child.

### Steps
- Push root (`preorder[0]`) onto stack, `inIndex = 0`.
- For each subsequent preorder value: if stack top's value `!= inorder[inIndex]`, this new node is the LEFT child of stack top, push it.
- Else, pop stack (advancing `inIndex` each pop) while top matches inorder[inIndex] - the last popped node gets this new value as its RIGHT child, push it.

### Complexity
Time: **O(n)**      
Space: **O(n)** - stack storage

---

## Key Observation
Both approaches rely on the same core insight (preorder gives root order, inorder gives left/right split), but Approach 1 makes this explicit via index-range recursion, while Approach 2 encodes it implicitly through stack behavior - matching against inorder position determines whether to attach as left or right child.

## When to use this
If problem involves:
- Reconstructing a tree from two traversal orders
→ Think **recursive index-range with hashmap** for clarity, or **iterative stack** for avoiding recursion overhead on deep trees.

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
- Construct Binary Tree from Inorder and Postorder Traversal
- Construct Binary Tree from Preorder and Postorder Traversal
- Serialize and Deserialize Binary Tree
- Maximum Binary Tree