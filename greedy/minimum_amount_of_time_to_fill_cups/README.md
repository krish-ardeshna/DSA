# Minimum Amount of Time to Fill Cups

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/  
Difficulty: Easy  
Pattern: Greedy, Heap

## What I understood

There are three types of cups containing cold, warm, and hot water.

Every second, you can either:
- Fill one cup of a single type, or
- Fill one cup each from two different types.

Find the minimum number of seconds required to fill all cups.

## Example

```
Input
amount = [1,4,2]

Output
4
```

## Idea

Either repeatedly choose the two largest remaining amounts (simulation), or observe that the answer depends only on:
- the total number of cups, and
- the largest amount.

## Approach 1: Max Heap (Simulation)

- Store all non-zero amounts in a max heap.
- Repeatedly remove the two largest values.
- Decrease both by one and push them back if they remain positive.
- Count the seconds until all cups are filled.

## Approach 2: Mathematical Observation

- Compute:
  - Total cups = `sum`
  - Largest amount = `mx`
- The answer is:
  - `mx` if one type dominates.
  - Otherwise, half of the total cups rounded up.

## Key Observation

Two cups can be filled per second only if they belong to different types.

Therefore, the minimum time is constrained by:
- the largest pile, and
- the total work remaining.

## When to use this

- Greedy scheduling
- Pairing two tasks together
- Maximum vs total workload
- Simulation optimization

→ Think **Max(maximum workload, ceil(total workload / 2))**.

## Edge Cases

- All amounts are zero.
- Only one type has cups.
- Two types are empty.
- All three amounts are equal.

## Complexity

### Approach 1

Time: **O(S log 3)** ≈ **O(S)**

Space: **O(1)**

where `S` is the total number of cups.

### Approach 2

Time: **O(1)**

Space: **O(1)**

## Related Problems

- Last Stone Weight
- Kth Largest Element in a Stream
- Task Scheduler
- Reorganize String