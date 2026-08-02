# Count Subarrays With Even Odd Ratio I

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/  
Difficulty: Medium  
Pattern: Brute Force, Counting

## What I understood

Given an array and two integers `a` and `b`, count the number of subarrays where the ratio between the number of even and odd elements satisfies the required condition.

## Example

```
Input
nums = [1,2,3,4], a = 1, b = 1

Output
6
```

## Idea

For every possible starting index, expand the subarray one element at a time while maintaining the number of even and odd elements.

Whenever the required ratio condition is satisfied, increment the answer.

## Approach: Brute Force

- Fix every possible starting index.
- Extend the ending index one step at a time.
- Maintain counts of even and odd elements.
- Check the ratio condition:
  - `even × b ≤ odd × a`
- Count every valid subarray.

## Key Observation

The parity counts can be updated in constant time while extending a subarray.

Using cross multiplication:

```
even × b ≤ odd × a
```

avoids floating-point precision issues.

## When to use this

If the problem involves:

- Enumerating all subarrays
- Maintaining running counts
- Ratio comparisons
- Prefix-style counting

→ Think **Brute Force with Incremental Counting**.

## Edge Cases

- Array with only even numbers.
- Array with only odd numbers.
- Single-element array.
- No valid subarrays.
- Large values of `a` and `b`.

## Complexity

### Approach

Time: **O(n²)**

Space: **O(1)**

where:

- `n` = number of elements

## Related Problems

- Count Number of Nice Subarrays
- Binary Subarrays With Sum
- Subarray Sum Equals K