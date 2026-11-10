# Climbing Stairs II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/climbing-stairs-ii/  
Difficulty: Not verified (recent problem, check LC page)  
Pattern: 1D DP (Last Jump of Size 1, 2 or 3)

## What I understood
(Reconstructed from the accepted code, recheck the exact statement on the LC page.)
You are on a staircase with steps `0` to `n`, and you start at step `0`. From step `i` you can jump to step `i + 1`, `i + 2` or `i + 3`. Landing on step `j` costs `costs[j - 1] + (j - i)^2`, where `costs` is 1-indexed by step. Return the minimum total cost to reach step `n`.

## Example
(Hand-traced and checked by brute force. These are the examples as I remember them, recheck on the LC page.)
```
Input
n = 4, costs = [1,2,3,4]
Output
13
```
Explanation: the best path is `0 -> 1 -> 2 -> 4`. Landing on step 1 costs `1 + 1 = 2`. Landing on step 2 costs `2 + 1 = 3`. Landing on step 4 (a jump of 2) costs `4 + 4 = 8`. Total is `2 + 3 + 8 = 13`.

```
Input
n = 4, costs = [5,1,6,2]
Output
11
```
Explanation: the best path is `0 -> 2 -> 4`. Landing on step 2 (a jump of 2) costs `1 + 4 = 5`. Landing on step 4 (a jump of 2) costs `2 + 4 = 6`. Total is `5 + 6 = 11`.

```
Input
n = 3, costs = [9,8,3]
Output
12
```
Explanation: jumping straight from step 0 to step 3 costs `3 + 9 = 12`. Every other path costs more.

## Idea (shared by all three techniques)
The last jump into step `i` comes from step `i - j`, with `j` equal to `1`, `2` or `3`. That jump costs `costs[i - 1] + j * j`.

**State:** `dp[i]` = minimum cost to reach step `i`.

**Recurrence:**
```
dp[i] = min over j in {1, 2, 3}, j <= i :  dp[i - j] + costs[i - 1] + j * j
```

**Base case:** `dp[0] = 0` (we start there).

**Answer:** `dp[n]`.

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly as `f(i)` and cache every result in `dp[i]`, so each step is solved once.

### Steps
- Create `dp[n + 1]` filled with `-1`.
- `f(0)` returns `0`.
- If `dp[i]` is already filled, return it.
- Try `j = 1, 2, 3` (with `j <= i`) and take the minimum of `f(i - j) + costs[i - 1] + j * j`.
- Store and return it.
- Call `f(n)`.

### Complexity
Time: **O(n)**  
Space: **O(n)** for the table, plus **O(n)** recursion stack (the recursion can go `n` calls deep)

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. Fill `dp` from step `1` up to step `n`, since `dp[i]` only needs smaller steps.

### Steps
- Create `dp[n + 1]` filled with a large value, and set `dp[0] = 0`.
- For `i = 1` to `n`, for `j = 1` to `3` with `j <= i`: `dp[i] = min(dp[i], dp[i - j] + costs[i - 1] + j * j)`.
- Return `dp[n]`.

### Complexity
Time: **O(n)**  
Space: **O(n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization (Last 3 Values)

### Idea
`dp[i]` only reads `dp[i - 1]`, `dp[i - 2]` and `dp[i - 3]`. Keep just those three values in variables `p1`, `p2` and `p3`.

### Steps
- `p1 = dp[0] = 0`. `p2 = p3 = INF`, because steps below `0` do not exist.
- For `i = 1` to `n`: `cur = min(p1 + 1, p2 + 4, p3 + 9) + costs[i - 1]`.
- Shift the values: `p3 = p2`, `p2 = p1`, `p1 = cur`.
- Return `p1`.

### Complexity
Time: **O(n)**  
Space: **O(1)**

---

## Key Observation
This is the classic climbing stairs DP with two changes: the jump size goes up to 3, and each jump has an extra cost of `j * j`. The extra cost depends only on the jump size, so it is added inside the same recurrence. Larger jumps skip steps (so their `costs` are not paid), but their `j * j` penalty grows, and the DP finds the best trade-off.

## When to use this
If problem involves:
- Moving along a line with a small fixed set of jump sizes
- A cost that depends on the landing step and the jump size
→ Think **1D DP on the last jump**, and keep only as many previous values as the largest jump.

## Edge Cases
- `n = 1` (only one jump of size 1, the answer is `costs[0] + 1`).
- `n = 2` (a jump of size 3 is not allowed, so the loop uses `j <= i`).
- `n = 3` (one jump of size 3 may be the best choice, as in Example 3).
- Large `costs` (a long path adds up. Use `long long` in the table, the final answer fits in `int` by the constraints I remember).
- Space-optimized version: the `INF` values for steps below `0` must not be used in the `min` (they are too large to win, and `INF` is `LLONG_MAX / 4` so adding to it does not overflow).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n) | O(n) + O(n) stack |
| Tabulation | O(n) | O(n) |
| Tabulation + Space Optimization | O(n) | O(1) |

where:
- `n` = number of steps

## Related Problems
- Climbing Stairs
- Min Cost Climbing Stairs
- House Robber
- Jump Game II