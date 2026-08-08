# Max Consecutive Ones
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/max-consecutive-ones/  
Difficulty: Easy  
Pattern: Array - Linear Scan (Running Counter)

## What I understood
Binary array (only 0s and 1s). Find the length of the longest run of consecutive 1s.

## Example
```
Input
nums = [1,1,0,1,1,1]
Output
3
```
```
Input
nums = [1,0,1,1,0,1]
Output
2
```

## Idea
Single pass suffices — track a running counter that grows on `1`, resets on `0`. Update global max whenever running counter exceeds it. No need to store actual runs, just track lengths on the fly.

## Approach: Single Pass Counter Reset
- Init `cnt = 0`, `maxConsecutive = 0`.
- Iterate array: if `num == 1`, increment `cnt`, update `maxConsecutive = max(maxConsecutive, cnt)`.
- If `num == 0`, reset `cnt = 0`.
- Return `maxConsecutive` after full pass.

## Key Observation
Max update happens inside the `1` branch itself — no need for a separate post-loop comparison, since reset on `0` naturally caps any stale count from carrying over incorrectly.

## When to use this
If problem involves:
- Finding longest run/streak of a repeated condition in an array
- Single pass, O(1) space suffices
→ Think **running counter + reset-on-break pattern**.

## Edge Cases
- All zeros → answer `0`.
- All ones → answer equals array length.
- Single element array.
- Alternating 0s and 1s → answer `1`.

## Complexity
### Approach
Time: **O(n)**
Space: **O(1)**

where:
- `n` = number of elements in array

## Related Problems
- Max Consecutive Ones II
- Max Consecutive Ones III
- Longest Subarray of 1's After Deleting One Element
- Binary Subarrays With Sum