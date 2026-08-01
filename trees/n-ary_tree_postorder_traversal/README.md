# N-ary Tree Postorder Traversal

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/  
Difficulty: Easy  
Pattern: Tree, DFS

## What I understood

Given the root of an N-ary tree, return its postorder traversal.

In postorder traversal, all children of a node are visited before the node itself.

## Example

```
Input
root = [1,null,3,2,4,null,5,6]

Output
[5,6,3,2,4,1]
```

## Idea

Postorder traversal follows the order:

- Visit every child.
- Visit the current node.

This can be implemented directly using recursion or iteratively by reversing a modified preorder traversal.

## Approach 1: Recursive DFS

- If the node is null, return.
- Recursively traverse every child.
- Add the current node to the answer.

## Approach 2: Iterative DFS (Stack + Reverse)

- Traverse the tree using a stack.
- Record nodes in Root → Children order.
- Reverse the recorded traversal.
- The reversed order becomes the required postorder traversal.

## Key Observation

Postorder means **Children → Root**.

A modified preorder traversal (**Root → Children**) becomes postorder after reversing the result.

## When to use this

If the problem involves:
- N-ary trees
- Postorder traversal
- Recursive DFS
- Iterative tree traversal

→ Think **DFS** or **Stack + Reverse**.

## Edge Cases

- Empty tree.
- Single-node tree.
- Tree with one child per node.
- Tree with many children at each node.

## Complexity

### Approach 1

Time: **O(n)**

Space: **O(h)**

### Approach 2

Time: **O(n)**

Space: **O(n)**

where:
- `n` = number of nodes
- `h` = height of the tree

## Related Problems

- N-ary Tree Preorder Traversal
- N-ary Tree Level Order Traversal
- Binary Tree Postorder Traversal
- Maximum Depth of N-ary Tree