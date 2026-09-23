# Length of Longest Subarray With at Most K Frequency
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/  
Difficulty: Medium  
Pattern: Sliding Window + Hashmap

## What I understood
Find length of the longest subarray such that no element in it appears more than `k` times. Subarray must be contiguous.

## Example
```
Input
nums = [1,2,3,1,2,3,1,2], k = 2
Output
6
```
```
Input
nums = [1,2,1,2,1,2,1,2], k = 1
Output
2
```

## Idea
Classic variable-size sliding window: expand `right` freely, track frequency of each element in the current window. The moment the newly added element's frequency exceeds `k`, shrink from `left` until that specific element's frequency drops back to `k`. Since only the just-added element can be the violator, no need to check the whole map.

## Approach: Variable-Size Sliding Window with Frequency Map
- Expand window by incrementing `freq[nums[right]]` each step.
- If `freq[nums[right]] > k`, shrink from `left`, decrementing frequencies, until `freq[nums[right]] <= k` again.
- After shrink (if any), update `ans = max(ans, right - left + 1)`.

## Key Observation
Only the element just added at `right` can possibly violate the constraint at each step - every other element in the window was already valid before this step, so the `while` condition only needs to check `freq[nums[right]]`, not scan the entire frequency map.

## When to use this
If problem involves:
- Longest/shortest contiguous subarray under a frequency or count constraint
- Constraint only changes due to the newly added/removed element
→ Think **variable-size sliding window + hashmap frequency tracking**.

## Edge Cases
- `k` equal to array length (whole array is valid, answer = n).
- All elements identical with `k = 1` (answer = 1).
- Single element array.
- `k` larger than any possible frequency (whole array valid).

## Complexity
### Approach
Time: **O(n)** - each element added and removed from window at most once        
Space: **O(n)** - hashmap storage in worst case (all distinct elements)

where:
- `n` = number of elements

## Related Problems
- Longest Substring Without Repeating Characters
- Subarrays with K Different Integers
- Max Consecutive Ones III
- Fruit Into Baskets