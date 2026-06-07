# Longest Valid Parentheses

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-valid-parentheses/  
Difficulty: Hard  
Pattern: Stack

## What I understood
We are given a string containing only '(' and ')'.

We need to find the length of the longest valid (well-formed) parentheses substring.

A valid substring must have:
- matching opening and closing parentheses
- correct ordering of brackets

Example:

s = ")()())"

Longest valid substring = "()()"

Answer = 4

## Idea

### Approach 1 (Stack + Valid Array)
Use a stack to match opening and closing parentheses.

Whenever a valid pair is found:
- mark both positions as valid in an array

After processing the string:
- find the longest consecutive sequence of valid positions

### Approach 2 (Stack of Indices)
Store indices instead of characters.

Initialize the stack with -1 to act as a boundary.

For every character:
- push index of '('
- for ')', remove a matching opening bracket
- if stack becomes empty, push current index as a new boundary
- otherwise calculate the current valid length

This directly gives the length of valid substrings.

## Approach
- Create a stack and push -1
- Traverse the string
- Push indices of opening brackets
- For closing brackets:
  - pop the stack
  - if stack becomes empty, push current index
  - otherwise update maximum length using current index and stack top
- Return maximum length found

## Key Observation
The stack top always represents the last unmatched position.

Whenever a valid pair is formed, the distance between the current index and the stack top gives the length of the current valid substring.

## When to use this
If the problem involves:
- matching parentheses
- longest valid bracket sequences
- nearest unmatched positions

→ think stack with indices

## Edge Cases
- Empty string
- Single character
- All opening brackets
- All closing brackets
- Multiple separate valid substrings
- Fully valid string

## Complexity

### Approach 1
Time: O(n)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(n)

## Related Problems
- Valid Parentheses
- Generate Parentheses
- Remove Outermost Parentheses
- Minimum Remove to Make Valid Parentheses