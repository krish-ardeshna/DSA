# Range Sum Query - Immutable

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/range-sum-query-immutable/  
Difficulty: Easy  
Pattern: Prefix Sum

## What I understood
We are given an integer array.

We need to answer multiple queries asking for the sum of elements between two indices.

The array never changes after initialization.

Example:

nums = [-2,0,3,-5,2,-1]

sumRange(0,2) = 1

sumRange(2,5) = -1

## Idea
Precompute the prefix sum array.

Each element in the prefix array stores the sum of all elements before that index.

Then any range sum can be calculated in constant time using:

prefix[right + 1] - prefix[left]

## Approach
- Build the prefix sum array during initialization
- Store cumulative sums
- For every query:
  - subtract the prefix sums
- Return the range sum

## Key Observation
Instead of calculating every range sum repeatedly, compute cumulative sums once.

Each query then becomes a simple subtraction.

## When to use this
If the problem involves:
- multiple range sum queries
- immutable arrays
- cumulative sums

→ think Prefix Sum

## Edge Cases
- Single element array
- Entire array query
- Negative numbers
- left equals right

## Complexity
Initialization: O(n)  
Each Query: O(1)  
Space: O(n)

## Related Problems
- Running Sum of 1d Array
- Find Pivot Index
- Product of Array Except Self
- Subarray Sum Equals K