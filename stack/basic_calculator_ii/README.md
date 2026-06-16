# Basic Calculator II

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/basic-calculator-ii/  
Difficulty: Medium  
Pattern: Stack

## What I understood
We are given a mathematical expression containing:

- integers
- '+'
- '-'
- '*'
- '/'
- spaces

We need to evaluate the expression while respecting operator precedence.

Multiplication and division must be performed before addition and subtraction.

Example:

s = "3+2*2"

Answer = 7

## Idea

### Approach 1 (Stack)
Use a stack to store numbers.

For:
- '+' → push number
- '-' → push negative number
- '*' → multiply with stack top
- '/' → divide stack top by current number

At the end, sum all elements in the stack.

### Approach 2 (Constant Space Optimization)
Instead of storing every number:

Maintain:
- res = finalized result
- last = most recent term

Multiplication and division update last directly.

Addition and subtraction first add the previous term into res and then start a new term.

This removes the need for a stack.

## Approach
- Traverse the expression
- Build multi-digit numbers
- Process operators when encountered
- Respect multiplication and division precedence immediately
- Compute the final answer

## Key Observation
Addition and subtraction can be postponed.

Only multiplication and division need immediate evaluation because of operator precedence.

## When to use this
If the problem involves:
- expression evaluation
- operator precedence
- parsing mathematical expressions

→ think stack or running term evaluation

## Edge Cases
- Single number
- Multiple spaces
- Multi-digit numbers
- Expressions ending with a number
- Division resulting in truncation

## Complexity

### Approach 1
Time: O(n)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(1)

## Related Problems
- Basic Calculator
- Basic Calculator III
- Evaluate Reverse Polish Notation
- Valid Parentheses