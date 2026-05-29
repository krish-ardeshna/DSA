# Minimum Element After Replacement With Digit Sum

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/  
Difficulty: Easy  
Pattern: Arrays / Math

## What I understood
Each element of the array must be replaced by the sum of its digits.

After replacing all elements,
we need to return the minimum value obtained.

Example:

10 → 1  
12 → 3  
13 → 4  
14 → 5

Answer = 1

## Idea

### Approach 1 (Helper Function)
Create a separate function to calculate digit sum.

For every element:
- calculate digit sum
- update minimum answer

### Approach 2 (In-place Calculation)
Calculate digit sum directly inside the loop.

This removes the need for a helper function while keeping the same logic.

## Approach
- Traverse array
- Calculate digit sum of each number
- Keep track of minimum digit sum
- Return final answer

## Key Observation
The actual transformed array is not needed.

Only the minimum digit sum matters.

## When to use this
If the problem involves:
- digit extraction
- digit sums
- finding minimum or maximum after transformation

→ process each number independently

## Edge Cases
- Single element array
- Numbers containing zeros
- All elements having same digit sum

## Complexity
Time: O(n × d)
- d = number of digits

Space: O(1)

## Related Problems
- Add Digits
- Palindrome Number
- Reverse Integer