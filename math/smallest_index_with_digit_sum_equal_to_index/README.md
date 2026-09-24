# Smallest Index With Digit Sum Equal to Index
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/  
Difficulty: Easy  
Pattern: Math - Digit Extraction

## What I understood
Find the smallest index `i` such that the digit sum of `nums[i]` equals `i` itself. Return -1 if no such index exists.

## Example
```
Input
nums = [1,3,2]
Output
2
```
```
Input
nums = [1,10,11]
Output
0
```

## Idea
Straightforward linear scan from left to right - check each index's digit sum against the index value, return immediately upon the first match (guaranteeing smallest index due to left-to-right order).

## Approach: Linear Scan, Check Digit Sum Against Index
- `digitSum(num)`: extract digits via repeated `% 10` and `/ 10`, accumulate sum.
- Iterate `i` from 0 to `n-1`: compute `digitSum(nums[i])`, compare against `i`.
- Return `i` immediately on first match (smallest index found first due to forward iteration).
- Return -1 if no match found after full scan.

## Key Observation
Scanning left to right and returning on first match automatically guarantees the SMALLEST valid index - no need for additional tracking or comparison logic beyond simple early return.

## When to use this
If problem involves:
- Finding the first/smallest index satisfying a per-element digit-based condition
→ Think **simple left-to-right linear scan with early return**, no need for complex search when only the smallest match matters and array isn't sorted by the relevant property.

## Edge Cases
- Index 0 satisfying the condition immediately (digit sum of `nums[0]` must be 0, meaning `nums[0]` itself is 0).
- No index satisfies the condition (return -1).
- Large numbers requiring multiple digit extractions.
- Single element array.

## Complexity
### Approach
Time: **O(n * d)** where d = average number of digits per element           
Space: **O(1)**

where:
- `n` = number of elements
- `d` = digit count per number

## Related Problems
- Add Digits
- Check Divisibility by Digit Sum and Product
- Sum of Digits in Base K
- Count Commas in Range