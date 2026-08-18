# Find the Largest Almost Missing Integer
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/  
Difficulty: Easy  
Pattern: Array - Sliding Window + Presence Counting

## What I understood
An integer is "almost missing" if it appears in exactly one window of size `k` (out of all possible contiguous windows). Find the largest such integer. Values are bounded (0-50 per constraint), which allows a fixed-size counting array instead of a hashmap.

## Example
```
Input
nums = [3,3,2,1,3], k = 2
Output
2
```
```
Input
nums = [1,1], k = 1
Output
-1
```

## Idea
For every possible window of size `k`, mark which values are present (not how many times, just presence). Accumulate a global count: how many windows contain each value at least once. A value is "almost missing" if it's present in exactly one window total. Return the largest such value.

## Approach: Brute Force Windows + Bounded Value Presence Count
- For each window start `i` (0 to `n-k`): build a `present[51]` boolean array marking which values (0-50) appear anywhere in that window.
- For each value `x` present in the window, increment global `count[x]`.
- After processing all windows, scan values from 50 down to 0; return the first `x` where `count[x] == 1`.
- Return -1 if no such value exists.

## Key Observation
Using presence (boolean) rather than frequency within each window is essential — a value appearing multiple times inside one window should still only count once toward that window's contribution to `count[x]`. Bounded value range (0-50) makes a fixed array viable instead of a hashmap, keeping per-window work O(k + 51) rather than needing dynamic structures.

## When to use this
If problem involves:
- Small bounded value range (values known to fit in a small fixed range)
- Sliding window presence (not frequency) tracking across all windows
→ Think **fixed-size presence array per window + global occurrence counting**.

## Edge Cases
- `k == n` (single window only, every present value has count exactly 1).
- `k == 1` (each window is a single element, count[x] = number of times x appears as its own window).
- All elements identical (count[x] = number of windows, likely > 1, never "almost missing" unless only 1 window exists).
- No integer is almost missing → returns -1.

## Complexity
### Approach
Time: **O(n * k)** roughly (n-k+1 windows, O(k) to scan each + O(51) to accumulate) — since 51 is constant, effectively O(n*k)      
Space: **O(1)** — fixed 51-size arrays regardless of input size

where:
- `n` = number of elements
- `k` = window size

## Related Problems
- Length of Longest Subarray With at Most K Frequency
- Maximum Length Substring With Two Occurrences
- Sliding Window Maximum
- Find All Numbers Disappeared in an Array