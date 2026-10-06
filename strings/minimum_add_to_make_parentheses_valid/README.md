# Minimum Add to Make Parentheses Valid
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/  
Difficulty: Medium  
Pattern: String - Running Counter (Unmatched Open/Close Tracking)

## What I understood
Given a string of only `(` and `)`, find the MINIMUM number of parentheses that must be ADDED (anywhere) to make the string valid.

## Example
```
Input
s = "())"
Output
1
```
```
Input
s = "((("
Output
3
```

## Idea
Every unmatched `)` encountered needs exactly one `(` added before it (nothing else to do about it once it has no open bracket to pair with, since insertions can't retroactively fix the past). Every `(` left unmatched at the very end needs exactly one `)` added after it. Both counts can be tracked in a single pass without a real stack, since only the COUNT of currently open brackets matters, not their identity.

## Approach: Track Open Count, Count Unmatched Closes Immediately
- `open` tracks how many unmatched `(` currently exist.
- On `(`: increment `open`.
- On `)`: if there's an unmatched open bracket available (`open > 0`), consume it (`open--`), this `)` is matched. Otherwise, this `)` has nothing to pair with, it will need an INSERTED `(`, increment `ans` immediately.
- After the full pass, any `open` still remaining represents unmatched `(` that will each need an inserted `)`, add `open` to `ans` at the end.
- Return `ans`.

## Key Observation
Unmatched `)` are resolved the MOMENT they're seen (added to `ans` right away), since there's no way for anything later to fix a `)` that has nothing before it to match, while unmatched `(` can only be resolved at the very END, once it's certain nothing later will pair with them.

## When to use this
If problem involves:
- Minimum insertions/deletions to balance a bracket sequence
→ Think **running counter for unmatched opens, resolve unmatched closes immediately, account for leftover opens at the end**, no actual stack needed since bracket identity doesn't matter, only counts.

## Edge Cases
- All `(` (every one needs a matching `)` appended, answer equals the count).
- All `)` (every one is immediately unmatched, answer equals the count).
- Already valid string (answer 0).
- Alternating pattern that's already balanced except for a trailing imbalance.

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = length of string s

## Related Problems
- Valid Parentheses
- Valid Parenthesis String
- Remove Invalid Parentheses
- Minimum Insertions to Balance a Parentheses String