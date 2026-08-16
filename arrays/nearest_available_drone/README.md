# Nearest Available Drone
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/nearest-available-drone/  
Difficulty: Easy (contest problem)  
Pattern: Array - Linear Scan (Manhattan Distance + Range Check)

## What I understood
Each drone has a position `(x, y)` and a max range `r`. Given a `target` position, find the index of the drone that can reach the target (Manhattan distance `<= r`) with the smallest such distance. Return -1 if no drone can reach it.

## Example
```
Input
drones = [[0,0,5],[3,3,10]], target = [2,2]
Output
0
```

## Idea
Straightforward single-pass check: for every drone, compute Manhattan distance to target, filter out drones whose range can't cover that distance, and among the remaining valid ones, track the minimum distance and its index.

## Approach: Single Pass, Track Closest Drone Within Range
- Init `reachable = -1`, `minDist = INT_MAX`.
- For each drone `i`: compute `dist = |x_i - target_x| + |y_i - target_y|`.
- If `dist <= drones[i][2]` (within range) and `dist < minDist` → update `minDist` and `reachable = i`.
- Return `reachable` (stays -1 if no drone qualifies).

## Key Observation
Two conditions must both hold for a drone to be considered: in-range (`dist <= range`) AND currently the closest found so far (`dist < minDist`) — combining both in a single pass avoids needing to filter then separately find minimum.

## When to use this
If problem involves:
- Finding nearest/closest entity satisfying a range or capacity constraint
- Distance metric is simple (Manhattan, Euclidean, etc.)
→ Think **single pass, combined filter + running minimum tracking**.

## Edge Cases
- No drone within range → returns -1.
- Multiple drones with identical minimum distance (first one encountered wins, due to strict `<` comparison).
- Target exactly at a drone's position (`dist = 0`).
- Drone's range exactly equals distance (`dist == range`, inclusive boundary via `<=`).

## Complexity
### Approach
Time: **O(n)**      
Space: **O(1)**

where:
- `n` = number of drones

## Related Problems
- Nearest Available Drone II
- K Closest Points to Origin
- Find Nearest Point That Has the Same X or Y Coordinate
- Minimum Distance to the Target Element