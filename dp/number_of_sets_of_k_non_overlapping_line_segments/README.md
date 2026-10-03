# Number of Sets of K Non-Overlapping Line Segments
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/  
Difficulty: Medium  
Pattern: Combinatorics (Pascal's Triangle DP)

## What I understood
Given `n` points on a number line (points 0 to n-1), choose `k` non-overlapping line segments (segments can share endpoints but can't overlap in their interior, and each segment connects two distinct points with the left point strictly less than the right point). Count the number of distinct ways to choose such a set of `k` segments, modulo `10^9 + 7`.

## Example
```
Input
n = 4, k = 2
Output
5
```
```
Input
n = 3, k = 1
Output
3
```

## Idea
This problem has a known closed-form combinatorial reduction: the answer equals `C(n+k-1, 2k)` (a specific binomial coefficient). Rather than deriving this from scratch via segment-placement reasoning, compute this binomial coefficient using Pascal's Triangle DP (safer against overflow and easier to get right than direct factorial-based computation with modular inverse).

## Approach: Reduce to C(n+k-1, 2k) via Pascal's Triangle
- Compute `N = n + k - 1` and `R = 2*k` (the two parameters of the target binomial coefficient `C(N, R)`).
- Build Pascal's Triangle DP table `dp[i][j]` = `C(i, j)`, using the standard recurrence `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`, with `dp[i][0] = 1` for all rows.
- Cap the inner loop at `min(i, R)` since `C(i, j)` for `j > i` is 0 and not needed.
- Return `dp[N][R]` (already reduced modulo `10^9 + 7` throughout construction).

## Key Observation
This is a known result derived from combinatorial reasoning about the underlying segment-selection problem — recognizing that the answer reduces to a single binomial coefficient avoids needing to build a more complex direct DP over segment placements. Building the coefficient via Pascal's Triangle (rather than factorial + modular inverse) sidesteps potential issues with computing modular inverses correctly.

## When to use this
If problem involves:
- Combinatorial counting problems where segment/interval placement counts reduce to a known "stars and bars" or binomial coefficient identity
→ Think **check if a direct combinatorial formula (like `C(n+k-1, 2k)`) applies before building a complex custom DP** — recognizing this reduces both code complexity and computation time significantly.

## Edge Cases
- `k = 0` (trivially 1 way — the empty set of segments).
- `n` exactly large enough for `k` segments to just barely fit.
- Large `n` and `k` requiring modular arithmetic throughout (handled via `% MOD` at each DP step).
- Minimum valid inputs (`n = 2, k = 1`).

## Complexity
### Approach
Time: **O(N * R)** where N = n+k-1, R = 2k — building the Pascal's Triangle table           
Space: **O(N * R)** — DP table storage

where:
- `n`, `k` = problem's input parameters

## Related Problems
- Unique Paths
- Combination Sum
- Pascal's Triangle
- Count of Range Sum