# Jump Game

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/jump-game/  
Difficulty: Medium  
Pattern: Greedy

## What I understood
We are given an array where each element represents the maximum jump length from that position.

We need to determine whether it is possible to reach the last index.

Example:

nums = [2,3,1,1,4]

Output = true

because we can reach the last index.

## Idea
Keep track of the farthest index that can be reached while traversing the array.

If the current index is ever greater than the farthest reachable index, reaching the end is impossible.

Otherwise, continuously update the farthest reachable position.

## Approach
- Initialize the maximum reachable index as 0
- Traverse the array
- If the current index is unreachable:
  - return false
- Update the farthest reachable index
- If the last index becomes reachable:
  - return true
- Return true after completing the traversal

## Key Observation
At every position, we only need to know the farthest index reachable so far.

There is no need to explore every possible jump.

## When to use this
If the problem involves:
- reachability
- maximum jump distance
- array traversal
- making locally optimal choices

→ think Greedy

## Edge Cases
- Single element array
- First element is 0
- Last index already reachable
- Array containing multiple zeros

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Jump Game II
- Jump Game III
- Jump Game IV
- Gas Station