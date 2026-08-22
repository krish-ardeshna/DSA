# Kth Missing Positive Number
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/kth-missing-positive-number/  
Difficulty: Easy  
Pattern: Binary Search (Missing Count via Index Offset)

## What I understood
Given a strictly increasing array of positive integers, find the `k`-th positive integer that is missing from the array (missing = not present in `arr`).

## Example
```
Input
arr = [2,3,4,7,11], k = 5
Output
9
```
```
Input
arr = [1,2,3,4], k = 2
Output
6
```

## Idea
For a strictly increasing array with no missing numbers, `arr[i]` would equal `i+1`. The number of missing positives before index `i` is exactly `arr[i] - (i+1)` — the gap between the actual value and where it "should" be if nothing were missing. This missing-count is monotonically non-decreasing as `i` increases, enabling binary search to find the boundary where missing-count first reaches/exceeds `k`.

## Approach: Binary Search on Missing Count
- Binary search over array indices.
- At `mid`, compute `missing = arr[mid] - (mid + 1)` (count of missing positives up to and including `arr[mid]`'s position).
- If `missing < k` → not enough missing numbers yet, search right half (`low = mid + 1`).
- Else → enough or more missing numbers found, search left half (`high = mid - 1`).
- After loop, `high` points to the last index where missing count was `< k`. Answer is `k + high + 1` — accounts for `high+1` actual array elements already passed, plus the `k` missing numbers needed.

## Key Observation
The formula `arr[i] - (i+1)` elegantly captures "how many positive integers are missing so far" without needing to track them explicitly — it's simply the difference between expected value (if array were gapless) and actual value at each position.

## When to use this
If problem involves:
- Finding k-th missing element in an otherwise structured/increasing sequence
- A monotonic "gap count" formula can be derived from position vs value
→ Think **binary search on the gap/missing-count formula**, not linear scan.

## Edge Cases
- `k` smaller than the first gap (missing numbers before `arr[0]`).
- `k` larger than all gaps within array range (answer extends beyond last array element).
- Array with no gaps at all up to some point.
- Single element array.

## Complexity
### Approach
Time: **O(log n)**      
Space: **O(1)**

where:
- `n` = number of elements in array

## Related Problems
- Missing Number
- Find All Numbers Disappeared in an Array
- First Missing Positive
- Smallest Missing Integer