# Maximize Consecutive Elements in an Array After Modification
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/  
Difficulty: Hard  
Pattern: Sorting + DP on Value (Longest Run of Consecutive Values Ending at Each Value)

## What I understood
Given an array `nums` of positive integers. You may increase each element by at most `1` (so an element `x` can stay `x` or become `x + 1`). After the changes, select one or more elements so that, when sorted, they are consecutive integers (for example `[3,4,5]`). Return the maximum number of elements you can select.

## Example
(Examples 1 and 2 are the LC examples as I remember them, recheck on the LC page. Example 3 is my own. All were hand-traced and checked by brute force.)
```
Input
nums = [2,1,5,1,1]
Output
3
```
Explanation: increase `nums[0]` (the `2`) to `3` and one `1` to `2`. Then `nums = [3,1,5,2,1]`. The elements `1, 2, 3` are consecutive, so 3 elements are selected.

```
Input
nums = [1,4,7,10]
Output
1
```
Explanation: even after increasing, no two elements can become consecutive, so the best is 1.

```
Input
nums = [1,1,3,3]
Output
4
```
Explanation: change one `1` to `2` and one `3` to `4`. The final values `1, 2, 3, 4` are consecutive, so all 4 elements are selected.

## Idea (shared by the DP approaches)
Sort the array. Process the elements in increasing order. Let `dp[v]` = the longest run of consecutive final values that ENDS exactly at value `v`, using the elements processed so far (each element used at most once).

For the current element `x`, there are two choices:
- **`x` becomes `x + 1`:** it extends a run that ends at `x`. So `dp[x + 1] = dp[x] + 1`.
- **`x` stays `x`:** it extends a run that ends at `x - 1`. So `dp[x] = dp[x - 1] + 1`.

The order of the two lines matters. The `x + 1` line must read `dp[x]` BEFORE this element changes `dp[x]`, because one element cannot be used as both `x` and `x + 1`.

With duplicates, the second copy of `x` reads a `dp[x]` that already includes the first copy. That gives the run "first copy as `x`, second copy as `x + 1`".

**Answer:** the largest `dp` value seen.

## Approach 1: Brute Force

### Idea
Every element has two choices (`+0` or `+1`). Try all `2^n` choices. For each one, put the final values in a set and find the longest run of consecutive values in it.

### Steps
- For every `mask` from `0` to `2^n - 1`: bit `i` of `mask` tells if `nums[i]` grows by 1.
- Build the set of final values.
- Walk the set in order and track the current run length. A value equal to `previous + 1` extends the run, otherwise the run restarts at `1`.
- Keep the maximum run over all masks.

### Complexity
Time: **O(2^n * n log n)**  
Space: **O(n)**

Only usable for very small `n`. It is here to check the other approaches.

---

## Approach 2: Sort + DP with a Hash Map

### Idea
Use the DP above with an `unordered_map` for `dp`, because the values can be large and sparse.

### Steps
- Sort `nums`.
- `dp` = empty map (a missing key counts as `0`). `ans = 0`.
- For each `x` in sorted order:
  - `dp[x + 1] = dp[x] + 1`
  - `dp[x] = dp[x - 1] + 1`
  - `ans = max(ans, dp[x], dp[x + 1])`
- Return `ans`.

### Complexity
Time: **O(n log n)** for the sort, plus **O(n)** expected for the hash map work  
Space: **O(n)**

---

## Approach 3: Sort + DP with O(1) Extra Space

### Idea
Each step only reads `dp[x - 1]` and `dp[x]` and writes `dp[x]` and `dp[x + 1]`. Because `x` never decreases, only the three values `dp[x - 1]`, `dp[x]`, `dp[x + 1]` are alive. Keep them in three variables `left`, `mid`, `right`, and slide the window when `x` moves up.

### Steps
- Sort `nums`. `base = nums[0]`, `left = mid = right = 0`.
- For each `x`, let `d = x - base`:
  - `d == 0`: no change.
  - `d == 1`: `left = mid`, `mid = right`, `right = 0`.
  - `d == 2`: `left = right`, `mid = right = 0`.
  - `d >= 3`: `left = mid = right = 0` (the old values are too far away to matter).
- Set `base = x`.
- `right = mid + 1`, then `mid = left + 1` (same order as Approach 2).
- `ans = max(ans, mid, right)`.
- Return `ans`.

### Complexity
Time: **O(n log n)** for the sort, then **O(n)**  
Space: **O(1)** extra (the sort is in place)

---

## Why There Is No Recursion + Memoization Version
The DP state is "the elements processed so far in sorted order", and the value `dp[x]` is rewritten when a duplicate of `x` arrives. A top-down function `f(value)` cannot express that cleanly, because the answer for a value depends on HOW MANY copies were already used. The natural form of this DP is bottom-up over the sorted array, which is what Approaches 2 and 3 do.

## Key Observation
Greedy does not work here. Always taking the smallest possible final value can get stuck: for `[3,4,6,6,6]` the best run is `4,5,6,7`, which needs the `3` and the `4` to be bumped UP to bridge the gap. The DP tries both choices for every element, so it handles this.

Once the array is sorted, the problem is a chain DP on values, and each element only ever touches the values `x - 1`, `x` and `x + 1`. That is why a hash map (or just three variables) is enough.

## When to use this
If problem involves:
- Each element can move by a tiny fixed amount (`+0` or `+1`)
- The goal is the longest run of consecutive values
→ Think **sort, then DP on value with `dp[x + 1] = dp[x] + 1` first and `dp[x] = dp[x - 1] + 1` second**.

## Edge Cases
- One element (answer `1`).
- All elements equal (for example `[1,1,1]`: the best run is `1, 2`, answer `2`, because only two final values are possible).
- Elements far apart (answer `1`).
- Many duplicates (each copy can still become `x` or `x + 1`, but never more than two copies help for one value).
- Already consecutive (every element stays, answer is `n`).
- The order of the two `dp` updates (swapping them lets one element count twice).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(2^n * n log n) | O(n) |
| Sort + DP (Hash Map) | O(n log n) | O(n) |
| Sort + DP (Rolling 3 Values) | O(n log n) | O(1) extra |

where:
- `n` = length of `nums`

## Related Problems
- Longest Consecutive Sequence
- Longest Harmonious Subsequence
- Delete and Earn
- Longest Increasing Subsequence