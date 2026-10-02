# Recover Binary Search Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/recover-binary-search-tree/  
Difficulty: Medium  
Pattern: BST - Inorder Traversal (Detect and Fix Swapped Nodes)

## What I understood
Exactly two nodes of a BST have had their VALUES mistakenly swapped. Recover the tree by fixing it in-place (swapping the values back), without changing the tree's structure.

## Example
```
Input
root = [1,3,null,null,2]
Output
[3,1,null,null,2]
```
```
Input
root = [3,1,4,null,null,2]
Output
[2,1,4,null,null,3]
```

## Idea
A correct BST's inorder traversal is strictly increasing. Swapping two values creates either ONE or TWO places where this increasing order breaks, depending on whether the swapped nodes are adjacent in the sequence or far apart. Running inorder traversal while tracking the previous node reveals these violation points directly.

## Approach: Inorder Traversal, Track First/Middle/Last Violation Nodes
- Seed `prev` with a sentinel node of value `INT_MIN`, so the very first real comparison never falsely triggers.
- During inorder traversal, whenever `root->val < prev->val` (a violation, order decreased), handle two cases:
  - First violation seen: record `first = prev` (the larger, out-of-place earlier value) and `middle = root` (the smaller value right after it).
  - A second violation (only happens when swapped nodes are NOT adjacent in inorder order): record `last = root`, this is the true second swapped node.
- After traversal: if BOTH `first` and `last` were set, the swap was non-adjacent, swap `first->val` and `last->val`. Otherwise, only `first` and `middle` were set (adjacent swap), swap those two instead.

## Key Observation
Exactly one violation occurs if the two swapped nodes happen to be adjacent in inorder order (fixed using `first`/`middle`), exactly two violations occur if they're farther apart (fixed using `first`/`last`), the algorithm doesn't need to know in advance which case applies, it just tracks both possibilities and decides at the end.

## When to use this
If problem involves:
- A BST invariant broken at exactly two points due to a swap
→ Think **inorder traversal with a running previous-node pointer**, violations in the expected sorted order directly identify the two misplaced nodes.

## Edge Cases
- Swapped nodes are adjacent in inorder sequence (only one violation detected).
- Swapped nodes are far apart (two violations detected).
- Root itself is one of the swapped nodes.
- Tree with only two nodes.

## Complexity
### Approach
Time: **O(n)**          
Space: **O(h)** - recursion stack, h = tree height

where:
- `n` = number of nodes
- `h` = height of the tree

## Related Problems
- Validate Binary Search Tree
- Kth Smallest Element in a BST
- Binary Search Tree Iterator
- Convert Sorted Array to Binary Search Tree