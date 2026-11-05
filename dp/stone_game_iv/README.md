# Stone Game IV
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/stone-game-iv/  
Difficulty: Hard  
Pattern: Game Theory + DP

## What I understood
There are `n` stones. Two players alternate turns (Alice first), each turn removing a non-zero perfect square number of stones. Player unable to move (0 stones left) loses. Both play optimally. Return true if Alice wins.

## Example
```
Input
n = 1
Output
true
```
```
Input
n = 2
Output
false
```
```
Input
n = 4
Output
true
```

## Idea
Current player wins at `n` stones if there exists ANY perfect square move `j*j` such that the resulting state `n - j*j` is a LOSING state for the opponent (`dp[n - j*j] == false`). This is standard game-theory DP: win if you can force opponent into a loss.

## Approach: Bottom-Up DP (Perfect Square Removal)
- `dp[i]` = true if current player wins when `i` stones remain.
- `dp[0] = false` (no stones left, current player loses — can't move).
- For each `i` from 1 to `n`, try every perfect square `j*j <= i`.
- If any `dp[i - j*j] == false` → current player can force a win → `dp[i] = true`, break early.
- Return `dp[n]`.

## Key Observation
This is a classic "Nim-like" game DP — outcome only depends on whether ANY reachable next-state is a loss for opponent, not on which specific square is removed. Early break on first winning move found is a valid optimization (don't need to check all squares once a win is confirmed).

## When to use this
If problem involves:
- Two players alternately removing items under a constrained move set
- Winner determined by forcing opponent into a "no valid move" or otherwise losing state
→ Think **DP over game states, win if any move leads to opponent's loss state**.

## Edge Cases
- `n = 0` (not per constraints, but conceptually a loss for mover).
- `n = 1` → trivially true (remove the 1 stone, opponent has 0 left).
- Perfect square `n` itself (e.g. `n = 4`) → doesn't always guarantee true, must still check DP result.
- Large `n` requiring full sqrt(n) inner loop per outer step.

## Complexity
### Approach
Time: **O(n * sqrt(n))** — outer loop n, inner loop up to sqrt(i) perfect squares
Space: **O(n)** — dp array

where:
- `n` = number of stones

## Related Problems
- Stone Game
- Stone Game II
- Stone Game III
- Predict the Winner