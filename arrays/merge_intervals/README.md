# Merge Intervals

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/merge-intervals/  
Difficulty: Medium  
Pattern: Intervals

## What I understood
We are given a collection of intervals.

If two intervals overlap, they should be merged into a single interval.

Return the list of merged intervals.

Example:

intervals = [[1,3],[2,6],[8,10],[15,18]]

Output = [[1,6],[8,10],[15,18]]

## Idea
Sort the intervals according to their starting values.

Traverse the sorted intervals:

- if the current interval overlaps with the last merged interval, merge them
- otherwise, start a new interval

## Approach
- Sort the intervals by start time
- Add the first interval to the answer
- Traverse the remaining intervals
- Merge overlapping intervals
- Otherwise add the current interval
- Return the merged intervals

## Key Observation
After sorting, all overlapping intervals become adjacent.

Therefore, each interval only needs to be compared with the last merged interval.

## When to use this
If the problem involves:
- overlapping intervals
- interval merging
- scheduling
- range consolidation

→ think Sorting + Merge

## Edge Cases
- Empty input
- Single interval
- No overlapping intervals
- All intervals overlap
- Touching intervals

## Complexity
Time: O(n log n)  
Space: O(n)

## Related Problems
- Insert Interval
- Non-overlapping Intervals
- Meeting Rooms
- Meeting Rooms II