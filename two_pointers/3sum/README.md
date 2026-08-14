# 3Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/3sum/  
Difficulty: Medium  
Pattern: Sort + Two Pointer

## What I understood
Find all unique triplets `[nums[i], nums[j], nums[k]]` in the array such that `i != j != k` and the three values sum to 0. No duplicate triplets allowed in the output.

## Example
```
Input
nums = [-1,0,1,2,-1,-4]
Output
[[-1,-1,2],[-1,0,1]]
```
```
Input
nums = [0,1,1]
Output
[]
```
```
Input
nums = [0,0,0]
Output
[[0,0,0]]
```

## Idea
Sorting first enables two things: two-pointer search collapses the inner two-sum into O(n) instead of O(n²), and duplicate triplets become adjacent/easy to detect and skip, since equal values cluster together after sorting.

## Approach: Sort + Fixed Index + Two Pointer, Skip Duplicates
- Sort the array first.
- Fix outer index `i` from 0 to n-1; skip if `nums[i] == nums[i-1]` (avoids duplicate triplets starting with same first value).
- Use two pointers `j = i+1`, `k = n-1` to find pairs summing to `-nums[i]`.
- If `sum < 0`, move `j++` (need bigger sum); if `sum > 0`, move `k--` (need smaller sum).
- If `sum == 0`, record triplet, then move both pointers inward, skipping any duplicate values at new `j`/`k` positions before continuing.

## Key Observation
Duplicate-skipping happens at three levels: outer index, and both inner pointers after a match is found — all three checks are necessary to guarantee no duplicate triplet slips through, since duplicates can occur independently at any of the three positions.

## When to use this
If problem involves:
- Finding triplets/tuples summing to a target
- Need unique combinations (no duplicate results)
→ Think **sort + two pointer**, reducing one dimension via fixed index, collapsing remaining two into linear scan.

## Edge Cases
- Array with no valid triplet (`[0,1,1]`).
- All zeros (`[0,0,0]` → single triplet `[0,0,0]`).
- Array smaller than 3 elements (returns empty, loop naturally handles via bounds).
- Many duplicate values requiring careful skip logic.

## Complexity
### Approach
Time: **O(n²)** — outer loop O(n), inner two-pointer scan O(n) each
Space: **O(1)** extra (excluding output), O(n) or O(log n) for sort depending on implementation

where:
- `n` = number of elements

## Related Problems
- Two Sum
- 3Sum Closest
- 4Sum
- 3Sum Smaller