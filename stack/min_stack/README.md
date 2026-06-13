# Min Stack

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/min-stack/  
Difficulty: Medium  
Pattern: Stack / Design

## What I understood
Design a stack that supports:

- push()
- pop()
- top()
- getMin()

All operations must work in O(1) time.

The challenge is to retrieve the minimum element without traversing the entire stack.

Example:

push(-2)
push(0)
push(-3)

getMin() = -3

pop()

top() = 0

getMin() = -2

## Idea

### Approach 1 (Stack of Pairs)
Store two values together:

- current value
- minimum value seen so far

For every push:
- store the current element
- store the minimum between current element and previous minimum

This allows direct access to the minimum element from the top of the stack.

### Approach 2 (Two Stacks)
Use:
- one stack for actual values
- one stack for minimum values

Whenever an element is pushed:
- push value into the main stack
- push the updated minimum into the minimum stack

Both stacks always remain synchronized.

## Approach
- Push elements normally
- Keep track of the minimum element at every level
- Update minimum information during push
- Remove minimum information during pop
- Return current minimum in O(1) time

## Key Observation
The minimum element for every stack state can be stored while pushing.

This avoids searching through the stack whenever getMin() is called.

## When to use this
If the problem involves:
- stack design
- tracking minimum or maximum values
- constant time queries

→ store extra information while pushing

## Edge Cases
- Single element stack
- Duplicate minimum values
- Negative numbers
- Multiple consecutive pop operations

## Complexity

### Approach 1
Time: O(1) for all operations  
Space: O(n)

### Approach 2
Time: O(1) for all operations  
Space: O(n)

## Related Problems
- Valid Parentheses
- Daily Temperatures
- Next Greater Element I
- Maximum Frequency Stack