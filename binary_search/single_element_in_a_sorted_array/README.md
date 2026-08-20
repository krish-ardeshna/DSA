# Single Element in a Sorted Array
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/  
Difficulty: Medium  
Pattern: Binary Search (Index Parity Check)

## What I understood
Sorted array where every element appears exactly twice, except one element which appears exactly once. Find that single element in O(log n) time, O(1) space.

## Example
```
Input
nums = [1,1,2,3,3,4,4,8,8]
Output
2
```
```
Input
nums = [3,3,7,7,10,11,11]
Output
10
```

## Idea
Before the single element, every pair `(x, x)` occupies indices `(even, odd)` — i.e. first occurrence at an even index, second at the next odd index. After the single element, this pairing shifts to `(odd, even)`. Binary search exploits this: at any `mid`, check if the pairing pattern still holds (single element is to the right) or has shifted (single element is at or before `mid`).

## Approach: Binary Search Using Even/Odd Index Pairing
- Handle trivial edge cases first: single-element array, or single element at very start/end (check first two / last two elements directly).
- Binary search between `low = 1` and `high = n-2` (edges already handled).
- At `mid`: if `nums[mid]` differs from both neighbors → found the single element, return it.
- Determine if pairing is still "intact" at `mid`: if `mid` is odd and matches `mid-1`, or `mid` is even and matches `mid+1` → pattern holds, single element is after `mid`, move `low = mid+1`.
- Otherwise, pattern has already shifted → single element is at or before `mid`, move `high = mid-1`.

## Key Observation
The index-parity shift (even-odd pairing before the single element, odd-even after) is the core insight — reduces what looks like a linear scan problem into a true binary search by checking pairing "phase" at each midpoint instead of comparing values directly against a target.

## When to use this
If problem involves:
- Sorted array where a structural pattern (like pairing) breaks at exactly one point
- Need O(log n) search exploiting that structural break
→ Think **binary search on index parity/pattern shift**, not value comparison.

## Edge Cases
- Single element array (`n == 1`).
- Single element at the very start or very end (handled via direct edge checks before binary search).
- Single element in the middle.
- Large array with single element near boundaries of the search range.

## Complexity
### Approach
Time: **O(log n)**          
Space: **O(1)**

where:
- `n` = number of elements

## Related Problems
- Single Number
- Single Number II
- Single Number III
- Find Minimum in Rotated Sorted Array