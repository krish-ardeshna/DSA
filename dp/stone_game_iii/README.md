# Stone Game III
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/stone-game-iii/  
Difficulty: Hard  
Pattern: Game Theory + DP

## What I understood
Alice and Bob alternately take 1, 2, or 3 stones from the front of the row (Alice goes first). Both play optimally to maximize their own score. Return "Alice" if Alice's total > Bob's, "Bob" if less, "Tie" if equal.

## Example
```
Input:  
stoneValue = [1,2,3,7]
Output: "Bob"   

Input:  
stoneValue = [1,2,3,-9]
Output: "Alice"
```

---

## Approach 1: Recursion (No Memoization)

### Idea
At each index `i`, current player tries taking 1, 2, or 3 stones. Score difference (current player's gain minus opponent's best response) is what matters, not raw totals. Opponent, from their turn onward, also plays optimally — recurse to get their best diff and subtract it.

### Steps
- `solve(i)` = best score difference achievable starting at index `i`.
- Try taking `k = 1, 2, 3` stones, track running `take` sum.
- For each `k`: `best = max(best, take - solve(i+k+1))`.
- Base case: `i >= n` → return 0 (no stones left).
- Final answer sign at `solve(0)` decides winner.

### Complexity
Time: **O(3^n)** — exponential, no memo, recomputes overlapping subproblems
Space: **O(n)** — recursion stack

---

## Approach 2: Bottom-Up DP (O(n) space)

### Idea
Same recurrence as Approach 1, but computed bottom-up with a `dp` array to avoid recomputation. `dp[i]` = best score diff starting from index `i`.

### Steps
- `dp[n] = 0` (base case, no stones left).
- Iterate `i` from `n-1` down to `0`.
- For each `i`, try `k = 1, 2, 3`: `dp[i] = max(dp[i], take - dp[i+k+1])`.
- Answer at `dp[0]`.

### Complexity
Time: **O(n)** — each state computed once, O(3) work per state
Space: **O(n)** — dp array

---

## Approach 3: Bottom-Up DP (O(1) space, rolling array)

### Idea
`dp[i]` only ever depends on `dp[i+1]`, `dp[i+2]`, `dp[i+3]` — at most 3 states ahead. No need to store full array; a rolling window of size 4 (mod 4 indexing) suffices.

### Steps
- Use `dp[4]` array, indexed via `i % 4`.
- Same recurrence as Approach 2, but reads/writes go through `dp[(i+k+1) % 4]` and `dp[i % 4]`.
- Answer at `dp[0 % 4] = dp[0]` after loop ends at `i = 0`.

### Complexity
Time: **O(n)**
Space: **O(1)** — fixed-size rolling array

---

## Key Observation
Track **score difference**, not individual scores — turns a two-player optimization into a single recurrence: `dp[i] = max over k of (sum of next k stones - dp[i+k+1])`. This works because whatever the opponent doesn't get, current player effectively "gains" in the diff. Rolling array works because lookback window is fixed at 3.

## When to use this
If problem involves:
- Two players alternately picking from front/back of array, both optimal
- Need to know winner/score margin, not just max score
→ Think **score-difference DP** (`dp[i] = max(take - dp[next])`).

## Edge Cases
- All stones negative.
- Single stone / very small array (`n <= 3`).
- All stones equal → check tie logic.
- Large `n` with alternating signs.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion (no memo) | O(3^n) | O(n) |
| Bottom-Up DP (array) | O(n) | O(n) |
| Bottom-Up DP (rolling) | O(n) | O(1) |

where:
- `n` = number of stones

## Related Problems
- Stone Game
- Stone Game II
- Predict the Winner
- Nim Game