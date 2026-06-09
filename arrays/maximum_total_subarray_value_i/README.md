# Maximum Total Subarray Value I

Platform: Contest Problem  
Problem Link: N/A  
Difficulty: Easy  
Pattern: Arrays / Greedy

## What I understood
The value of a subarray is defined as:

maximum element − minimum element

We need to maximize the total value obtained from choosing exactly k subarrays.

Example:

nums = [1,3,5,2]

Maximum element = 5

Minimum element = 1

Subarray value = 5 - 1 = 4

For k = 2

Answer = 4 × 2 = 8

## Idea
Find the maximum and minimum element in the array.

The maximum possible value of a subarray is obtained when the subarray contains both the global minimum and global maximum elements.

Therefore:

singleSubarrayValue = maxElement - minElement

Since we can choose k subarrays independently, the answer becomes:

singleSubarrayValue × k

## Approach
- Find the maximum element in the array
- Find the minimum element in the array
- Calculate their difference
- Multiply the difference by k
- Return the result

## Key Observation
The largest possible subarray value is achieved by including both the global maximum and global minimum elements.

Once this value is known, selecting k such subarrays contributes the same value each time.

## When to use this
If the problem involves:
- maximizing differences
- finding global minimum and maximum
- repeated contribution of the same optimal value

→ think about the overall range of the array

## Edge Cases
- Single element array
- All elements equal
- Negative numbers
- k = 1
- Large values of k

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Maximum Subarray
- Best Time to Buy and Sell Stock
- Maximum Difference Between Increasing Elements
- Find Minimum and Maximum Element in an Array