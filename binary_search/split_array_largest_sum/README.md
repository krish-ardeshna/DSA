# Split Array Largest Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/split-array-largest-sum/  
Difficulty: Hard  
Pattern: Binary Search on Answer

## What I understood
Split `nums` into `k` non-empty contiguous subarrays such that the largest sum among all subarrays is minimized. Return that minimized largest sum.

## Example
```
Input
nums = [7,2,5,10,8], k = 2
Output
18
```
```
Input
nums = [1,2,3,4,5], k = 2
Output
9
```

## Idea
As the allowed "max subarray sum" increases, fewer splits are needed (more elements fit per subarray) — monotonic relationship enables binary search. Search space bounded between `max(nums)` (can't go lower, since single largest element must fit in some subarray alone) and `sum(nums)` (upper bound, everything in one subarray).

## Approach: Binary Search on Max Subarray Sum + Greedy Partition Count
- Compute bounds: `low = max(nums)`, `high = totalSum(nums)`.
- Binary search over candidate max-sum `mid`.
- Feasibility check (`canHold`): greedily accumulate elements into current subarray while sum stays `<= mid`; start new subarray otherwise. Count total subarrays needed.
- If `canHold(mid) <= k` → mid is a valid (achievable) max sum using at most k subarrays, try smaller (`high = mid - 1`).
- Else → mid too small, need larger (`low = mid + 1`).
- Return `low` (minimum achievable largest-subarray-sum) after search converges.

## Key Observation
This is structurally identical to "Capacity To Ship Packages Within D Days" — same greedy partition-counting feasibility check, just framed as "minimize max sum" instead of "minimize capacity." Overflow matters here: search bounds and mid must use `long long` since total sum can exceed `int` range for large inputs.

## When to use this
If problem involves:
- Partitioning a sequence into k contiguous groups to minimize (or maximize) some aggregate property
- Feasibility of a candidate value is monotonic
→ Think **binary search on answer + greedy partition-count check**; watch for overflow when computing bounds.

## Edge Cases
- `k` equal to array length (each element its own subarray, answer = max element).
- `k = 1` (single subarray, answer = total sum).
- Large sums requiring `long long` bounds (int would overflow/truncate).
- All elements identical.

## Complexity
### Approach
Time: **O(n log(sum - max))** — binary search over sum range, O(n) partition check per iteration        
Space: **O(1)** extra

where:
- `n` = number of elements

## Related Problems
- Capacity To Ship Packages Within D Days
- Minimum Number of Days to Make m Bouquets
- Koko Eating Bananas
- Find the Smallest Divisor Given a Threshold