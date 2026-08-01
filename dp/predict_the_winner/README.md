# Predict the Winner

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/predict-the-winner/  
Difficulty: Medium  
Pattern: Dynamic Programming, Minimax, Game Theory

## What I understood

Two players take turns picking either the leftmost or rightmost number from the array.

Both players play optimally. Determine whether Player 1 can guarantee a win (or a tie, which also counts as a win).

## Example

```
Input
nums = [1,5,2]

Output
false
```

## Idea

Instead of tracking both players' scores separately, track the maximum score difference the current player can achieve over the opponent.

At every turn, choose the move that maximizes this score difference. If the final difference is non-negative, Player 1 can guarantee a win.

## Approach 1: Recursion (Minimax)

- At every turn, choose either the leftmost or rightmost number.
- Since the opponent also plays optimally, subtract the opponent's best possible score difference.
- Return the maximum score difference obtainable.

## Approach 2: 2D DP (Tabulation)

- Let `dp[i][j]` represent the maximum score difference the current player can achieve from subarray `[i...j]`.
- Initialize the diagonal with the array values.
- Build the DP table for increasing subarray lengths.
- Return whether `dp[0][n-1]` is non-negative.

## Approach 3: 1D DP (Space Optimized)

- Observe that each DP state depends only on the current and previous rows.
- Compress the 2D DP table into a single array.
- Update the array from right to left while preserving dependencies.

## Approach 4: Mathematical Observation + 1D DP

- If the array length is even, Player 1 can always guarantee a win by choosing either the even-indexed or odd-indexed positions throughout the game.
- For odd-length arrays, use the space-optimized DP approach.

## Key Observation

Instead of tracking each player's score separately, track the **maximum score difference** the current player can achieve over the opponent.

For any subarray `[i...j]`:

```
difference = max(
    nums[i] - difference(i + 1, j),
    nums[j] - difference(i, j - 1)
)
```

If the final score difference is non-negative, Player 1 can guarantee at least a tie, which counts as a win.

Additionally, when the array length is even, Player 1 can always guarantee a win by committing to either the even-indexed or odd-indexed positions, making DP unnecessary.

## When to use this

If the problem involves:
- Two-player optimal game
- Minimax decisions
- Interval DP
- Score difference optimization

→ Think **Minimax + Dynamic Programming**.

## Edge Cases

- Single element.
- Two elements.
- Even-length array.
- Odd-length array.
- All values equal.
- Strictly increasing or decreasing values.

## Complexity

### Approach 1

Time: **O(2ⁿ)**

Space: **O(n)**

### Approach 2

Time: **O(n²)**

Space: **O(n²)**

### Approach 3

Time: **O(n²)**

Space: **O(n)**

### Approach 4

Time: **O(n²)**

Space: **O(n)**

## Related Problems

- Stone Game
- Stone Game II
- Stone Game III
- Optimal Strategy for a Game (GFG)