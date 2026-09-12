# Sum of Subarray Minimums
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sum-of-subarray-minimums/  
Difficulty: Medium  
Pattern: Monotonic Stack (Previous/Next Smaller Element Contribution)

## What I understood
Given an array, find the sum of `min(subarray)` across ALL possible contiguous subarrays. Since the number of subarrays is O(n²), brute force is too slow for large arrays — need an O(n) contribution-counting approach. Return result modulo `10^9 + 7`.

## Example
```
Input
arr = [3,1,2,4]
Output
17
```
```
Input
arr = [11,81,94,43,3]
Output
444
```

## Idea
Instead of iterating every subarray and finding its min (O(n²) or worse), flip the perspective: for each element, count how many subarrays have THIS element as their minimum, and multiply by its value — sum these contributions across all elements. An element `arr[i]` is the minimum of a subarray exactly when that subarray's left boundary stays within the range bounded by the "previous smaller element" (PSE) and its right boundary stays within the range bounded by "next smaller element" (NSE).

## Approach: PSE/NSE via Monotonic Stack + Contribution Counting
- Compute `pse[i]` = index of nearest element to the left that is STRICTLY smaller than `arr[i]` (using `>` in stack pop condition, ensuring ties go to the earlier-occurring element to avoid double-counting).
- Compute `nse[i]` = index of nearest element to the right that is smaller-or-equal to `arr[i]` (using `>=` in stack pop condition, complementing the tie-breaking rule from PSE).
- For each `i`: `left = i - pse[i]` (number of valid left boundaries), `right = nse[i] - i` (number of valid right boundaries).
- Total subarrays where `arr[i]` is the minimum = `left * right`. Contribution to answer = `left * right * arr[i]`.
- Sum all contributions, modulo `10^9 + 7`.

## Key Observation
The asymmetric tie-breaking (`>` for PSE, `>=` for NSE) is essential when duplicate values exist — it ensures each subarray with a repeated minimum value is counted exactly once (attributed to one specific occurrence of that value), preventing both undercounting and overcounting.

## When to use this
If problem involves:
- Sum/count of min or max across all subarrays
→ Think **monotonic stack for previous/next smaller (or greater) element, then contribution counting** (`left_range * right_range * value`) instead of brute-force subarray enumeration.

## Edge Cases
- All elements identical (careful tie-breaking prevents double-counting).
- Strictly increasing array (each element's PSE is nothing extends far left, NSE reaches the very end).
- Strictly decreasing array (opposite pattern).
- Single element array.

## Complexity
### Approach
Time: **O(n)** — each element pushed/popped from stack at most once across both PSE and NSE computations                
Space: **O(n)** — stack and result arrays

where:
- `n` = number of elements

## Related Problems
- Sum of Subarray Ranges
- Sum of Subarray Maximums
- Next Greater Element I
- Largest Rectangle in Histogram