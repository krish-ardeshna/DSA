# Valid Parenthesis String
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/valid-parenthesis-string/  
Difficulty: Medium  
Pattern: Greedy (Balance Range Tracking)

## What I understood
String contains `(`, `)`, and `*`, where `*` can be treated as EITHER `(`, `)`, or an empty string. Determine if there's SOME valid interpretation of every `*` that makes the whole string a valid parentheses sequence.

## Example
```
Input
s = "(*))"
Output
true
```
```
Input
s = "(*)"
Output
true
```
```
Input
s = "(()"
Output
false
```

## Idea
Rather than branching into every possible interpretation of each `*` (exponential), track the RANGE of possible open-bracket counts simultaneously: `low` is the balance assuming every `*` so far was used as unhelpfully as possible (as `)` or empty), `high` is the balance assuming every `*` was used as generously as possible (as `(`). As long as this range stays valid throughout (never entirely negative) and can include zero at the very end, some valid assignment of the `*`s exists.

## Approach: Track Min and Max Possible Open-Count Simultaneously
- `(`: both `low` and `high` increase (definite open).
- `)`: both `low` and `high` decrease (definite close).
- `*`: `low` decreases (pessimistic, treat as close), `high` increases (optimistic, treat as open).
- If `high` ever drops below 0, even the MOST generous interpretation can't recover, no valid assignment exists from here, return false immediately.
- Clamp `low` to 0 whenever it goes negative, a negative `low` just means "this pessimistic path is already broken", but since `*` could also have been empty or open instead, 0 is still a reachable state, not an invalid one, so cap rather than fail.
- At the end, a valid assignment exists if and only if `low == 0` is achievable, meaning zero is within the final reachable range.

## Key Observation
Clamping `low` at 0 (instead of letting it go negative or failing early) is the key insight, unlike `high`, a negative `low` doesn't mean failure, it just means that specific pessimistic path isn't realizable, but some less pessimistic choice for earlier `*`s could still land exactly on 0, which remains tracked correctly by capping.

## When to use this
If problem involves:
- Validity checking where some characters are "wildcards" with multiple possible interpretations
→ Think **track the full RANGE of possible states (min and max) simultaneously** instead of branching into every combination, collapsing an exponential search into a single linear pass.

## Edge Cases
- String of only `*` characters (always valid, can resolve to empty).
- Unbalanced definite brackets that no `*` substitution can fix (e.g., more `)` than any arrangement of `*` and `(` can match).
- `*` needed to act as empty string specifically (handled implicitly, since the range naturally includes "not using" the `*` as either bracket).
- Empty string (trivially valid).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = length of string s

## Related Problems
- Valid Parentheses
- Minimum Add to Make Parentheses Valid
- Check if a Parentheses String Can Be Valid
- Remove Invalid Parentheses