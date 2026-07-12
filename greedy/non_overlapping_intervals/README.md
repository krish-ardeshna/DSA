# Non-overlapping Intervals

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/non-overlapping-intervals/  
Difficulty: Medium  
Pattern: Greedy / Intervals

## What I understood
We are given a collection of intervals.

We need to remove the minimum number of intervals so that the remaining intervals do not overlap.

Example:

intervals = [[1,2],[2,3],[3,4],[1,3]]

Output = 1

because removing [1,3] makes all remaining intervals non-overlapping.

## Idea
Sort the intervals by their ending values.

Always keep the interval that finishes first because it leaves more room for future intervals.

Whenever an overlap occurs, remove the current interval.

## Approach
- Sort intervals by their ending time
- Keep track of the last selected interval
- Traverse all intervals
- If the current interval overlaps:
  - increment the removal count
- Otherwise:
  - update the previous ending time
- Return the total removals

## Key Observation
Choosing the interval with the smallest ending value maximizes the chance of fitting more intervals later.

This greedy choice leads to the minimum number of removals.

## When to use this
If the problem involves:
- interval scheduling
- minimizing removals
- non-overlapping intervals
- optimal interval selection

→ think Greedy after sorting by end time

## Edge Cases
- Single interval
- No overlapping intervals
- All intervals overlap
- Intervals touching at endpoints

## Complexity
Time: O(n log n)  
Space: O(1)

## Related Problems
- Merge Intervals
- Insert Interval
- Meeting Rooms
- Minimum Number of Arrows to Burst Balloons