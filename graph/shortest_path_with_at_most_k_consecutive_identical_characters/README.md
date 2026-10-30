# Shortest Path With At Most K Consecutive Identical Characters
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Graph (Dijkstra on an Expanded State Graph: Node + Current Run Length)

## What I understood
(Reconstructed from the accepted code, recheck against the LC statement.)  
A directed weighted graph has `n` nodes (`0` to `n - 1`). Each edge is `[from, to, weight]`. Every node `i` has a label `labels[i]`, and `k` is a limit. Find the path from node `0` to node `n - 1` with the smallest total weight, where the path never has MORE than `k` nodes with the same label in a row. Return that weight, or `-1` if no valid path exists.

## Example
(Hand-traced and checked by brute force, not copied from the LC page.)
```
Input
n = 3, edges = [[0,1,1],[1,2,1],[0,2,5]], labels = "aab", k = 2
Output
2
```
Explanation: the path 0 -> 1 -> 2 has the labels `a, a, b`. The longest run is 2, which is allowed, so the cost is 1 + 1 = 2. The direct edge 0 -> 2 costs 5, which is worse.

```
Input
n = 3, edges = [[0,1,1],[1,2,1],[0,2,5]], labels = "aab", k = 1
Output
5
```
Explanation: now the run `a, a` is too long, so 0 -> 1 is never allowed. Only the direct edge 0 -> 2 (labels `a, b`) is valid, and it costs 5.

```
Input
n = 2, edges = [[0,1,4]], labels = "aa", k = 1
Output
-1
```
Explanation: the only edge joins two `a` nodes, which makes a run of 2 and breaks `k = 1`. No valid path exists.

## Idea
A normal shortest path only needs "which node am I at". Here the next step may be forbidden depending on HOW MANY equal labels the path just ended with. So the node alone is not enough information.

**State:** `(u, cnt)` = standing at node `u`, and the current path ends with exactly `cnt` equal labels in a row (`1 <= cnt <= k`).

**Transition:** take an edge `u -> v` with weight `w`:
```
nextCnt = (labels[u] == labels[v]) ? cnt + 1 : 1
```
- Same label: the run grows by one. If `nextCnt > k`, the move is not allowed.
- Different label: the run restarts at `1`.

**Start:** `(0, 1)` with distance `0`. Node `0` already counts as a run of length 1.

**Goal:** any state `(n - 1, cnt)`. The answer is the smallest distance over all `cnt`.

Now every move costs a non-negative weight on a graph of states, so this is a plain shortest-path problem. Dijkstra works.

---

## Approach: Dijkstra over states (node, run length)

### Idea
Run Dijkstra on the expanded graph with `n * k` states. `dist[u][cnt]` stores the best distance to reach node `u` with a current run of `cnt`.

Dijkstra pops states in increasing order of distance, so the FIRST time any state of node `n - 1` is popped, its distance is already the best over all run lengths. Return it right away.

### Steps
- Build the adjacency list `adj[u] = {(v, w), ...}`.
- Create `dist[n][k + 1]` filled with `INF`. Set `dist[0][1] = 0`.
- Push `(0, 0, 1)` (distance, node, run) into a min-heap.
- Pop `(d, u, cnt)`. If `d != dist[u][cnt]`, it is an old entry, skip it.
- If `u == n - 1`, return `d`.
- For each edge `(v, w)`: compute `nextCnt`. Skip if `nextCnt > k`. If `d + w < dist[v][nextCnt]`, update it and push.
- If the heap becomes empty, return `-1`.

### Complexity
Time: **O(k * E * log(n * k))**  (there are `n * k` states, and each state looks at the outgoing edges of its node, so about `k * E` relaxations in total)  
Space: **O(n * k + E)**

---

## Key Observation
The skill in this problem is to ADD the missing information to the state, then run a standard algorithm. Dijkstra itself is unchanged. The new dimension (`cnt`) only has to be small enough to store, which is why the limit `k` matters: the number of states is `n * k`.

The check for `nextCnt > k` also keeps `cnt` from ever exceeding `k`, so the array never overflows.

Distances can be large (many edges with big weights), so the distance is stored in `long long`.

An optional improvement (not in the code): a state `(u, cnt)` with a SMALLER run and a distance that is not larger is always at least as good as `(u, cnt2)` with `cnt < cnt2`. Dropping those dominated states can reduce memory when `k` is large.

## When to use this
If problem involves:
- A shortest path where a move depends on some history of the path (stops used, run length, keys held, obstacles removed)
- That history is small enough to count
→ Think **Dijkstra (or BFS) on states: (node, history)**.

## Edge Cases
- `n == 1` (the start is already the target, answer `0`).
- No path from `0` to `n - 1` (answer `-1`).
- The only path breaks the run limit (answer `-1`).
- `k == 1` (no two neighbouring nodes on the path may share a label).
- Cycles in the graph (Dijkstra handles them, since weights are non-negative).
- Large total distance (needs `long long`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Dijkstra on (node, run length) | O(k * E * log(n * k)) | O(n * k + E) |

where:
- `n` = number of nodes
- `E` = number of edges
- `k` = maximum allowed run of equal labels

## Related Problems
- Cheapest Flights Within K Stops
- Shortest Path in a Grid with Obstacles Elimination
- Minimum Obstacle Removal to Reach Corner
- Minimum Cost to Reach Destination in Time
- Network Delay Time