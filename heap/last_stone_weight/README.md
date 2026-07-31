# Last Stone Weight

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/last-stone-weight/  
Difficulty: Easy  
Pattern: Heap (Priority Queue)

## What I understood

Each turn, pick the two heaviest stones.

- If both have the same weight, both are destroyed.
- Otherwise, the lighter stone is destroyed, and the heavier stone becomes `y - x`.

Repeat until at most one stone remains.

## Example

```
Input
stones = [2,7,4,1,8,1]

Output
1
```

## Idea

The problem repeatedly requires access to the two largest elements.

A max heap efficiently provides the largest stone in `O(log n)` time after every update.

## Approach: Max Heap

- Insert all stones into a max heap.
- While more than one stone remains:
  - Remove the two largest stones.
  - If they are different, insert their difference back into the heap.
- Return the remaining stone, or `0` if none remain.

## Key Observation

The only operation performed repeatedly is finding the two largest stones.

A max heap is designed exactly for this operation.

## When to use this

If the problem involves:
- Repeatedly finding the largest element
- Dynamic insertion and deletion
- Priority-based processing
- Top element after every update

→ Think **Max Heap (Priority Queue)**.

## Edge Cases

- Only one stone.
- All stones have equal weight.
- Final stone weight becomes `0`.
- Large number of stones.

## Complexity

### Approach

Time: **O(n log n)**

Space: **O(n)**

where:
- `n` = number of stones

## Related Problems

- Kth Largest Element in a Stream
- Kth Largest Element in an Array
- Top K Frequent Elements
- Furthest Building You Can Reach