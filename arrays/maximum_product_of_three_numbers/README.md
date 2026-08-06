# Maximum Product of Three Numbers

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-product-of-three-numbers/  
Difficulty: Easy  
Pattern: Sorting, Array

## What I understood

Given an integer array, return the maximum product that can be obtained by multiplying any three numbers.

Since negative numbers are allowed, the answer is not always obtained from the three largest values.

Example:

nums = [-10, -10, 5, 2]

Output = 500

## Idea

There are only two possible candidates for the maximum product:

- The product of the three largest numbers.
- The product of the two smallest numbers (most negative) and the largest number.

Compare both and return the larger product.

## Approach 1: Sorting

- Sort the array.
- Compute the product of the last three elements.
- Compute the product of the first two and the last element.
- Return the maximum.

## Approach 2: One Pass (Optimal)

- Traverse the array once.
- Track:
  - largest
  - second largest
  - third largest
  - smallest
  - second smallest
- Compute both possible products.
- Return the larger one.

## Key Observation

The maximum product can come from:
- Three large positive numbers.
- Two very small (negative) numbers and one large positive number.

Checking these two cases is sufficient.

## When to use this

If the problem asks for:
- maximum product
- exactly three elements
- negative numbers
- optimization without sorting

→ think about tracking the largest and smallest values simultaneously.

## Edge Cases

- All numbers are positive.
- All numbers are negative.
- Two very small negative numbers produce the maximum product.
- Array contains zeros.

## Complexity

### Approach 1

Time: O(n log n)

Space: O(1)

### Approach 2

Time: O(n)

Space: O(1)

## Related Problems

- Maximum Product of Two Elements in an Array
- Third Maximum Number
- Maximum Product Subarray