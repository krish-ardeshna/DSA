# Find the Minimum and Maximum Number of Nodes Between Critical Points
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/  
Difficulty: Medium  
Pattern: Linked List - Single Pass (Local Min/Max Detection)

## What I understood
A "critical point" is a node that is either a local maxima (greater than both neighbors) or local minima (less than both neighbors) — first and last nodes can never be critical points since they lack two neighbors. Find the minimum and maximum distance (in node count) between any two critical points. Return `[-1,-1]` if fewer than 2 critical points exist.

## Example
```
Input
head = [5,3,1,2,5,1,2]
Output
[1,3]
```
```
Input
head = [1,3,2,2,3,2,2,2,7]
Output
[-1,-1]
```

## Idea
Single pass through the list, tracking each node's position. Whenever a critical point is found, compare it against the immediately previous critical point (for minimum gap — since critical points found in traversal order, adjacent ones naturally give the tightest possible min) and against the very first critical point found (for maximum gap — since the overall span between first and last-seen critical point is always the max possible spread).

## Approach: Single Pass, Track First/Previous Critical Point Positions
- Traverse using three pointers: `prevNode`, `curr`, and `curr->next` (nextNode) to check the middle node's local min/max status without needing to store values separately.
- Track `pos` (current node's index), `first` (position of first critical point found), `prev` (position of most recently found critical point).
- On finding a critical point: if it's the first one, just record `first`. Otherwise, update `minDist = min(minDist, pos - prev)` (gap to immediately previous critical point) and `maxDist = pos - first` (gap to the very first one, which grows as more critical points are found further along).
- After loop, if no min distance was ever set (fewer than 2 critical points), return `{-1,-1}`; else return `{minDist, maxDist}`.

## Key Observation
Minimum distance only needs comparison with the immediately preceding critical point (consecutive critical points give the tightest possible gaps — any non-adjacent pair would have a larger gap). Maximum distance only needs comparison with the very first critical point (since that's always the widest possible span as traversal progresses forward).

## When to use this
If problem involves:
- Finding min/max spacing between events/points detected during a single traversal
→ Think **track first-seen and previous-seen positions separately** — min needs consecutive comparison, max needs comparison against the very first occurrence.

## Edge Cases
- Fewer than 2 critical points exist → return `[-1,-1]`.
- Exactly 2 critical points (min and max distance are equal, both computed from the same pair).
- All critical points evenly spaced (min equals max).
- List too short to have any interior nodes (list length < 3, loop doesn't execute).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = number of nodes in the list

## Related Problems
- Linked List Cycle
- Middle of the Linked List
- Palindrome Linked List
- Next Greater Node In Linked List