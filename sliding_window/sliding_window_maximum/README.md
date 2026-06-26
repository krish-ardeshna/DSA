# Sliding Window Maximum

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sliding-window-maximum/  
Difficulty: Hard  
Pattern: Sliding Window / Monotonic Queue

## What I understood
Given an array and a window of size k, we need to find the maximum element in every sliding window.

As the window moves one position to the right, report the maximum element for each window.

Example:

nums = [1,3,-1,-3,5,3,6,7]

k = 3

Output = [3,3,5,5,6,7]

## Idea

### Approach 1 (Max Heap)
Maintain a max heap storing:

- value
- index

For every element:
- insert it into the heap
- remove elements that are outside the current window
- the heap top always gives the current maximum

### Approach 2 (Monotonic Deque)
Maintain a deque containing indices in decreasing order of their values.

For every element:
- remove indices outside the current window
- remove smaller elements from the back
- insert the current index

The front of the deque always stores the maximum element of the current window.

## Approach
- Traverse the array
- Maintain only valid window elements
- Update the data structure
- Record the maximum once the first window is formed
- Continue until the end of the array

## Key Observation
The maximum element is only affected when:

- it leaves the window
- a larger element enters the window

A monotonic deque efficiently maintains candidates for the maximum without unnecessary comparisons.

## When to use this
If the problem involves:
- sliding windows
- maximum or minimum in a window
- efficient window updates

→ think monotonic deque

## Edge Cases
- k = 1
- k = array size
- All elements equal
- Negative numbers
- Strictly increasing or decreasing arrays

## Complexity

### Approach 1
Time: O(n log n)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(k)

## Related Problems
- Sliding Window Median
- Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
- Daily Temperatures
- Next Greater Element I