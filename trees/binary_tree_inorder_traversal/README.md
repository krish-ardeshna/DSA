# Binary Tree Inorder Traversal

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/  
Difficulty: Easy  
Pattern: Binary Tree / DFS

## What I understood
We need to return the inorder traversal of a binary tree.

Inorder traversal follows:

Left → Root → Right

Example:

Tree:

    1
     \
      2
     /
    3

Inorder = [1,3,2]

## Idea

### Approach 1 (Iterative Traversal using Stack)
Use a stack to simulate recursion.

Keep moving to the left subtree and store nodes in the stack.

When no left child exists:
- process the current node
- move to the right subtree

### Approach 2 (Recursive Traversal)
Use recursion to naturally follow inorder traversal.

For every node:
- visit left subtree
- process current node
- visit right subtree

This directly matches the inorder traversal definition.

## Approach
- Traverse the left subtree
- Visit the current node
- Traverse the right subtree
- Store visited nodes in the answer array
- Return the final traversal

## Key Observation
Inorder traversal always processes nodes in:

Left → Root → Right

The recursive solution follows this order naturally, while the iterative solution uses a stack to simulate the recursive call stack.

## When to use this
If the problem involves:
- inorder traversal
- binary tree DFS
- converting recursive traversal into iterative traversal

→ think recursion or stack-based DFS

## Edge Cases
- Empty tree
- Single node tree
- Only left children
- Only right children
- Balanced tree

## Complexity

### Approach 1
Time: O(n)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(n)

## Related Problems
- Binary Tree Preorder Traversal
- Binary Tree Postorder Traversal
- Binary Tree Level Order Traversal
- Validate Binary Search Tree