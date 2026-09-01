# Minimize the Maximum Waiting Time at Synchronized Traffic Lights
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/  
Difficulty: Medium (contest problem)  
Pattern: Math - Modular Arithmetic

## What I understood
Traffic lights operate on a repeating cycle of length `period`, all synchronized. `lights` gives some threshold values within that cycle. For each `arrivalTime`, compute its position within the current cycle (`time % period`); if that position is at or beyond the maximum light threshold, a waiting penalty of `period - r` applies. Find the maximum penalty across all arrival times.

## Example
```
Input
period = 10, lights = [2,5], arrivalTime = [3,8,12]
Output
(maximum penalty across all arrival times based on cycle position)
```

## Idea
Since only the maximum light threshold determines whether a penalty applies (per this solution's logic), precompute `maxLight` once. For each arrival, reduce it to its cycle-relative position via modulo, check against `maxLight`, and if triggered, the penalty is simply the remaining time until the cycle resets (`period - r`).

## Approach: Modular Offset Check Against Max Light
- Compute `maxLight` as the maximum value in `lights`.
- For each `time` in `arrivalTime`: compute `r = time % period` (position within current cycle).
- If `r >= maxLight`, this arrival incurs a penalty of `period - r`; update running max `ans`.
- Return `ans` after processing all arrival times (0 if no arrival ever triggers a penalty).

## Key Observation
Reducing absolute arrival time to a cycle-relative position via modulo is the key trick for any repeating/periodic-cycle problem — turns unbounded time values into a bounded range `[0, period)` that can be directly compared against fixed thresholds.

## When to use this
If problem involves:
- Repeating/periodic cycles (like traffic lights, schedules, circular buffers)
- Need to determine position or penalty relative to cycle boundaries
→ Think **modulo reduction to cycle-relative position**, then direct threshold comparison.

## Edge Cases
- Arrival time exactly at cycle boundary (`r == 0`).
- Arrival time exactly at `maxLight` threshold (boundary inclusive per `>=`).
- No arrival ever triggers penalty (`ans` stays 0).
- Very large `arrivalTime` values needing modulo to stay bounded.

## Complexity
### Approach
Time: **O(n + m)** — O(m) to find max light, O(n) to process arrivals       
Space: **O(1)** extra

where:
- `n` = number of arrival times
- `m` = number of lights

## Related Problems
- Car Pooling
- Meeting Rooms II
- Minimum Number of Taps to Open to Water a Garden
- Circular Array Loop