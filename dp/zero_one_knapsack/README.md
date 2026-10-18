# 0 and 1 Knapsack
Platform: TakeUForward (Striver's DSA Sheet)  
Problem Link: <paste TakeUForward link here>  
Difficulty: Medium  
Pattern: DP on Subsequences (0/1 Knapsack, Take / Not Take)

## What I understood
There are `n` items, each with a weight `wt[i]` and a value `val[i]`, and a bag that can carry at most weight `W`. Each item can be taken at most ONCE (that is the "0 and 1": either 0 copies or 1 copy). Find the maximum total value that fits in the bag.

## Example
```
Input
wt = [1, 2, 4, 5], val = [5, 4, 8, 6], W = 5
Output
13
```
Explanation: take items with weight 1 and 4 (total weight 5), value 5 + 8 = 13.

```
Input
wt = [1, 2, 3], val = [10, 15, 40], W = 6
Output
65
```
Explanation: all three items fit (total weight 6), value 10 + 15 + 40 = 65.

```
Input
wt = [4], val = [7], W = 3
Output
0
```
Explanation: the only item is heavier than the bag, so nothing can be taken.

## Idea (shared by all four techniques)
Greedy fails here: grabbing the item with the best value-per-weight can leave unusable space. Every item must be compared by what taking it costs in remaining capacity, which is exactly the take / not take DP.

**State:** `f(idx, W)` = maximum value obtainable using items `0..idx` with a bag capacity of `W`.

**Recurrence:** for item `idx` there are two choices:
```
notTake = f(idx - 1, W)
take    = val[idx] + f(idx - 1, W - wt[idx])      (only if wt[idx] <= W)
f(idx, W) = max(take, notTake)
```

**Base case (`idx == 0`):** only the first item remains. Take it if it fits (`wt[0] <= W`), giving `val[0]`, otherwise 0.

**Answer:** `f(n - 1, W)`.

There are only `n * (W + 1)` distinct states, and each is solved in O(1), so the DP removes the exponential blowup of trying every subset.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(idx, W)` result in a table. A `-1` marker means "not computed yet", which is safe because values are never negative.

### Steps
- Create `dp[n][W + 1]` filled with `-1`.
- Call `f(n - 1, W)`.
- At `idx == 0`, return `val[0]` if `wt[0] <= W`, else `0`.
- If `dp[idx][W]` is filled, return it.
- Otherwise compute `notTake`, and `take` only if the item fits, store `max(take, notTake)`, and return it.

### Complexity
Time: **O(n * W)**              
Space: **O(n * W)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill `dp[idx][w]` row by row, starting from the first item, so every value it needs from the previous row is already known.

### Steps
- Create `dp[n][W + 1]` of zeros.
- Base row: for every capacity `w >= wt[0]`, set `dp[0][w] = val[0]`.
- For `idx = 1 .. n - 1`, for `w = 0 .. W`:
  - `notTake = dp[idx - 1][w]`.
  - `take = val[idx] + dp[idx - 1][w - wt[idx]]` if `wt[idx] <= w`, else not allowed.
  - `dp[idx][w] = max(take, notTake)`.
- Answer is `dp[n - 1][W]`.

### Complexity
Time: **O(n * W)**          
Space: **O(n * W)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Two Rows)

### Idea
Row `idx` reads only row `idx - 1`. Keep two arrays: `prev` for the previous item and `curr` for the current one.

### Steps
- `prev` holds the base row (`prev[w] = val[0]` for `w >= wt[0]`).
- For each later item, fill `curr[w]` from `prev[w]` and `prev[w - wt[idx]]`.
- After each item, `prev = curr`.
- Answer is `prev[W]`.

### Complexity
Time: **O(n * W)**          
Space: **O(W)**, two arrays of size `W + 1`

---

## Approach 4: Tabulation with Space Optimization (Single Row, Reverse Loop)

### Idea
Even the second row is not needed. Update one array in place, but loop the capacity **from `W` down to `0`**. When `prev[w]` is updated, the cell it reads, `prev[w - wt[idx]]`, is at a smaller index that has not been overwritten yet, so it still holds the previous item's value.

### Steps
- `prev` holds the base row.
- For each later item, loop `w` from `W` down to `0`:
  - `notTake = prev[w]`.
  - `take = val[idx] + prev[w - wt[idx]]` if `wt[idx] <= w`.
  - `prev[w] = max(take, notTake)`.
- Answer is `prev[W]`.

### Complexity
Time: **O(n * W)**          
Space: **O(W)**, a single array (half the memory of Approach 3)

---

## Key Observation
All four techniques compute the same recurrence, they only differ in how much memory they spend. The reverse loop in Approach 4 is the important detail: if the capacity loop went forward, `prev[w - wt[idx]]` would already contain the CURRENT item's update, so the same item could be taken many times. That would accidentally solve the unbounded knapsack instead of 0/1. Going backward guarantees each item is used at most once.

## When to use this
If problem involves:
- Choosing a subset of items under a capacity limit to maximize a total
- Each item used at most once
→ Think **0/1 knapsack: state = (item index, remaining capacity), take / not take**, then compress to one row with a reverse capacity loop.

## Edge Cases
- `wt[0] > W` (the base row stays all zeros, so the first item can never be taken).
- `n = 1` (the loop over later items never runs, the answer is the base row).
- `W = 0` (nothing fits unless an item has weight 0).
- All items heavier than `W` (answer 0).
- All items fit (answer is the sum of all values).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * W) | O(n * W) + O(n) stack |
| Tabulation | O(n * W) | O(n * W) |
| Space Optimization (Two Rows) | O(n * W) | O(W) |
| Space Optimization (Single Row) | O(n * W) | O(W) |

where:
- `n` = number of items
- `W` = capacity of the bag

## Related Problems
- Partition Equal Subset Sum
- Last Stone Weight II
- Count Partitions with Given Difference
- Unbounded Knapsack