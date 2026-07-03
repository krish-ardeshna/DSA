# Running Sum of 1d Array

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/running-sum-of-1d-array/  
Difficulty: Easy  
Pattern: Prefix Sum

## What I understood
We are given an array of integers.

For each index, we need to compute the sum of all elements from the beginning of the array up to that index.

Example:

nums = [1,2,3,4]

Output = [1,3,6,10]

## Idea

### Approach 1 (Extra Prefix Sum Array)
Maintain a running sum while traversing the array.

Store each prefix sum in a separate result array.

### Approach 2 (In-place Prefix Sum)
Instead of using another array, update the original array itself.

Each element becomes the sum of itself and the previous prefix sum.

This saves extra space.

## Approach
- Initialize the prefix sum
- Traverse the array from left to right
- Compute the running total
- Store the result either:
  - in a new array
  - or directly in the original array
- Return the final array

## Key Observation
Each running sum depends only on the previous running sum.

This allows us to compute the answer in-place without using additional memory.

## When to use this
If the problem involves:
- cumulative sums
- range queries
- running totals

→ think prefix sum

## Edge Cases
- Single element array
- Negative numbers
- All zeros
- Empty array

## Complexity

### Approach 1
Time: O(n)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(1)

## Related Problems
- Find the Highest Altitude
- Find Pivot Index
- Range Sum Query - Immutable
- Subarray Sum Equals K