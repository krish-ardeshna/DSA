# Binary Tree Postorder Traversal

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/  
Difficulty: Easy  
Pattern: Binary Tree / DFS

## What I understood
We need to return the postorder traversal of a binary tree.

Postorder traversal follows:

Left → Right → Root

Example:

Tree:

    1
     \
      2
     /
    3

Postorder = [3,2,1]

## Idea
Instead of directly performing postorder traversal, we perform a modified preorder traversal.

Normal preorder:

Root → Left → Right

Modified preorder:

Root → Right → Left

The obtained sequence is then reversed.

After reversing:

Left → Right → Root

which becomes the required postorder traversal.

## Approach
- Create an empty stack
- Push the root node
- While stack is not empty:
  - remove the top node
  - add its value to the answer
  - push left child if it exists
  - push right child if it exists
- Reverse the final answer
- Return the result

## Key Observation
The reverse of:

Root → Right → Left

is:

Left → Right → Root

which is exactly the postorder traversal order.

## When to use this
If the problem involves:
- postorder traversal
- iterative tree traversal
- replacing recursion with stacks

→ think modified preorder + reverse

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
- Binary Tree Preorder Traversal
- Binary Tree Inorder Traversal
- N-ary Tree Postorder Traversal
- Binary Tree Level Order Traversal