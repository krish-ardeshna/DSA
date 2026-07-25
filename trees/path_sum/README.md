# Path Sum

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/path-sum/  
Difficulty: Easy  
Pattern: Tree, DFS, Recursion

## What I understood
Given the root of a binary tree and an integer `targetSum`, determine whether the tree has a root-to-leaf path such that the sum of all node values equals `targetSum`.

Example:

root = [5,4,8,11,null,13,4,7,2,null,null,null,1]

targetSum = 22

Output = true

## Idea

### Approach 1 (Running Sum)
Maintain the sum from the root to the current node.

Whenever a leaf node is reached, compare the accumulated sum with the target.

### Approach 2 (Remaining Sum)
Subtract the current node's value from the target while traversing.

At a leaf node, check whether the remaining target equals the leaf value.

## Approach

### Approach 1
- Start with sum = 0.
- Add the current node value.
- Continue recursively.
- At a leaf node, compare the accumulated sum with the target.

### Approach 2
- Subtract the current node value from the target.
- Pass the remaining target to child nodes.
- At a leaf node, return true if the remaining target equals the leaf value.

## Key Observation
Every root-to-leaf path is explored exactly once.

Instead of storing the whole path, only the current sum (or remaining target) needs to be maintained.

## When to use this
If the problem involves:
- root-to-leaf path
- path sum
- DFS
- recursion

→ think DFS with Running Sum or Remaining Sum

## Edge Cases
- Empty tree
- Single node
- Negative values
- Target not present

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
- Path Sum II
- Path Sum III
- Sum Root to Leaf Numbers
- Binary Tree Maximum Path Sum