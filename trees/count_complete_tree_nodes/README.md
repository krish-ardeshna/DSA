# Count Complete Tree Nodes
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-complete-tree-nodes/  
Difficulty: Medium  
Pattern: Tree - Binary Search Style Recursion (Exploit Complete Tree Property)

## What I understood
Given a COMPLETE binary tree (every level fully filled except possibly the last, which fills left to right), count the total number of nodes. A naive O(n) traversal always works, but the completeness property allows a faster O(log²n) approach.

## Example
```
Input
root = [1,2,3,4,5,6]
Output
6
```
```
Input
root = []
Output
0
```

## Idea
In a complete tree, if the height measured by ALWAYS going left equals the height measured by ALWAYS going right, that subtree is a PERFECT binary tree (every level completely full) - its node count can be computed instantly via the formula `2^height - 1`, no need to traverse it. If the heights differ, the subtree isn't perfect (the last level is only partially filled), so recurse into both children normally - but at least ONE of the two children's subtrees will still be perfect (due to the completeness guarantee), giving a logarithmic reduction at each recursive step.

## Approach: Compare Left-Edge and Right-Edge Heights to Detect Perfect Subtrees
- `findHeightLeft`: walk from a node always taking the LEFT child, counting steps until null - gives the height along the leftmost edge.
- `findHeightRight`: same but always taking the RIGHT child - gives height along the rightmost edge.
- `countNodes`: base case, `root == NULL` → 0.
- Compute `lh` and `rh` for current root. If EQUAL, the subtree is perfect → return `(1 << lh) - 1` directly (no further recursion needed).
- If NOT equal, recurse normally: `1 + countNodes(left) + countNodes(right)`.

## Key Observation
The completeness property guarantees that at most ONE side needs full recursive exploration at any given node - the OTHER side either resolves immediately via the perfect-subtree formula, or the imbalance is confined to a bounded portion of the tree, giving an overall O(log²n) complexity instead of O(n): O(log n) recursive depth, each level doing O(log n) work to compute the two heights.

## When to use this
If problem involves:
- Counting nodes (or similar aggregate) in a COMPLETE (not just any) binary tree
→ Think **compare left-edge height vs right-edge height to detect perfect subtrees**, using the closed-form node count formula to skip full traversal wherever possible.

## Edge Cases
- Empty tree (`root == NULL`).
- Perfectly complete tree (single height comparison resolves the entire count in O(log n), no recursion needed at all).
- Tree with exactly one node missing from being perfect (worst case for this optimization, still O(log²n)).
- Single node tree.

## Complexity
### Approach
Time: **O(log²n)** - O(log n) recursive depth, O(log n) height computation at each level        
Space: **O(log n)** - recursion stack

where:
- `n` = number of nodes

## Related Problems
- Maximum Depth of Binary Tree
- Balanced Binary Tree
- Complete Binary Tree Inserter
- Check Completeness of a Binary Tree