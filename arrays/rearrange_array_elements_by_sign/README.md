# Rearrange Array Elements by Sign
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/  
Difficulty: Medium  
Pattern: Array - Two Pointer (Index Placement)

## What I understood
Array has equal count of positive and negative integers, original relative order among positives (and separately among negatives) must be preserved. Rearrange so array alternates starting with positive at index 0, negative at index 1, and so on.

## Example
```
Input
nums = [3,1,-2,-5,2,-4]
Output
[3,-2,1,-5,2,-4]
```
```
Input
nums = [-1,1]
Output
[1,-1]
```

## Idea
Since output positions are fixed (positives always land on even indices, negatives on odd indices), single pass with two separate index trackers suffices — no sorting or grouping needed. Just walk input once and drop each element straight into its correct slot.

## Approach: Separate Even/Odd Index Placement
- Init `ans` array of size `n`, `posIndex = 0`, `negIndex = 1`.
- Iterate input once: if positive, place at `ans[posIndex]`, then `posIndex += 2`.
- If negative, place at `ans[negIndex]`, then `negIndex += 2`.
- Relative order preserved automatically since input scanned left to right and each sign's index only ever increases by 2.

## Key Observation
Guaranteed equal count of positives/negatives (per problem constraint) means both index trackers land exactly on the last valid slot with no gaps or overflow — this only works because of that guarantee.

## When to use this
If problem involves:
- Interleaving two groups into fixed alternating positions
- Relative order within each group must be preserved
- Counts of both groups are equal or otherwise constrained
→ Think **separate index trackers, single pass, direct placement**.

## Edge Cases
- Smallest valid input (`[pos, neg]` pair only).
- All positives first then all negatives in input (or vice versa) — still works since placement is order-independent of clustering.
- Large array with alternating signs already.

## Complexity
### Approach
Time: **O(n)**
Space: **O(n)** — output array (required, not extra beyond output)

where:
- `n` = number of elements

## Related Problems
- Rearrange Array Elements by Sign II
- Sort Array By Parity
- Wiggle Sort
- Sort Colors