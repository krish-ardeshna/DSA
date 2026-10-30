# Burst Balloons
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/burst-balloons/  
Difficulty: Hard  
Pattern: DP on Partitions (Interval DP, Choose the LAST Balloon to Burst)

## What I understood
There are `n` balloons, each with a number `nums[i]`. Bursting balloon `i` gives `nums[i - 1] * nums[i] * nums[i + 1]` coins. A missing neighbour at either end counts as `1`. After a balloon bursts, its two neighbours become adjacent. Burst all balloons in the best order and return the maximum coins.

## Example
```
Input
nums = [3,1,5,8]
Output
167
```
Explanation: burst 1 (3*1*5 = 15), burst 5 (3*5*8 = 120), burst 3 (1*3*8 = 24), burst 8 (1*8*1 = 8). Total is 167.

```
Input
nums = [1,5]
Output
10
```
Explanation: burst 1 (1*1*5 = 5), then burst 5 (1*5*1 = 5). Total is 10.

```
Input
nums = [7]
Output
7
```
Explanation: one balloon, both neighbours count as 1, so 1*7*1 = 7.

## Idea (shared by both techniques)
Pad `nums` with a `1` on both ends, so the real balloons sit at indices `1..n`.

The trick is to think about the **last** balloon to burst in a range, not the first.

- If balloon `idx` is the LAST one burst in range `[i..j]`, its neighbours at that moment are always `nums[i - 1]` and `nums[j + 1]` (everything else in the range is already gone).
- The left part `[i..idx - 1]` and the right part `[idx + 1..j]` become two independent subproblems.
- If we chose the FIRST balloon instead, the neighbours of the remaining balloons would change, and the two sides would depend on each other.

**State:** `f(i, j)` = maximum coins from bursting all balloons in `i..j`, while `nums[i - 1]` and `nums[j + 1]` are still present.

**Recurrence:**
```
f(i, j) = max over idx in [i..j] of
          nums[i-1] * nums[idx] * nums[j+1] + f(i, idx - 1) + f(idx + 1, j)
```

**Base case:** `i > j` means no balloons, so `0`.

**Answer:** `f(1, n)`.

The `-1` memo marker is safe because coins are never negative (`nums[i] >= 0`).

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(i, j)` range so each range is solved once.

### Steps
- Pad `nums` with `1` at both ends.
- Create `dp[n + 1][n + 1]` filled with `-1`.
- `f(i, j)`: if `i > j` return `0`. If `dp[i][j]` is filled, return it.
- Try every `idx` from `i` to `j` as the last balloon. Its value is `nums[i - 1] * nums[idx] * nums[j + 1] + f(i, idx - 1) + f(idx + 1, j)`.
- Keep the maximum, store it, return it.
- Call `f(1, n)`.

### Complexity
Time: **O(n^3)**  
Space: **O(n^2)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. A range `[i..j]` needs the smaller ranges inside it, so fill with `i` going down and `j` going up.

### Steps
- Pad `nums`, create `dp[n + 2][n + 2]` filled with `0` (this already covers every `i > j` base case).
- For `i = n` down to `1`, for `j = 1` up to `n`, skip when `i > j`.
- For each `idx` in `[i..j]`, compute `nums[i - 1] * nums[idx] * nums[j + 1] + dp[i][idx - 1] + dp[idx + 1][j]`.
- `dp[i][j]` is the maximum of those values.
- Answer is `dp[1][n]`.

### Complexity
Time: **O(n^3)**  
Space: **O(n^2)**, no recursion stack

---

## Why There Is No Space-Optimized Version
`dp[i][j]` reads `dp[i][idx - 1]` and `dp[idx + 1][j]` for EVERY `idx` in the range. That means any earlier row or column of the table can be needed, so rolling rows is not possible. The full `O(n^2)` table stays.

## Key Observation
Choosing the LAST balloon is what makes the problem work. It freezes the two neighbours of that balloon, which cuts the range into two independent halves. Thinking about the first balloon makes the halves depend on each other and breaks the DP. This same "pick the last one" idea is the heart of every interval DP.

## When to use this
If problem involves:
- Removing items from a line, where the reward depends on the CURRENT neighbours
- The order of removal changes the total
→ Think **interval DP on the last item removed**, with sentinels at both ends.

## Edge Cases
- One balloon (answer is `nums[0]`, since both neighbours are `1`).
- Balloons with value `0` (bursting them gives nothing, but they still stay valid neighbours until removed).
- All balloons equal.
- `nums` gets modified (padded) by the function, so pass a copy if the original is needed again.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^3) | O(n^2) + O(n) stack |
| Tabulation | O(n^3) | O(n^2) |

where:
- `n` = number of balloons

## Related Problems
- Minimum Cost to Cut a Stick
- Remove Boxes
- Matrix Chain Multiplication
- Different Ways to Evaluate a Boolean Expression