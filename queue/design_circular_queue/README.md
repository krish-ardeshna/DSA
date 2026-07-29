# Design Circular Queue

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/design-circular-queue/  
Difficulty: Medium  
Pattern: Queue, Circular Array

## What I understood
Design a queue with a fixed capacity.

The queue should support insertion, deletion, and access to the front and rear elements in constant time.

## Example
```
Input
["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
[[3],[1],[2],[3],[4],[],[],[],[4],[]]

Output
[null,true,true,true,false,3,true,true,true,4]

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

Move the pointers using modulo arithmetic so they wrap around the array instead of shifting elements.

## Approach: Circular Array
- Store elements in a fixed-size array.
- Insert at `rear` and move it forward.
- Delete from `front` and move it forward.
- Track the current size using `count`.
- Use modulo arithmetic to wrap indices.

## Key Observation
A circular array eliminates the need to shift elements after every deletion.

Moving the `front` and `rear` pointers with modulo arithmetic allows all queue operations to run in constant time.

## When to use this
If the problem involves:
- Circular queue
- Fixed-size buffer
- Wrap-around indexing
- Constant-time queue operations

→ Think **Circular Array**.

## Edge Cases
- Insert into a full queue.
- Delete from an empty queue.
- Capacity of `1`.
- Pointer wrap-around after multiple operations.

## Complexity

### Approach
Time:
- Enqueue: **O(1)**
- Dequeue: **O(1)**
- Front: **O(1)**
- Rear: **O(1)**
- Is Empty: **O(1)**
- Is Full: **O(1)**

Space: **O(k)**

where `k` is the queue capacity.

## Related Problems
- Design Circular Deque
- Implement Queue using Stacks
- Implement Stack using Queues