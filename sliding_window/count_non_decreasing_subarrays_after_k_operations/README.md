# Count Non-Decreasing Subarrays After K Operations
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/  
Difficulty: Hard  
Pattern: Prefix Maximum Cost + Two Pointers (Binary Lifting on Next Greater / Monotonic Deque)

## What I understood
(Reconstructed from the accepted code, recheck the exact statement on the LC page.)
Given an integer array `nums` and an integer `k`. For each subarray, you may apply at most `k` operations, where one operation increases any element of that subarray by `1`. Every subarray is judged INDEPENDENTLY (the operations on one subarray do not change the array for another). Return the number of subarrays that can be made non-decreasing.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
nums = [6,3,1,2,4,4], k = 7
Output
17
```
Explanation: count the valid subarrays by their start index. Start 0: `[6]` costs 0, `[6,3]` costs 3, `[6,3,1]` costs 3 + 5 = 8 > 7, so 2 are valid. Start 1: `[3]`, `[3,1]` (2), `[3,1,2]` (3), `[3,1,2,4]` (3), `[3,1,2,4,4]` (3), so 5 are valid. Start 2: `[1]`, `[1,2]`, `[1,2,4]`, `[1,2,4,4]` all cost 0, so 4. Start 3: 3. Start 4: 2. Start 5: 1. Total is 2 + 5 + 4 + 3 + 2 + 1 = 17.

```
Input
nums = [6,3,1,3,6], k = 4
Output
12
```
Explanation: start 0: `[6]` (0), `[6,3]` (3), `[6,3,1]` (8 > 4), so 2. Start 1: `[3]`, `[3,1]` (2), `[3,1,3]` (2), `[3,1,3,6]` (2), so 4. Start 2: `[1]`, `[1,3]`, `[1,3,6]`, so 3. Start 3: 2. Start 4: 1. Total is 2 + 4 + 3 + 2 + 1 = 12.

## Idea (shared by all approaches)
**Cost of one subarray.** To make a subarray non-decreasing with `+1` operations, scan left to right and raise each element up to the largest value seen so far (its PREFIX MAXIMUM, starting at the left end of the subarray). Raising is forced, and raising more than that is never useful. So:
```
cost(l, r) = sum over i in [l, r] of ( max(nums[l..i]) - nums[i] )
```
A subarray is valid when `cost(l, r) <= k`.

**Monotonic cost.** `cost(l, r)` never decreases when `r` grows (a new element adds `prefixMax - nums[r] >= 0`). It never increases when `l` grows (removing the left element can only lower the prefix maxima). So for each `l` the valid `r` values form one range `[l, R(l)]`, and `R(l)` never decreases when `l` grows. That allows two pointers.

**Answer:** the sum of `R(l) - l + 1` over all `l`.

## Approach 1: Brute Force

### Idea
For every start `l`, extend `r` one element at a time. Keep the running prefix maximum and the cost. Stop at the first `r` where the cost is more than `k`.

### Steps
- `ans = 0`.
- For each `l`: `mx = 0`, `cost = 0`.
- For `r = l` to `n - 1`: `mx = max(mx, nums[r])`, `cost += mx - nums[r]`.
- If `cost > k`, break. Otherwise `ans++`.
- Return `ans`.

### Complexity
Time: **O(n^2)**  
Space: **O(1)**

Too slow for `n = 10^5`.

---

## Approach 2: Two Pointers + Binary Lifting on Next Greater Element

### Idea
Use two pointers `left` and `right`. The only hard part is computing `cost(left, right)` fast, which means the sum of prefix maxima over `[left, right]`.

The prefix maxima starting at `l` follow a chain: from `i`, the maximum stays `nums[i]` until the next STRICTLY greater element `nxt[i]`. So the segment `[i, nxt[i])` contributes `nums[i] * (nxt[i] - i)`. Then the chain continues from `nxt[i]`.

Binary lifting makes the chain walk fast: `up[j][i]` = the position after `2^j` jumps, and `sum[j][i]` = total contribution of those jumps.

### Steps
- Build `nxt[i]` with a monotonic stack (next strictly greater element, `n` if none).
- Build `up[0][i] = nxt[i]` and `sum[0][i] = nums[i] * (nxt[i] - i)`. Build the higher levels from lower ones. Position `n` points to itself with sum `0`.
- Build the prefix sum array `pref`.
- `getCost(l, r)`: start at `pos = l`. For `j` from high to low, if `up[j][pos] <= r + 1`, add `sum[j][pos]` and move to it. If `pos <= r` at the end, add `nums[pos] * (r - pos + 1)` for the last partial segment. Return `total - (pref[r + 1] - pref[l])`.
- For each `right` from `0` to `n - 1`: while `getCost(left, right) > k`, do `left++`. Then `ans += right - left + 1`.
- Return `ans`.

### Complexity
Time: **O(n log n)**  
Space: **O(n log n)**

---

## Approach 3: Two Pointers + Monotonic Deque

### Idea
Sweep `l` from RIGHT to LEFT. The prefix-maximum chain of the window `[l, r]` is a stack-like list: adding `nums[l]` at the front absorbs the nearby elements that are smaller or equal. Moving `r` left removes elements from the back. So a deque holds the chain, with the front changing when `l` moves and the back changing when `r` moves. Because `R(l)` only moves left as `l` moves left, `r` only moves left, and every element enters and leaves once.

Each deque entry is `(value, length)`: this value is the prefix maximum for `length` positions of the window. `cur` = the sum of `value * length`.

### Steps
- Build `pref`. Set `r = n - 1`, `cur = 0`, empty deque.
- For `l` from `n - 1` down to `0`:
  - `len = 1`. While the front value is `<= nums[l]`: add its length to `len`, subtract `value * length` from `cur`, pop it.
  - Push `(nums[l], len)` at the front, and add `nums[l] * len` to `cur`.
  - While `cur - (pref[r + 1] - pref[l]) > k`: subtract the back value from `cur`, reduce the back length by 1 (pop if `0`), and do `r--`.
  - `ans += r - l + 1`.
- Return `ans`.

### Complexity
Time: **O(n)**  
Space: **O(n)**

---

## Key Observation
The cost formula `sum(prefixMax - element)` and the two-pointer monotonicity do most of the work. What is left is "sum of prefix maxima of a window". Approach 2 answers it by jumping along the next-greater chain with binary lifting, one query at a time. Approach 3 notices that the chain of the window is exactly a monotonic stack, so it updates the sum incrementally and each element is touched a constant number of times.

The cost can be as large as about `10^5 * 10^9 = 10^14`. Use `long long` for every sum. The answer can reach about `5 * 10^9` (when every subarray is valid), so it is also `long long`.

## When to use this
If problem involves:
- Counting subarrays whose "cost" only grows when the subarray grows
- A cost made of prefix maxima (or minima), which the next greater element chain describes
→ Think **two pointers**, and a **monotonic stack / deque (or binary lifting on next greater)** to get the window cost quickly.

## Edge Cases
- `k = 0` (only already non-decreasing subarrays count).
- Array already non-decreasing (every subarray costs 0, answer is `n * (n + 1) / 2`).
- Strictly decreasing array (the cost grows fastest).
- Equal values (the absorption uses `<=` in the deque, and `nxt` is STRICTLY greater in lifting, both give the same cost).
- `n = 1` (answer `1`).
- Large values (use `long long` everywhere).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n^2) | O(1) |
| Two Pointers + Binary Lifting | O(n log n) | O(n log n) |
| Two Pointers + Monotonic Deque | O(n) | O(n) |

where:
- `n` = length of `nums`

## Related Problems
- Non-decreasing Array
- Daily Temperatures
- Sliding Window Maximum
- Count Subarrays With Score Less Than K