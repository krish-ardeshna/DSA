# All Nodes Distance K in Binary Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/  
Difficulty: Medium  
Pattern: Tree - Parent Mapping + BFS (Treat Tree as Undirected Graph)

## What I understood
Given a binary tree, a `target` node, and an integer `k`, return the values of all nodes that are exactly distance `k` from `target` - distance measured in edges, and movement can go in ANY direction (down to children, or up to parent), not just downward like a normal tree traversal.

## Example
```
Input
root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output
[7,4,1]
```
```
Input
root = [1], target = 1, k = 3
Output
[]
```

## Idea
A binary tree only has child pointers (downward), but distance-k search needs to move in BOTH directions (up to parent too). Solve this by first building an explicit parent-pointer map (via any traversal, here BFS), effectively turning the tree into an UNDIRECTED graph. Then run a standard BFS from `target`, treating left child, right child, AND parent as equally valid neighbors - stopping once `k` levels have been expanded.

## Approach: Build Parent Pointers, BFS from Target Treating Tree as Graph
- **`markParents`**: BFS from root, recording `parent_tree[child] = current` for every left/right child encountered - builds a complete parent lookup map.
- **`distanceK`**: BFS from `target`, using a `visited` map to avoid revisiting nodes (critical, since now traversal can go up AND down, creating potential cycles back through parent-child links without tracking).
- Track `curr_level`; process level by level (standard BFS level batching via `size = q.size()`), incrementing `curr_level` each iteration, breaking out once `curr_level == k` (meaning the queue now holds exactly the nodes at distance k, unprocessed).
- For each node processed: push its left child, right child, AND parent (via the map) if not already visited.
- After the loop, whatever remains in the queue represents all nodes at exactly distance `k` - collect their values into the result.

## Key Observation
The break condition (`curr_level++ == k`) happens BEFORE processing that level's nodes - this means when the loop exits, the queue holds the nodes that WOULD be processed next (i.e., nodes at distance exactly `k`), which is exactly the answer, no further processing needed.

## When to use this
If problem involves:
- Distance/reachability queries in a tree requiring movement in BOTH parent and child directions
→ Think **build parent pointers via any traversal, then BFS treating the tree as an undirected graph**, using a visited set to prevent revisiting.

## Edge Cases
- `k = 0` (only the target itself, distance 0).
- `target` is the root (no parent to traverse upward through).
- `k` larger than the tree's actual maximum distance from target (result is empty, loop just exhausts the queue without breaking early).
- Target is a leaf node (must rely entirely on parent traversal to explore upward).

## Complexity
### Approach
Time: **O(n)** - O(n) to build parent map, O(n) worst case for BFS          
Space: **O(n)** - parent map, visited map, queue storage

where:
- `n` = number of nodes

## Related Problems
- Binary Tree Level Order Traversal
- Lowest Common Ancestor of a Binary Tree
- Amount of Time for Binary Tree to Be Infected
- Path Sum III