# Smallest Missing Integer Greater Than Sequential Prefix Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/  
Difficulty: Easy  
Pattern: Array - Prefix Sum + Hash Set

## What I understood
Find the length of the longest sequential prefix — a prefix where each element is exactly 1 more than the previous (`nums[i] == nums[i-1] + 1`). Sum that prefix. Then find the smallest integer `>= sum` that does NOT already exist anywhere in the array.

## Example
```
Input
nums = [1,2,3,2,5]
Output
6
```
```
Input
nums = [3,4,5,1,12,14,13]
Output
15
```

## Idea
Two separate sub-problems chained together: first compute the sequential prefix sum (stop as soon as the +1 pattern breaks), then do a simple "smallest missing value starting from X" search using a hash set for O(1) membership checks.

## Approach: Sequential Prefix Sum + Set Lookup
- Init `sum = nums[0]` (first element always part of prefix by definition).
- Walk from index 1: while `nums[i] == nums[i-1] + 1`, add to `sum`; stop at first break.
- Build a hash set of all array values for O(1) lookup.
- Starting from `sum`, increment until a value not in the set is found; return it.

## Key Observation
The prefix-sum computation and the missing-value search are independent steps — no need to overcomplicate by merging them into one pass. Hash set lookup keeps the missing-value search efficient even if many consecutive values from `sum` onward happen to exist in the array.

## When to use this
If problem involves:
- Detecting a prefix/run satisfying a simple arithmetic pattern
- Followed by a "smallest missing" style search
→ Think **prefix scan + hash set membership check**, treat as two independent sub-problems.

## Edge Cases
- Entire array is sequential (`[1,2,3,4]`) → prefix sum covers whole array.
- Prefix breaks immediately (`nums[1] != nums[0]+1`) → prefix is just `nums[0]`.
- Sum itself might already be far beyond max array value → loop still correctly terminates once out of set range.
- Duplicate values in array.

## Complexity
### Approach
Time: **O(n)** — one pass for prefix sum, one pass to build set, worst-case one pass for missing search
Space: **O(n)** — hash set storage

where:
- `n` = number of elements

## Related Problems
- Missing Number
- Find All Numbers Disappeared in an Array
- First Missing Positive
- Smallest Subarray With All Occurrences of the Most Frequent Element