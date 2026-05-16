# Rotate Function

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/rotate-function/  
Difficulty: Medium  
Pattern: Array / Mathematical Observation

## What I understood
We need to calculate the maximum value of the rotate function after rotating the array multiple times.

A brute force approach would calculate every rotation separately, but that becomes expensive.

## Idea
Instead of recalculating from scratch for every rotation, use a relation between consecutive rotations.

If:
F(k) = rotate function for kth rotation

Then:
F(k) = F(k-1) + totalSum - n * lastElement

This helps calculate the next value in O(1).

## Approach
- Calculate:
  - total sum of array
  - initial rotate value F(0)
- Store maximum answer
- Use recurrence relation to compute next rotation values
- Update maximum

## Mistake I made
Initially thought about rotating the array physically and recalculating every time, which leads to O(n²).

## When to use this
If the problem involves:
- repeated rotations
- recalculating similar expressions
- optimization over repeated computation

→ try finding a mathematical relation between states

## Edge Cases
- Array with one element
- Negative values in array

## Complexity
Time: O(n)  
Space: O(1)