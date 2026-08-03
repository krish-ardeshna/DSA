# Minimum Depth of Binary Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/  
Difficulty: Easy  
Pattern: Tree - DFS (Recursion) / BFS (Queue) / DFS (Iterative Stack)

## What I understood
Minimum depth = number of nodes on shortest path from root down to nearest leaf.
A leaf = node with no children. A node with only one child does NOT count as leaf — must go through its non-null child.

## Example
Input:  
root = [3,9,20,null,null,15,7]  
Output: 
2

---

## Approach 1: Recursive DFS

### Idea
Naive `min(left, right)` breaks when one side missing — that side returns 0, falsely wins as "shorter" though not a valid leaf path. Special-case single-child nodes to force traversal down the existing child.

### Steps
- Base case: `root == NULL` → depth 0.
- Left child missing → must go right → `1 + minDepth(right)`.
- Right child missing → must go left → `1 + minDepth(left)`.
- Both exist → `1 + min(minDepth(left), minDepth(right))`.

### Complexity
Time: **O(n)**
Space: **O(h)** — recursion stack

---

## Approach 2: BFS (Queue)

### Idea
BFS explores level by level. First leaf encountered is guaranteed the shallowest — return immediately, no need to explore rest of tree.

### Steps
- Push `(root, depth=1)` into queue.
- Pop node; if it's a leaf (`no left, no right`) → return depth immediately.
- Else push existing children with `depth+1`.

### Complexity
Time: **O(n)** worst case, but often better in practice (early exit)
Space: **O(n)** — queue can hold up to one full level

---

## Approach 3: DFS (Iterative, Explicit Stack)

### Idea
Same traversal logic as recursive DFS, but recursion replaced with manual stack to avoid call-stack overhead / stack overflow risk on deep skewed trees. Explores fully (no early exit like BFS), tracks min via `ans` variable.

### Steps
- Push `(root, depth=1)` onto stack.
- Pop node; if leaf → update `ans = min(ans, depth)`.
- Push existing children with `depth+1`.
- Continue till stack empty, return `ans`.

### Complexity
Time: **O(n)**
Space: **O(h)** — stack size bound by tree height

---

## Key Observation
Single-child nodes are the trap across all approaches — must guard against counting missing-child depth as valid leaf path. BFS is uniquely efficient here since problem asks for *minimum*, letting early exit skip unnecessary exploration. Iterative DFS avoids recursion depth limits but loses BFS's early-exit advantage.

## When to use this
If problem involves:
- Tree depth / height computation
- Leaf-only path constraints
- Need shortest path in unweighted tree → **BFS** wins
- Worried about recursion stack limits on deep trees → **Iterative DFS**

## Edge Cases
- Empty tree (`root == NULL`).
- Single node tree.
- Skewed tree (only left or only right children throughout).
- One child missing at various levels.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursive DFS | O(n) | O(h) |
| BFS (Queue) | O(n) worst, faster avg | O(n) |
| Iterative DFS (Stack) | O(n) | O(h) |

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Maximum Depth of Binary Tree
- Balanced Binary Tree
- Diameter of Binary Tree
- Binary Tree Level Order Traversal