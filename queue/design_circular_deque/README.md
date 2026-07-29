# Design Circular Deque

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/design-circular-deque/  
Difficulty: Medium  
Pattern: Queue, Circular Array

## What I understood
Design a deque (double-ended queue) with a fixed capacity.

The deque should support insertion, deletion, and access from both the front and rear in constant time.

## Example
```
Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]

Output
[null, true, true, true, false, 3, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
```

## Idea
Use a fixed-size circular array.

Maintain:
- `front` → index of the first element.
- `rear` → index just after the last element.
- `count` → current number of elements.

Modulo arithmetic allows both pointers to wrap around the array, making full use of the allocated space.

## Approach: Circular Array
- Store elements in a fixed-size array.
- Move `front` backward for front insertion.
- Move `rear` forward for rear insertion.
- Move pointers appropriately during deletion.
- Use `count` to determine whether the deque is empty or full.

## Key Observation
Instead of shifting elements after every insertion or deletion, only move the `front` and `rear` pointers.

Circular indexing allows all deque operations to run in constant time.

## When to use this
If the problem involves:
- Circular queue/deque
- Fixed-size buffer
- Wrap-around indexing
- Constant-time insert/delete

→ Think **Circular Array**.

## Edge Cases
- Insert into a full deque.
- Delete from an empty deque.
- Capacity of `1`.
- Pointer wrap-around after multiple operations.

## Complexity

### Approach
Time:
- Insert Front: **O(1)**
- Insert Last: **O(1)**
- Delete Front: **O(1)**
- Delete Last: **O(1)**
- Get Front: **O(1)**
- Get Rear: **O(1)**

Space: **O(k)**

where `k` is the deque capacity.

## Related Problems
- Design Circular Queue
- Implement Queue using Stacks
- Implement Stack using Queues