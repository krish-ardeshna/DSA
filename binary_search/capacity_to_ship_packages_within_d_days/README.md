# Capacity To Ship Packages Within D Days
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/  
Difficulty: Medium  
Pattern: Binary Search on Answer

## What I understood
Packages (given as `weights`, in order) must be shipped within `days` days, one day loads packages in given order until adding the next would exceed the ship's capacity, then moves to next day. Find the minimum ship capacity that allows shipping all packages within `days` days.

## Example
```
Input
weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output
15
```
```
Input
weights = [3,2,2,4,1,4], days = 3
Output
6
```

## Idea
As capacity increases, number of days needed decreases (or stays same) — monotonic relationship enables binary search on capacity. Search space bounded between `max(weights)` (smallest valid capacity, since ship must carry the heaviest single package) and `sum(weights)` (largest sensible capacity, ships everything in 1 day).

## Approach: Binary Search on Capacity + Greedy Day Simulation
- Compute search bounds: `low = max(weights)`, `high = totalWeights(weights)`.
- Binary search over capacity `mid`.
- Feasibility check (`findDays`): greedily simulate loading — add package to current day's load if it fits (`load + x <= cap`); otherwise start new day with that package.
- If `findDays(mid) <= days` → capacity works, try smaller (`high = mid - 1`).
- Else → capacity too small, need larger (`low = mid + 1`).
- Return `low` (minimum feasible capacity) after search converges.

## Key Observation
Package order must be preserved (can't reorder to optimize) — this makes the greedy day-simulation straightforward (no sorting/grouping needed), since each day simply takes as many consecutive packages as fit before overflowing.

## When to use this
If problem involves:
- Minimum capacity/resource such that a sequential greedy process completes within a constraint (days, trips, etc.)
- Feasibility is monotonic with respect to the resource being searched
→ Think **binary search on answer + greedy simulation feasibility check**.

## Edge Cases
- `days` equal to number of packages (capacity = max single package weight suffices).
- `days = 1` (capacity must equal total sum, ship everything at once).
- Single package.
- All packages identical weight.

## Complexity
### Approach
Time: **O(n log(sum - max))** — binary search over capacity range, O(n) simulation per iteration        
Space: **O(1)** extra

where:
- `n` = number of packages

## Related Problems
- Koko Eating Bananas
- Minimum Number of Days to Make m Bouquets
- Split Array Largest Sum
- Find the Smallest Divisor Given a Threshold