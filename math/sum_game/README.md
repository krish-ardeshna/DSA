# Sum Game
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sum-game/  
Difficulty: Hard  
Pattern: Game Theory + Math

## What I understood
String `num` has even length, digits and `'?'` characters. Alice and Bob alternate turns replacing a `'?'` with a digit 0-9 (Alice wants final left-half-sum != right-half-sum, Bob wants them equal). Both play optimally. Return true if Alice wins.

## Example
```
Input
num = "5023"
Output
false
```
```
Input
num = "0??2"
Output
false
```

## Idea
Reduces to pure counting/parity analysis, no actual game simulation needed. Split string into two halves, count known digit sum and number of `'?'` in each half separately. Two cases decide the winner:
- If total `'?'` count is odd → Alice always wins (she gets to make the last move, guaranteeing an imbalance she controls).
- If total `'?'` count is even → outcome depends on whether the "forced" difference (based on known sums and equal-split `'?'` filling at average value 4.5 each, doubled to avoid fractions via the `9 * diff / 2` formula) is nonzero.

## Approach: Count Digits/Question Marks Per Half + Parity Case Analysis
- Split `num` at midpoint; accumulate `leftSum`/`rightSum` (known digits) and `leftQ`/`rightQ` (question mark counts) per half.
- If `(leftQ + rightQ)` is odd → return true immediately (Alice wins via last-move advantage).
- Else, check if `leftSum - rightSum != 9 * (rightQ - leftQ) / 2` — if true, Alice wins (an unavoidable imbalance exists); if false, Bob forces equality.

## Key Observation
This is a known derived result specific to this game's structure — with optimal play, each pair of `'?'` (one per player's turn) effectively averages to summing 9 across the pair (since one player pushes a value up, the other down, canceling toward a fixed total). The parity of total `'?'` count is the decisive first-order factor; the exact formula for the even case comes from analyzing this cancellation behavior, not something to re-derive via simulation.

## When to use this
If problem involves:
- Turn-based game filling in unknowns (blanks/question marks) with adversarial objectives
- Outcome reducible to counting/parity rather than needing to simulate every move
→ Think **split into known-value sum + unknown-count, analyze parity and forced-difference formulas** specific to the game's turn structure.

## Edge Cases
- No `'?'` at all (deterministic outcome based purely on `leftSum` vs `rightSum`).
- All `'?'` (fully symmetric game).
- Odd total `'?'` count (Alice always wins regardless of digit values).
- Already balanced known sums with even `'?'` count split evenly between halves.

## Complexity
### Approach
Time: **O(n)** — single pass to count sums and question marks       
Space: **O(1)**

where:
- `n` = length of the string

## Related Problems
- Stone Game
- Stone Game IX
- Predict the Winner
- Can I Win