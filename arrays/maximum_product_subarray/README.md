# Maximum Product Subarray

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-product-subarray/  
Difficulty: Medium  
Pattern: Arrays / Kadane Variation

## What I understood
We need to find the contiguous subarray with the maximum product.

Unlike maximum sum subarray,
negative numbers make this problem trickier because:
- a negative × negative can become positive

## Idea
Track:
- current maximum product
- current minimum product

Why minimum?
Because a large negative value can become the next maximum after multiplication with another negative number.

## Approach
- Initialize:
  - currMax
  - currMin
  - answer
- Traverse array
- If current element is negative:
  - swap currMax and currMin
- Update:
  - currMax = max(current number, current product)
  - currMin = min(current number, current product)
- Update final answer

## Key Observation
A negative number can completely change the situation.

The current minimum product can suddenly become the maximum product.

## When to use this
If the problem involves:
- subarrays
- products
- negative number sign changes

→ track both maximum and minimum values

## Edge Cases
- Single element array
- Array containing zero
- All negative numbers

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Maximum Subarray
- Kadane’s Algorithm
- House Robber