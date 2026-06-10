# Binary Tree Preorder Traversal

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/  
Difficulty: Easy  
Pattern: Binary Tree / DFS

## What I understood
We need to return the preorder traversal of a binary tree.

Preorder traversal follows:

Root → Left → Right

Example:

Tree:

    1
     \
      2
     /
    3

Preorder = [1,2,3]

## Idea
Use a stack to simulate recursion.

Process the current node first, then ensure the left subtree is processed before the right subtree.

Since a stack follows Last In First Out (LIFO), we push:
- right child first
- left child second

This guarantees that the left child is processed before the right child.

## Approach
- Create an empty stack
- Push the root node
- While stack is not empty:
  - remove the top node
  - add its value to the answer
  - push right child if it exists
  - push left child if it exists
- Return the answer

## Key Observation
Preorder traversal requires:

Root → Left → Right

Since a stack processes the most recently inserted element first, pushing the right child before the left child ensures the left subtree is visited first.

## When to use this
If the problem involves:
- tree traversal
- preorder traversal
- replacing recursion with iteration

→ think stack-based DFS

## Edge Cases
- Empty tree
- Single node tree
- Only left children
- Only right children
- Balanced tree

## Complexity
Time: O(n)  
Space: O(n)

## Related Problems
- Binary Tree Inorder Traversal
- Binary Tree Postorder Traversal
- N-ary Tree Preorder Traversal
- Binary Tree Level Order Traversal