# Longest Subsequence With Non-Zero Bitwise XOR
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/  
Difficulty: Medium  
Pattern: Bit Manipulation (XOR Properties)

## What I understood
Find the length of the longest subsequence of `nums` whose elements XOR together to a non-zero value. Subsequence doesn't need to be contiguous.

## Example
```
Input
nums = [1,2,3]
Output
3
```
```
Input
nums = [0,0]
Output
0
```

## Idea
Only 3 cases matter, decided by two simple checks: total XOR of the whole array, and whether any non-zero element exists at all.
- If XOR of entire array is already non-zero → taking all `n` elements works, answer is `n`.
- If total XOR is 0 but at least one non-zero element exists → drop that one non-zero element from the subsequence, remaining `n-1` elements now XOR to that non-zero value (removing a value that was part of a 0-XOR total flips the running result to non-zero).
- If every element is 0 (total XOR is 0 and no non-zero element exists) → no subsequence can ever have non-zero XOR, answer is `0`.

## Approach: Total XOR Check + Non-Zero Element Check
- Single pass: compute `xorr` (XOR of all elements) and track `hasNonZero` flag.
- If `xorr != 0` → return `n`.
- Else if `hasNonZero` → return `n - 1`.
- Else → return `0`.

## Key Observation
Zero elements are "free" to include or exclude — they never affect XOR result (`x ^ 0 = x`). This means the actual decision only revolves around whether a non-zero XOR is achievable at all, reducing the problem to simple case analysis instead of any real subsequence search or DP.

## When to use this
If problem involves:
- Subsequence property based on XOR (or similar self-inverse operation)
- Result depends only on aggregate property (total XOR), not on which specific elements are chosen
→ Think **whole-array property check + small case analysis**, avoid brute-force subsequence enumeration.

## Edge Cases
- All zeros → answer `0`.
- Single element, non-zero → answer `1`.
- Single element, zero → answer `0`.
- Total XOR already non-zero with mix of zeros and non-zeros → answer still `n` (zeros included freely).

## Complexity
### Approach
Time: **O(n)** — single pass    
Space: **O(1)**

where:
- `n` = number of elements

## Related Problems
- Single Number
- Maximum XOR of Two Numbers in an Array
- Minimum XOR Sum of Two Arrays
- Find the Original Array of Prefix XOR