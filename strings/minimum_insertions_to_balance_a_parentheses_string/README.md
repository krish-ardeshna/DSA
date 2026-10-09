# Minimum Insertions to Balance a Parentheses String
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/  
Difficulty: Medium  
Pattern: Greedy (Running Counter of Needed Closers)

## What I understood
Every `(` must be matched by exactly TWO consecutive `))`. Given a string of `(` and `)`, find the minimum number of insertions (of either bracket, anywhere) to make it balanced under this rule.

## Example
```
Input
s = "(()))"
Output
1
```
```
Input
s = "())"
Output
0
```
```
Input
s = "))())("
Output
3
```

## Idea
Normal bracket balancing needs one counter of open brackets. Here every `(` creates a debt of two `)`, so track `need` = number of `)` still owed. Two kinds of problems can show up while scanning:
- A `)` arrives with nothing owed, so a `(` must be inserted before it.
- A new `(` arrives while `need` is odd, meaning the previous `(` only got a single `)`, so one `)` must be inserted to complete that pair.

Both fixes can be made the moment the problem is seen, and anything still owed at the end needs insertions too.

## Approach: Track Pending ')' Needed, Fix Odd Gaps and Unmatched Closers on the Fly
- Init `ans = 0` (insertions so far), `need = 0` (closers still owed).
- On `(`:
  - If `need` is odd, the previous `(` is stuck with only one `)`. Insert a `)` (`ans++`) and pay one off (`need--`).
  - Then this `(` adds a new debt of two, `need += 2`.
- On `)`:
  - Pay one off, `need--`.
  - If `need` goes below 0, nothing was owed, so insert a `(` (`ans++`). That inserted `(` still owes one more `)`, so set `need = 1`.
- Return `ans + need`, since leftover owed closers must each be inserted.

## Key Observation
The odd-`need` check only matters when a new `(` appears. An odd `need` means a `(` got exactly one `)` and was then interrupted, because a lone `)` cannot satisfy it. Resetting `need = 1` (not 0) after inserting a `(` for an unmatched `)` is the easy-to-miss detail: the inserted `(` is already half paid by the current `)`, but still owes one more.

## When to use this
If problem involves:
- Bracket balancing where one opener needs more than one closer (or a fixed ratio)
- Minimum insertions, decided greedily as problems appear
→ Think **counter of owed closers**, fix problems immediately, add leftover debt at the end. No stack needed.

## Edge Cases
- All `)` (each pair of `))` costs one inserted `(`, an odd leftover costs an extra insertion).
- All `(` (each needs two inserted `)`, answer is `2 * count`).
- `(` followed by a single `)` then another `(` (the odd-`need` fix triggers).
- Already balanced string (answer 0).

## Complexity
### Approach
Time: **O(n)**              
Space: **O(1)**

where:
- `n` = length of string s

## Related Problems
- Minimum Add to Make Parentheses Valid
- Valid Parenthesis String
- Remove Invalid Parentheses
- Valid Parentheses