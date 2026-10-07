# Remove Invalid Parentheses
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-invalid-parentheses/  
Difficulty: Hard  
Pattern: DFS Backtracking (Forward Pass Then Mirrored Backward Pass)

## What I understood
Given a string with letters, `(`, and `)`, remove the MINIMUM number of parentheses so the result is valid. Return ALL distinct valid results achievable with that minimum removal count.

## Example
```
Input
s = "()())()"
Output
["()()()","(())()"]
```
```
Input
s = "(a)())()"
Output
["(a)()()","(a())()"]
```

## Idea
Scan left to right tracking balance, the FIRST point where balance goes negative marks an excess `)` somewhere before it. Branch over every CANDIDATE `)` in the unresolved region that could be the one removed (skipping consecutive duplicate `)` at the same position to avoid generating duplicate results), recurse on each resulting string. Once a full left-to-right pass completes with no negative balance, excess `(` might still remain, handle that by REVERSING the string and swapping which character counts as open/close, then running the exact same logic again. Only once BOTH directions pass cleanly is a result valid, it gets reversed back and recorded.

## Approach: Detect First Invalid Point, Branch Over Candidate Removals, Flip Direction
- `dfs(s, start, last, open, close)`: scan from `start`, tracking balance using the current `open`/`close` character roles.
- The moment balance goes negative, try removing EACH valid candidate `close` character between `last` and the current invalid position (skipping duplicates of the same removable character in a row, this is the key dedup trick avoiding producing the same string multiple ways). For each candidate, build the string with that character removed, recurse with `start` resuming at the invalid index and `last` moved to the removal point (prevents reconsidering already-cleared regions).
- If the loop finishes with no negative balance (this direction is now clean): if currently processing OPEN parens (first pass), reverse the string and recurse again swapping roles (now hunting excess `(` as if they were the "closing" bracket in reverse). If this was ALREADY the second (reversed) pass, the string is fully valid, reverse it back to original orientation and record it.

## Key Observation
Reversing the string and swapping open/close roles elegantly reuses the EXACT same removal logic for both directions, excess `)` are naturally caught scanning forward, excess `(` become "excess closing brackets" when the string is reversed and roles are flipped, no separate logic is needed for the second direction. The duplicate-skip check (`j == last || s[j-1] != close`) prevents branching into removing two adjacent identical brackets as if they were different choices, which would otherwise produce the same resulting string multiple times.

## When to use this
If problem involves:
- Minimum removals to fix a bracket-validity violation, needing ALL optimal results
→ Think **DFS branching over every candidate removal at the first violation point**, with a duplicate-skip to avoid redundant branches, and a direction-flip trick (reverse + swap roles) to handle both excess-open and excess-close cases with one shared routine.

## Edge Cases
- String already valid (both passes complete with no invalid balance found immediately, returns the string unchanged).
- String with no parentheses at all (trivially valid).
- Multiple distinct valid results achievable with the same minimum removal count (all captured).
- String that's letters only interspersed among many invalid brackets.

## Complexity
### Approach
Time: **O(2^n)** worst case, each removal decision branches, though the duplicate-skip and immediate-invalid-detection prune significantly in practice          
Space: **O(n)** per recursive call for string copies, plus recursion depth

where:
- `n` = length of string s

## Related Problems
- Valid Parentheses
- Minimum Add to Make Parentheses Valid
- Valid Parenthesis String
- Different Ways to Add Parentheses