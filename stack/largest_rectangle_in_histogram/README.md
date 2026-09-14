# Largest Rectangle in Histogram
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/  
Difficulty: Hard  
Pattern: Monotonic Stack

## What I understood
Given an array of bar heights forming a histogram, find the area of the largest rectangle that can be formed within the histogram's outline (rectangle width spans contiguous bars, height limited by the shortest bar in that span).

## Example
```
Input
heights = [2,1,5,6,2,3]
Output
10
```
```
Input
heights = [2,4]
Output
4
```

---

## Approach 1: Single Pass with Post-Loop Cleanup

### Idea
Maintain a monotonic increasing stack of indices. When a shorter bar is encountered, it means every taller bar still in the stack has found its "right boundary" (the current shorter bar) — pop and compute area for each, using the new stack top (if any) as the left boundary. After the main loop, any remaining stack elements never found a right boundary within the array, so their right boundary defaults to `n` (end of array).

### Steps
- Iterate `i` from 0 to n-1: while stack top's height `>` current height, pop and calculate area using `nse = i` (current index as right boundary) and `pse = stack top after pop` (or -1 if empty).
- Push current index.
- After main loop, process remaining stack elements with `nse = n` (they extend to the array's end).

### Complexity
Time: **O(n)**          
Space: **O(n)** — stack storage

---

## Approach 2: Separate PSE/NSE Arrays

### Idea
Precompute Previous Smaller Element (PSE) and Next Smaller Element (NSE) index arrays independently and completely before any area calculation — each bar's maximum possible width is bounded by these two values. Then, a simple final pass computes each bar's contribution.

### Steps
- `findPSE`: for each index, find nearest index to the left with a strictly smaller height (using `>=` in pop condition to handle duplicates via left-tie-breaking).
- `findNSE`: for each index, find nearest index to the right with a smaller-or-equal height (symmetric handling).
- Final pass: for each index `i`, `width = nse[i] - pse[i] - 1`, area = `height[i] * width`, track max.

### Complexity
Time: **O(n)**      
Space: **O(n)** — two auxiliary arrays plus stack

---

## Key Observation
Both approaches rely on the same core idea (each bar's max rectangle width is bounded by nearest smaller bars on both sides) — Approach 1 computes this inline during a single pass with cleanup, while Approach 2 separates the boundary-finding into standalone reusable functions first, then does area computation in a clean final pass.

## When to use this
If problem involves:
- Finding maximal area/span bounded by "nearest smaller element" on both sides
→ Think **monotonic stack for previous/next smaller element**, either combined single-pass with post-loop cleanup, or separate precomputed PSE/NSE arrays for clarity.

## Edge Cases
- Strictly increasing histogram (largest rectangle likely uses full height at some point, or is bounded late).
- Strictly decreasing histogram.
- All bars same height (rectangle = full width × that height).
- Single bar (area = that single height).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Single Pass Cleanup | O(n) | O(n) |
| Separate PSE/NSE | O(n) | O(n) |

where:
- `n` = number of bars

## Related Problems
- Maximal Rectangle
- Trapping Rain Water
- Sum of Subarray Minimums
- Sum of Subarray Ranges