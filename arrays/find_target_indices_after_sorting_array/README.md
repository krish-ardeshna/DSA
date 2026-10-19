# Find Target Indices After Sorting Array
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/  
Difficulty: Easy  
Pattern: Sorting + Linear Scan

## What I understood
Sort the array in non-decreasing order, then return the list of all indices `i` where the sorted array has `nums[i] == target`. The indices must be in increasing order. Return an empty list if the target does not appear.

## Example
```
Input
nums = [1, 2, 5, 2, 3], target = 2
Output
[1, 2]
```
Explanation: the sorted array is `[1, 2, 2, 3, 5]`, and the value 2 sits at indices 1 and 2.

```
Input
nums = [1, 2, 5, 2, 3], target = 3
Output
[3]
```

```
Input
nums = [1, 2, 5, 2, 3], target = 4
Output
[]
```
Explanation: 4 is not in the array, so there are no indices to report.

## Idea
The question asks for positions in the SORTED array, so the array must be sorted first. After sorting, all copies of the target sit next to each other, and scanning from left to right naturally produces the indices in increasing order, so no extra sorting of the answer is needed.

## Approach: Sort the Array, Collect Indices Where Value Equals Target
- Sort `nums` in ascending order.
- Walk through the sorted array with index `i`.
- Whenever `nums[i] == target`, push `i` into the answer.
- Return the answer (empty if no match).

## Key Observation
The indices come out already ordered and contiguous, because equal values are grouped together after sorting. If the array were large, there is a way to skip the sort entirely: the target's first index equals the count of elements smaller than the target, and the number of results equals the count of elements equal to the target, so the whole answer can be built in O(n) from two counters. For the small constraints here (`n <= 100`), sorting is simple and fast enough.

## When to use this
If problem involves:
- A question about positions in the sorted version of an array
- Small input size, where an extra sort does not matter
→ Think **sort first, then scan for matches**, and keep the O(n) counting idea in mind when the input is large.

## Edge Cases
- Target not present (answer is an empty list).
- Target appears once (answer has a single index).
- All elements equal to the target (answer is every index `0..n-1`).
- Single element array (answer is `[0]` if it equals the target, else empty).
- Unsorted input with duplicates spread out (sorting groups them together).

## Complexity
### Approach
Time: **O(n log n)**, dominated by sorting          
Space: **O(1)** extra (excluding the output list and the sort's own stack)

where:
- `n` = number of elements

## Related Problems
- Find First and Last Position of Element in Sorted Array
- Search Insert Position
- How Many Numbers Are Smaller Than the Current Number
- Count Elements With Strictly Smaller and Greater Elements