# Stone Game

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/stone-game/  
Difficulty: Medium  
Pattern: Dynamic Programming, Minimax, Game Theory

## What I understood

Alice and Bob take turns picking an entire pile of stones from either the beginning or the end of the row.

Both players play optimally. Determine whether Alice (Player 1) can guarantee a win.

## Example

```
Input
piles = [5,3,4,5]

Output
true
```

## Idea

Both players play optimally.

Instead of tracking each player's score separately, track the maximum score difference the current player can achieve over the opponent.

For this specific problem, an even stronger observation exists: because the number of piles is always even and the total number of stones is odd, Player 1 can always force a win.

## Approach 1: Recursion (Minimax)

- Pick either the leftmost or rightmost pile.
- The opponent then plays optimally.
- Compute the maximum score difference obtainable from both choices.

## Approach 2: Memoization (Top-Down DP)

- Store the result for every subarray `[i...j]`.
- Reuse previously computed states instead of solving them again.
- Return whether the final score difference is positive.

## Approach 3: Tabulation (Bottom-Up DP)

- Let `dp[i][j]` represent the maximum score difference for subarray `[i...j]`.
- Initialize single piles.
- Fill the DP table for increasing subarray lengths.
- Return whether `dp[0][n-1]` is positive.

## Approach 4: Mathematical Observation (Game Theory)

- The number of piles is always even.
- Alice can commit to taking either all even-indexed piles or all odd-indexed piles.
- Before the game begins, she chooses whichever set has the larger total.
- Therefore, she is guaranteed to collect more stones than Bob.

## Key Observation

For the DP approaches, let:

```
difference(i, j)
```

represent the maximum score difference the current player can achieve from piles `[i...j]`.

The recurrence is:

```
difference = max(
    piles[i] - difference(i + 1, j),
    piles[j] - difference(i, j - 1)
)
```

However, this problem has a stronger mathematical observation.

Since:
- the number of piles is always even,
- the total number of stones is odd,

Player 1 can commit to taking either all even-indexed piles or all odd-indexed piles.

By choosing the larger of the two sets before the game starts, Player 1 is guaranteed to finish with more stones.

Therefore, the answer is always `true`.

## When to use this

If the problem involves:
- Two-player optimal game
- Minimax decisions
- Interval DP
- Score difference optimization
- Game theory

→ Think **Minimax + Dynamic Programming**, and look for mathematical observations that may simplify the solution.

## Edge Cases

- Two piles.
- Large pile values.
- Equal pile values.
- Minimum valid input.

## Complexity

### Approach 1

Time: **O(2ⁿ)**

Space: **O(n)**

### Approach 2

Time: **O(n²)**

Space: **O(n²)**

### Approach 3

Time: **O(n²)**

Space: **O(n²)**

### Approach 4

Time: **O(1)**

Space: **O(1)**

## Related Problems

- Predict the Winner
- Stone Game II
- Stone Game III
- Stone Game VII