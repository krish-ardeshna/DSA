# Implement Stack using Queues

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/implement-stack-using-queues/  
Difficulty: Easy  
Pattern: Queue / Design

## What I understood
We need to implement a stack using only queue operations.

A stack follows:

Last In First Out (LIFO)

while a queue follows:

First In First Out (FIFO)

We must support:
- push()
- pop()
- top()
- empty()

Example:

push(1)

push(2)

top() = 2

pop() = 2

empty() = false

## Idea
Use a single queue.

Whenever a new element is pushed:
- insert it into the queue
- rotate all previous elements behind it

This makes the newly inserted element appear at the front of the queue.

As a result:
- front of queue always represents the top of the stack

## Approach
- Push the new element into the queue
- Rotate the remaining elements:
  - remove front element
  - insert it at the back
- Repeat until the new element reaches the front
- For pop():
  - remove and return queue front
- For top():
  - return queue front
- For empty():
  - check whether queue is empty

## Key Observation
By rotating the queue after every insertion, we can always keep the most recently inserted element at the front.

This allows a FIFO queue to behave like a LIFO stack.

## When to use this
If the problem involves:
- implementing one data structure using another
- stack simulation
- queue manipulation

→ think rotation of elements

## Edge Cases
- Single element
- Multiple consecutive pushes
- Pop after one element
- Empty structure

## Complexity
Push: O(n)  
Pop: O(1)  
Top: O(1)  
Empty: O(1)

Space: O(n)

## Related Problems
- Implement Queue using Stacks
- Min Stack
- Design Circular Queue
- Design Circular Deque