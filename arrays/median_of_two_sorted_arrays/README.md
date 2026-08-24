# Median of Two Sorted Arrays
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/  
Difficulty: Hard  
Pattern: Array - Merge Simulation (Two Pointer, No Extra Array)

## What I understood
Given two sorted arrays, find the median of the combined sorted sequence — without necessarily merging them into a new array. Optimal solutions target O(log(min(n1,n2))) via binary search on partition, but this approach uses a simpler O(n1+n2) merge-simulation.

## Example
```
Input
nums1 = [1,3], nums2 = [2]
Output
2.0
```
```
Input
nums1 = [1,2], nums2 = [3,4]
Output
2.5
```

## Idea
Median only depends on 1 or 2 specific positions in the fully merged sequence (middle element if odd total length, average of two middle elements if even). Rather than building the full merged array, simulate the merge using two pointers, but only record values when the running count (`cnt`) hits the target index/indices — everything else is discarded.

## Approach: Two Pointer Merge, Track Only Middle Element(s)
- Compute target indices: `ind2 = n/2`, `ind1 = ind2 - 1` (for even n, these are the two middle elements; for odd n, only `ind2` matters).
- Standard two-pointer merge: compare `nums1[i]` vs `nums2[j]`, advance the smaller, incrementing `cnt` each step.
- At each step, check if `cnt == ind1` or `cnt == ind2`; if so, record that element.
- After both pointers exhaust (handled via two follow-up while loops for leftover elements), return based on parity: odd length → `ind2el` directly; even length → average of `ind1el` and `ind2el`.

## Key Observation
No need to actually construct the merged array — since only 1-2 positions matter for the median, tracking just those positions during the merge simulation keeps space at O(1) (excluding input), while still being straightforward to reason about compared to the binary-search-on-partition optimal approach.

## When to use this
If problem involves:
- Needing specific position(s) from a merge of two sorted sequences
- Full merged array isn't otherwise needed
→ Think **merge simulation tracking only target positions**, avoids O(n) extra space of full merge.

## Edge Cases
- One array empty.
- Arrays of very different sizes.
- Total combined length odd vs even (different return logic).
- Duplicate values across both arrays.

## Complexity
### Approach
Time: **O(n1 + n2)** — full merge simulation (not the optimal O(log(min(n1,n2))) binary search approach)        
Space: **O(1)** extra — no merged array stored

where:
- `n1`, `n2` = sizes of the two input arrays

## Related Problems
- Merge Sorted Array
- Kth Smallest Element in a Sorted Matrix
- Find K Pairs with Smallest Sums
- Median of a Row Wise Sorted Matrix