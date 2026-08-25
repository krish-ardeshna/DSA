# Smallest Missing Multiple of K
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/  
Difficulty: Not verified (contest problem, check LC page directly)  
Pattern: Hashing + Linear Search

## What I understood
Given an array `nums` and integer `k`, find the smallest positive multiple of `k` that does NOT appear in `nums`.

## Example
```
Input
nums = [1,2,3,4,8], k = 4
Output
12
```

## Idea
Convert array to a hash set for O(1) membership checks, then simply walk through multiples of `k` (`k, 2k, 3k, ...`) in increasing order until one isn't found in the set.

## Approach: Hash Set Lookup + Incremental Multiple Check
- Build hash set from `nums`.
- Start `x = k` (smallest positive multiple of k).
- While `x` exists in the set, increment `x` by `k` (move to next multiple).
- Return `x` once a missing multiple is found.

## Key Observation
Since we're only checking multiples of `k` (not every integer), the search space per query is bounded by how many consecutive multiples of `k` happen to be present in `nums` — worst case scans through many multiples if array is dense with them, but each check itself is O(1) via hash set.

## When to use this
If problem involves:
- Finding smallest/first missing value from a restricted candidate set (multiples, specific pattern, etc.)
- Fast membership testing needed
→ Think **hash set + incremental candidate check**, don't overcomplicate with sorting or binary search unless candidate range is very large.

## Edge Cases
- `k` itself missing from array (immediate return `k`).
- All small multiples of `k` present, requiring many iterations.
- Empty array (`k` returned immediately, since nothing to match).
- Large `k` values.

## Complexity
### Approach
Time: **O(n + m)** — O(n) to build set, O(m) worst case to find missing multiple, where m = number of consecutive present multiples             
Space: **O(n)** — hash set storage

where:
- `n` = number of elements in nums
- `m` = number of multiples checked before finding a miss

## Related Problems
- Missing Number
- Smallest Missing Integer Greater Than Sequential Prefix Sum
- Kth Missing Positive Number
- Find the Smallest Divisor Given a Threshold