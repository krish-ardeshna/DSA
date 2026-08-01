# N-ary Tree Preorder Traversal

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/  
Difficulty: Easy  
Pattern: Tree, DFS

## What I understood

Given the root of an N-ary tree, return its preorder traversal.

In preorder traversal, the current node is visited before all of its children.

## Example

```
Input
root = [1,null,3,2,4,null,5,6]

Output
[1,3,5,6,2,4]
```

## Idea

Preorder traversal follows the order:

- Visit the current node.
- Visit every child from left to right.

This can be implemented recursively or iteratively using a stack.

## Approach 1: Recursive DFS

- If the node is null, return.
- Add the current node to the answer.
- Recursively traverse each child.

## Approach 2: Iterative DFS (Stack)

- Push the root onto a stack.
- Pop the top node and add it to the answer.
- Push the children onto the stack in reverse order.
- Repeating this process preserves the left-to-right preorder traversal.

## Key Observation

Preorder always follows the order **Root → Children**.

In the iterative approach, pushing children from **right to left** ensures they are processed from **left to right** because a stack follows the LIFO principle.

## When to use this

If the problem involves:
- N-ary trees
- Preorder traversal
- Recursive DFS
- Iterative tree traversal

→ Think **DFS** or **Stack**.

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
- `n` = number of nodes.
- `h` = height of the tree.

## Related Problems

- N-ary Tree Postorder Traversal
- N-ary Tree Level Order Traversal
- Binary Tree Preorder Traversal
- Maximum Depth of N-ary Tree