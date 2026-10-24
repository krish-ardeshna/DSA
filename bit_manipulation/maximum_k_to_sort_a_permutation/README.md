# Maximum K to Sort a Permutation
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/  
Difficulty: Medium  
Pattern: Bit Manipulation (AND of All Misplaced Values)

## What I understood
`nums` is a permutation of `0..n-1`. Two elements at indices `i` and `j` may be swapped only if `nums[i] AND nums[j] == k`, for one fixed non-negative integer `k`. Find the MAXIMUM `k` for which the array can be sorted using any number of such swaps. If the array is already sorted, return 0.

## Example
```
Input
nums = [0, 3, 2, 1]
Output
1
```
Explanation: the misplaced values are 3 and 1, and `3 AND 1 = 1`. Swapping them sorts the array.

```
Input
nums = [0, 1, 3, 2]
Output
2
```
Explanation: the misplaced values are 3 and 2, and `3 AND 2 = 2`.

```
Input
nums = [2, 1, 0]
Output
0
```
Explanation: the misplaced values are 2 and 0, and `2 AND 0 = 0`.

## Idea
**Upper bound.** A value that is not at its own index has to be swapped at least once. Every swap involving a value `x` needs `x AND y == k`, which forces all the bits of `k` to be set in `x`. So `k` must be a submask of EVERY misplaced value, which means:
```
k <= (AND of all misplaced values)
```

**This bound is reachable.** Let `k` be that AND. Because `k` is a submask of every misplaced value, it is no bigger than any of them, so `k` is a value in `0..n-1` and sits somewhere in the array. That value works as a helper: for every misplaced `x`, `k AND x = k`. A helper that can swap with every misplaced value lets us sort the way you sort with an empty slot: park a value on the helper's position, move values into place, and put the helper back. So the maximum `k` is exactly the AND of the misplaced values.

## Approach: AND Together Every Value That Is Not at Its Own Index
- Start `ans = -1`. In two's complement every bit of `-1` is set, so it is the identity for AND.
- For each index `i`, if `nums[i] != i`, do `ans &= nums[i]`.
- Return `max(ans, 0)`. If nothing was misplaced, `ans` is still `-1`, and the answer is 0 for a sorted array.

## Key Observation
The problem looks like a graph or cycle problem (which swaps are legal, in what order), but the whole answer collapses into one bitwise AND, because the value `k` itself can act as a free helper for every swap. Starting `ans` at `-1` instead of a special flag is what lets the sorted case fall out of the final `max(ans, 0)` with no extra branch.

## When to use this
If problem involves:
- Swaps (or merges) allowed only when a bitwise AND, OR or XOR condition holds
- Asking for the best threshold value `k`
→ Think **every involved element must contain the bits of `k`, so the answer is the AND of the elements that must move**, then check that a helper element exists.

## Edge Cases
- Already sorted array (answer 0).
- Exactly two misplaced values (answer is the AND of that pair).
- A misplaced value of 0 anywhere (the AND collapses to 0).
- All misplaced values sharing a high bit (a larger `k` is possible).
- Single element array (sorted, answer 0).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = number of elements

## Related Problems
- Minimum Operations to Sort a Permutation
- Largest Combination With Bitwise AND Greater Than Zero
- Minimum Swaps to Sort by Digit Sum
- Maximum XOR After Operations