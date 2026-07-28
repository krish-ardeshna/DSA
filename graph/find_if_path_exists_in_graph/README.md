# Find if Path Exists in Graph

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-if-path-exists-in-graph/  
Difficulty: Easy  
Pattern: Graph Traversal (DFS, BFS)

## What I understood
Given an undirected graph and two vertices (`source` and `destination`), determine whether there exists a path between them.

Example:
```
n = 3
edges = [[0,1],[1,2],[2,0]]
source = 0
destination = 2

Output = true
```

## Idea
Convert the edge list into an adjacency list, then traverse the graph starting from the source.

If the destination is reachable, return `true`; otherwise return `false`.

## Approach 1: Depth-First Search (DFS)
- Build the adjacency list.
- Start DFS from the source node.
- Mark every reachable node as visited.
- Check whether the destination was visited.

## Approach 2: Breadth-First Search (BFS)
- Build the adjacency list.
- Start BFS from the source node.
- Visit neighboring nodes level by level.
- Return `true` as soon as the destination is reached.

## Key Observation
The problem asks only whether the destination is reachable from the source.

Any complete graph traversal (DFS or BFS) correctly determines reachability.

## When to use this
If the problem involves:
- Reachability
- Graph traversal
- Path existence
- Connected components

→ Think **DFS/BFS Traversal**.

## Edge Cases
- `source == destination`
- Graph with no edges.
- Disconnected graph.
- Graph containing cycles.

## Complexity

### Approach 1
Time: **O(V + E)**  
Space: **O(V)**

### Approach 2
Time: **O(V + E)**  
Space: **O(V)**

where:
- `V` = number of vertices
- `E` = number of edges

## Related Problems
- Keys and Rooms
- Number of Provinces
- Number of Islands