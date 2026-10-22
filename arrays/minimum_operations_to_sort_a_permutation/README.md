# Minimum Operations to Sort a Permutation
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Cyclic Rotation Check Around the Position of 0

## What I understood
`nums` is a permutation of `0..n-1`. The goal is to sort it using the allowed operation, with the minimum number of operations, or `-1` if impossible.

**Note:** the exact operation rule is not written here, because I could not verify it. Paste the statement from the LC page below before relying on the cost formulas.

```
<paste the operation rule from the LC page here>
```

What the accepted code shows is the structure of the solution: the array must be a **cyclic rotation of the sorted order**, read either forward or backward starting at the position of `0`. The cost then depends only on the index of `0`.

## Example
```
Input
nums = [0, 1, 2, 3]
Output
0
```
Explanation: the array is already sorted, so no operation is needed.

```
Input
nums = [3, 2, 1, 0]
Output
1
```
Explanation: this value comes from tracing the code, not from LC. It is a reversed rotation with `0` at index 3, so the code takes `n - zero = 1`.

```
Input
nums = [0, 2, 1, 3]
Output
-1
```
Explanation: this value comes from tracing the code, not from LC. Reading cyclically from `0`, the order is `0, 2, 1, 3` forward and `0, 3, 1, 2` backward, and neither is increasing, so the code returns `-1`.

## Idea
Locate `0` at index `zero`. Then walk away from it in a fixed direction around the circle (cyclic indexing with `% n`):
- Direction `+1`: the values read `0, 1, 2, ..., n-1` in order exactly when the array is a rotation of the sorted array.
- Direction `-1`: the same check for a reversed rotation.

Since `nums` is a permutation, "non-decreasing in this walk" is the same as "values appear as `0, 1, ..., n-1`". If neither direction works, the array can never be sorted, so the answer is `-1`.

If a direction works, the number of operations is a function of `zero` and `n`. The code uses these costs:
- direction `+1`: `min(zero, n - zero + 2)`
- direction `-1`: `min(zero + 2, n - zero)`

and takes the smaller of the valid ones. (These formulas depend on the operation rule, so they need checking against the statement.)

## Approach: Check If Array Is a Rotation of Sorted (Forward or Backward) From 0, Then Pick the Cheapest Cost Based on the Index of 0
- Find `zero`, the index of the value `0`.
- `check(step)`: for `i = 1 .. n - 1`, compare the values at cyclic positions `zero + (i - 1) * step` and `zero + i * step` (using `+ n` before `% n` so the index is never negative). Fail if any earlier value is larger than the next.
- If `check(1)` passes, candidate answers are `zero` and `n - zero + 2`.
- If `check(-1)` passes, candidate answers are `zero + 2` and `n - zero`.
- Return the minimum candidate, or `-1` if neither direction passed.

## Key Observation
The whole problem reduces to ONE number, the position of `0`, once the array is known to be a cyclic rotation. That is why a single pass of `O(n)` is enough, with no search. Adding `n` before the modulo makes the cyclic index safe for the backward walk (`step = -1`), where `zero + i * step` would otherwise go negative.

## When to use this
If problem involves:
- A permutation that can only be fixed when it is a rotation of sorted order
- A cost that depends only on where one anchor value sits
→ Think **walk cyclically from the anchor to validate the shape, then read the cost off the anchor's index**.

## Edge Cases
- Already sorted permutation (answer 0, `zero = 0` and `check(1)` passes).
- `n = 1` (answer 0).
- `n = 2`, both orders are rotations in both directions.
- Not a rotation in either direction (answer `-1`).
- Both directions valid at once (possible for tiny `n`), the code takes the smaller cost.

## Complexity
### Approach
Time: **O(n)**, one scan to find `0` and at most two cyclic checks                
Space: **O(1)**

where:
- `n` = number of elements

## Related Problems
- Check if Array Is Sorted and Rotated
- Rotate Array
- Sum of Sortable Integers
- Minimum Operations to Sort a String