# Kth Largest Element in a Stream

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/  
Difficulty: Easy  
Pattern: Heap (Priority Queue)

## What I understood
Design a class that continuously receives integers from a stream and returns the kth largest element after each insertion.

## Example

```
Input
["KthLargest","add","add","add","add","add"]
[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]

Output
[null,4,5,5,8,8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4,5,8,2]);
kthLargest.add(3);  // return 4
kthLargest.add(5);  // return 5
kthLargest.add(10); // return 5
kthLargest.add(9);  // return 8
kthLargest.add(4);  // return 8
```

## Idea
Maintain only the `k` largest elements seen so far.

A min heap keeps the smallest among these `k` elements at the top, which is exactly the kth largest element in the stream.

## Approach: Min Heap
- Build a min heap from the initial numbers.
- Whenever the heap size exceeds `k`, remove the smallest element.
- For every new value:
  - Insert it into the heap.
  - Remove the smallest element if the heap size exceeds `k`.
- The top of the heap always represents the kth largest element.

## Key Observation
The kth largest element is the smallest element among the largest `k` elements.

Keeping only `k` elements avoids storing and sorting the entire stream after every insertion.

## When to use this
If the problem involves:
- Kth largest/smallest element
- Streaming data
- Dynamic top-k queries
- Frequent insertions

→ Think **Min Heap of Size K**.

## Edge Cases
- Empty initial array.
- `k = 1`.
- Duplicate values.
- Negative numbers.

## Complexity

### Approach
Constructor:
- Time: **O(n log k)**
- Space: **O(k)**

Add:
- Time: **O(log k)**
- Space: **O(k)**

where:
- `n` = initial number of elements
- `k` = required rank

## Related Problems
- Kth Largest Element in an Array
- Top K Frequent Elements
- Find Median from Data Stream
```