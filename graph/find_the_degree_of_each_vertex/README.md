# Find the Degree of Each Vertex

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-degree-of-each-vertex/  
Difficulty: Easy  
Pattern: Graph, Matrix Traversal

## What I understood
An adjacency matrix represents an undirected graph where:
- `matrix[i][j] = 1` means there is an edge between vertices `i` and `j`.
- `matrix[i][j] = 0` means there is no edge.

Return the degree of every vertex.

Example:
```
matrix = [
  [0,1,1],
  [1,0,0],
  [1,0,0]
]

Output = [2,1,1]
```

## Idea
The degree of a vertex is simply the number of edges connected to it.

In an adjacency matrix, each row represents all connections of one vertex. Therefore, summing all values in a row gives its degree.

## Approach: Row-wise Degree Counting
- Create a degree array of size `n`.
- Traverse each row of the adjacency matrix.
- Sum all values in the row.
- Store the sum as the degree of that vertex.

## Key Observation
Each row of an adjacency matrix directly represents all edges incident to a vertex.

So, the row sum equals the degree of that vertex.

## When to use this
If the problem involves:
- Adjacency matrix
- Degree of vertices
- Matrix traversal
- Graph representation

→ Think **Row-wise Matrix Traversal**.

## Edge Cases
- Graph with a single vertex.
- Graph with no edges.
- Complete graph.
- Isolated vertices (degree `0`).

## Complexity

### Approach
Time: **O(n²)**  
Space: **O(n)**

## Related Problems
- Find Center of Star Graph
- Find the Town Judge
- Number of Provinces