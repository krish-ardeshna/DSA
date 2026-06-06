# Left and Right Sum Differences

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/left-and-right-sum-differences/  
Difficulty: Easy  
Pattern: Arrays / Prefix Sum

## What I understood
For every index:

- leftSum[i] = sum of elements before index i
- rightSum[i] = sum of elements after index i

We need to create an array where:

answer[i] = |leftSum[i] - rightSum[i]|

Example:

nums = [10,4,8,3]

leftSum  = [0,10,14,22]
rightSum = [15,11,3,0]

answer = [15,1,11,22]

## Idea

### Approach 1 (Brute Force)
For every index:
- calculate the sum of all elements on the left
- calculate the sum of all elements on the right
- store the absolute difference

This directly follows the problem statement.

### Approach 2 (Running Left Sum and Right Sum)
First calculate the total sum of the array.

While traversing:
- remove current element from rightSum
- calculate difference using leftSum and rightSum
- add current element to leftSum

This avoids recalculating sums for every index.

## Approach
- Calculate total array sum
- Initialize leftSum = 0
- Traverse the array
- Update rightSum by removing current element
- Store absolute difference
- Add current element to leftSum
- Return result array

## Key Observation
Instead of calculating left and right sums repeatedly, we can maintain them while traversing the array.

This reduces unnecessary work and improves efficiency.

## When to use this
If the problem involves:
- prefix sums
- suffix sums
- range sum calculations
- repeated sum queries

→ think running sums

## Edge Cases
- Single element array
- Array containing zeros
- All elements equal
- Large values in the array

## Complexity

### Approach 1
Time: O(n²)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(n)

## Related Problems
- Running Sum of 1d Array
- Find Pivot Index
- Range Sum Query
- Product of Array Except Self