# Insert Interval

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/insert-interval/  
Difficulty: Medium  
Pattern: Intervals

## What I understood
We are given a list of non-overlapping intervals sorted by their starting values.

We need to insert a new interval while maintaining the sorted order and merging any overlapping intervals.

Example:

intervals = [[1,3],[6,9]]

newInterval = [2,5]

Output = [[1,5],[6,9]]

## Idea
Traverse the intervals once.

For every interval:

- if it lies completely before the new interval, add it to the answer
- if it lies completely after the new interval, add the merged interval first and continue
- otherwise, merge the overlapping intervals by updating the new interval

Finally, add the merged new interval.

## Approach
- Traverse the intervals
- Add non-overlapping intervals before the new interval
- Merge overlapping intervals
- Insert the merged interval before remaining intervals
- Return the final list

## Key Observation
Since the intervals are already sorted and non-overlapping, each interval is processed only once.

Sorting is not required.

## When to use this
If the problem involves:
- inserting intervals
- merging overlapping ranges
- maintaining sorted intervals

→ think Single Pass Interval Merge

## Edge Cases
- Empty interval list
- Insert at the beginning
- Insert at the end
- New interval overlaps multiple intervals
- New interval overlaps none

## Complexity
Time: O(n)  
Space: O(n)

## Related Problems
- Merge Intervals
- Non-overlapping Intervals
- Meeting Rooms
- Meeting Rooms II