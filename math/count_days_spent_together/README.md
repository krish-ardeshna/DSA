# Count Days Spent Together
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-days-spent-together/  
Difficulty: Easy  
Pattern: Math - Date to Day-of-Year + Interval Overlap

## What I understood
Alice and Bob each stay in Rome for a range of days, given as `"MM-DD"` strings (arrival and leaving day, both inclusive). All dates are in the same non-leap year. Return the number of days both of them are in Rome.

## Example
```
Input
arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output
3
```
Explanation: both are there on August 16, 17 and 18.

```
Input
arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output
0
```
Explanation: Alice leaves on October 31 and Bob arrives on November 1, so they never overlap.

## Idea
Comparing `"MM-DD"` strings and counting days between them is awkward. Convert every date to its **day number in the year** (1 to 365). Then the problem is plain interval overlap on numbers.

Two ranges `[a1, a2]` and `[b1, b2]` overlap on `[max(a1, b1), min(a2, b2)]`. If that range is empty (end before start), the answer is 0.

## Approach: Convert Dates to Day Numbers, Intersect the Two Ranges
- Keep the days of each month: `31, 28, 31, 30, ...` (non-leap year).
- `dayOfYear("MM-DD")` = `DD` plus the days of all earlier months.
- `start = max(arrival of Alice, arrival of Bob)`, `end = min(leave of Alice, leave of Bob)`.
- Both ends are inclusive, so the count is `end - start + 1`, and `max(0, ...)` turns a negative result (no overlap) into 0.

## Key Observation
The `+ 1` matters because both the arrival day and the leaving day count. The `max(0, ...)` matters because `end - start + 1` is zero or negative when the ranges do not touch. Two ranges that share exactly one day (`end == start`) correctly give 1.

## When to use this
If problem involves:
- Overlap of two date or time ranges
- Dates that are awkward to compare directly
→ Think **convert to a single number line, then take `max` of starts and `min` of ends**.

## Edge Cases
- No overlap at all (answer 0).
- Ranges touching on exactly one day (answer 1).
- One range fully inside the other (answer is the length of the inner range).
- Identical ranges (answer is the full length).
- Ranges in different months (handled by the month table).

## Complexity
### Approach
Time: **O(1)**, at most 12 additions per date           
Space: **O(1)**

where:
- the input size is fixed (four short strings)

## Related Problems
- Meeting Rooms
- Merge Intervals
- Interval List Intersections
- Day of the Year