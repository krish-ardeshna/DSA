# Majority Element II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/majority-element-ii/  
Difficulty: Medium  
Pattern: Boyer-Moore Voting (Extended to n/3)

## What I understood
Given an array, find all elements that appear more than `⌊n/3⌋` times. At most 2 such elements can exist (since 3 elements each appearing more than n/3 times would exceed total count n). Target O(n) time, O(1) space.

## Example
```
Input
nums = [3,2,3]
Output
[3]
```
```
Input
nums = [1,1,1,3,3,2,2,2]
Output
[1,2]
```

## Idea
Standard Boyer-Moore voting (for n/2 majority) tracks one candidate. Here, since at most 2 elements can exceed n/3, extend the algorithm to track two candidates and two counters simultaneously. Candidates "cancel out" against any third distinct value, same cancellation logic as the classic algorithm, just doubled.

## Approach: Boyer-Moore Voting with Two Candidates
- Phase 1 (find candidates): iterate array, maintain `el1/cnt1` and `el2/cnt2`.
  - If `cnt1 == 0` and current value isn't already `el2`, assign it as new `el1`.
  - Else if `cnt2 == 0` and current value isn't already `el1`, assign it as new `el2`.
  - Else if matches `el1` or `el2`, increment that counter.
  - Else (matches neither, both slots occupied), decrement both counters (cancellation).
- Phase 2 (verify): recount actual occurrences of `el1` and `el2` in full array (candidates from phase 1 aren't guaranteed valid without verification).
- Include candidate in answer only if actual count `> n/3` (i.e. `>= floor(n/3)+1`).
- Sort result before returning.

## Key Observation
Phase 1 alone can produce false positives (e.g. array with no element actually exceeding n/3) — verification phase is mandatory, not optional. The algorithm generalizes cleanly: n/2 majority uses 1 candidate, n/3 uses 2 candidates, n/k would use k-1 candidates.

## When to use this
If problem involves:
- Finding elements exceeding a fractional threshold (n/2, n/3, etc.) of array length
- Need O(n) time, O(1) space (ruling out hashmap counting)
→ Think **Boyer-Moore Voting**, extended with (threshold_denominator - 1) candidate slots.

## Edge Cases
- All elements identical (single majority element, appears in nearly every slot).
- No element actually exceeds n/3 (phase 1 candidates are false positives, verification filters them out).
- Small arrays (`n = 1, 2, 3`).
- Exactly two elements tie for majority.

## Complexity
### Approach
Time: **O(n)** — two linear passes (candidate finding + verification)   
Space: **O(1)** — excluding output array

where:
- `n` = number of elements

## Related Problems
- Majority Element
- Majority Element III (generalized to n/k)
- Check If a String Contains All Binary Codes of Size K
- Find the Duplicate Number