# Elevator Requests I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/elevator-requests-i/  
Difficulty: Easy (contest problem)
Pattern: Array - Linear Scan (Running Distance Sum)

## What I understood
Elevator starts at floor 0. Given a sequence of floor requests, elevator must visit them in given order. Total time taken = sum of absolute floor differences between consecutive stops (including start).

## Example
```
Input
n = 5, requests = [2,1,3]
Output
4
```

## Idea
Elevator movement between two floors takes time proportional to floor distance, in given visiting order (no reordering allowed) — just accumulate `|next - current|` for every request, updating current floor as you go.

## Approach: Single Pass Accumulate Absolute Difference
- Init `currFloor = 0`, `timeTaken = 0`.
- For each `floor` in requests: add `abs(floor - currFloor)` to `timeTaken`, update `currFloor = floor`.
- Return `timeTaken` after processing all requests.

## Key Observation
No optimization or reordering needed — requests must be served in given order, so total time is simply the sum of consecutive absolute differences, a fixed value regardless of any clever strategy.

## When to use this
If problem involves:
- Sequential movement/traversal cost between ordered points
- Cost is absolute distance between consecutive positions
→ Think **single pass running sum of absolute differences**.

## Edge Cases
- Empty requests list → `timeTaken = 0`.
- Single request → distance from floor 0 to that floor.
- Requests revisiting same floor consecutively (`diff = 0`, no added time).
- Negative-direction moves (floor decreasing) — `abs()` handles both directions uniformly.

## Complexity
### Approach
Time: **O(m)**      
Space: **O(1)**

where:
- `m` = number of requests

## Related Problems
- Minimum Moves to Equal Array Elements
- Best Time to Buy and Sell Stock
- Car Pooling
- Trip Count