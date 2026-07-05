# Find Pivot Index

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-pivot-index/  
Difficulty: Easy  
Pattern: Prefix Sum

## What I understood
We are given an integer array.

The pivot index is the index where the sum of all elements to the left equals the sum of all elements to the right.

We need to return the leftmost pivot index. If no such index exists, return -1.

Example:

nums = [1,7,3,6,5,6]

Output = 3

## Idea
First compute the total sum of the array.

While traversing the array:
- maintain the sum of elements on the left
- calculate the right sum using:

rightSum = totalSum - leftSum - currentElement

If leftSum equals rightSum, the current index is the pivot index.

## Approach
- Calculate the total sum of the array
- Initialize leftSum as 0
- Traverse the array
- Compute the right sum
- Compare left and right sums
- If they are equal, return the current index
- Otherwise update leftSum
- Return -1 if no pivot index exists

## Key Observation
The right sum does not need to be computed separately.

It can be obtained using:

totalSum - leftSum - currentElement

This allows solving the problem in a single traversal after computing the total sum.

## When to use this
If the problem involves:
- cumulative sums
- balancing left and right sums
- prefix computations

→ think prefix sum

## Edge Cases
- Pivot at the first index
- Pivot at the last index
- No pivot index
- Single element array
- Negative numbers

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Running Sum of 1d Array
- Find the Highest Altitude
- Product of Array Except Self
- Range Sum Query - Immutable