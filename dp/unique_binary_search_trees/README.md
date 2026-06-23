# Unique Binary Search Trees

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/unique-binary-search-trees/  
Difficulty: Medium  
Pattern: Dynamic Programming / Catalan Numbers

## What I understood
Given n distinct values from 1 to n, we need to find the number of structurally unique Binary Search Trees (BSTs) that can be formed.

Example:

n = 3

Possible unique BSTs = 5

Answer = 5

## Idea
For every node chosen as the root:

- nodes on the left form the left subtree
- nodes on the right form the right subtree

If:
- left subtree can be formed in L ways
- right subtree can be formed in R ways

Then the current root contributes:

L × R

possible BSTs.

By trying every node as the root and summing all possibilities, we get the answer.

## Approach
- Create a DP array where dp[i] represents the number of unique BSTs with i nodes
- Initialize:
  - dp[0] = 1
  - dp[1] = 1
- For every possible number of nodes:
  - Try every node as the root
  - Compute left subtree size
  - Compute right subtree size
  - Add all valid combinations
- Return dp[n]

## Key Observation
Choosing a root divides the remaining nodes into:

- left subtree nodes
- right subtree nodes

The total number of BSTs for that root equals:

(number of left BSTs) × (number of right BSTs)

This is the Catalan Number recurrence.

## When to use this
If the problem involves:
- counting BST structures
- counting unique tree configurations
- combining left and right subproblems

→ think Dynamic Programming and Catalan Numbers

## Edge Cases
- n = 1
- n = 2
- Small values of n
- Large values requiring DP reuse

## Complexity
Time: O(n²)  
Space: O(n)

## Related Problems
- Unique Binary Search Trees II
- Different Ways to Add Parentheses
- Count Number of Binary Trees
- Catalan Number Problems