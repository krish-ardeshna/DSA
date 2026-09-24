# Circle and Rectangle Overlapping
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/  
Difficulty: Medium  
Pattern: Math - Closest Point Clamping

## What I understood
Given a circle (center `(xCenter, yCenter)`, radius `radius`) and an axis-aligned rectangle (`(x1,y1)` bottom-left, `(x2,y2)` top-right), determine if they overlap (touching counts as overlapping).

## Example
```
Input
radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output
true
```
```
Input
radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output
false
```

## Idea
The circle and rectangle overlap if and only if the CLOSEST point on the rectangle to the circle's center lies within (or exactly on) the circle's radius. Find that closest point by "clamping" the circle's center coordinates to the rectangle's bounds — if the center's x-coordinate is already within `[x1, x2]`, the closest x is just that coordinate itself; otherwise it's whichever boundary (`x1` or `x2`) is nearer. Same logic applies independently for y.

## Approach: Find Closest Point on Rectangle to Circle Center, Check Distance
- Compute `closestX = max(x1, min(xCenter, x2))` — clamps `xCenter` into the rectangle's x-range.
- Compute `closestY = max(y1, min(yCenter, y2))` — same clamping for y-range.
- Compute squared distance from circle center to this closest point: `dx*dx + dy*dy`.
- Overlap occurs if this squared distance `<= radius*radius` (using squared values avoids floating-point square root entirely).

## Key Observation
Clamping via `max(lo, min(val, hi))` is a general and elegant technique for finding "nearest point within a range" — applying it independently on both axes correctly finds the nearest point on an AXIS-ALIGNED rectangle to any external point, without needing separate case analysis for whether the point is left/right/above/below/inside the rectangle.

## When to use this
If problem involves:
- Determining overlap/intersection between a circle and an axis-aligned rectangle (or similar "distance to nearest point in a bounded region" check)
→ Think **clamp the external point's coordinates into the rectangle's bounds to find the closest point**, then compare squared distance against radius squared (avoiding sqrt for precision and speed).

## Edge Cases
- Circle center exactly inside the rectangle (closest point equals center itself, distance 0, always overlaps).
- Circle touching rectangle edge exactly (distance equals radius exactly, counts as overlap via `<=`).
- Circle entirely outside and far from rectangle (no overlap).
- Very small radius (near-zero, only overlaps if center is very close to or inside rectangle).

## Complexity
### Approach
Time: **O(1)**          
Space: **O(1)**

where:
- Constant-time arithmetic regardless of coordinate magnitude

## Related Problems
- Rectangle Overlap
- Minimum Distance Between Points
- Check if Point Is Reachable
- K Closest Points to Origin