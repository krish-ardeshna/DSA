# Largest Divisible Subset
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/largest-divisible-subset/  
Difficulty: Medium  
Pattern: DP on Subsequences (LIS Variant, Divisibility Instead of Greater-Than)

## What I understood
Given a set of distinct positive integers `nums`, return the largest subset in which EVERY pair `(a, b)` satisfies `a % b == 0` or `b % a == 0`. If several largest subsets exist, any one is accepted.

## Example
```
Input
nums = [1, 2, 3]
Output
[1, 2]
```
Explanation: `[1, 3]` is also valid, any one of them is accepted.

```
Input
nums = [1, 2, 4, 8]
Output
[1, 2, 4, 8]
```

```
Input
nums = [5]
Output
[5]
```

## Idea (shared by both techniques)
Checking every pair in a subset looks expensive, but divisibility is TRANSITIVE: if `a` divides `b` and `b` divides `c`, then `a` divides `c`. So after SORTING, a subset is valid exactly when every element divides the NEXT one in the chain. That turns the pair condition into a chain condition, which is the Longest Increasing Subsequence pattern with "divides" instead of "is smaller than".

**State:** `dp[i]` = length of the longest divisible chain that ENDS at `nums[i]` (the array is sorted).

**Recurrence:**
```
dp[i] = 1 + max( dp[prev] )   over all prev < i with nums[i] % nums[prev] == 0
```
(and `dp[i] = 1` if no such `prev` exists).

**Rebuilding the subset:** keep `hash[i]` = the `prev` that gave the best chain for `i` (or `i` itself if it starts a chain). The best answer ends at the index with the largest `dp`. Follow `hash` backward from there to collect the elements, then reverse.

**Answer:** the subset rebuilt from the index with the largest `dp`.

Lengths are never negative, so `-1` is a safe "not computed yet" marker.

---

## Approach 1: Recursion + Memoization (Top-Down), Then Rebuild

### Idea
Compute `dp[i]` with a recursive function that asks for `dp[prev]` of every smaller divisor, caching each result. The same parent bookkeeping is recorded as the best `prev` is found.

### Steps
- Sort `nums`.
- Create `dp` filled with `-1` and `hash` of the same size.
- `f(i)`: if `dp[i]` is filled, return it. Otherwise start with `best = 1` and `hash[i] = i`, then for every `prev < i` with `nums[i] % nums[prev] == 0`, compute `len = 1 + f(prev)` and keep the largest (updating `hash[i]`).
- Call `f(i)` for every `i`, tracking the index with the largest `dp`.
- Walk `hash` backward from that index, collect, reverse.

### Complexity
Time: **O(n^2)**  
Space: **O(n)** for `dp` and `hash`, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up) with Parent Tracking

### Idea
Fill `dp` from left to right. When `dp[i]` is computed, every `dp[prev]` with `prev < i` is already known.

### Steps
- Sort `nums`. `dp[i] = 1` and `hash[i] = i` initially.
- For each `i`, for each `prev < i`: if `nums[i] % nums[prev] == 0` and `1 + dp[prev] > dp[i]`, update `dp[i]` and set `hash[i] = prev`.
- Track the index `lastIndex` with the largest `dp`.
- Walk `hash` backward from `lastIndex` until an element points to itself, collect, reverse.

### Complexity
Time: **O(n^2)**  
Space: **O(n)**

---

## Why There Is No Space-Optimized Version
Each `dp[i]` can depend on ANY earlier `dp[prev]`, and the `hash` array is needed at the end to rebuild the actual subset. Dropping old cells would make the traceback impossible. Space is already only `O(n)`.

## Key Observation
The two things that make this problem easy are: sort first (so a chain only needs to compare neighbours), and use transitivity of divisibility (so checking `nums[i] % nums[prev] == 0` against the chain's LAST element is enough, not against every member). The `hash` array is the standard trick for printing the answer in LIS-style problems.

## When to use this
If problem involves:
- Choosing the largest group where every pair satisfies a transitive relation (divides, is smaller than, is a prefix of)
→ Think **sort, then LIS-style DP ending at each index with a parent array**.

## Edge Cases
- Single element (answer is that element).
- No two numbers divide each other (answer is any single element).
- Includes `1` (it divides everything, so it can start any chain).
- A long chain such as `[1, 2, 4, 8, 16]` (the answer is the whole array).
- Several equally good subsets (any one is accepted).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^2) | O(n) + O(n) stack |
| Tabulation | O(n^2) | O(n) |

where:
- `n` = number of elements

## Related Problems
- Longest Increasing Subsequence
- Longest String Chain
- Number of Longest Increasing Subsequence
- Delete and Earn