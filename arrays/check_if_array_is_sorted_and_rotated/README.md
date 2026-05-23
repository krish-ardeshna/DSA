# Check if Array Is Sorted and Rotated

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/  
Difficulty: Easy  
Pattern: Arrays

## What I understood
A sorted and rotated array can have at most one position where the order decreases.

Example:
3 4 5 1 2

Only one break exists:
5 > 1

That means the array was originally sorted and then rotated.

## Idea
Traverse the array and count how many times:
nums[i] > nums[i + 1]

Since the array is circular,
the last element should also be compared with the first element.

If the count becomes greater than 1,
the array cannot be sorted and rotated.

## Approach
- Initialize count = 0
- Traverse array
- Compare current element with next element
- Use modulo for circular comparison
- Return true if count <= 1

## Key Observation
A valid sorted rotated array can only have one "drop" in increasing order.

More than one break means the sorted order is violated.

## When to use this
If the problem involves:
- rotated arrays
- circular traversal
- checking sorted structure

→ count order breaks

## Edge Cases
- Already sorted array
- Array with duplicates
- Single element array

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Find Minimum in Rotated Sorted Array
- Search in Rotated Sorted Array
- Rotate Array