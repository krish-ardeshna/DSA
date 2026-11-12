# Longest Strictly Increasing or Strictly Decreasing Subarray
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/  
Difficulty: Easy  
Pattern: Array + Single Pass (Track Current Increasing and Decreasing Run)

## What I understood
Given an array of integers `nums`. Return the length of the longest subarray that is either strictly increasing or strictly decreasing. A subarray is a contiguous part of the array. "Strictly" means equal neighbours are not allowed.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
nums = [1,4,3,3,2]
Output
2
```
Explanation: the strictly increasing subarrays are `[1]`, `[4]`, `[3]`, `[2]` and `[1,4]`. The strictly decreasing subarrays are `[1]`, `[4]`, `[3]`, `[3]`, `[2]`, `[4,3]` and `[3,2]`. The longest have length 2. `[3,3]` is not strictly monotonic.

```
Input
nums = [3,3,3,3]
Output
1
```
Explanation: equal neighbours break every run, so the longest is any single element.

```
Input
nums = [3,2,1]
Output
3
```
Explanation: the whole array is strictly decreasing, so the answer is 3.

## Idea (shared by both approaches)
A strictly increasing run grows while `nums[i] > nums[i - 1]`. A strictly decreasing run grows while `nums[i] < nums[i - 1]`. Any other case (equal neighbours) ends both runs. The answer is the longest run of either kind.

## Approach 1: Brute Force

### Idea
From every start index `i`, extend an increasing run as far as it goes, then extend a decreasing run as far as it goes. Keep the longest length.

### Steps
- `ans = 1`.
- For each start `i`, set `j = i` and move `j` right while `nums[j + 1] > nums[j]`. Update `ans` with `j - i + 1`.
- Set `j = i` again and move `j` right while `nums[j + 1] < nums[j]`. Update `ans` with `j - i + 1`.
- Return `ans`.

### Complexity
Time: **O(n^2)**  
Space: **O(1)**

---

## Approach 2: Single Pass

### Idea
Walk the array once. Keep `inc` = length of the increasing run ending at `i`, and `dec` = length of the decreasing run ending at `i`.

### Steps
- `inc = dec = ans = 1`.
- For `i = 1` to `n - 1`:
  - If `nums[i] > nums[i - 1]`: `inc++`, `dec = 1`.
  - Else if `nums[i] < nums[i - 1]`: `dec++`, `inc = 1`.
  - Else: `inc = 1`, `dec = 1`.
  - `ans = max(ans, inc, dec)`.
- Return `ans`.

### Complexity
Time: **O(n)**  
Space: **O(1)**

---

## Key Observation
At each position the pair of neighbours is either up, down, or equal. Only one of `inc` and `dec` can continue. The other one must restart at length 1. So two counters are enough, and every element is visited once.

## When to use this
If problem involves:
- The longest contiguous run with a rule between neighbours (increasing, decreasing, alternating)
→ Think **one pass with a counter that grows when the rule holds and resets when it breaks**.

## Edge Cases
- One element (answer `1`).
- All elements equal (answer `1`).
- The whole array strictly increasing or strictly decreasing (answer `n`).
- Equal neighbours in the middle (both counters reset).
- A run that changes direction (for example `1,3,2`: the increasing run ends and a decreasing run of length 2 starts at `3`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n^2) | O(1) |
| Single Pass | O(n) | O(1) |

where:
- `n` = length of `nums`

## Related Problems
- Longest Continuous Increasing Subsequence
- Longest Turbulent Subarray
- Longest Mountain in Array
- Maximum Ascending Subarray Sum