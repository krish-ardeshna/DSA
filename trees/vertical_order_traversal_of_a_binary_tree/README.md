# Vertical Order Traversal of a Binary Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/  
Difficulty: Hard  
Pattern: Tree - BFS + Nested Ordered Maps (Column, Row, Sorted Values)

## What I understood
Assign each node a coordinate: root at `(0, 0)`, left child at `(x-1, y+1)`, right child at `(x+1, y+1)` (x = column, y = row/depth). Group nodes by column (left to right), and within each column, order by row (top to bottom); if multiple nodes share the exact same `(x, y)` position, they must be sorted by VALUE (ascending) as a tie-breaker.

## Example
```
Input
root = [3,9,20,null,null,15,7]
Output
[[9],[3,15],[20],[7]]
```
```
Input
root = [1,2,3,4,5,6,7]
Output
[[4],[2],[1,5,6],[3],[7]]
```

## Idea
Three levels of ordering are needed simultaneously: column (x) ascending, then row (y) ascending within each column, then value ascending for ties at the exact same (x,y). Nested ordered containers naturally handle all three: `map<int, map<int, multiset<int>>>` — outer map keyed by column (auto-sorted), inner map keyed by row (auto-sorted), and a multiset for values at that exact position (auto-sorted, allows duplicates).

## Approach: BFS with (x, y) Coordinates, Nested Map + Multiset for Ordering
- BFS traversal (queue-based) tracking each node alongside its `(x, y)` coordinate, starting root at `(0,0)`.
- For each dequeued node: insert its value into `nodes[x][y]` (a multiset, handling same-position duplicates via auto-sort).
- Push children with updated coordinates: left → `(x-1, y+1)`, right → `(x+1, y+1)`.
- After BFS completes, iterate the outer map (columns in order) — for each column, iterate its inner map (rows in order), flattening all multiset values (already sorted) into that column's result vector.
- Collect all columns into final answer.

## Key Observation
Using `multiset` (not `set`) for the innermost container is essential — multiple nodes CAN share the exact same `(x, y)` coordinate (e.g., a node's right child and its sibling's left child can align), and their VALUES need to be sorted among themselves without losing duplicates, which `multiset` naturally provides via its sorted insertion.

## When to use this
If problem involves:
- Multi-level ordering (grouping + sub-sorting + tie-breaking) of tree/graph nodes based on computed coordinates
→ Think **nested ordered containers** (map of maps, or map of multisets) that naturally enforce each level's required sort order without needing manual sorting logic afterward.

## Edge Cases
- Multiple nodes at the exact same (x, y) position (value tie-breaking required).
- Skewed tree (all nodes in a single column, or spread across many single-node columns).
- Single node tree.
- Deep tree with many overlapping columns from different branches.

## Complexity
### Approach
Time: **O(n log n)** — BFS is O(n), but map/multiset insertions are O(log n) each, plus final flattening            
Space: **O(n)** — nested map/multiset storage, output storage

where:
- `n` = number of nodes

## Related Problems
- Binary Tree Vertical Order Traversal (LC 314, easier variant without value tie-breaking)
- Binary Tree Level Order Traversal
- Cousins in Binary Tree
- Find Largest Value in Each Tree Row