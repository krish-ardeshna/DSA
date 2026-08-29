# Make Lexicographically Smallest Array by Swapping Elements
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/  
Difficulty: Medium  
Pattern: Sort + Union-Find Style Grouping (via Sorted Adjacent Check)

## What I understood
Two elements can be swapped if their absolute value difference is `<= limit`. Swaps can be performed any number of times, chaining together (if A can swap with B, and B can swap with C, then A's value can effectively reach C's position too, even if `|A-C| > limit`). Find the lexicographically smallest array achievable through any sequence of such swaps.

## Example
```
Input
nums = [1,5,3,9,8], limit = 2
Output
[1,3,5,8,9]
```
```
Input
nums = [1,7,6,18,2,1], limit = 3
Output
[1,6,7,18,1,2]
```

## Idea
Swappability forms connected groups — sort values first, then any two adjacent (in sorted order) values within `limit` of each other belong to the same swappable group, and this extends transitively (chain-like) even if the endpoints of the group aren't directly within `limit` of each other. Each such group's original index positions can have their values freely rearranged among themselves. To minimize lexicographically, sort each group's original positions and assign the group's sorted values to those sorted positions in order.

## Approach: Sort by Value, Group Swappable Chains, Reassign Sorted Positions
- Pair each value with its original index, sort by value.
- Walk through sorted array, greedily extending a group while consecutive sorted values differ by `<= limit` (chain condition).
- For each group: collect original indices, sort them ascending.
- Assign group's sorted values to group's sorted indices in matching order — smallest value goes to smallest index within the group, and so on.
- Repeat for all groups, building final answer array.

## Key Observation
Grouping via consecutive sorted-value gaps (not all-pairs comparison) correctly captures transitive swappability — if `v1` and `v2` are swappable and `v2` and `v3` are swappable, `v1` and `v3` end up in the same group even if `|v1-v3| > limit`, because the chain of adjacent-in-sorted-order comparisons captures this transitivity automatically without needing explicit union-find.

## When to use this
If problem involves:
- Elements groupable by a transitive "can swap/connect" relation based on value proximity
- Need lexicographically smallest/optimal arrangement within each group
→ Think **sort values, form groups via consecutive gap threshold, then assign smallest values to smallest original indices within each group**.

## Edge Cases
- `limit = 0` (only exact duplicate values can swap, likely each forms singleton groups unless duplicates exist).
- All elements within `limit` of each other (single group, effectively full sort).
- No elements within `limit` of any neighbor (array remains unchanged, each element its own group).
- Duplicate values in the array.

## Complexity
### Approach
Time: **O(n log n)** — dominated by sorting         
Space: **O(n)** — auxiliary arrays for pairs and indices

where:
- `n` = number of elements

## Related Problems
- Smallest String With Swaps
- Most Stones Removed with Same Row or Column
- Number of Islands
- Redundant Connection