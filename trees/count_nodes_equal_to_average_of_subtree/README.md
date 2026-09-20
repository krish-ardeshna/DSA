# Count Nodes Equal to Average of Subtree
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/  
Difficulty: Medium  
Pattern: Tree - Post-Order DFS (Sum + Count Aggregation)

## What I understood
For every node in a binary tree, compute the average value of its entire subtree (sum of all node values in that subtree, divided by number of nodes, using integer/floor division). Count how many nodes have a value exactly equal to their own subtree's average.

## Example
```
Input
root = [4,8,5,0,1,null,6]
Output
5
```
```
Input
root = [1]
Output
1
```

## Idea
Post-order DFS naturally computes subtree aggregates bottom-up — by the time a node is processed, both its left and right subtree's sum and count are already known (returned from recursive calls). Combine them with the current node's own value to get this node's full subtree sum/count, check the average condition, then pass the combined sum/count up to the parent.

## Approach: Post-Order DFS Returning Subtree Sum and Node Count
- Recursive `solve(root)` returns `{sum, count}` for the subtree rooted at `root`.
- Base case: `root == nullptr` → return `{0, 0}`.
- Recurse into left and right children first (post-order).
- Combine: `sum = left.sum + right.sum + root->val`, `count = left.count + right.count + 1`.
- Check condition: if `root->val == sum / count` (integer division = floor average), increment global `ans` counter.
- Return `{sum, count}` for this subtree, to be used by the parent's calculation.

## Key Observation
Using a `pair<sum, count>` return value is the clean way to propagate both pieces of aggregate information needed at each level without global state for sum/count (though the answer counter itself is kept as a class member for simplicity, since it's a running total, not something that needs to combine across siblings).

## When to use this
If problem involves:
- Per-node subtree aggregate computation (sum, count, average, etc.) compared against the node's own value
→ Think **post-order DFS returning a combined aggregate (pair/tuple)** so each level can build on its children's already-computed results.

## Edge Cases
- Single node tree (trivially its own average, always counts).
- Leaf nodes (subtree = just themselves, average = their own value, always counts).
- Skewed tree (all left or all right children).
- Integer division truncation affecting whether condition matches (e.g., sum/count not dividing evenly).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(h)** — recursion stack, h = tree height

where:
- `n` = number of nodes
- `h` = height of tree

## Related Problems
- Average of Levels in Binary Tree
- Binary Tree Maximum Path Sum
- Sum of Left Leaves
- Balanced Binary Tree