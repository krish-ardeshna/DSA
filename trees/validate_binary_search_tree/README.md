# Validate Binary Search Tree

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/validate-binary-search-tree/  
Difficulty: Medium  
Pattern: Trees / DFS

## What I understood
We need to determine whether a binary tree is a valid Binary Search Tree (BST).

A BST satisfies:

- every node in the left subtree is smaller than the current node
- every node in the right subtree is greater than the current node
- both left and right subtrees must also be valid BSTs

Example:

    2
   / \
  1   3

Answer = true

## Idea

### Approach 1 (Recursion with Valid Range)
Maintain the valid range for every node.

Initially:

(-∞, +∞)

Whenever we move:
- left → update the upper bound
- right → update the lower bound

If any node violates its range, the tree is not a BST.

### Approach 2 (Iterative Inorder Traversal)
Perform an inorder traversal using a stack.

For a valid BST, inorder traversal always produces values in strictly increasing order.

Compare every node with the previously visited node.

If the current value is not greater than the previous one, the tree is invalid.

## Approach
- Traverse every node
- Verify BST properties
- Stop immediately if any violation is found
- Return true if every node satisfies the BST conditions

## Key Observation
A valid BST has an inorder traversal that is strictly increasing.

Another way to verify it is by ensuring every node lies within its valid value range.

## When to use this
If the problem involves:
- validating BST properties
- inorder traversal
- recursive constraints on node values

→ think inorder traversal or value range validation

## Edge Cases
- Empty tree
- Single node tree
- Duplicate values
- Invalid subtree
- Large positive or negative node values

## Complexity

### Approach 1
Time: O(n)  
Space: O(h)

### Approach 2
Time: O(n)  
Space: O(h)

where:
- n = number of nodes
- h = height of the tree

## Related Problems
- Same Tree
- Symmetric Tree
- Recover Binary Search Tree
- Kth Smallest Element in a BST