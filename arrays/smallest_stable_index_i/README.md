# Smallest Stable Index I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/smallest-stable-index-i/  
Difficulty: Easy 
Pattern: Array - Prefix Max + Suffix Min / Brute Force

## What I understood
For each index `i`, an "instability score" is defined as `max(nums[0..i]) - min(nums[i..n-1])` — max of the prefix up to and including `i`, minus min of the suffix starting from `i`. Find the smallest index `i` where this score is `<= k`. Return -1 if no such index exists.

## Example
```
Input
nums = [5,2,8,1,9], k = 3
Output
(smallest index where prefix-max minus suffix-min is <= k)
```

## Idea
The prefix-max at index `i` only grows or stays the same as `i` increases (monotonic), and can be tracked incrementally in a single forward pass. The suffix-min at index `i` requires knowing all elements from `i` to the end — precomputing this once from right to left avoids repeated re-scanning, turning an otherwise O(n²) brute-force check into O(n) overall.

## Approach 1: Precomputed Suffix Min + Running Prefix Max

### Idea
Precompute `suffixMin[i]` for every index once (right to left), then do a single forward pass tracking `prefixMax` incrementally, checking the stability condition at each index using the precomputed suffix values.

### Steps
- Build `suffixMin` array: `suffixMin[n-1] = nums[n-1]`, then `suffixMin[i] = min(nums[i], suffixMin[i+1])` going backward.
- Forward pass: maintain running `prefixMax`, updating it with `nums[i]` at each step.
- Check `prefixMax - suffixMin[i] <= k`; return `i` on first match.
- Return -1 if no index satisfies the condition.

### Complexity
Time: **O(n)**
Space: **O(n)** — suffix min array

---

## Approach 2: Brute Force (max_element / min_element per index)

### Idea
Directly compute prefix max and suffix min at each index independently using STL's `max_element`/`min_element` — simpler to write but redundantly rescans overlapping ranges for every index.

### Steps
- For each index `i`: compute `maxi = max(nums[0..i])` and `mini = min(nums[i..n-1])` via STL calls.
- Check `maxi - mini <= k`; return `i` on first match.
- Return -1 if no index satisfies the condition.

### Complexity
Time: **O(n²)** — each index triggers an O(n) scan via max_element/min_element
Space: **O(1)** extra

---

## Key Observation
Precomputing suffix min once (Approach 1) exploits the fact that suffix ranges shrink as `i` increases and can be built incrementally from the back — same principle applies to prefix max building incrementally from the front. Brute force (Approach 2) ignores this reusability, redoing full range scans at every index.

## When to use this
If problem involves:
- Per-index conditions depending on prefix and/or suffix aggregate values (max, min, sum)
→ Think **precompute prefix/suffix arrays once**, avoid brute-force per-index STL range calls when n is large.

## Edge Cases
- Single element array (prefix max = suffix min = that element, score = 0).
- Strictly increasing array (prefix max grows, suffix min shrinks slowly).
- Strictly decreasing array.
- No index ever satisfies the condition → return -1.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Prefix Max + Suffix Min | O(n) | O(n) |
| Brute Force | O(n²) | O(1) |

where:
- `n` = number of elements

## Related Problems
- Smallest Stable Index II
- Maximum Difference Between Increasing Elements
- Find the Distance Value Between Two Arrays
- Minimum Cost to Reach Destination in Time