# Find Mode in Binary Search Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/  
Difficulty: Easy  
Pattern: Tree - Hashmap+DFS / Recursive Inorder / Morris Inorder (O(1) space)

## What I understood
Given a BST (may contain duplicates), find all values that occur with maximum frequency (mode). BST inorder traversal visits values in non-decreasing sorted order, meaning equal values appear consecutively — this property enables tracking frequency without a hashmap.

## Example
```
Input
root = [1,null,2,2]
Output
[2]
```
---

## Approach 1: Hashmap + DFS

### Idea
Simplest brute-force: count frequency of every value via any traversal (doesn't need to exploit BST property), then scan map for max frequency values.

### Steps
- DFS every node, increment `freq[val]`.
- Scan map once to find `maxFreq`.
- Scan map again, collect all values matching `maxFreq`.

### Complexity
Time: **O(n)**
Space: **O(n)** — hashmap storage

---

## Approach 2: Recursive Inorder Traversal (O(h) space)

### Idea
Exploit BST property: inorder traversal gives sorted order, so duplicate values are always adjacent. Track running count of current value vs `prev` node; reset count when value changes, update max/answer list on the fly — no hashmap needed.

### Steps
- Inorder traverse (left → node → right).
- At each node: if same as `prev`, increment `cnt`; else reset `cnt = 1`.
- If `cnt > maxCnt` → new mode found, clear `ans`, push current val.
- If `cnt == maxCnt` → tie, push current val too.
- Update `prev = node`, continue traversal.

### Complexity
Time: **O(n)**
Space: **O(h)** — recursion stack, h = tree height

---

## Approach 3: Morris Inorder Traversal (O(1) space)

### Idea
Same counting logic as Approach 2, but replaces recursion with Morris Traversal — uses tree's own right pointers as temporary threads to simulate the call stack, achieving true O(1) auxiliary space.

### Steps
- Standard Morris inorder: for each node, if no left child, process it and move right.
- If left child exists, find inorder predecessor (rightmost node in left subtree).
- If predecessor's right is null → thread it to current node, move left.
- If predecessor's right already points to current (thread exists) → remove thread, process current node, move right.
- Same `process()` counting logic as Approach 2 applied at each visit.

### Complexity
Time: **O(n)**
Space: **O(1)** — no recursion stack, no extra structure

---

## Key Observation
BST's sorted inorder property is the real unlock — turns frequency counting into a linear scan with adjacent-duplicate tracking, removing need for hashmap entirely. Morris traversal pushes this further, removing even the recursion stack by temporarily rewiring tree pointers.

## When to use this
If problem involves:
- BST (with possible duplicates) needing frequency-based answer
- Need O(1) space traversal on a tree
→ Think **Morris Inorder Traversal** for space optimization, or **recursive inorder** for simplicity.

## Edge Cases
- Single node tree.
- All nodes same value.
- No duplicates at all (every value is a mode, all with cnt=1).
- Skewed tree (all left or all right children).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Hashmap + DFS | O(n) | O(n) |
| Recursive Inorder | O(n) | O(h) |
| Morris Inorder | O(n) | O(1) |

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Binary Search Tree Iterator
- Minimum Absolute Difference in BST
- Validate Binary Search Tree
- Convert Sorted Array to Binary Search Tree