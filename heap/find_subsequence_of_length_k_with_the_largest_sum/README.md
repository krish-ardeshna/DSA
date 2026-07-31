# Find Subsequence of Length K With the Largest Sum

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/  
Difficulty: Easy  
Pattern: Heap, Sorting

## What I understood

Find a subsequence of length `k` having the maximum possible sum while preserving the original order of the selected elements.

## Example

```
Input
nums = [2,1,3,3], k = 2

Output
[3,3]
```

## Idea

The subsequence must contain the `k` largest values, but the final answer must preserve their original order.

Store each element with its original index, select the best `k` elements, then sort those selected elements by index.

## Approach 1: Min Heap

- Store `(value, index)` in a min heap.
- Keep only the largest `k` elements by removing the smallest whenever the heap size exceeds `k`.
- Extract the selected elements.
- Sort them by original index.
- Build the answer.

## Approach 2: Sorting

- Store `(value, index)` for every element.
- Sort by value in descending order.
- Keep the first `k` elements.
- Sort these `k` elements by their original index.
- Build the answer.

## Key Observation

The largest `k` values determine the maximum sum, while sorting the selected elements by their original indices restores the required subsequence order.

## When to use this

- Need Top K elements
- Original order must be preserved
- Selecting based on value
- Heap optimization when `k << n`

→ Think **Top K + Original Index**.

## Edge Cases

- `k = 1`
- `k = n`
- Duplicate values
- Negative numbers
- All elements equal

## Complexity

### Approach 1

Time: **O(n log k)**

Space: **O(k)**

### Approach 2

Time: **O(n log n)**

Space: **O(n)**

## Related Problems

- Kth Largest Element in a Stream
- Kth Largest Element in an Array
- Top K Frequent Elements
- Relative Ranks
```