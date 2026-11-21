# Find Subtree Sizes After Changes
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-subtree-sizes-after-changes/  
Difficulty: Medium  
Pattern: Tree DFS + Nearest Ancestor with the Same Character (Last Occurrence Array)

## What I understood
Given a tree with `n` nodes rooted at node `0`, where `parent[i]` is the parent of node `i` (`parent[0] = -1`), and a string `s` where `s[i]` is the character of node `i`. For every node `x` from `1` to `n - 1`, at the SAME time (using the original tree to find ancestors):
- Find the closest ancestor `y` of `x` with `s[y] == s[x]`.
- If `y` exists, remove the edge between `x` and its parent, and make `y` the new parent of `x`.

Return an array `answer` where `answer[i]` is the size of the subtree of node `i` in the FINAL tree.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
parent = [-1,0,0,1,1,1], s = "abaabc"
Output
[6,3,1,1,1,1]
```
Explanation: node 2 (`a`) has the ancestor 0 (`a`), so its parent stays 0. Node 3 (`a`) has the ancestors 1 (`b`) and 0 (`a`), so its parent changes from 1 to 0. Node 4 (`b`) has the parent 1 (`b`), so it stays. Node 5 (`c`) has no ancestor with `c`, so it stays under 1. The final tree is `0 -> {1, 2, 3}` and `1 -> {4, 5}`. The sizes are 6, 3, 1, 1, 1, 1.

```
Input
parent = [-1,0,4,0,1], s = "abbba"
Output
[5,2,1,1,1]
```
Explanation: node 1 (`b`) has no ancestor `b`, so it stays under 0. Node 2 (`b`) has the ancestors 4 (`a`) and 1 (`b`), so its parent changes from 4 to 1. Node 3 (`b`) has no ancestor `b`, so it stays under 0. Node 4 (`a`) has the ancestors 1 (`b`) and 0 (`a`), so its parent changes from 1 to 0. The final tree is `0 -> {1, 3, 4}` and `1 -> {2}`. The sizes are 5, 2, 1, 1, 1.

## Idea (shared by all approaches)
Two steps:
1. **Find the new parent of every node.** It is the closest ancestor with the same character in the ORIGINAL tree, or the old parent if there is none.
2. **Compute subtree sizes in the new tree.**

A key fact: the new parent of a node is always one of its original ANCESTORS. So the new graph is still a tree, and the new parent always comes BEFORE the node in a DFS order of the original tree.

## Approach 1: Brute Force

### Idea
For every node, walk up the original parent chain until a node with the same character is found. Then, for every node, walk up the new parent chain and add 1 to each ancestor.

### Steps
- `newParent = parent`.
- For each `x` from `1` to `n - 1`: `y = parent[x]`. While `y != -1` and `s[y] != s[x]`, `y = parent[y]`. If `y != -1`, `newParent[x] = y`.
- `answer[i] = 1` for all `i`.
- For each `x` from `1` to `n - 1`: `y = newParent[x]`. While `y != -1`, `answer[y]++`, `y = newParent[y]`.
- Return `answer`.

### Complexity
Time: **O(n * depth)**, which is **O(n^2)** on a chain  
Space: **O(n)**

---

## Approach 2: DFS (Last Occurrence per Character) + DFS for Sizes

### Idea
While walking down the original tree with a DFS, keep `last[c]` = the closest ancestor of the current node whose character is `c`. When the DFS enters node `x`, `last[s[x]]` is exactly the closest same-character ancestor. After the subtree of `x` is done, restore `last[s[x]]` to its old value (backtracking).

After all new parents are known, build the new tree and compute sizes with a second DFS.

### Steps
- Build `adj` from `parent`.
- `last[26] = -1`, `newParent[n]`.
- `findParent(node)`: `c = s[node]`, `old = last[c]`. `newParent[node] = (old != -1) ? old : parent[node]`. Set `last[c] = node`. Visit every child. Restore `last[c] = old`.
- Call `findParent(0)`.
- Build `tree` from `newParent` and run `dfs` to get the subtree sizes.
- Return `answer`.

### Complexity
Time: **O(n)**  
Space: **O(n)** (plus recursion depth up to `n` on a chain)

---

## Approach 3: Iterative DFS + Sizes in Reverse Order

### Idea
Use the same `last[]` idea, but with an explicit stack, so that a deep tree cannot overflow the call stack. Push an EXIT marker below the children of every node, so that `last[c]` is restored when the whole subtree is done.

Record the nodes in the order they are first visited. Because a new parent is an original ancestor, it appears EARLIER in this order. So going through the order BACKWARDS and adding each node's size to its new parent works: every node's size is final before it is added to its parent. No second tree and no second DFS are needed.

### Steps
- Build `adj` from `parent`.
- Stack with `(0, -1, enter)`.
- Pop an entry. If it is an EXIT marker, do `last[c] = old` and continue.
- Otherwise: `old = last[c]`, `newParent[node] = (old != -1) ? old : parent[node]`, `last[c] = node`, append `node` to `order`.
- Push the EXIT marker `(node, old, exit)`, then push every child as an enter entry.
- `answer[i] = 1` for all `i`.
- For `i` from `n - 1` down to `1`: `v = order[i]`, `answer[newParent[v]] += answer[v]`.
- Return `answer`.

### Complexity
Time: **O(n)**  
Space: **O(n)**, no recursion

---

## Key Observation
The new parent is always an old ANCESTOR, never a node from another branch. That gives two things for free:
- the result is still a tree (no cycles),
- the order of the original DFS is a valid order to add sizes upward, so a second DFS is not required.

The 26-slot `last[]` array with backtracking finds "the closest ancestor with the same character" in O(1) per node. Every lookup uses the ORIGINAL tree, so all the changes are decided before any edge is moved, matching "at the same time" in the statement.

## When to use this
If problem involves:
- A rooted tree and a rule about the closest ancestor that satisfies a property (same character, same label, etc.)
- Only a small alphabet of properties
→ Think **DFS with a "last seen per value" array, and restore it when leaving the node**.

## Edge Cases
- `n = 1` (only the root, answer is `[1]`).
- A node with no ancestor of the same character (it keeps its parent).
- The closest same-character ancestor is already the parent (nothing changes).
- A chain of `10^5` nodes (recursive DFS goes `10^5` calls deep, the iterative version avoids it).
- Several nodes moving under the same ancestor.
- The root's character matters, because the root is an ancestor of everything.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n * depth), up to O(n^2) | O(n) |
| DFS + `last[]` + DFS for sizes | O(n) | O(n) + recursion depth |
| Iterative DFS + reverse order | O(n) | O(n) |

where:
- `n` = number of nodes

## Related Problems
- Number of Nodes in the Sub-Tree With the Same Label
- Longest Path With Different Adjacent Characters
- Sum of Distances in Tree
- Count Nodes Equal to Average of Subtree