# Implement Queue using Stacks

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/implement-queue-using-stacks/  
Difficulty: Easy  
Pattern: Stack / Design

## What I understood
We need to implement a queue using only stack operations.

A queue follows:

First In First Out (FIFO)

while a stack follows:

Last In First Out (LIFO)

We must support:
- push()
- pop()
- peek()
- empty()

Example:

push(1)
push(2)

peek() = 1
pop() = 1

empty() = false

## Idea
Use two stacks:

- inputStack
- outputStack

New elements are always pushed into inputStack.

When we need the front element:
- move all elements from inputStack to outputStack
- this reverses their order
- the oldest element becomes the top of outputStack

This allows stack operations to simulate queue behavior.

## Approach
- Push new elements into inputStack
- If outputStack is empty:
  - transfer all elements from inputStack to outputStack
- For pop():
  - remove and return top of outputStack
- For peek():
  - return top of outputStack
- For empty():
  - check both stacks

## Key Observation
Moving elements from one stack to another reverses their order.

This reversal converts LIFO behavior into FIFO behavior.

## When to use this
If the problem involves:
- implementing one data structure using another
- queue simulation
- order reversal

→ think two stacks

## Edge Cases
- Single element
- Multiple pushes before pop
- Multiple consecutive pops
- Empty queue

## Complexity
Push: O(1)  
Pop: O(1) amortized  
Peek: O(1) amortized  
Empty: O(1)

Space: O(n)

## Related Problems
- Implement Stack using Queues
- Min Stack
- Design Circular Queue
- Design Circular Deque