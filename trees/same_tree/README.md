# Same Tree

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/same-tree/  
Difficulty: Easy  
Pattern: Binary Tree / DFS

## What I understood
We are given the roots of two binary trees.

Two trees are considered the same if:
- they have identical structure
- corresponding nodes contain the same values

We need to determine whether both trees are exactly the same.

Example:

Tree 1:

    1
   / \
  2   3

Tree 2:

    1
   / \
  2   3

Answer = true

## Idea
Compare both trees simultaneously using recursion.

For every pair of nodes:
- if both are null, they match
- if one is null and the other is not, they differ
- if values are different, they differ

If the current nodes match, recursively compare:
- left subtrees
- right subtrees

## Approach
- Check if both nodes are null
- Check if one node is null
- Compare node values
- Recursively compare left children
- Recursively compare right children
- Return true only if both subtree comparisons are true

## Key Observation
Two trees are identical only when:

- current nodes match
- left subtrees match
- right subtrees match

A mismatch at any level immediately makes the trees different.

## When to use this
If the problem involves:
- comparing two trees
- checking structural equality
- recursive tree traversal

→ think DFS comparison

## Edge Cases
- Both trees are empty
- One tree is empty
- Different node values
- Same values but different structure
- Single node trees

## Complexity
Time: O(n)  
Space: O(h)

where:
- n = number of nodes
- h = height of the tree

## Related Problems
- Symmetric Tree
- Subtree of Another Tree
- Balanced Binary Tree
- Maximum Depth of Binary Tree