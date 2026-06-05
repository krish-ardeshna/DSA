# Valid Parentheses

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/valid-parentheses/  
Difficulty: Easy  
Pattern: Stack

## What I understood
We are given a string containing only brackets.

A string is valid if:
- every opening bracket has a matching closing bracket
- brackets close in the correct order
- every closing bracket matches the most recent unmatched opening bracket

Example:

()[]{}

Answer = true

Example:

([)]

Answer = false

## Idea
Use a stack to keep track of opening brackets.

For every character:
- push opening brackets onto the stack
- when a closing bracket appears:
  - check whether the stack is empty
  - verify that the top element is the matching opening bracket
  - remove the matched bracket

At the end:
- the stack should be empty for a valid string

## Approach
- Create an empty stack
- Traverse the string
- Push opening brackets into the stack
- For closing brackets:
  - if stack is empty, return false
  - if top does not match, return false
  - otherwise pop the stack
- Return whether the stack is empty

## Key Observation
A closing bracket must always match the most recent unmatched opening bracket.

This follows the Last In First Out (LIFO) property of a stack.

## When to use this
If the problem involves:
- matching brackets
- nested structures
- balanced expressions

→ think stack

## Edge Cases
- Empty string
- Single bracket
- Only opening brackets
- Only closing brackets
- Incorrect nesting
- Multiple valid nested brackets

## Complexity
Time: O(n)  
Space: O(n)

## Related Problems
- Min Stack
- Daily Temperatures
- Remove Outermost Parentheses
- Next Greater Element I