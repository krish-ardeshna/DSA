# Find the Pivot Integer

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-pivot-integer/  
Difficulty: Easy  
Pattern: Prefix Sum / Math

## What I understood
We are given an integer n.

We need to find an integer x such that:

- the sum of numbers from 1 to x
- equals the sum of numbers from x to n

If no such integer exists, return -1.

Example:

n = 8

Output = 6

because:

1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21

## Idea

### Approach 1 (Prefix Sum Simulation)
First calculate the total sum from 1 to n.

Traverse every possible pivot:
- maintain the left sum
- compute the right sum using the total sum

If both sums become equal, return the current number.

### Approach 2 (Mathematical Observation)
Let:

- S = sum from 1 to n
- x = pivot

The required condition becomes:

Sum(1...x) = Sum(x...n)

After simplifying:

x² = S

Therefore:
- compute the total sum
- take its square root
- if the square of the root equals the sum, that root is the pivot
- otherwise return -1

## Approach
- Compute the total sum
- Either:
  - simulate prefix sums
  - or use the mathematical observation
- Return the pivot if it exists
- Otherwise return -1

## Key Observation
The pivot exists only when the total sum from 1 to n is a perfect square.

This reduces the solution from linear time to constant time.

## When to use this
If the problem involves:
- balancing prefix and suffix sums
- arithmetic series
- mathematical simplification

→ think Prefix Sum first, then look for a mathematical pattern

## Edge Cases
- n = 1
- No valid pivot
- Large values of n

## Complexity

### Approach 1
Time: O(n)  
Space: O(1)

### Approach 2
Time: O(1)  
Space: O(1)

## Related Problems
- Find Pivot Index
- Running Sum of 1d Array
- Product of Array Except Self
- Range Sum Query - Immutable