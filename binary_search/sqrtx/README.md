# Sqrt(x)

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sqrtx/  
Difficulty: Easy  
Pattern: Binary Search

## What I understood
We need to find the square root of a number and return only the integer part.

Built-in functions are not allowed.

## Idea
Instead of checking every number linearly,
binary search can be used because:
- square values increase in sorted order

Search space:
0 → x

## Approach
- Initialize:
  - low = 0
  - high = x
- Find middle value
- Compare:
  - mid * mid with x
- If:
  - equal → return mid
  - smaller → store possible answer and search right
  - larger → search left
- Return stored answer

## Key Observation
The answer space itself is sorted.

That makes binary search possible even without an actual array.

## When to use this
If the problem involves:
- monotonic increasing values
- searching numeric answer space
- square roots or precision search

→ think binary search on answers

## Edge Cases
- x = 0
- x = 1
- non-perfect squares

## Complexity
Time: O(log x)  
Space: O(1)

## Related Problems
- Valid Perfect Square
- Binary Search
- Koko Eating Bananas