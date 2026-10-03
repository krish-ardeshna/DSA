# Climbing Stairs
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/climbing-stairs/  
Difficulty: Easy  
Pattern: DP (Fibonacci-Style Recurrence)

## What I understood
Climbing `n` stairs, each move is either 1 or 2 steps. Count the number of distinct ways to reach the top.

## Example
```
Input
n = 2
Output
2
```
```
Input
n = 3
Output
3
```

---

## Approach 1: Space-Optimized Iterative (O(1) Space)

### Idea
The number of ways to reach step `i` equals ways-to-reach `i-1` plus ways-to-reach `i-2` (arrive via a 1-step or a 2-step), the exact Fibonacci recurrence. Only the last two values are ever needed, so track just those two rolling variables.

### Steps
- Base cases: `n <= 2` returns `n` directly.
- Keep `prev1` (ways for `i-1`) and `prev2` (ways for `i-2`), starting at `prev1=2, prev2=1` for `i=3`.
- Loop from 3 to `n`, computing `ways = prev1 + prev2`, then shift the rolling variables forward.
- Return `prev1` after the loop.

### Complexity
Time: **O(n)**          
Space: **O(1)**

---

## Approach 2: DP Array (O(n) Space)

### Idea
Same recurrence as Approach 1, but stored explicitly in a `dp` array, index by index, rather than rolled into just two variables. More memory than needed, but makes the Fibonacci relationship directly visible in the code.

### Steps
- `dp[1] = 1`, `dp[2] = 2` as base cases.
- For `i` from 3 to `n`: `dp[i] = dp[i-1] + dp[i-2]`.
- Return `dp[n]`.

### Complexity
Time: **O(n)**          
Space: **O(n)** - full dp array, even though only the last two values are ever read at each step

---

## Approach 3: Recursion + Memoization (Top-Down DP)

### Idea
Same recursive structure as a naive recursion, `ways(n) = ways(n-1) + ways(n-2)`, but a `memo` array caches each subproblem's result the first time it's computed. Every subsequent call for the same `n` returns instantly instead of re-expanding the whole recursion tree, eliminating the exponential blowup of plain recursion.

### Steps
- Base case: `n <= 1` returns 1.
- Before recursing, check `memo[n]`, if already computed, return it directly.
- Otherwise, compute `recur(n-1) + recur(n-2)`, store the result in `memo[n]`, and return it.

### Complexity
Time: **O(n)** - each distinct subproblem computed exactly once     
Space: **O(n)** - memo array, plus O(n) recursion stack depth

---

## Key Observation
All three approaches encode the identical Fibonacci-style recurrence, the only difference is how much of the computation history gets reused. Memoization turns the same recursive shape that was exponential into linear time, simply by refusing to recompute a subproblem once its answer is known, bridging the gap between naive recursion and the bottom-up DP array.

## When to use this
If problem involves:
- A recurrence where the current state only depends on a FIXED, small number of previous states
→ Think **memoize the recursive version first** to fix exponential blowup with minimal code change, then consider converting to bottom-up (iterative) DP, and finally to rolling variables, once correctness at each stage is confirmed.

## Edge Cases
- `n = 1` (only one way).
- `n = 2` (two ways).
- Larger `n`, where memoization keeps performance linear instead of exponential.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Space-Optimized Iterative | O(n) | O(1) |
| DP Array | O(n) | O(n) |
| Recursion + Memoization | O(n) | O(n) |

where:
- `n` = number of stairs

## Related Problems
- Fibonacci Number
- Min Cost Climbing Stairs
- House Robber
- Decode Ways