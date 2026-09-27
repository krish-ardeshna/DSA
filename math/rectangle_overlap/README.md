# Rectangle Overlap
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/rectangle-overlap/  
Difficulty: Medium  
Pattern: Math - Interval Intersection

## What I understood
Each rectangle is given as `[x1, y1, x2, y2]` (bottom-left and top-right corners), axis-aligned. Determine if two such rectangles overlap with a positive area (edges/corners merely touching does NOT count as overlapping).

## Example
```
Input
rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output
true
```
```
Input
rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output
false
```

## Idea
Two axis-aligned rectangles overlap with positive area if and only if their projections onto BOTH the x-axis and y-axis overlap with positive length. This reduces the 2D overlap check into two independent 1D interval-intersection checks - compute the intersection interval on each axis, and both must have strictly positive width/height.

## Approach: Compute Overlap Interval on Both Axes
- X-axis overlap: `left = max(rec1[0], rec2[0])`, `right = min(rec1[2], rec2[2])`.
- Y-axis overlap: `bottom = max(rec1[1], rec2[1])`, `top = min(rec1[3], rec2[3])`.
- Rectangles overlap (positive area) only if `left < right` AND `bottom < top` (strict inequality - equal values mean edges merely touch, zero-area intersection, not counted).

## Key Observation
Using strict `<` (not `<=`) is essential to correctly exclude edge-touching or corner-touching cases, which have zero overlap area and shouldn't count as "overlapping" per the problem's definition.

## When to use this
If problem involves:
- Determining intersection/overlap between two axis-aligned rectangles or intervals
→ Think **decompose into independent x-axis and y-axis interval intersection checks**, requiring strict positive overlap on both.

## Edge Cases
- Rectangles sharing an edge exactly (touching, not overlapping - should return false).
- Rectangles sharing only a corner point (should return false).
- One rectangle fully contained within another (should return true).
- Identical rectangles (should return true).

## Complexity
### Approach
Time: **O(1)**          
Space: **O(1)**

where:
- Constant-time comparison regardless of coordinate magnitude

## Related Problems
- Rectangle Area
- Rectangle Area II
- Number of Ways to Divide a Long Corridor
- Employee Free Time