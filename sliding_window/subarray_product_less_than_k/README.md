# Subarray Product Less Than K

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/subarray-product-less-than-k/  
Difficulty: Medium  
Pattern: Sliding Window

## What I understood
We are given an array of positive integers and an integer k.

We need to count the number of contiguous subarrays whose product is strictly less than k.

Example:

nums = [10,5,2,6]

k = 100

Output = 8

## Idea
Use a sliding window to maintain a valid subarray.

Keep multiplying elements while expanding the window.

If the product becomes greater than or equal to k, shrink the window from the left until the product becomes valid again.

Every valid window ending at the current index contributes:

(end - start + 1)

new subarrays.

## Approach
- Handle the case when k ≤ 1
- Initialize a sliding window
- Expand the window by multiplying the current element
- Shrink the window while the product is not valid
- Count all valid subarrays ending at the current index
- Return the total count

## Key Observation
If a window has a product less than k, then every suffix of that window also has a product less than k.

Therefore, once the window is valid, we can directly add:

(end - start + 1)

to the answer.

## When to use this
If the problem involves:
- contiguous subarrays
- products
- positive numbers
- counting valid windows

→ think Sliding Window

## Edge Cases
- k ≤ 1
- Single element array
- Product always less than k
- Product always greater than or equal to k

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Minimum Size Subarray Sum
- Maximum Erasure Value
- Fruit Into Baskets
- Longest Repeating Character Replacement