# Find the Smallest Divisor Given a Threshold
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/  
Difficulty: Medium  
Pattern: Binary Search on Answer

## What I understood
Find the smallest positive integer `divisor` such that dividing every element in `nums` by it (with each result rounded UP to nearest integer, i.e. ceiling division) and summing all results gives a total `<= threshold`.

## Example
```
Input
nums = [1,2,5,9], threshold = 6
Output
5
```
```
Input
nums = [44,22,33,11,1], threshold = 5
Output
44
```

## Idea
As `divisor` increases, each element's ceiling-divided contribution shrinks (or stays same), so total sum is monotonically non-increasing with respect to divisor — classic setup for binary search on answer. Search space bounded between 1 (smallest divisor) and max element in array (any divisor larger than the max element gives sum equal to array length, no further benefit needed beyond that).

## Approach: Binary Search on Divisor + Ceiling Sum Check
- Early exit: if array length alone exceeds `threshold`, impossible (even divisor = max value gives sum = n, minimum achievable), return -1.
- Binary search `divisor` between 1 and max element.
- Feasibility check (`summation`): for given `div`, compute sum of `ceil(num / div)` for every element, using integer-safe ceiling trick `(num + div - 1) / div` instead of floating-point `ceil()`.
- If sum `<= threshold` → divisor works, try smaller (`high = mid - 1`).
- Else → divisor too small, need larger (`low = mid + 1`).
- Return `low` (smallest feasible divisor) after search converges.

## Key Observation
Integer-based ceiling division (`(num + div - 1) / div`) avoids floating-point precision issues that `ceil((double)num/div)` could introduce for edge-case large values — safer and typically faster than floating-point math.

## When to use this
If problem involves:
- Finding minimum/maximum divisor, capacity, or threshold value where a computed aggregate is monotonic with respect to that value
→ Think **binary search on answer**, use integer ceiling trick instead of floating-point when computing ceiling divisions.

## Edge Cases
- `threshold` exactly equal to array length → forces divisor = max element (minimum possible sum).
- `threshold` less than array length → impossible, return -1.
- Single element array.
- Large values requiring careful integer overflow consideration (not an issue here since `div` and `num` bounded reasonably).

## Complexity
### Approach
Time: **O(n log(max_element))** — binary search over divisor range, O(n) summation check per iteration      
Space: **O(1)** extra

where:
- `n` = number of elements

## Related Problems
- Koko Eating Bananas
- Capacity To Ship Packages Within D Days
- Minimum Number of Days to Make m Bouquets
- Split Array Largest Sum