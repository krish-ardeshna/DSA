# Minimum Positive Sum Subarray
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-positive-sum-subarray/  
Difficulty: Easy  
Pattern: Brute Force with Running Sum + Prefix Sum and Ordered Set (Sliding Window)

## What I understood
Given an integer array `nums` and two integers `l` and `r`. Find the minimum positive sum among all subarrays whose length is between `l` and `r` (both included). A sum must be greater than `0` to count. If no such subarray exists, return `-1`.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
nums = [3,-2,1,4], l = 2, r = 3
Output
1
```
Explanation: the subarrays of length 2 or 3 and their sums are `[3,-2]` = 1, `[-2,1]` = -1, `[1,4]` = 5, `[3,-2,1]` = 2, `[-2,1,4]` = 3. The positive sums are 1, 5, 2, 3, so the minimum is 1.

```
Input
nums = [-2,2,-3,1], l = 2, r = 3
Output
-1
```
Explanation: the sums are `[-2,2]` = 0, `[2,-3]` = -1, `[-3,1]` = -2, `[-2,2,-3]` = -3, `[2,-3,1]` = 0. None is positive, so the answer is -1.

```
Input
nums = [1,2,3,4], l = 2, r = 4
Output
3
```
Explanation: the length-2 sums are 3, 5, 7. The longer subarrays have larger sums (6, 9, 10). The minimum positive sum is 3.

## Idea (shared by both approaches)
Check every subarray with length in `[l, r]`, keep the sums that are positive, and take the smallest. The two approaches differ in how fast they find the best subarray ending at each position.

## Approach 1: Brute Force (Running Sum From Every Start)

### Idea
For every start `i`, extend `j` to the right for at most `r` elements. Keep a running sum, so each new subarray costs O(1). Update the answer when the length is at least `l` and the sum is positive.

### Steps
- `ans = INT_MAX`.
- For each start `i`: `sum = 0`.
- For `j = i` to `min(n - 1, i + r - 1)`: `sum += nums[j]`, `len = j - i + 1`.
- If `len >= l` and `sum > 0`, `ans = min(ans, sum)`.
- Return `-1` if `ans` is still `INT_MAX`, else `ans`.

### Complexity
Time: **O(n * r)**  
Space: **O(1)**

---

## Approach 2: Prefix Sum + Ordered Set (Sliding Window of Starts)

### Idea
Let `pref[i]` be the sum of the first `i` elements. Then the sum of `nums[i..e-1]` is `pref[e] - pref[i]`. For a fixed end `e`, the valid starts `i` satisfy `e - r <= i <= e - l`. The smallest positive sum is `pref[e] - (the largest pref[i] that is smaller than pref[e])`. A sorted multiset over the valid starts answers this with one `lower_bound`. The window of starts slides by one as `e` grows.

### Steps
- Build `pref[0..n]`.
- `starts` = empty multiset of `pref[i]` for the valid starts.
- For `e = 1` to `n`:
  - If `e - l >= 0`, insert `pref[e - l]`.
  - If `e - r - 1 >= 0`, erase ONE copy of `pref[e - r - 1]`.
  - `it = starts.lower_bound(pref[e])`. If `it != begin`, take `*prev(it)` (the largest value below `pref[e]`) and update `ans = min(ans, pref[e] - *prev(it))`.
- Return `-1` if `ans` is still `INT_MAX`, else `ans`.

### Complexity
Time: **O(n log n)**  
Space: **O(n)**

---

## Key Observation
With prefix sums, "a positive sum subarray ending at `e`" becomes "a smaller prefix sum earlier in a window". The smallest positive sum is the gap to the NEAREST smaller prefix sum, so an ordered set with `lower_bound` finds it quickly. Erase only one copy from the multiset, because prefix sums can repeat.

For `n <= 100` the simple double loop is already fast enough. The ordered-set version matters if `n` were large.

## When to use this
If problem involves:
- A length range `[l, r]` for subarrays
- A condition on the subarray sum (positive, closest to a target, at most `k`)
→ Think **prefix sums, and an ordered set over the prefix sums of the valid starts**.

## Edge Cases
- No positive subarray (return `-1`).
- `l == r` (only one length is allowed, so the window of starts has one element).
- `l = 1` (single elements count too).
- `r = n` (the whole array is allowed).
- Sum exactly `0` does not count (must be strictly greater than `0`, so `lower_bound` is used, not `upper_bound`).
- Duplicate prefix sums (use `multiset`, and erase with `find` so only one copy goes).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n * r) | O(1) |
| Prefix Sum + Ordered Set | O(n log n) | O(n) |

where:
- `n` = length of `nums`
- `r` = maximum allowed length

## Related Problems
- Maximum Subarray
- Subarray Sum Equals K
- Minimum Size Subarray Sum
- Continuous Subarray Sum