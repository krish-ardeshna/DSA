# Maximum Nesting Depth of the Parentheses
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/  
Difficulty: Easy  
Pattern: String - Running Counter (Stack Without the Stack)

## What I understood
Given a valid parentheses string (digits, operators, and balanced parentheses), find the maximum nesting depth, meaning the largest number of parentheses open at the same time.

## Example
```
Input
s = "(1+(2*3)+((8)/4))+1"
Output
3
```
```
Input
s = "(1)+((2))+(((3)))"
Output
3
```
```
Input
s = "1+(2*3)/(2-1)"
Output
1
```

## Idea
A stack would only be used to know how many `(` are currently open, and that is just a count. Since the string is guaranteed valid, keep one integer `depth`: increment on `(`, decrement on `)`, and remember the largest value `depth` ever reached.

## Approach: Single Pass Depth Counter, Track Max
- Init `depth = 0`, `ans = 0`.
- On `(`: `depth++`, then update `ans = max(ans, depth)`.
- On `)`: `depth--`.
- Ignore every other character.
- Return `ans`.

## Key Observation
The max only needs updating when `depth` goes UP (on `(`), because a `)` can never create a new peak. No validation or matching logic is needed, since the input is guaranteed to be a valid parentheses string.

## When to use this
If problem involves:
- Nesting depth or balance of brackets in an already-valid string
- Only the count of currently open brackets matters, not their identity
→ Think **single integer counter instead of a stack**. Reach for a real stack only when different bracket types or matched contents matter.

## Edge Cases
- No parentheses at all (answer 0).
- Fully flat sequence like `()()()` (answer 1).
- One deeply nested group like `((((()))))` (depth equals the number of pairs).
- Parentheses mixed with digits and operators (non-bracket characters are ignored).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = length of string s

## Related Problems
- Valid Parentheses
- Reverse Substrings Between Each Pair of Parentheses
- Remove Outermost Parentheses
- Minimum Add to Make Parentheses Valid