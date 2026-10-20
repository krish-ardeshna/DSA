# Sum of Sortable Integers
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sum-of-sortable-integers/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Prefix Max + Suffix Min + Divisor Enumeration

## What I understood
(Reconstructed from the accepted logic, recheck against the LC statement.)  
For a divisor `k` of `n = nums.size()`, split the array into `n / k` consecutive blocks of size `k`. Each block may be cyclically rotated any number of times. The integer `k` is "sortable" if, after rotating blocks, the whole array can be non-decreasing. Return the sum of all sortable divisors `k`.

## Example
```
Input
nums = [1, 2, 3]
Output
4
```
Explanation: `k = 1` works because the array is already sorted, and `k = 3` works because the single block is already sorted. 1 + 3 = 4.

```
Input
nums = [3, 1, 2]
Output
3
```
Explanation: `k = 1` fails (not sorted). `k = 3` works, since rotating the one block gives `[1, 2, 3]`.

```
Input
nums = [2, 1, 4, 3]
Output
2
```
Explanation: `k = 2` works: rotate `[2, 1]` to `[1, 2]` and `[4, 3]` to `[3, 4]`. `k = 1` fails, and `k = 4` fails because the single block has two descents and is not a rotation of a sorted array.

## Idea
A divisor `k` is sortable when two things hold at once:

1. **Each block is a rotation of a sorted run.** Walk around the block as a circle. A rotation of a sorted array has at most ONE place where the value drops (counting the wrap from the last element back to the first). Count descents inside the block, and add one more if `nums[end] > nums[start]` (that is the wrap-around descent).
2. **Blocks are already ordered against each other.** Rotating a block never moves its elements into another block, so for every block boundary, everything on the left must be `<=` everything on the right. That is exactly `prefMax[start] <= suffMin[start]` for every block start.

If both hold for every block, rotating each block into sorted order gives a fully sorted array.

## Approach: For Each Divisor k, Check Every Block Is a Rotated Sorted Run and Blocks Are Already Ordered Against Each Other
- Build three helper arrays once:
  - `prefMax[i]` = max of `nums[0..i-1]`.
  - `suffMin[i]` = min of `nums[i..n-1]`.
  - `prefDrop[i]` = number of descents `nums[j-1] > nums[j]` for `j <= i`.
- `check(k)`: for each block `[start, start + k - 1]`:
  - `drops = prefDrop[end] - prefDrop[start]` (descents strictly inside the block, found in O(1)).
  - If `nums[end] > nums[start]`, add one wrap-around descent.
  - Fail if `drops > 1`, or if `prefMax[start] > suffMin[start]`.
- Enumerate divisors up to `sqrt(n)`: for each divisor `k`, test both `k` and `n / k` (skip the duplicate when `k * k == n`), and add the sortable ones to the answer.

## Key Observation
`prefDrop` turns "count descents inside a block" into an O(1) subtraction, so `check(k)` costs only O(n / k) (one step per block). Summed over all divisors of `n`, the total work is the sum of `n / d` over divisors `d`, which is `sigma(n)`, close to linear. A block of equal values never creates a descent, because the comparison is strict, and the wrap check `nums[end] > nums[start]` is strict too, so ties are handled correctly. `k = 1` is sortable exactly when the array is already sorted, which the boundary condition enforces on its own.

## When to use this
If problem involves:
- Rotating or shifting fixed-size blocks and asking if the result can be sorted
- Trying every divisor of `n` as a block size
→ Think **a block is rotation-sortable if it has at most one cyclic descent**, and check that blocks are mutually ordered with **prefix max versus suffix min**.

## Edge Cases
- Already sorted array (every divisor is sortable, answer is the sum of all divisors of `n`).
- `n = 1` (the only divisor is 1, which is sortable).
- A block of equal elements (zero descents, always fine).
- Duplicates straddling a block boundary (allowed, since the condition uses `<=`, not `<`).
- Perfect square `n` (the divisor `sqrt(n)` must be counted only once).

## Complexity
### Approach
Time: **O(n + sigma(n))**, which is close to O(n), since each divisor `k` is checked in O(n / k) after the O(n) precomputation              
Space: **O(n)** for the three helper arrays

where:
- `n` = number of elements
- `sigma(n)` = sum of the divisors of `n`

## Related Problems
- Check if Array Is Sorted and Rotated
- Rotate Array
- Max Chunks To Make Sorted
- Find Minimum in Rotated Sorted Array