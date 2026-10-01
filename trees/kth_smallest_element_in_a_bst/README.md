# Kth Smallest Element in a BST
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/  
Difficulty: Medium  
Pattern: BST - Inorder Traversal (Stack-Based / Morris O(1) Space)

## What I understood
Given a BST and integer `k`, return the `k`-th smallest value in the tree (1-indexed).

## Example
```
Input
root = [3,1,4,null,2], k = 1
Output
1
```
```
Input
root = [5,3,6,2,4,null,null,1], k = 3
Output
3
```

---

## Approach 1: Iterative Stack-Based Inorder

### Idea
Inorder traversal of a BST visits values in ascending sorted order. Simulating this traversal iteratively with an explicit stack lets the walk STOP as soon as the `k`-th value is popped, without needing to build a full sorted list first.

### Steps
- Push all left-spine nodes from `root` onto the stack.
- Pop the top, decrement `k` - if `k` hits 0, this popped node's value is the answer.
- Move to that node's right child and repeat pushing its left-spine.

### Complexity
Time: **O(h + k)** - h to reach leftmost node, then k pops      
Space: **O(h)** - stack storage

---

## Approach 2: Morris Inorder Traversal (O(1) Space)

### Idea
Same inorder visiting order as Approach 1, but avoids the stack entirely by temporarily threading the tree's own null right-pointers to simulate the "return path" a stack would normally provide.

### Steps
- If current node has no left child, it's visitable now: decrement `k`, if 0 record `ans`, move right.
- Otherwise, find the current node's inorder predecessor (rightmost node in its left subtree).
  - If predecessor's right pointer is null, thread it to point back to current node, move left (into the subtree).
  - If predecessor's right pointer already points to current node (thread already exists, meaning the left subtree is fully processed), remove the thread, this node is now visitable: decrement `k`, if 0 record `ans`, move right.

### Complexity
Time: **O(n)** - each edge in the tree is traversed at most twice (once to create the thread, once to remove it)            
Space: **O(1)** - no stack, no recursion

---

## Key Observation
Both approaches produce values in the same sorted order, they just differ in how the "resume point" after visiting a node's left subtree is remembered. Approach 1 remembers it explicitly on a stack; Approach 2 remembers it by temporarily rewiring the tree itself, avoiding any extra memory.

## When to use this
If problem involves:
- Finding the k-th element (smallest/largest) in a BST via inorder order
→ Think **stack-based inorder** for simplicity and early-exit efficiency, or **Morris traversal** when O(1) auxiliary space is required.

## Edge Cases
- `k` equal to total node count (answer is the maximum value, tree's rightmost node).
- `k = 1` (answer is the minimum value, tree's leftmost node).
- Skewed tree (left-leaning or right-leaning).
- Single node tree (`k` must be 1).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Iterative Stack | O(h + k) | O(h) |
| Morris Traversal | O(n) | O(1) |

where:
- `n` = number of nodes
- `h` = height of the tree

## Related Problems
- Kth Largest Element in a Stream
- Validate Binary Search Tree
- Binary Search Tree Iterator
- Inorder Successor in BST