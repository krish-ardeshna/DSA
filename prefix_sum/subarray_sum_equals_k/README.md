# Subarray Sum Equals K

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/  
Difficulty: Medium  
Pattern: Prefix Sum / Hash Map

## What I understood
We are given an integer array and an integer k.

We need to count the number of continuous subarrays whose sum equals k.

Example:

nums = [1,1,1]

k = 2

Output = 2

## Idea
Maintain the prefix sum while traversing the array.

For every current prefix sum:

currentSum

we need to know whether there exists a previous prefix sum:

currentSum - k

If it exists, then every occurrence of that prefix sum forms a valid subarray ending at the current index.

Use a hash map to store the frequency of every prefix sum.

## Approach
- Initialize a hash map with:
  - prefix sum 0 having frequency 1
- Traverse the array
- Update the current prefix sum
- Check whether (currentSum - k) exists
- Add its frequency to the answer
- Store the current prefix sum in the hash map
- Return the final count

## Key Observation
If:

PrefixSum(j) - PrefixSum(i) = k

then:

PrefixSum(i) = PrefixSum(j) - k

Instead of checking every subarray, we only need to know how many times the required prefix sum has already appeared.

## When to use this
If the problem involves:
- counting subarrays
- target sum
- prefix sums
- hash map lookups

→ think Prefix Sum + Hash Map

## Edge Cases
- Negative numbers
- Multiple valid subarrays
- Array containing zeros
- k = 0
- Single element array

## Complexity
Time: O(n)  
Space: O(n)

## Related Problems
- Continuous Subarray Sum
- Maximum Size Subarray Sum Equals k
- Running Sum of 1d Array
- Product of Array Except Self