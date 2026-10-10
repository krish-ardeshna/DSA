# Minimum Sum of Squared Difference
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-sum-of-squared-difference/  
Difficulty: Medium  
Pattern: Greedy (Shave Largest Differences First, Frequency Buckets)

## What I understood
Two arrays `nums1` and `nums2`. The sum of squared difference is the sum of `(nums1[i] - nums2[i])^2`. We can change elements of `nums1` by +1 or -1 at most `k1` times, and elements of `nums2` by +1 or -1 at most `k2` times. Find the minimum possible sum of squared difference.

## Example
```
Input
nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output
579
```
```
Input
nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output
43
```

## Idea
Changing either array by 1 reduces `|nums1[i] - nums2[i]|` by 1 (as long as it is above 0), so `k1` and `k2` are interchangeable. Merge them into one budget `k = k1 + k2`. Squares punish big values hardest, so each operation should hit the currently largest difference. Reducing the largest `d` to `d - 1` saves `2d - 1`, which is the biggest saving available.

Doing this one unit at a time is too slow, so bucket the differences by value and level them down from the top, many at once.

## Approach: Bucket Differences by Value, Reduce From the Top Down
- Compute `diff[i] = |nums1[i] - nums2[i]|`, track `maxDiff` and `total`.
- If `k >= total`, every difference can be made 0, return 0.
- Build `freq[d]` = how many differences equal `d`.
- Walk `d` from `maxDiff` down to 1 while budget remains:
  - `reduce = min(k, freq[d])`.
  - Move `reduce` elements from bucket `d` to bucket `d - 1`.
  - Spend `k -= reduce`.
- Answer = sum of `freq[d] * d * d` over all `d`.

## Key Observation
Because we walk top-down, `freq[d]` already includes elements pushed down from `d + 1`. This means leftover budget naturally keeps flattening the whole top group together. If the budget runs out partway through a bucket, only some elements drop one level, which is still optimal since all elements in that bucket are equal.

Use `long long` for `k`, the frequencies and the final sum. The answer can reach about `1e15`.

## When to use this
If problem involves:
- A cost that grows by square (or any convex function) of each element
- A shared budget of +1/-1 operations
→ Think **always reduce the current maximum first**, and use **frequency buckets** when the value range is small enough to avoid a heap and unit-by-unit simulation.

## Edge Cases
- `k1 + k2 >= sum of all differences` (answer 0, handled by the early return).
- `k1 = k2 = 0` (no reduction, plain sum of squares).
- All differences already 0.
- Budget runs out in the middle of a bucket.

## Complexity
### Approach
Time: **O(n + maxDiff)**            
Space: **O(maxDiff)**

where:
- `n` = number of elements
- `maxDiff` = largest absolute difference between paired elements

## Related Problems
- Minimum Absolute Sum Difference
- Minimize Deviation in Array
- Reduce Array Size to The Half
- Last Stone Weight