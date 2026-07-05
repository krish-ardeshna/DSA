# Product of Array Except Self

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/product-of-array-except-self/  
Difficulty: Medium  
Pattern: Prefix Sum

## What I understood
Given an integer array, we need to return an array where each element is the product of all elements except itself.

Division is not allowed.

Example:

nums = [1,2,3,4]

Output = [24,12,8,6]

## Idea

### Approach 1 (Brute Force)
For every index:
- traverse the entire array
- multiply every element except the current one

Store the computed product in the answer array.

### Approach 2 (Prefix and Suffix Products)
For every index:

Product Except Self =

Prefix Product × Suffix Product

First compute products of all elements to the left.

Then multiply them with products of all elements to the right.

This avoids division and runs in linear time.

## Approach
- Create the answer array
- Store prefix products while traversing left to right
- Compute suffix products while traversing right to left
- Multiply both contributions
- Return the answer

## Key Observation
For every index:

Product Except Self =

(Product of all left elements)
×
(Product of all right elements)

Using prefix and suffix products eliminates the need for division.

## When to use this
If the problem involves:
- product excluding current element
- prefix computations
- suffix computations
- avoiding division

→ think prefix and suffix arrays

## Edge Cases
- Array containing zeros
- Single zero
- Multiple zeros
- Negative numbers
- Array of size two

## Complexity

### Approach 1
Time: O(n²)  
Space: O(1) (excluding output array)

### Approach 2
Time: O(n)  
Space: O(1) (excluding output array)

## Related Problems
- Running Sum of 1d Array
- Find Pivot Index
- Trapping Rain Water
- Maximum Product Subarray