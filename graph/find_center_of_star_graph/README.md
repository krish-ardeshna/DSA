# Find Center of Star Graph

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-center-of-star-graph/  
Difficulty: Easy  
Pattern: Star Graph Property

## What I understood
A star graph has one center node connected to every other node.

Given the edges of a star graph, find the center node.

Example:

edges = [[1,2],[2,3],[4,2]]

Output = 2

## Idea
Start with a straightforward counting solution and gradually optimize it by reducing unnecessary work until reaching the constant-time observation.

## Approach 1: Frequency Map
- Count the frequency of every node.
- Return the node whose frequency equals the number of edges.

## Approach 2: Count Candidate Occurrences
- Take the two nodes from the first edge as candidates.
- Count how many times each candidate appears.
- Return the candidate whose count equals the number of edges.

## Approach 3: Observation (Optimal)
- Compare the first two edges.
- The common node is the center.

## Key Observation
Every edge in a star graph contains the center node. Therefore, the common node between the first two edges must be the center.

## When to use this
If the problem involves:
- star graph
- center node
- node degree
- common node

→ think Star Graph Property

## Edge Cases
- Minimum star graph: [[1,2],[2,3]]
- Center appears in either position of an edge
- Any valid ordering of edges

## Complexity

### Approach 1
Time: O(n)

Space: O(n)

### Approach 2
Time: O(n)

Space: O(1)

### Approach 3
Time: O(1)

Space: O(1)

## Related Problems
- Find the Town Judge
- Find Champion II
- Find Greatest Common Divisor of Array