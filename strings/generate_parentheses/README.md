# Generate Parentheses
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/generate-parentheses/  
Difficulty: Medium  
Pattern: Backtracking (Constrained Choice Generation)

## What I understood
Given `n` pairs of parentheses, generate all combinations of WELL-FORMED parentheses strings (every string must be a valid sequence, balance never goes negative, ends balanced).

## Example
```
Input
n = 3
Output
["((()))","(()())","(())()","()(())","()()()"]
```
```
Input
n = 1
Output
["()"]
```

## Idea
Build the string character by character, at each step only allowing a choice that CANNOT lead to an invalid result later, rather than generating everything and filtering afterward. An opening bracket is allowed as long as not all `n` have been used yet, a closing bracket is only allowed if there's currently an unmatched open bracket to close, this keeps every PARTIAL string on the path always extendable into something valid, and avoids ever constructing nor backtracking out of hopeless branches.

## Approach: Backtrack Tracking Open/Close Counts, Prune Invalid Branches
- Base case: once `curr` reaches length `2*n`, it's a complete valid string (guaranteed by the constraints enforced along the way), record it.
- Try adding `(` only if `open < n` (haven't used all opens yet), recurse, then backtrack (undo the push).
- Try adding `)` only if `close < open` (there's an unmatched open bracket to pair with), recurse, then backtrack.
- Both branches are tried from every state, the two guard conditions are what make this pure backtracking instead of brute-force-then-filter.

## Key Observation
The condition `close < open` is the key constraint, it's exactly the real-time version of "balance never goes negative", by only ever allowing a close when it strictly trails the open count, every prefix generated along the way is automatically valid, so no invalid complete string can ever be produced.

## When to use this
If problem involves:
- Generating all valid combinations/sequences under a structural constraint (balance, ordering, counts)
→ Think **backtracking with constraint-checked choices at each step**, prune branches the moment they become invalid, rather than generating freely and filtering at the end.

## Edge Cases
- `n = 0` (only valid output is the empty string, though problem typically constrains `n >= 1`).
- `n = 1` (single pair, only one valid arrangement).
- Larger `n` (exponential growth in valid combinations, specifically the Catalan number for that `n`).

## Complexity
### Approach
Time: **O(4^n / sqrt(n))** - bounded by the nth Catalan number, the number of valid sequences       
Space: **O(4^n / sqrt(n))** - output storage, plus O(n) recursion depth

where:
- `n` = number of parentheses pairs

## Related Problems
- Valid Parentheses
- Remove Invalid Parentheses
- Different Ways to Add Parentheses
- Letter Combinations of a Phone Number