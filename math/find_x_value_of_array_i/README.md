# Find X Value of Array I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-x-value-of-array-i/  
Difficulty: Medium  
Pattern: DP (Running Product Modulo Distribution)

## What I understood
For each remainder value `x` from 0 to `k-1`, count how many contiguous subarrays of `nums` have a product that, when taken modulo `k`, equals `x`. Return this count as an array of size `k`.

## Example
```
Input
nums = [1,2,3,4,5], k = 3
Output
(counts of subarrays whose product mod k equals 0, 1, 2 respectively)
```

## Idea
Instead of enumerating every subarray explicitly (O(n²) subarrays, each requiring product computation), maintain a running DP state: `dp[r]` = count of subarrays ENDING AT THE CURRENT POSITION whose product mod k equals `r`. When a new element arrives, every existing "ending here" subarray gets extended by one element, shifting its remainder via multiplication; additionally, the new element alone starts a fresh subarray of length 1.

## Approach: Track Count of Subarray Products by Remainder, Roll Forward
- Maintain `dp[k]` = count of subarrays ending at the PREVIOUS position, grouped by their product's remainder.
- For each new `num`: compute `rem = num % k`.
- Start `newdp[rem]++` (the new single-element subarray consisting of just `num`).
- For every existing remainder `r` with `dp[r] > 0`: extending those subarrays by multiplying in `num` shifts their remainder to `(r * rem) % k` — add `dp[r]` to `newdp[newRem]`.
- Add all of `newdp` into the global `ans` array (since every subarray ending at this position is now counted).
- Roll `dp = newdp` for the next iteration.

## Key Observation
This is essentially a "prefix product modulo bucket" DP — similar in spirit to prefix-sum-based subarray counting problems, but using multiplication and modular arithmetic instead of addition. Maintaining ONLY the "ending here" counts (not all historical subarrays explicitly) keeps each step O(k) instead of needing to recompute or store all O(n²) subarray products.

## When to use this
If problem involves:
- Counting subarrays/subsequences by some accumulated value (product, sum, XOR) modulo a fixed small number k
→ Think **DP tracking counts bucketed by remainder, rolling forward per element**, extending existing "ending here" states rather than recomputing from scratch.

## Edge Cases
- `k = 1` (every product mod 1 is 0, all subarrays fall into bucket 0).
- Single element array.
- Elements that are multiples of `k` (remainder 0, potentially "absorbing" many subsequent remainders to 0 once multiplied in).
- Large array requiring efficient O(n*k) rather than O(n²) or worse.

## Complexity
### Approach
Time: **O(n * k)** — each element processed with O(k) work to update the dp/newdp arrays            
Space: **O(k)** — dp and newdp arrays

where:
- `n` = number of elements in nums
- `k` = the modulus

## Related Problems
- Find X Value of Array II
- Subarray Product Less Than K
- Continuous Subarray Sum
- Count Subarrays With Fixed Bounds