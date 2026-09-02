# Construct Uniform Parity Array I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/construct-uniform-parity-array-i/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Math - Parity Argument

## What I understood
For each element in `nums1`, a choice can be made: keep the element as-is, or replace it with the difference between it and some other element (`nums1[i] - nums1[j]`). Determine if it's possible to make every resulting element share the same parity (all odd or all even).

## Example
```
Input
nums1 = [2,3]
Output
true
```
```
Input
nums1 = [2,4,6]
Output
true
```

## Idea
Two cases fully cover every possible input, and both always succeed:
- If at least one odd number exists in the array, every even number can be converted to odd by subtracting that odd number (`even - odd = odd`), while existing odd numbers are simply kept as-is. Result: entire array becomes odd.
- If no odd numbers exist, every element is already even, so no changes are needed — entire array is already uniformly even.

Since both scenarios are always achievable, the answer is unconditionally `true` for any valid input.

## Approach: Always Achievable via Parity Manipulation
- No computation needed — the parity argument proves both possible starting states (has odd numbers / all even) can always reach a uniform-parity result.
- Return `true` unconditionally.

## Key Observation
The subtraction operation's parity behavior (`even - odd = odd`, `odd - odd = even`, `even - even = even`, `odd - even = odd`) means an odd number in the array acts as a universal "converter" — any even number can absorb its oddness via subtraction, so the presence of even just one odd number guarantees full odd-uniformity is achievable.

## When to use this
If problem involves:
- Determining feasibility of a transformation based on parity properties
- The transformation's effect on parity follows simple, fixed rules (like subtraction parity table)
→ Think **case-split on presence/absence of a specific parity type, verify both cases are always achievable**, avoiding unnecessary simulation.

## Edge Cases
- Array of all even numbers (already uniform, no changes needed).
- Array of all odd numbers (already uniform).
- Mixed array with both parities (odd number(s) convert the evens).
- Single element array (trivially uniform).

## Complexity
### Approach
Time: **O(1)**          
Space: **O(1)**

where:
- No iteration or computation needed since the answer is provably always true

## Related Problems
- Construct Uniform Parity Array II
- Sum of All Odd Length Subarrays
- Minimum Number of Operations to Make Array XOR Equal to K
- Divide Array Into Equal Pairs