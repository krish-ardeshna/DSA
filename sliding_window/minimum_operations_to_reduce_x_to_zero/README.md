# Minimum Operations to Reduce X to Zero
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/  
Difficulty: Medium  
Pattern: Sliding Window (Complement Target Transformation)

## What I understood
Each operation removes either the LEFTMOST or RIGHTMOST element of `nums`, subtracting its value from `x`. Find the MINIMUM number of operations to make `x` exactly 0. Return -1 if impossible.

## Example
```
Input
nums = [1,1,4,2,3], x = 5
Output
2
```
```
Input
nums = [5,6,7,8,9], x = 4
Output
-1
```

## Idea
Removing elements from BOTH ends to sum to `x` is equivalent to KEEPING a contiguous MIDDLE subarray whose sum equals `total - x` (everything NOT removed). This transforms a two-sided removal problem into a standard "find the LONGEST subarray with a given sum" sliding window problem — maximizing the kept middle subarray directly minimizes the number of removed (operations) elements.

## Approach: Find Longest Middle Subarray Summing to (total - x)
- Compute `total` = sum of all elements.
- Compute `target = total - x` — the sum the KEPT middle subarray must equal.
- Edge cases: if `target < 0`, impossible (x exceeds total sum), return -1. If `target == 0`, the entire array must be removed, answer is `n` (no middle subarray needed, degenerate case).
- Standard variable-size sliding window: expand `right`, add to `windowSum`; shrink from `left` while `windowSum > target` (valid since all values assumed non-negative, per problem constraints).
- Whenever `windowSum == target`, track `maxLen` (longest such subarray found).
- Final answer: `n - maxLen` (elements NOT in the longest kept subarray = elements that must be removed). Return -1 if no valid subarray found.

## Key Observation
The complement transformation (`removed from ends` ↔ `kept in middle`) is the crucial reframing — directly trying to simulate all possible left/right removal combinations would be far more complex, but converting to "longest subarray with sum == target" makes it a well-known, directly solvable sliding window problem.

## When to use this
If problem involves:
- Removing elements from BOTH ends of an array to reach a target sum/condition, minimizing operations
→ Think **complement to "longest middle subarray with sum = total - target"**, solvable via standard sliding window, rather than directly simulating two-pointer removal from both ends.

## Edge Cases
- `x` greater than total sum (impossible, target negative, return -1).
- `x` equals total sum exactly (remove everything, target = 0, answer = n).
- No valid subarray sums to target (return -1).
- Single element array.

## Complexity
### Approach
Time: **O(n)**              
Space: **O(1)**

where:
- `n` = number of elements

## Related Problems
- Subarray Sum Equals K
- Maximum Size Subarray Sum Equals k
- Minimum Size Subarray Sum
- Find Two Non-overlapping Sub-arrays Each With Target Sum