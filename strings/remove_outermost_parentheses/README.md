# Remove Outermost Parentheses
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-outermost-parentheses/  
Difficulty: Easy  
Pattern: String - Running Depth Counter

## What I understood
A valid parentheses string splits into "primitive" parts, each a minimal balanced group like `(...)`. Remove the outermost pair of every primitive part and return what's left, concatenated.

## Example
```
Input
s = "(()())(())"
Output
"()()()"
```
```
Input
s = "(()())(())(()(()))"
Output
"()()()()(())"
```
```
Input
s = "()()"
Output
""
```

## Idea
The outermost brackets of a primitive part are exactly the ones sitting at the boundary of depth 0. An opening bracket that takes depth from 0 to 1 is outer. A closing bracket that brings depth back to 0 is outer. Every other bracket is kept. One running depth counter is enough to tell which is which.

## Approach: Skip Brackets at Depth 0 Boundary While Scanning
- Keep `depth = 0`.
- On `(`: add it to the answer only if `depth > 0` already (so it is not the outer opener), then `depth++`.
- On `)`: `depth--` first, then add it only if `depth > 0` still (so it is not the outer closer).
- Return the built string.

## Key Observation
The order of the depth update differs between the two brackets. An opener checks depth BEFORE incrementing, a closer checks depth AFTER decrementing. In both cases the check is asking the same question: is this bracket sitting on the depth-0 boundary?

## When to use this
If problem involves:
- Stripping or isolating the top-level structure of a balanced bracket string
- Decisions that depend only on the current nesting level
→ Think **single depth counter, no stack needed**.

## Edge Cases
- Single primitive like `()` (result is empty string).
- Only sibling primitives like `()()()` (result is empty string).
- One deeply nested primitive like `((()))` (result is `(())`).
- Empty input (empty output).

## Complexity
### Approach
Time: **O(n)**      
Space: **O(n)** for the output string, O(1) extra

where:
- `n` = length of string s

## Related Problems
- Maximum Nesting Depth of the Parentheses
- Valid Parentheses
- Score of Parentheses
- Minimum Add to Make Parentheses Valid