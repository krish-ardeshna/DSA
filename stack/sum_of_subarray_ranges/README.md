# Sum of Subarray Ranges
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sum-of-subarray-ranges/  
Difficulty: Medium  
Pattern: Monotonic Stack (Max Sum - Min Sum Contribution)

## What I understood
For each contiguous subarray, its "range" = `max(subarray) - min(subarray)`. Sum this range across ALL possible subarrays. Since `sum(max - min) = sum(max) - sum(min)`, this reduces to computing "sum of subarray maximums" minus "sum of subarray minimums" independently.

## Example
```
Input
nums = [1,2,3]
Output
4
```
```
Input
nums = [1,3,3]
Output
4
```

---

## Approach 1: Single-Pass Combined Max-Min via Sentinel Boundary

### Idea
Instead of running fully separate passes for max-sum and min-sum, use a single monotonic stack pass with an extended index range `0` to `n` (using `n` as a sentinel "flush" index to force-pop all remaining stack elements at the end), computing max-contribution in one loop and subtracting min-contribution in a second loop — same stack logic pattern, opposite comparison directions.

### Steps
- First loop (max contribution): iterate `i` from 0 to `n` (inclusive), pop stack while current element is `>=` top (using `<=` comparison for popping), computing `left * right * value` contribution for popped elements, add to `ans`.
- Reset stack.
- Second loop (min contribution): same structure but pop condition reversed (`>=`), subtract contribution from `ans`.
- The sentinel index `n` at the end of each loop forces any remaining stack elements to be resolved (their "right boundary" extends to the array's end).

### Complexity
Time: **O(n)**                  
Space: **O(n)** — stack storage

---

## Approach 2: Separate Max Sum and Min Sum via NGE/PGE and NSE/PSE

### Idea
Explicitly split into two independent sub-problems: "sum of subarray maximums" (using Next Greater Element and Previous Greater Element) and "sum of subarray minimums" (using Next Smaller Element and Previous Smaller Element, same technique as the standalone "Sum of Subarray Minimums" problem). Compute both fully, then subtract.

### Steps
- `sumSubarrayMaxs`: build NGE/PGE arrays via monotonic stack, contribution = `left * right * value` per element, summed.
- `sumSubarrayMins`: build NSE/PSE arrays via monotonic stack, same contribution formula.
- Final answer: `sumSubarrayMaxs - sumSubarrayMins`.

### Complexity
Time: **O(n)** — 4 separate O(n) monotonic stack passes                 
Space: **O(n)** — multiple auxiliary arrays

---

## Key Observation
Both approaches rely on the identical mathematical identity (`sum(max) - sum(min) = sum(max - min)`), differing only in code organization — Approach 1 interleaves both computations using a shared sentinel-extended loop structure (more compact, harder to read), while Approach 2 keeps them as fully separate, reusable helper functions (clearer, matches the standalone "Sum of Subarray Minimums" problem's structure directly).

## When to use this
If problem involves:
- Sum of a per-subarray range/spread metric (max - min) across all subarrays
→ Think **decompose into sum(max) - sum(min)**, each solvable independently via monotonic stack contribution counting (NGE/PGE for max, NSE/PSE for min).

## Edge Cases
- All elements identical (max = min for every subarray, answer = 0).
- Strictly increasing or decreasing array.
- Single element array (only 1 subarray, range = 0).
- Large values requiring `long long` to avoid overflow in final sum.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Combined Pass (Sentinel) | O(n) | O(n) |
| Separate Sums (4 helpers) | O(n) | O(n) |

where:
- `n` = number of elements

## Related Problems
- Sum of Subarray Minimums
- Sum of Subarray Maximums
- Next Greater Element I
- Largest Rectangle in Histogram