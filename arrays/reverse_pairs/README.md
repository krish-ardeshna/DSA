# Reverse Pairs
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/reverse-pairs/  
Difficulty: Hard  
Pattern: Merge Sort (Modified Count During Merge)

## What I understood
Count the number of pairs `(i, j)` where `i < j` and `nums[i] > 2 * nums[j]`. Naive O(n²) checking all pairs is too slow for large inputs; need a sub-O(n²) approach.

## Example
```
Input
nums = [1,3,2,3,1]
Output
2
```
```
Input
nums = [2,4,3,5,1]
Output
3
```

## Idea
Modified merge sort: since both halves get sorted independently before merging, use that sorted structure to count valid cross-half pairs in linear time during each merge step — using a two-pointer sweep exploiting monotonicity, since `arr[i]` from the left half only increases, allowing `right` pointer to advance monotonically without resetting.

## Approach: Merge Sort with Cross-Pair Counting
- Standard merge sort recursion: split into `low..mid` and `mid+1..high`, recursively count pairs in each half.
- Before merging (while both halves are still separately sorted from previous recursive calls), count cross-half pairs via `countPairs`: for each `i` in left half, advance `right` pointer while `arr[i] > 2 * arr[right]`, add `(right - (mid+1))` to count.
- The `right` pointer never resets between iterations of `i` — since left half is sorted ascending, if `arr[i] > 2*arr[right]` held for previous `i`, it still holds for a larger `arr[i]`, avoiding redundant re-scanning.
- Perform standard merge afterward to keep the combined range sorted for higher-level recursive calls.
- Sum counts from left recursion + right recursion + cross-pair count at this level.

## Key Observation
Counting must happen BEFORE the merge step (while halves are still separately sorted) — pairs counted here are specifically cross-half pairs where the left-half index is less than the right-half index, matching the original array's relative ordering requirement `i < j`. Using `2LL * arr[right]` avoids integer overflow when values are large.

## When to use this
If problem involves:
- Counting pairs/inversions satisfying an order-and-value condition across the array
- Naive O(n²) too slow, need O(n log n)
→ Think **modified merge sort**, count cross-half pairs during the divide-and-conquer merge step using two-pointer monotonic advancement.

## Edge Cases
- Array with all identical elements.
- Already sorted array (ascending or descending).
- Negative numbers (overflow risk on `2 * arr[right]` without `2LL` cast).
- Single element or empty array (base case, 0 pairs).

## Complexity
### Approach
Time: **O(n log n)** — merge sort structure, linear counting per merge level        
Space: **O(n)** — temporary array during merge

where:
- `n` = number of elements

## Related Problems
- Count of Smaller Numbers After Self
- Reverse Pairs II
- Global and Local Inversions
- Count Inversions