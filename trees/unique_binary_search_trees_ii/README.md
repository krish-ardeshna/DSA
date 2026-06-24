# Unique Binary Search Trees II

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/unique-binary-search-trees-ii/  
Difficulty: Medium  
Pattern: Recursion / Divide and Conquer / BST

## What I understood
Given an integer n, we need to generate all structurally unique BSTs that store values from 1 to n.

Unlike Unique BST I, where we only count the number of BSTs, here we must actually construct and return all possible trees.

Example:

n = 3

Output contains 5 unique BSTs.

## Idea
Try every value in the range as the root.

For a chosen root:

- values smaller than the root form the left subtree
- values greater than the root form the right subtree

Recursively generate:
- all possible left subtrees
- all possible right subtrees

Then combine every left subtree with every right subtree.

## Approach
- Create a recursive function buildTrees(start, end)
- If start > end:
  - return a vector containing nullptr
- Try every value as the root
- Generate all left subtree possibilities
- Generate all right subtree possibilities
- Combine every left tree with every right tree
- Create a new root and attach them
- Store all generated trees
- Return the final list

## Key Observation
For every chosen root:

Number of BSTs formed =

(all possible left subtrees) × (all possible right subtrees)

Therefore, we generate every valid combination of left and right subtree structures.

## When to use this
If the problem involves:
- generating all possible trees
- recursive structure construction
- divide and conquer on ranges
- BST generation

→ think recursive partitioning around a root

## Edge Cases
- n = 1
- n = 0
- Small ranges
- Empty subtree cases

## Complexity
Time: O(Cn × n)  
Space: O(Cn × n)

where:

- Cn is the nth Catalan Number
- Number of generated BSTs = Catalan(n)

## Related Problems
- Unique Binary Search Trees
- Different Ways to Add Parentheses
- Full Binary Trees
- Construct Binary Search Tree from Preorder Traversal