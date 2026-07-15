# Trapping Rain Water

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/trapping-rain-water/  
Difficulty: Hard  
Pattern: Two Pointers

## What I understood
We are given an elevation map where each bar has width 1.

After raining, water can be trapped between the bars.

We need to calculate the total amount of trapped rainwater.

Example:

height = [0,1,0,2,1,0,1,3,2,1,2,1]

Output = 6

## Idea
Use two pointers starting from both ends of the array.

Maintain:
- maximum height seen from the left
- maximum height seen from the right

At each step:
- process the side with the smaller height
- calculate trapped water using the corresponding maximum height

## Approach
- Initialize two pointers at both ends
- Maintain leftMax and rightMax
- Move the pointer with the smaller height
- Update the maximum height seen so far
- Add trapped water whenever the current height is smaller than the maximum
- Return the total trapped water

## Key Observation
The amount of water trapped at a position depends on the smaller of the maximum heights on its left and right.

By always processing the side with the smaller height, we can determine the trapped water without precomputing prefix and suffix maximum arrays.

## When to use this
If the problem involves:
- water trapping
- left and right boundaries
- optimizing space
- array traversal from both ends

→ think Two Pointers

## Edge Cases
- Empty array
- Single bar
- All bars of equal height
- Strictly increasing heights
- Strictly decreasing heights

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Container With Most Water
- Largest Rectangle in Histogram
- Trapping Rain Water II
- Max Consecutive Ones III