# Two Sum

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/two-sum/  
Difficulty: Easy  
Pattern: Hashing

## What I understood
We need to find two numbers whose sum equals the target.  
A brute force approach using two loops works, but it is inefficient (O(n^2)), so an optimized approach is needed.

## Idea
Instead of checking every pair, store visited elements in a hashmap.  
For each element, check if (target - current element) already exists.

## Approach
- Traverse the array once
- For each element:
  - Calculate: diff = target - nums[i]
  - Check if diff exists in map
    - If yes → return indices
  - Else → store current number in map

## Mistake I made
At first, I used brute force and didn’t think about optimization.

## When to use this
If the problem involves:
- finding a pair with a target sum
- checking complements

→ use a hashmap for O(1) lookup

## Edge Cases
- No valid pair → return empty vector

## Complexity
Time: O(n)  
Space: O(n)