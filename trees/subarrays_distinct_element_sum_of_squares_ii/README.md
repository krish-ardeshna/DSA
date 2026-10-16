# Subarrays Distinct Element Sum of Squares II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/  
Difficulty: Hard  
Pattern: Segment Tree (Lazy Range Add, Maintain Sum and Sum of Squares)

## What I understood
For every contiguous subarray of `nums`, take the number of DISTINCT values in it and square it. Return the sum of these squares over all subarrays, modulo `10^9 + 7`. This is the same task as Version I, but with `n` up to `10^5`, so checking every subarray (O(n^2)) is too slow.

## Example
```
Input
nums = [1,2,1]
Output
15
```
Explanation: the six subarrays have distinct counts 1, 1, 1, 2, 2, 2, so the squares add up to 1 + 1 + 1 + 4 + 4 + 4 = 15.

```
Input
nums = [2,2]
Output
3
```
Explanation: every subarray has 1 distinct value, so 1 + 1 + 1 = 3.

## Idea
Sweep the RIGHT end `i` from left to right. Keep an array `d[j]` where `d[j]` = the distinct count of the subarray `nums[j..i]`. The answer for this `i` is the sum of `d[j]^2` over all `j <= i`, and the final answer is the total of these over all `i`.

When `i` moves forward and adds `nums[i]`, which start positions `j` see a NEW distinct value? Let `prev` be the last index where `nums[i]` appeared before.
- For `j <= prev`, the subarray already contained this value, so `d[j]` does not change.
- For `j` in `(prev, i]`, the value is new, so `d[j]` goes up by exactly 1.

So each step is one range update: **add 1 to `d[prev + 1 .. i]`**, then read the sum of squares of the whole array. Positions beyond `i` are still 0, so they add nothing.

## Approach: Sweep Right Endpoint, Range +1 on Positions Where a Value Is New
- Keep a hashmap `last[value]` = most recent index of that value (`-1` if unseen).
- Build a segment tree over positions `0..n-1` that supports:
  - range add of `+1`
  - query of the sum of squares of the whole array
- The tree stores, per node: `sum` (sum of values), `sq` (sum of squares), and `lazy` (pending add).
- Applying `+val` to a node of length `len`:
  - `sq' = sq + 2 * val * sum + val^2 * len` (since `(x + val)^2 = x^2 + 2 * val * x + val^2`)
  - `sum' = sum + val * len`
  - `lazy += val`
  - Note `sq` must be updated BEFORE `sum`, because the formula needs the old `sum`.
- For each `i`: update range `[prev + 1, i]` by 1, set `last[nums[i]] = i`, add `sq[1]` (the root) to the answer.

## Key Observation
The sum of squares looks hard to maintain under range updates, but it has a clean algebraic update rule. Keeping `sum` and `sq` together in each node lets the lazy `+val` be applied to a whole segment in O(1) without touching its children. All values are reduced modulo `10^9 + 7`, and the `val` used here is only ever `1` (or a lazily accumulated count up to `n`), so the intermediate products fit in `long long`.

## When to use this
If problem involves:
- A statistic over all subarrays (distinct count, sum of squares) with large `n`
- Each new element changing the value of a CONTIGUOUS block of start positions
→ Think **sweep the right end, maintain per-start values in a segment tree with lazy range updates**, and use `last occurrence` to find the block that changes.

## Edge Cases
- Single element array (answer is 1).
- All elements equal (each step updates only the single position `i`, since `prev + 1 = i`).
- All elements distinct (each step updates the whole range `[0, i]`).
- Large `n` (the modulo keeps the sums small, and `long long` avoids overflow in the products).

## Complexity
### Approach
Time: **O(n log n)**, one range update per element          
Space: **O(n)** for the segment tree arrays and the hashmap

where:
- `n` = number of elements

## Related Problems
- Subarrays Distinct Element Sum of Squares I
- Count Distinct Numbers on Board
- Range Sum Query - Mutable
- Count of Smaller Numbers After Self