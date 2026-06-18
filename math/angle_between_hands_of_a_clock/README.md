# Angle Between Hands of a Clock

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/angle-between-hands-of-a-clock/  
Difficulty: Medium  
Pattern: Math / Geometry

## What I understood
Given the hour and minute values of a clock, we need to find the smaller angle formed between the hour hand and the minute hand.

The answer should always be the minimum angle between the two possible angles.

Example:

hour = 3
minutes = 30

Hour hand = 105°
Minute hand = 180°

Answer = 75°

## Idea
Calculate the position of both clock hands independently.

The minute hand moves:

- 6° per minute

The hour hand moves:

- 30° per hour
- 0.5° per minute

Find the absolute difference between the two angles.

Since a clock forms a full circle of 360°, the smaller angle is:

min(diff, 360 - diff)

## Approach
- Calculate the angle of the hour hand
- Calculate the angle of the minute hand
- Find the absolute difference
- Return the smaller angle between:
  - diff
  - 360 - diff

## Key Observation
The hour hand does not stay fixed within an hour.

It continuously moves as minutes pass.

For every minute:
- hour hand moves 0.5°
- minute hand moves 6°

## When to use this
If the problem involves:
- clock calculations
- angle computation
- circular measurements

→ think about movement rates and geometry

## Edge Cases
- 12:00
- 6:00
- 12:30
- Same position of both hands
- Angles greater than 180°

## Complexity
Time: O(1)  
Space: O(1)

## Related Problems
- Clock Angle Problems
- Circular Array Problems
- Geometry Based Calculations
- Distance Between Clock Hands