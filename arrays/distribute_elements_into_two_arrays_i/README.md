# Distribute Elements Into Two Arrays I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/  
Difficulty: Easy  
Pattern: Array - Greedy Simulation

## What I understood
Distribute `nums` (1-indexed operations) into two arrays `arr1` and `arr2`. First element goes to `arr1`, second to `arr2`. For every subsequent element, compare the last elements currently in `arr1` and `arr2`: if `arr1`'s last is greater, append to `arr1`; otherwise append to `arr2`. Final result is `arr1` followed by `arr2`.

## Example
```
Input
nums = [2,1,3,4,5]
Output
[2,3,4,5,1]
```
```
Input
nums = [5,4,3,8]
Output
[5,3,4,8]
```

## Idea
Direct simulation of the stated rule — no shortcuts needed since the rule is deterministic and must be followed exactly as described, step by step, for each remaining element after the first two.

## Approach: Greedy Last-Element Comparison
- Seed `arr1` with `nums[0]`, `arr2` with `nums[1]`.
- For each remaining element (index 2 onward): compare `arr1.back()` vs `arr2.back()`.
- If `arr1.back() > arr2.back()` → append to `arr1`; else → append to `arr2`.
- After processing all elements, concatenate `arr2` onto the end of `arr1` and return.

## Key Observation
This is pure simulation — the problem defines the exact rule to follow, so the "approach" is just correctly implementing that rule without overthinking; no need for sorting, searching, or optimization since the assignment for each element is fully determined by the immediately preceding state.

## When to use this
If problem involves:
- Following an exact, deterministic distribution/assignment rule step-by-step
→ Think **direct simulation**, don't look for a shortcut where none exists.

## Edge Cases
- Array of exactly 2 elements (no loop iterations needed, just concatenate).
- All elements identical (comparison always routes to `arr2` per `else` branch, given `>` not `>=`).
- Values causing `arr1.back()` and `arr2.back()` to tie repeatedly.
- Large array requiring many comparisons.

## Complexity
### Approach
Time: **O(n)**                              
Space: **O(n)** — output arrays (required)

where:
- `n` = number of elements

## Related Problems
- Distribute Elements Into Two Arrays II
- Two Sum
- Sort Array By Parity
- Wiggle Sort