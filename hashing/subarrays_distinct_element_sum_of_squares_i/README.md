# Subarrays Distinct Element Sum of Squares I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/  
Difficulty: Easy  
Pattern: Brute Force + Hash Set (Enumerate All Subarrays)

## What I understood
For every contiguous subarray of `nums`, count how many DISTINCT values it contains, then square that count. Return the sum of these squares over all subarrays.

## Example
```
Input
nums = [1,2,1]
Output
15
```
Explanation: the six subarrays are [1], [2], [1], [1,2], [2,1], [1,2,1] with distinct counts 1, 1, 1, 2, 2, 2. Squares: 1 + 1 + 1 + 4 + 4 + 4 = 15.

```
Input
nums = [1,1]
Output
3
```
Explanation: subarrays [1], [1], [1,1] each have 1 distinct value, so 1 + 1 + 1 = 3.

## Idea
The constraints are small (`n <= 100`), so checking every subarray is fast enough. Fix the starting index `i`, then grow the subarray one element at a time by moving the end index `j`. A set that keeps all values seen since `i` always tells the distinct count of the current subarray, and it only needs one insert per step, so no recounting is required.

## Approach: Fix Start, Extend End, Track Distinct Count With a Set
- For each start index `i`, create an empty `unordered_set`.
- For each end index `j` from `i` to `n - 1`:
  - Insert `nums[j]` into the set (duplicates are ignored automatically).
  - `distinct = st.size()`.
  - Add `distinct * distinct` to `ans`.
- Return `ans`.

## Key Observation
Extending a subarray by one element can only increase the distinct count by 0 or 1, and the set handles that for free. Resetting the set for every new start `i` is what keeps subarrays from leaking values into each other. The answer fits in `int` for `n <= 100` (at most about 5050 subarrays, each contributing at most 10^4).

## When to use this
If problem involves:
- A per-subarray property (distinct count, max, sum) over small input sizes
→ Think **two nested loops, with one running structure updated as the end index grows**. For large `n`, this needs a smarter counting-by-contribution approach instead.

## Edge Cases
- Single element array (one subarray, answer 1).
- All elements equal (every subarray has 1 distinct value, answer is the number of subarrays).
- All elements distinct (distinct count equals the subarray length).
- Repeated values far apart (the set remembers them while the subarray spans both).

## Complexity
### Approach
Time: **O(n^2)**, about `n * (n + 1) / 2` subarrays with O(1) average set work each         
Space: **O(n)** for the set

where:
- `n` = number of elements

## Related Problems
- Subarrays Distinct Element Sum of Squares II
- Count Distinct Numbers on Board
- Subarrays with K Different Integers
- Longest Substring Without Repeating Characters