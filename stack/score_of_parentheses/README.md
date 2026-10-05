# Score of Parentheses
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/score-of-parentheses/  
Difficulty: Medium  
Pattern: Stack (Nested Score Accumulation)

## What I understood
A balanced parentheses string scores as follows: `()` has score 1, `AB` (two balanced parts next to each other) scores `A's score + B's score`, and `(A)` (a balanced part wrapped in one more pair) scores `2 * A's score`. Compute the total score of the given string.

## Example
```
Input
s = "(()(()))"
Output
6
```
```
Input
s = "()"
Output
1
```
```
Input
s = "(())"
Output
2
```

## Idea
Each level of nesting needs its own running score, since a closing bracket's contribution depends on whether anything was INSIDE it (score doubles) or it was an immediate empty pair (score is exactly 1). A stack naturally represents nesting, each `(` opens a fresh scoring scope, each `)` closes the current scope and folds its result into the PARENT scope using the two scoring rules.

## Approach: Stack of Partial Scores, Combine on Closing Bracket
- Push a `0` to seed the outermost (base) scope.
- On `(`: push a new `0`, starting a fresh scope for whatever comes next.
- On `)`: pop the current scope's accumulated score (`inner`).
  - If `inner == 0`, this was an immediate `()` pair with nothing inside, contributes exactly 1.
  - Otherwise, something was nested inside, contributes `2 * inner`.
  - Add this contribution directly into the now-exposed PARENT scope (`st.top() += score`), this handles BOTH the "wrap" rule (nesting doubles) and the "concatenation" rule (sibling scores just add up) in one step.
- Return the final remaining value on the stack, which represents the total score for the whole string.

## Key Observation
Folding each closed scope's result directly into its parent (rather than keeping scores separate and summing at the end) is what naturally implements the concatenation rule `AB` for free, siblings at the same nesting level just keep accumulating into the same stack slot as they're each closed in turn.

## When to use this
If problem involves:
- Scoring or evaluating a nested bracket structure where depth affects the computed value
→ Think **stack holding one accumulator per nesting level**, folding each closed level's result into its parent on the way out, this handles both nesting and sibling combination through the same mechanism.

## Edge Cases
- Single pair `()` (score 1, base case).
- Deeply nested single chain like `((()))` (each level doubles the one inside).
- Multiple sibling groups at the same level like `()()()` (scores simply add).
- Mixed nesting and siblings together.

## Complexity
### Approach
Time: **O(n)**              
Space: **O(n)** - stack storage, bounded by maximum nesting depth

where:
- `n` = length of string s

## Related Problems
- Maximum Nesting Depth of the Parentheses
- Valid Parentheses
- Reverse Substrings Between Each Pair of Parentheses
- Remove Outermost Parentheses