# Clone Graph
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/clone-graph/  
Difficulty: Medium  
Pattern: Graph Traversal (DFS, BFS)

## What I understood
Given a reference to a node in a connected undirected graph, create a deep copy of the entire graph.
The cloned graph should have:
- New nodes.
- The same values.
- The same connections.
- No shared nodes with the original graph.

## Example

```
Input
adjList = [[2,4],[1,3],[2,4],[1,3]]

Output
[[2,4],[1,3],[2,4],[1,3]]

Explanation
There are 4 nodes:
1 is connected to 2 and 4.
2 is connected to 1 and 3.
3 is connected to 2 and 4.
4 is connected to 1 and 3.

The output is a deep copy of the original graph with the same connections.
```

## Idea
Traverse the graph while creating a copy of every node.
Since graphs may contain cycles, maintain a mapping from each original node to its cloned node. This prevents cloning the same node multiple times and preserves the graph structure.

## Approach 1: Depth-First Search (DFS)
- Use recursion to traverse the graph.
- Clone a node when it is first visited.
- Store the mapping from original node to cloned node.
- Recursively clone all neighbors.

## Approach 2: Breadth-First Search (BFS)
- Use a queue to traverse the graph level by level.
- Clone each newly discovered node.
- Store the mapping from original node to cloned node.
- Connect cloned neighbors while processing each node.

## Key Observation
Graphs can contain cycles, so visiting the same node multiple times is possible.
Maintaining a mapping between original and cloned nodes ensures:
- Every node is cloned exactly once.
- Cycles are handled correctly.
- Neighbor relationships are preserved.

## When to use this
If the problem involves:
- Deep copying a graph
- Graph traversal
- Cyclic graphs
- Node-to-node mapping
→ Think **Graph Traversal + Hash Map**.

## Edge Cases
- Empty graph (`node == nullptr`).
- Graph with a single node.
- Self-loop on a node.
- Cyclic graph.

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
- Find if Path Exists in Graph
- Keys and Rooms
- Number of Provinces