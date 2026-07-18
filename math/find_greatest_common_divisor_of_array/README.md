# Find Greatest Common Divisor of Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/  
Difficulty: Easy  
Pattern: Math / GCD

## What I understood
We are given an integer array.

We need to find the GCD of the smallest and largest elements in the array.

Example:

nums = [2,5,6,9,10]

Output = 2

## Idea
The problem only requires the smallest and largest values.

After finding them, directly compute their GCD.

## Approach
- Find the minimum element in the array.
- Find the maximum element in the array.
- Compute the GCD of these two values.
- Return the result.

## Key Observation
The answer depends only on the minimum and maximum elements. The remaining elements do not affect the result.

## When to use this
If the problem involves:
- GCD
- minimum and maximum element
- simple array traversal

→ think Math + GCD

## Edge Cases
- Array with one element
- All elements equal
- Array containing prime numbers
- Minimum and maximum are the same

## Complexity
Time: O(n)

Space: O(1)

## Related Problems
- Ugly Number
- GCD of Odd and Even Sums
- Sum of GCD of Formed Pairs
- Find Greatest Common Divisor