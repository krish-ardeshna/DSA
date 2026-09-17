# Find Two Non-overlapping Sub-arrays Each With Target Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/  
Difficulty: Medium  
Pattern: Sliding Window + DP (Best Length Ending By Index)

## What I understood
Find two NON-OVERLAPPING contiguous subarrays, each summing exactly to `target`, minimizing the SUM of their two lengths. Return -1 if no such pair exists.

## Example
```
Input
arr = [3,2,2,4,3], target = 3
Output
2
```
```
Input
arr = [7,3,4,7], target = 7
Output
2
```

## Idea
Use a variable-size sliding window (standard technique for positive-number target-sum subarrays) to find every window whose sum equals `target`. For each such window ending at `right`, its length can be combined with the BEST (minimum-length) qualifying window found so far that ends strictly BEFORE this window starts — since that guarantees non-overlap. Maintain a running array `res[i]` = minimum length of any target-sum subarray ending at or before index `i`, allowing O(1) lookup of the best "earlier" window when a new qualifying window is found.

## Approach: Variable Window + Running Min-Length-So-Far Array
- Standard sliding window: expand `right`, add to `sum`; shrink from `left` while `sum > target` (only valid since all values are positive, guaranteeing monotonic sum behavior).
- When `sum == target`: compute `len = right - left + 1`.
  - Check if a valid non-overlapping earlier window exists (`res[left-1] != INF`); if so, update `ans` with combined length.
  - Update `res[right]` to the minimum of this window's length and the best found in `res[right-1]` (carrying forward the running minimum).
- If `sum != target` at this `right`, just carry forward `res[right] = res[right-1]` (no new window found here, but running minimum persists).
- Final answer: `ans` if any valid pair found, else -1.

## Key Observation
The `res[]` array cleverly separates "finding windows" from "combining pairs" — by the time a new window is found ending at `right`, `res[left-1]` already holds the best possible LEFT-side window (guaranteed non-overlapping, since it ends before the current window starts), enabling instant pair evaluation without needing to re-scan earlier windows.

## When to use this
If problem involves:
- Finding two (or more) non-overlapping subarrays each satisfying some property, optimizing a combined metric (sum of lengths, etc.)
→ Think **sliding window to find qualifying windows + running "best-so-far" array indexed by position**, enabling O(1) combination checks instead of re-scanning.

## Edge Cases
- Only one qualifying window exists (no valid pair, must return -1 since two are needed).
- No qualifying window exists at all.
- Multiple overlapping candidate windows at the same position (running min correctly tracks best non-overlapping choice).
- All elements sum exactly to target as a single window (still needs a SECOND non-overlapping one).

## Complexity
### Approach
Time: **O(n)** — single pass sliding window, left pointer only moves forward        
Space: **O(n)** — `res` array storage

where:
- `n` = number of elements

## Related Problems
- Maximum Sum of Two Non-Overlapping Subarrays
- Minimum Size Subarray Sum
- Subarray Sum Equals K
- Best Time to Buy and Sell Stock III