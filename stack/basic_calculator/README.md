# Basic Calculator

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/basic-calculator/  
Difficulty: Hard  
Pattern: Stack

## What I understood
We are given a mathematical expression containing:

- integers
- '+' operator
- '-' operator
- parentheses '(' and ')'
- spaces

We need to evaluate the expression and return the result.

Example:

s = "(1+(4+5+2)-3)+(6+8)"

Answer = 23

## Idea
Use a stack to store the state before entering a parenthesized expression.

Whenever we encounter:
- a number → build the current number
- '+' or '-' → apply the previous number to the result
- '(' → save the current result and sign
- ')' → finish the current expression and merge it with the previous one

This allows nested expressions to be evaluated correctly.

## Approach
- Traverse the string character by character
- Build numbers using consecutive digits
- Maintain:
  - current result
  - current number
  - current sign
- On '+' or '-':
  - add the current number to the result using its sign
  - update the sign
- On '(':
  - store current result and sign in the stack
  - start a new expression
- On ')':
  - finish the current expression
  - combine it with the previous expression stored in the stack
- Return the final result

## Key Observation
Parentheses create a new expression scope.

By storing the current result and sign before entering parentheses, we can correctly evaluate nested expressions and merge them back when the closing parenthesis is reached.

## When to use this
If the problem involves:
- expression evaluation
- nested parentheses
- maintaining previous computation states

→ think stack

## Edge Cases
- Single number
- Negative result
- Nested parentheses
- Multi-digit numbers
- Expressions containing spaces

## Complexity
Time: O(n)  
Space: O(n)

## Related Problems
- Basic Calculator II
- Basic Calculator III
- Evaluate Reverse Polish Notation
- Valid Parentheses