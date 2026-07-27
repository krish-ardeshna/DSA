# Keys and Rooms

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/keys-and-rooms/  
Difficulty: Medium  
Pattern: Graph Traversal (DFS, BFS)

## What I understood
Each room may contain keys to other rooms. Initially, only room `0` is unlocked.

Determine whether it is possible to visit every room.

Example:
```
rooms = [[1],[2],[3],[]]
Output = true
```

## Idea
Treat each room as a graph node and each key as a directed edge.

Start from room `0` and traverse the graph. If every room is visited, return `true`; otherwise return `false`.

## Approach 1: Depth-First Search (DFS)
- Start DFS from room `0`.
- Visit every reachable room recursively.
- After traversal, check whether every room was visited.

## Approach 2: Breadth-First Search (BFS)
- Start BFS from room `0`.
- Visit rooms level by level using a queue.
- After traversal, check whether every room was visited.

## Key Observation
The problem is simply checking whether every node is reachable from node `0` in a directed graph.

Both DFS and BFS visit exactly the set of reachable rooms.

## When to use this
If the problem involves:
- Reachability
- Graph traversal
- Visiting all nodes
- Connected components from a starting node

→ Think **DFS/BFS Traversal**.

## Edge Cases
- Only one room: `[[]]`
- Rooms that contain no keys.
- Cycles between rooms.
- Unreachable rooms.

## Complexity

### Approach 1
Time: **O(V + E)**  
Space: **O(V)**

### Approach 2
Time: **O(V + E)**  
Space: **O(V)**

where:
- `V` = number of rooms
- `E` = total number of keys

## Related Problems
- Number of Provinces
- Find if Path Exists in Graph
- Number of Islands