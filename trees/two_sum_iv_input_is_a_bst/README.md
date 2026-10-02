# Two Sum IV - Input is a BST
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/  
Difficulty: Easy  
Pattern: BST - Bidirectional Iterator (Forward + Reverse Inorder)

## What I understood
Given a BST and a target `k`, determine if two distinct nodes exist whose values sum to `k`.

## Example
```
Input
root = [5,3,6,2,4,null,7], k = 9
Output
true
```
```
Input
root = [5,3,6,2,4,null,7], k = 28
Output
false
```

## Idea
This is the classic two-pointer "sorted array, two sum" trick, applied without ever materializing a sorted array. A normal BST iterator produces values in ASCENDING order via inorder traversal, a REVERSED iterator (push right spine instead of left, descend left instead of right) produces values in DESCENDING order. Running both simultaneously gives exactly the smallest-and-largest-remaining pair at every step, letting the two-pointer sum comparison work directly.

## Approach: Two BST Iterators Meeting in the Middle (Two Pointer on Sorted Stream)
- `BSTIterator` is parameterized by a `reverse` flag: when `false`, it behaves as a normal ascending inorder iterator (push left spine, expand right on `next()`), when `true`, it's mirrored (push right spine, expand left on `next()`), yielding descending order.
- Create `l` (ascending) and `r` (descending) iterators over the same tree.
- Pull the first value from each: `i` (smallest), `j` (largest).
- While `i < j`: if `i + j == k`, found a pair, return true. If sum is too small, advance `i` forward (next smallest). If too large, advance `j` backward (next largest).
- Loop ends (no match) once pointers cross.

## Key Observation
Since both iterators walk the SAME tree independently and only ever move in one direction each, the total work across the whole search is still bounded by the number of nodes, this gets two-pointer efficiency without ever converting the tree into an actual array first.

## When to use this
If problem involves:
- Two Sum-style pair search over data that's already sorted or sortable via traversal order (like inorder on a BST)
→ Think **two independent iterators moving toward each other**, rather than extracting all values into an array first.

## Edge Cases
- Tree with only one node (can never find a pair with itself, correctly handled since loop needs `i < j`).
- Target achievable only by using the SAME node twice (not allowed, two pointers starting from different ends naturally avoids this unless tree has only 1 node).
- No valid pair exists (loop runs out, returns false).
- Duplicate values in the tree (handled correctly as long as they're genuinely different nodes).

## Complexity
### Approach
Time: **O(n)** - each node visited at most once across both iterators combined          
Space: **O(h)** - stack space for each iterator

where:
- `n` = number of nodes
- `h` = height of the tree

## Related Problems
- Two Sum
- Binary Search Tree Iterator
- Kth Smallest Element in a BST
- Closest Binary Search Tree Value