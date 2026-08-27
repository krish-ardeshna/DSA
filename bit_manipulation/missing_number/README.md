# Missing Number
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/missing-number/  
Difficulty: Easy  
Pattern: Bit Manipulation (XOR)

## What I understood
Given array containing `n` distinct numbers from range `[0, n]`, exactly one number in that range is missing. Find it.

## Example
```
Input
nums = [3,0,1]
Output
2
```
```
Input
nums = [9,6,4,2,3,5,7,0,1]
Output
8
```

## Idea
If every index `0..n-1` and every value in `nums` were paired up perfectly with the full range `0..n`, XOR-ing all of them together would cancel every matched pair (`a ^ a = 0`), leaving only the one unmatched number — the missing one. Start with `ans = n` (accounts for the one extra number in the range `[0,n]` not covered by indices `0..n-1`), then XOR in every index and every array value.

## Approach: XOR All Indices, Values, and n Together
- Init `ans = n`.
- For each index `i` from 0 to n-1: XOR in both `i` and `nums[i]`.
- Every number that appears in both the expected range and the actual array cancels out via XOR.
- Only the missing number (present in expected range but not in array) survives, since it never gets cancelled.
- Return `ans`.

## Key Observation
This is a direct extension of the "Single Number" XOR trick — instead of finding a single unpaired value among duplicates, here the "duplicate" comes from artificially pairing each array value with an index, engineering the same self-cancelling structure.

## When to use this
If problem involves:
- Finding a single missing/extra value from a complete or near-complete numeric range
- O(1) space requirement, avoiding sum-formula overflow risk for very large n
→ Think **XOR indices against values**, same cancellation principle as Single Number.

## Edge Cases
- Missing number is 0.
- Missing number is n (the largest possible value in range).
- Single element array (`n=1`).
- Large n where sum-based approach might risk overflow (XOR approach avoids this entirely).

## Complexity
### Approach
Time: **O(n)**      
Space: **O(1)**

where:
- `n` = size of the array (range is 0 to n)

## Related Problems
- Single Number
- Find the Duplicate Number
- Find All Numbers Disappeared in an Array
- First Missing Positive