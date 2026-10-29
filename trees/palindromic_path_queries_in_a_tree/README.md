# Palindromic Path Queries in a Tree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/palindromic-path-queries-in-a-tree/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Tree + Bitmask Parity (Euler Tour + Fenwick + Binary Lifting, Heavy-Light Decomposition)

## What I understood
(Reconstructed from the accepted code, recheck against the LC statement.)  
A tree has `n` nodes (rooted at node `0` in the code), and every node `i` holds one lowercase letter `s[i]`. Two kinds of queries come in order:
- `"update u c"`: change the letter on node `u` to `c`.
- `"query u v"`: look at the letters on the path from `u` to `v` (both ends included). Answer `true` if those letters can be rearranged into a palindrome, otherwise `false`.

Return the answers of all `query` operations, in order.

## Example
(Hand-traced and checked by brute force, not copied from the LC page.)
```
Input
n = 3, edges = [[0,1],[1,2]], s = "aab"
queries = ["query 0 2", "update 1 b", "query 0 2", "update 2 c", "query 0 2", "query 1 1"]
Output
[true, true, false, true]
```
Explanation: the path 0-1-2 starts as `a, a, b`, and `aba` is a palindrome, so `true`. After `update 1 b` it is `a, b, b`, and `bab` works, so `true`. After `update 2 c` it is `a, b, c`, where three letters each appear once, so `false`. The last query is a single node, which is always a palindrome, so `true`.

```
Input
n = 5, edges = [[0,1],[0,2],[1,3],[1,4]], s = "abcba"
queries = ["query 3 2", "update 2 a", "query 3 2", "query 3 4"]
Output
[false, true, true]
```
Explanation: the path 3-1-0-2 has the letters `b, b, a, c`. Both `a` and `c` appear once, so `false`. After `update 2 a` the letters are `b, b, a, a`, which gives `true`. The path 3-1-4 has `b, b, a`, and `bab` works, so `true`.

## Idea (shared by both approaches)
**Palindrome test.** A multiset of letters can be rearranged into a palindrome if and only if AT MOST ONE letter appears an odd number of times. So only the PARITY of each letter matters, and 26 parities fit in one integer.

**Mask.** Give each letter `c` the bit `1 << (c - 'a')`. The XOR of the bits of all letters on a path is a mask where bit `c` is `1` exactly when letter `c` appears an odd number of times.

**Check.** At most one bit is set exactly when `(mask & (mask - 1)) == 0`.

The remaining problem: get the XOR of the letter bits on a tree path quickly, while letters change.

---

## Approach 1: Euler Tour + Fenwick (Range XOR, Point Query) + Binary Lifting

### Idea
Let `pref[u]` be the XOR of the letter bits on the root-to-`u` path, using the ORIGINAL letters.

For a path `u - v` with lowest common ancestor `w`:
```
path mask = pref[u] ^ pref[v] ^ bit(s[w])
```
The part above `w` is in both prefixes and cancels. But `w` itself is also in both, so it cancels too, and `bit(s[w])` adds it back.

**Updates.** Changing the letter of `u` changes `pref` of EVERY node in the subtree of `u`, by the same value `delta = bit(old) ^ bit(new)`. In an Euler tour (DFS order) a subtree is one contiguous range `[tin[u], tout[u])`. So an update is "XOR `delta` into a range", and reading `pref` of a node is a point query. A Fenwick tree does both: put the value at the start and at the end of the range, and a point query is the prefix XOR.

### Steps
- Iterative DFS from node `0` to get `parent`, `depth`, `tin` (entry order), and `pref`.
- Build the binary lifting table `up[k][u]` (the `2^k`-th ancestor of `u`) for the LCA.
- Subtree size gives `tout[u] = tin[u] + size[u]`.
- `update u c`: `delta = bit(s[u]) ^ bit(c)`. Apply `rangeXor(tin[u], tout[u], delta)`, then set `s[u] = c`.
- `query u v`: find `w = lca(u, v)`. Read `pu = pref[u] ^ fenwick(tin[u])` and `pv` the same way. The mask is `pu ^ pv ^ bit(s[w])` using the CURRENT letter of `w`. Answer `(mask & (mask - 1)) == 0`.

### Complexity
Time: **O((n + q) log n)** (build the table in `O(n log n)`, each query or update is `O(log n)`)  
Space: **O(n log n)** for the binary lifting table

---

## Approach 2: Heavy-Light Decomposition + Fenwick (Point Update, Path Query)

### Idea
Skip `pref` and the LCA. Store the letter bit of every node directly, and ask for the XOR of a path.

Heavy-Light Decomposition (HLD) splits the tree into vertical chains, so that any path touches only `O(log n)` chains. Give every chain a block of consecutive positions, from top to bottom. Then the nodes of the path that lie on one chain are one contiguous range of positions. A Fenwick tree over the positions answers "XOR of a range" and supports changing a single position.

### Steps
- BFS from node `0` for `parent`, `depth`, and an order where parents come first.
- Subtree sizes, then the heavy child of each node (the child with the largest subtree).
- Chains: for every chain head, walk down the heavy children and give consecutive positions.
- Put `bit(s[u])` at `pos[u]` in the Fenwick.
- `update u c`: XOR `bit(old) ^ bit(new)` into `pos[u]`, then set `s[u] = c`.
- `query u v`: while `head[u] != head[v]`, take the node whose chain head is deeper, XOR the range `[pos[head], pos[node]]`, and jump to `parent[head]`. Then both nodes are on one chain, so XOR the range between them. The LCA comes out for free.
- Answer `(mask & (mask - 1)) == 0`.

### Complexity
Time: **O(n log n + q log^2 n)** (an update is `O(log n)`, a query crosses `O(log n)` chains and each range query costs `O(log n)`)  
Space: **O(n)**

---

## Key Observation
Both approaches use the same trick: reduce "can be rearranged into a palindrome" to a single XOR mask. They differ in how they handle a letter change.

- Approach 1 treats a change as a subtree change (one range update on the Euler tour) and fixes the path with the LCA. Queries are faster, `O(log n)`.
- Approach 2 changes one position and pays for it when the path is read. It needs no LCA and no `up` table, so memory is `O(n)`, but a query is `O(log^2 n)`.

The brute force walks up from `u` and `v` and counts letters. That is `O(n)` per query and too slow for large trees.

## When to use this
If problem involves:
- Path queries on a tree with point updates on nodes
- A property that depends only on counts mod 2 (palindrome, even or odd counts)
→ Think **XOR bitmask per path**, then pick a way to read a path XOR fast: **prefix XOR from the root + Euler tour Fenwick** (subtree updates), or **HLD + Fenwick** (point updates).

## Edge Cases
- `u == v` (one node, always `true`).
- `u` is an ancestor of `v` (then `w == u`).
- An update that sets the same letter (`delta == 0`, nothing to change).
- A path-shaped tree (deepest case, so DFS must be iterative, not recursive).
- A star-shaped tree (many children under the root).
- `n == 1`.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Euler Tour + Fenwick + Binary Lifting | O((n + q) log n) | O(n log n) |
| Heavy-Light Decomposition + Fenwick | O(n log n + q log^2 n) | O(n) |

where:
- `n` = number of nodes
- `q` = number of queries

## Related Problems
- Can Make Palindrome from Substring
- Find the Longest Substring Containing Vowels in Even Counts
- Lowest Common Ancestor of a Binary Tree
- Kth Ancestor of a Tree Node
- Range Sum Query - Mutables