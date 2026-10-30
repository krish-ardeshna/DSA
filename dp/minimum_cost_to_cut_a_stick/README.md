# Minimum Cost to Cut a Stick
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/  
Difficulty: Hard  
Pattern: DP on Partitions (Interval DP, Choose the FIRST Cut in a Segment)

## What I understood
A wooden stick has length `n` (positions `0` to `n`). The array `cuts` lists positions where the stick must be cut, in any order I like. Cutting a stick costs the CURRENT length of the piece being cut. After a cut, that piece splits into two. Return the minimum total cost to make all cuts.

## Example
```
Input
n = 7, cuts = [1,3,4,5]
Output
16
```
Explanation: cut order [3, 5, 1, 4]. Cut at 3 costs 7 (piece 0..7). Cut at 5 costs 4 (piece 3..7). Cut at 1 costs 3 (piece 0..3). Cut at 4 costs 2 (piece 3..5). Total 7 + 4 + 3 + 2 = 16.

```
Input
n = 9, cuts = [5,6,1,4,2]
Output
22
```
Explanation: cut order [4, 6, 5, 2, 1]. Costs are 9 (piece 0..9), 5 (piece 4..9), 2 (piece 4..6), 4 (piece 0..4), 2 (piece 0..2). Total 22.

## Idea (shared by both techniques)
Add `0` and `n` to `cuts` and sort it. Now `cuts[1..c]` are the real cuts and `cuts[0]`, `cuts[c + 1]` are the two stick ends.

Look at the piece that contains the real cuts `i..j`. It runs from `cuts[i - 1]` to `cuts[j + 1]`, so its length is `cuts[j + 1] - cuts[i - 1]`.

Choose which cut `idx` in `[i..j]` is made FIRST on this piece:
- It costs the whole piece length.
- It splits the piece into two independent pieces: cuts `i..idx - 1` and cuts `idx + 1..j`.

**State:** `f(i, j)` = minimum cost to make all cuts `i..j` on the piece `(cuts[i - 1], cuts[j + 1])`.

**Recurrence:**
```
f(i, j) = min over idx in [i..j] of
          (cuts[j+1] - cuts[i-1]) + f(i, idx - 1) + f(idx + 1, j)
```

**Base case:** `i > j` means no cuts left on this piece, so `0`.

**Answer:** `f(1, c)`, where `c` is the number of real cuts.

The `-1` memo marker is safe because costs are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly and cache every `(i, j)` result.

### Steps
- Add `0` and `n` to `cuts`, sort it, let `c = cuts.size() - 2`.
- Create `dp[c + 2][c + 2]` filled with `-1`.
- `f(i, j)`: return `0` if `i > j`, return the cached value if filled.
- Try every `idx` in `[i..j]` as the first cut: `cuts[j + 1] - cuts[i - 1] + f(i, idx - 1) + f(idx + 1, j)`.
- Keep the minimum, store it, return it.
- Call `f(1, c)`.

### Complexity
Time: **O(c^3)**  
Space: **O(c^2)** for the dp table, plus **O(c)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion. A range of cuts needs the smaller ranges inside it, so `i` goes down and `j` goes up.

### Steps
- Prepare `cuts` the same way, create `dp[c + 2][c + 2]` filled with `0` (this covers every `i > j` base case).
- For `i = c` down to `1`, for `j = 1` up to `c`, skip when `i > j`.
- `dp[i][j]` is the minimum over `idx` of `cuts[j + 1] - cuts[i - 1] + dp[i][idx - 1] + dp[idx + 1][j]`.
- Answer is `dp[1][c]`.

### Complexity
Time: **O(c^3)**  
Space: **O(c^2)**, no recursion stack

---

## Why There Is No Space-Optimized Version
`dp[i][j]` reads `dp[i][idx - 1]` and `dp[idx + 1][j]` for EVERY `idx`, so any earlier row or column may be needed. The full `O(c^2)` table has to stay.

## Key Observation
The cost of a cut depends only on the piece it is made on, and the piece is fully described by its two end positions. Adding `0` and `n` as sentinels turns every piece into a pair `(i - 1, j + 1)` of indices, which is exactly the interval DP state. It is the mirror of Burst Balloons: there we pick the LAST item, here we pick the FIRST cut, and both split the range into two independent halves.

## When to use this
If problem involves:
- Splitting a segment where the cost depends on the size of the segment being split
- The order of splits changes the total
→ Think **interval DP**, with sentinel ends and a choice of the first split.

## Edge Cases
- One cut (cost is just `n`).
- Cuts given in unsorted order (sort first).
- A cut close to an end of the stick.
- Large `n` (up to `10^6`) with few cuts: the DP depends only on the number of cuts, not on `n`.
- `cuts` gets modified (padded and sorted) by the function, so pass a copy if the original is needed again.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(c^3) | O(c^2) + O(c) stack |
| Tabulation | O(c^3) | O(c^2) |

where:
- `c` = number of cuts

## Related Problems
- Burst Balloons
- Matrix Chain Multiplication
- Different Ways to Evaluate a Boolean Expression
- Palindrome Partitioning II