# Maximum Product of Two Elements in an Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/  
Difficulty: Easy  
Pattern: Array, Sorting

## What I understood
Given an integer array, choose two different elements and return the maximum value of:

```
(nums[i] - 1) × (nums[j] - 1)
```

Example:
```
nums = [3,4,5,2]
Output = 12
```

## Idea
Since the expression subtracts `1` from both selected numbers, the maximum value is generally obtained from the two largest elements.

The sorting approach directly finds them, while the optimal approach tracks them in a single traversal.

## Approach 1: Sorting
- Sort the array.
- Compute the product using the two largest elements.
- Return the result.

## Approach 2: One Pass (Optimal)
- Traverse the array once.
- Track the largest and second largest values.
- Compute the answer using these two values.

## Key Observation
Subtracting `1` from every selected element preserves their relative order.

Therefore, the two largest numbers always produce the maximum value.

## When to use this
If the problem involves:
- Maximum pair product
- Selecting two elements
- Single-pass optimization
- Largest and second largest values

→ Think **Largest Element Tracking**.

## Edge Cases
- Minimum valid array size: `[1,2]`
- Duplicate largest values.
- Array containing zeros.
- All elements are the same.

## Complexity

### Approach 1
Time: **O(n log n)**  
Space: **O(1)**

### Approach 2
Time: **O(n)**  
Space: **O(1)**

## Related Problems
- Maximum Product of Three Numbers
- Third Maximum Number
- Find Greatest Common Divisor of Array