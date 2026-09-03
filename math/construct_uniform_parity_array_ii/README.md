# Construct Uniform Parity Array II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Math - Parity + Threshold Check

## What I understood
Extension of Construct Uniform Parity Array I, but with an added constraint — likely that subtraction (`nums1[i] - nums1[j]`) must yield a non-negative result (or some similar restriction), meaning an even number can only be converted to odd using an odd number that's smaller than or equal to it. If any even number is smaller than the smallest available odd number, that even number can't be converted (no valid odd subtractor exists for it), making full uniformity impossible.

## Example
```
Input
nums1 = [2,3,4]
Output
true
```
```
Input
nums1 = [1,4]
Output
false
```

## Idea
Unlike version I (where any odd number could universally convert any even number regardless of magnitude), this version restricts valid conversions to only use an odd number `<= ` the even number being converted (likely tied to a non-negative-result constraint on the subtraction). So, find the smallest odd number in the array; if any even number is smaller than this smallest odd number, it has no valid odd subtractor available, and full odd-uniformity fails.

## Approach: Find Min Odd, Check No Even is Smaller
- Scan array, find `minOdd` (smallest odd value present).
- If no odd number exists at all → array is already uniform (all even), return `true`.
- Otherwise, scan again: if any even number is smaller than `minOdd`, that number can never be converted (no odd number available to subtract without violating whatever underlying constraint applies) → return `false`.
- If all even numbers are `>= minOdd` → every even number has at least one valid odd subtractor, uniformity achievable → return `true`.

## Key Observation
The key difference from Version I is that magnitude now matters for conversion validity — this suggests the underlying operation constraint (likely `nums1[i] - nums1[j] >= 0` or similar) limits which odd numbers can serve as valid subtractors for a given even number, unlike the unconstrained version where any odd number would work regardless of size.

## When to use this
If problem involves:
- Feasibility checks with an added magnitude/ordering constraint on an otherwise parity-based transformation
→ Think **find the critical threshold value (like minOdd here), then verify no element violates the threshold requirement**.

## Edge Cases
- No odd numbers at all (trivially uniform, already all even).
- Smallest odd number is smaller than all even numbers (all conversions valid).
- An even number smaller than the smallest odd number exists (fails).
- Single element array.

## Complexity
### Approach
Time: **O(n)** — two linear passes      
Space: **O(1)**

where:
- `n` = number of elements

## Related Problems
- Construct Uniform Parity Array I
- Sum of All Odd Length Subarrays
- Minimum Number of Operations to Make Array XOR Equal to K
- Divide Array Into Equal Pairs