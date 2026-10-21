# Unbounded Knapsack
Platform: TakeUForward (Striver's DSA Sheet)  
Problem Link: https://takeuforward.org/practice/dsa/unbounded-knapsack
Difficulty: Medium  
Pattern: DP on Subsequences (Unbounded Knapsack, Take Stays on Same Index)

## What I understood
There are `n` item types, each with a weight `wt[i]` and a value `val[i]`, and a bag that can carry at most weight `W`. Unlike the 0/1 knapsack, every item type can be taken ANY number of times. Find the maximum total value that fits in the bag.

## Example
```
Input
wt = [2, 4, 6], val = [5, 11, 13], W = 10
Output
27
```
Explanation: take the weight-4 item twice and the weight-2 item once (weight 4 + 4 + 2 = 10), value 11 + 11 + 5 = 27.

```
Input
wt = [1, 3, 4], val = [1, 4, 5], W = 7
Output
9
```
Explanation: take the weight-3 item and the weight-4 item (weight 7), value 4 + 5 = 9. Taking the weight-3 item twice and the weight-1 item once also gives 4 + 4 + 1 = 9.

```
Input
wt = [5], val = [10], W = 4
Output
0
```
Explanation: the only item is heavier than the bag, so nothing can be taken.

## Idea (shared by all three techniques)
Greedy (best value per weight first) can leave unusable space, so each choice has to be compared by what it costs in remaining capacity. That is the take / not take DP, with one change from 0/1 knapsack: an item can be reused.

**State:** `f(idx, W)` = maximum value obtainable using item types `0..idx` with a bag capacity of `W`.

**Recurrence:** for item type `idx` there are two choices:
```
notTake = f(idx - 1, W)                              (never use this item type)
take    = val[idx] + f(idx, W - wt[idx])             (use one copy, stay on the same type)
f(idx, W) = max(take, notTake)
```
The key detail is that `take` stays at `idx` instead of moving to `idx - 1`. After using one copy, the same item may be used again. In 0/1 knapsack, taking moves to `idx - 1`, which is why each item is used at most once.

**Base case (`idx == 0`):** only the first item type is left, so fill the bag with as many copies as fit: `(W / wt[0]) * val[0]`.

**Answer:** `f(n - 1, W)`.

There are only `n * (W + 1)` distinct states, each solved in O(1). The `-1` memo marker is safe because values are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, W)` result so no state is solved twice.

### Steps
- Create `dp[n][W + 1]` filled with `-1` (not computed yet).
- Call `f(n - 1, W)`.
- At `idx == 0`, return `(W / wt[0]) * val[0]`.
- If `dp[idx][W]` is filled, return it.
- Otherwise compute `notTake`, and `take` only if the item fits (`take = val[idx] + f(idx, W - wt[idx])`), store `max(take, notTake)`, return it.

### Complexity
Time: **O(n * W)**          
Space: **O(n * W)** for the dp table, plus **O(W)** recursion stack (the `take` branch can go as deep as `W / min(wt)` levels)

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill `dp[idx][w]` row by row from the first item type. Each value needs the previous row (`notTake`) and the SAME row at a smaller capacity (`take`), and both are already computed when `w` goes upward.

### Steps
- Create `dp[n][W + 1]` of zeros.
- Base row: `dp[0][w] = (w / wt[0]) * val[0]` for every capacity `w`.
- For `idx = 1 .. n - 1`, for `w = 0 .. W`:
  - `notTake = dp[idx - 1][w]`.
  - `take = val[idx] + dp[idx][w - wt[idx]]` if `wt[idx] <= w`, else `0`.
  - `dp[idx][w] = max(take, notTake)`.
- Answer is `dp[n - 1][W]`.

### Complexity
Time: **O(n * W)**          
Space: **O(n * W)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `idx` reads only the previous row and the current row. Keep two arrays: `prev` for the previous item type and `curr` for the current one.

### Steps
- `prev` holds the base row.
- For each later item type, fill `curr[w]` using `prev[w]` (not take) and `curr[w - wt[idx]]` (take, same row).
- After each row, `prev = curr`.
- Answer is `prev[W]`.

`curr[w - wt[idx]]` is already filled in the current row, because `w` goes upward and weights are at least 1, so the cell read is always at a smaller capacity.

### Complexity
Time: **O(n * W)**            
Space: **O(W)**, two arrays of size `W + 1`

---

## Key Observation
Unbounded knapsack differs from 0/1 knapsack in exactly one place: `take` calls `f(idx, ...)` instead of `f(idx - 1, ...)`. That also flips the loop direction in the space-optimized version. For 0/1 knapsack, a single row must be updated backward so an item is not used twice. Here, reusing the current row's already-updated values is exactly what is wanted, so the capacity loop goes forward. The same pattern powers Coin Change, Coin Change II and Rod Cutting. The base case assumes every weight is positive (`wt[0] >= 1`), otherwise the division is invalid.

## When to use this
If problem involves:
- Choosing items under a capacity limit to maximize a total
- Every item type can be used any number of times
→ Think **unbounded knapsack: `take` stays on the same index, `notTake` moves to the previous index**.

## Edge Cases
- Every item heavier than `W` (answer 0).
- `n = 1` (answer is `(W / wt[0]) * val[0]`).
- `W = 0` (answer 0).
- One item with a very high value-per-weight (it gets repeated until the bag is nearly full).
- Large `W` with a tiny weight (deep recursion in Approach 1, so Approaches 2 and 3 are safer).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * W) | O(n * W) + O(W) stack |
| Tabulation | O(n * W) | O(n * W) |
| Tabulation + Space Optimization | O(n * W) | O(W) |

where:
- `n` = number of item types
- `W` = capacity of the bag

## Related Problems
- 0 and 1 Knapsack
- Coin Change
- Coin Change II
- Rod Cutting