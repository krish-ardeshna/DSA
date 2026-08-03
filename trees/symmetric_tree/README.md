# Symmetric Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/symmetric-tree/  
Difficulty: Easy  
Pattern: Tree - DFS (Recursion) / BFS (Queue)

## What I understood
A tree is symmetric if its left subtree is a mirror reflection of its right subtree.
Mirror means: root values equal, left's left matches right's right, left's right matches right's left — recursively.

## Example
```
Input
root = [1,2,2,3,4,4,3]
Output
true
```
```
Input
root = [1,2,2,null,3,null,3]
Output
false
```

---

## Approach 1: Recursive Mirror Check

### Idea
Instead of comparing tree to itself, compare `left` subtree against `right` subtree using a mirror rule: `left->left` vs `right->right`, `left->right` vs `right->left`.

### Steps
- If both nodes null → symmetric at this pair, return true.
- If only one null → asymmetric, return false.
- Values must match.
- Recurse: `isMirror(left->left, right->right) && isMirror(left->right, right->left)`.

### Complexity
Time: **O(n)**
Space: **O(h)** — recursion stack

---

## Approach 2: BFS (Queue)

### Idea
Push node pairs that should mirror each other. Pop two at a time, compare. Push their children in mirrored order so next pair popped is also a valid mirror pair.

### Steps
- Push `root->left`, `root->right`.
- Pop pair `(left, right)`.
  - Both null → skip (continue).
  - One null → return false.
  - Values differ → return false.
- Push `(left->left, right->right)` and `(left->right, right->left)` in mirrored order.
- Empty queue with no mismatch → return true.

### Complexity
Time: **O(n)**
Space: **O(n)** — queue can hold up to one full level

---

## Key Observation
Core idea same in both: compare **outer pair** (left.left vs right.right) and **inner pair** (left.right vs right.left) at every level. Recursion does this via call stack, BFS does it via explicit queue ordering.

## When to use this
If problem involves:
- Structural mirror / palindrome-tree check
- Comparing two subtrees under a flipped rule
→ Think **Mirror recursion** or **BFS with paired pushes**.

## Edge Cases
- Empty tree (`root == NULL`) — note: current code assumes root non-null, will crash on empty input if root itself is null. Verify LC test cases handle this (LC guarantees root non-null per constraints for this problem, but flagging since I haven't verified their exact constraint text).
- Single node tree → true.
- Tree with only one side populated.
- Equal values but different structure.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursive Mirror | O(n) | O(h) |
| BFS (Queue) | O(n) | O(n) |

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Same Tree
- Invert Binary Tree
- Subtree of Another Tree
- Binary Tree Diameter