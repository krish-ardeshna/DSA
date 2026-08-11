# Next Permutation
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/next-permutation/  
Difficulty: Medium  
Pattern: Array - Two Pointer (In-Place Rearrangement)

## What I understood
Rearrange array into the lexicographically next greater permutation of numbers. If no such permutation exists (array is in fully descending order, i.e. the last permutation), rearrange into the lowest possible order (fully ascending). Must be done in-place, O(1) extra space.

## Example
```
Input
nums = [1,2,3]
Output
[1,3,2]
```
```
Input
nums = [3,2,1]
Output
[1,2,3]
```
```
Input
nums = [1,1,5]
Output
[1,5,1]
```

## Idea
A permutation's suffix that is non-increasing is already at its "maximum" arrangement for that suffix — no next permutation possible there. So scan from the right to find the first index (`idx`) where the sequence breaks ascending order (`nums[idx] < nums[idx+1]`). That's the pivot to increase. Everything after it is currently descending (max arrangement) and needs to become ascending (min arrangement) after the swap.

## Approach: Pivot Find + Swap + Reverse Suffix
- Scan from right, find first `idx` where `nums[idx] < nums[idx+1]` (breaks descending pattern).
- If no such `idx` found (`idx == -1`) → array is fully descending, it's the last permutation → reverse entire array to get smallest permutation.
- Otherwise, scan from the right again to find smallest element greater than `nums[idx]` (rightmost such element, to keep swap minimal), swap it with `nums[idx]`.
- Reverse the suffix after `idx` — since it was descending before swap, reversing makes it ascending (smallest possible arrangement for that suffix).

## Key Observation
The suffix after the pivot is always descending before any modification (that's exactly why `idx` was found there). Reversing a descending suffix into ascending order gives the smallest possible tail — combined with picking the smallest valid swap candidate for the pivot, this guarantees the immediate next permutation, not some arbitrary greater one.

## When to use this
If problem involves:
- Generating lexicographic next/previous arrangement of a sequence
- In-place permutation manipulation with O(1) space constraint
→ Think **pivot-find + swap + reverse-suffix** pattern.

## Edge Cases
- Fully descending array (last permutation) → wraps to fully ascending.
- Array with duplicate elements (e.g. `[1,1,5]`).
- Single element array → no change possible.
- Already smallest permutation, needs next → straightforward pivot near the end.

## Complexity
### Approach
Time: **O(n)** — at most two linear scans plus a reverse
Space: **O(1)** — in-place, no extra structure

where:
- `n` = number of elements

## Related Problems
- Permutations
- Permutations II
- Previous Permutation With One Swap
- Next Greater Element III