# Number of Longest Increasing Subsequence
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/  
Difficulty: Medium  
Pattern: DP on Subsequences (LIS with Count Array)

## What I understood
Given an integer array `nums`, return how many different longest strictly increasing subsequences it has. Two subsequences are different if they use different INDICES, even when the values are the same.

## Example
```
Input
nums = [1, 3, 5, 4, 7]
Output
2
```
Explanation: the longest increasing subsequences have length 4, and there are two of them: [1, 3, 4, 7] and [1, 3, 5, 7].

```
Input
nums = [2, 2, 2, 2, 2]
Output
5
```
Explanation: the longest length is 1, and each of the 5 elements on its own is a different subsequence.

```
Input
nums = [1, 2, 4, 3, 5, 4, 7, 2]
Output
3
```
Explanation: the longest length is 5, and there are three of them (the two choices for the middle element, and the two 4s as the second last step).

## Idea (shared by both techniques)
Same as Longest Increasing Subsequence (LIS), but each position now tracks TWO numbers instead of one.

**State:** for every index `i`:
- `dp[i]` = length of the longest increasing subsequence that ENDS at `nums[i]`.
- `cnt[i]` = how many such longest subsequences end at `nums[i]`.

**Recurrence:** for every earlier `prev < i` with `nums[prev] < nums[i]`, compare the chain length you would get by extending `prev`:
```
if 1 + dp[prev] > dp[i]:   dp[i] = 1 + dp[prev];  cnt[i] = cnt[prev]       (found a LONGER chain, restart the count)
if 1 + dp[prev] == dp[i]:  cnt[i] += cnt[prev]                             (found ANOTHER chain of the same length, add the count)
```
Both `dp[i]` and `cnt[i]` start at `1` (the element alone is one subsequence of length 1).

**Answer:** let `maxi` = the maximum `dp[i]`. The answer is the sum of `cnt[i]` over every `i` with `dp[i] == maxi`. The longest subsequences can end at several different indices, so every one of them has to be added.

Lengths and counts are never negative, so `-1` is a safe "not computed yet" marker.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Compute the pair `{length, count}` for index `i` recursively. The function asks the same question for every smaller earlier element and merges the answers with the rule above. Returning the pair means one recursive call fills in both numbers.

### Steps
- Create `dp[n]` of pairs, all `{-1, -1}` (not computed yet).
- `f(i)`: if `dp[i].first != -1`, return it. Otherwise start with `len = 1`, `cnt = 1`.
- For every `prev < i` with `nums[prev] < nums[i]`, take `p = f(prev)`: if `1 + p.first > len`, set `len = 1 + p.first` and `cnt = p.second`. If equal, add `p.second` to `cnt`.
- Store and return `{len, cnt}`.
- Call `f(i)` for every `i`, find the maximum length, then add up the counts of all indices that reach it.

### Complexity
Time: **O(n^2)**  
Space: **O(n)** for the dp pairs, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Fill `dp` and `cnt` from left to right. When index `i` is computed, every `prev < i` is already finished.

### Steps
- `dp[i] = 1` and `cnt[i] = 1` for all `i`.
- For each `i`, for each `prev < i` with `nums[prev] < nums[i]`: apply the two-case rule (longer chain restarts the count, an equal chain adds to it).
- Track `maxi`.
- Sum `cnt[i]` over all `i` with `dp[i] == maxi`.

### Complexity
Time: **O(n^2)**  
Space: **O(n)**

---

## Why There Is No Space-Optimized Version
Each `dp[i]` and `cnt[i]` can depend on ANY earlier index, not just the previous one, so no cell can be thrown away. Space is already only `O(n)`.

## Key Observation
The easy mistake is to count only the subsequences ending at the LAST maximum, or to forget the "restart" case: when a longer chain is found, the old count is wrong and must be REPLACED, not added to. The equal-length case is where the counting really happens, because two different earlier elements can lead to the same length. A faster `O(n log n)` solution exists with a segment tree or binary search over buckets, but the `O(n^2)` DP is the standard answer for `n <= 2000`.

## When to use this
If problem involves:
- Counting how many optimal solutions exist, not just finding the optimal value
→ Think **track a `(best value, number of ways)` pair per state**: replace the count on a strictly better value, add counts on a tie.

## Edge Cases
- Single element (answer 1).
- All elements equal (answer `n`, every element is its own length-1 subsequence).
- Strictly increasing (answer 1, only the whole array).
- Strictly decreasing (answer `n`, every element alone).
- The longest subsequence ending at several different indices (all counts are added).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^2) | O(n) + O(n) stack |
| Tabulation | O(n^2) | O(n) |

where:
- `n` = number of elements

## Related Problems
- Longest Increasing Subsequence
- Largest Divisible Subset
- Longest String Chain
- Longest Continuous Increasing Subsequence