# Minimum Swaps to Sort by Digit Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/  
Difficulty: Medium  
Pattern: Sorting + Permutation Cycle Detection

## What I understood
Given an array of distinct positive integers, the target order is: sort by DIGIT SUM ascending, and if two numbers have the same digit sum, sort by the number itself ascending. Find the minimum number of swaps (of any two elements, not just adjacent ones) needed to rearrange the array into this order.

## Example
```
Input
nums = [37,100]
Output
1
```
Explanation: digit sums are 10 and 1, so the target order is [100,37]. One swap fixes it.

```
Input
nums = [22,14,33,7]
Output
0
```
Explanation: digit sums are 4, 5, 6, 7, already in order, so no swap is needed.

```
Input
nums = [18,43,34,16]
Output
2
```
Explanation: digit sums are 9, 7, 7, 7. The target order is [16,34,43,18]. Swap 18 with 16, then 43 with 34.

## Idea
First decide where every element must end up: sort a copy of the array by the rule (digit sum, then value), and remember each element's ORIGINAL index. Now the sorted position `i` holds an element that currently sits at index `get<2>(arr[i])`. That gives a permutation, a mapping from "where it should go" to "where it is now".

A permutation breaks into independent cycles. A cycle of length `k` needs exactly `k - 1` swaps to fix, because each swap can put one element in its final place, and the last swap fixes two at once. Cycles of length 1 are already in place and cost nothing. So the answer is the sum of `(cycle length - 1)` over all cycles.

## Approach: Sort With Original Indices, Count Swaps as (Cycle Size - 1) Per Cycle
- Build `arr[i] = (digitSum, value, originalIndex)` for every element.
- Sort `arr`. The tuple order is exactly the required order: digit sum first, then value. The original index is last, but since all values are distinct it never decides a tie.
- Keep a `visited` array. For each unvisited position `i` that is not already in place (`originalIndex != i`):
  - Walk the cycle: `j = i`, then repeatedly mark `j` visited and jump to `j = originalIndex of arr[j]`, counting the cycle size.
  - Add `cycleSize - 1` to the swap count.
- Return the total.

## Key Observation
The minimum number of swaps to sort any array of distinct elements is `n - (number of cycles)`, where fixed points count as cycles of length 1. Here the "array" is sorted by a custom key, so the only extra step is attaching original indices before sorting, so the permutation can be read off directly. Since the values are distinct, the order is a strict total order, which makes the target arrangement unique.

## When to use this
If problem involves:
- The minimum number of arbitrary swaps to reach a sorted (or otherwise fixed) arrangement
- A custom sort key that fully determines the target order
→ Think **sort with original indices, then count permutation cycles** (`swaps = sum of (cycle length - 1)`).

## Edge Cases
- Already sorted array (every element is a fixed point, answer 0).
- Single element array (answer 0).
- Many numbers with the same digit sum (the value tie-break decides the order).
- Fully reversed order (a few long cycles, so swaps are about `n / 2`).
- One long cycle covering the whole array (answer `n - 1`).

## Complexity
### Approach
Time: **O(n log n)**, dominated by sorting          
Space: **O(n)** for the tuple array and the visited array

where:
- `n` = number of elements

## Related Problems
- Minimum Swaps to Sort an Array
- Minimum Number of Operations to Sort a Binary Tree by Level
- Sort Integers by The Number of 1 Bits
- Minimum Swaps to Make Sequences Increasing