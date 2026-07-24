# Merge Sorted Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/merge-sorted-array/  
Difficulty: Easy  
Pattern: Two Pointers

## What I understood
Two sorted arrays are given. `nums1` has enough extra space to hold all elements of `nums2`. Merge them into `nums1` in sorted order.

Example:

nums1 = [1,2,3,0,0,0]

m = 3

nums2 = [2,5,6]

n = 3

Output = [1,2,2,3,5,6]

## Idea

### Approach 1 (Erase + Append + Sort)
Remove the extra zeroes from `nums1`, append all elements of `nums2`, then sort the merged array.

### Approach 2 (Three Pointers)
Start filling `nums1` from the last position. Compare the largest remaining elements of both arrays and place the larger one at the end.

## Approach
- Initialize three pointers:
  - `i` at the end of valid elements in `nums1`
  - `j` at the end of `nums2`
  - `k` at the last position of `nums1`
- Compare `nums1[i]` and `nums2[j]`.
- Place the larger element at `nums1[k]`.
- Move the corresponding pointer.
- Copy any remaining elements from `nums2`.

## Key Observation
Since `nums1` has extra space at the end, merging backwards avoids overwriting useful elements.

## When to use this
If the problem involves:
- two sorted arrays
- in-place merging
- constant extra space

→ think Two Pointers from End

## Edge Cases
- `nums2` is empty
- `nums1` has no initial elements
- All elements of one array are smaller than the other
- Duplicate values

## Complexity

### Approach 1
Time: O((m+n) log(m+n))

Space: O(1)

### Approach 2
Time: O(m+n)

Space: O(1)

## Related Problems
- Merge Two Sorted Lists
- Merge Intervals
- Sort Colors
- Two Sum II - Input Array Is Sorted