# 4Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/4sum/  
Difficulty: Medium  
Pattern: Sort + Two Pointer (Nested Fixed Indices)

## What I understood
Find all unique quadruplets `[nums[i], nums[j], nums[k], nums[l]]` (distinct indices) that sum to `target`. No duplicate quadruplets in output.

## Example
```
Input
nums = [1,0,-1,0,-2,2], target = 0
Output
[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```
```
Input
nums = [2,2,2,2,2], target = 8
Output
[[2,2,2,2]]
```

## Idea
Direct extension of the 3Sum pattern — add one more fixed outer index, collapsing the problem from 4 unknowns to 2 fixed + two-pointer scan for the remaining pair. Same sort-first strategy enables duplicate skipping and the two-pointer sum search.

## Approach: Sort + Two Fixed Indices + Two Pointer, Skip Duplicates
- Sort array first.
- Fix outer index `i`, skip duplicates (`nums[i] == nums[i-1]`).
- Fix second index `j` (starting after `i`), skip duplicates relative to previous `j` at same `i` level.
- Use two pointers `k = j+1`, `l = n-1` to find remaining pair summing to `target - nums[i] - nums[j]` (computed directly as running `sum`).
- On match: record quadruplet, move both pointers inward, skip duplicate values at new `k`/`l`.
- Use `long long` for sum to avoid integer overflow when adding up to 4 large int values.

## Key Observation
Same duplicate-avoidance principle as 3Sum, just applied at one more nesting level — duplicates must be skipped independently at `i`, `j`, `k`, and `l` for correctness. Overflow guard (`long long sum`) matters here since target and values can be large enough that 4-value sum exceeds `int` range.

## When to use this
If problem involves:
- Finding k-tuples summing to a target, k >= 3
- Need unique combinations only
→ Think **sort + (k-2) fixed indices + two pointer** for the innermost pair — pattern generalizes from 3Sum to 4Sum to kSum.

## Edge Cases
- All identical elements matching target exactly (`[2,2,2,2,2]`, target 8).
- No valid quadruplet exists.
- Overflow-prone large values (handled via `long long`).
- Array smaller than 4 elements.

## Complexity
### Approach
Time: **O(n³)** — two nested fixed-index loops O(n²), inner two-pointer scan O(n)       
Space: **O(1)** extra (excluding output), sort cost O(log n) or O(n)

where:
- `n` = number of elements

## Related Problems
- 3Sum
- Two Sum
- 3Sum Closest
- 4Sum II