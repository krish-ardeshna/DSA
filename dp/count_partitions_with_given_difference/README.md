# Count Partitions with Given Difference
Platform: TakeUForward (Striver's DSA Sheet)  
Problem Link: <paste TakeUForward link here>  
Difficulty: Medium  
Pattern: DP on Subsequences (Count Subsets with Sum K, Zeros Handled)

## What I understood
Given an array `arr` of `n` non-negative integers and an integer `diff`, split the array into two subsets `S1` and `S2` (every element goes into exactly one) such that `S1 - S2 = diff`. Count the number of valid ways to do this, modulo `10^9 + 7`.

## Example
```
Input
arr = [5, 2, 6, 4], diff = 3
Output
1
```
Explanation: total is 17, so the subsets must sum to 10 and 7. Only {5, 2} sums to 7, so {6, 4} (sum 10) is the other side. That is the single valid split.

```
Input
arr = [1, 1, 1, 1], diff = 0
Output
6
```
Explanation: both subsets must sum to 2, and any 2 of the 4 ones can form the first subset, giving C(4, 2) = 6 ways.

```
Input
arr = [0, 0, 1], diff = 1
Output
4
```
Explanation: the 1 must be in the bigger subset, and each of the two zeros can go on either side, so 2 * 2 = 4 ways.

## Idea (shared by all three techniques)
Two facts about the two subsets:
```
S1 + S2 = totalSum
S1 - S2 = diff
```
Subtracting gives `S2 = (totalSum - diff) / 2`. So the problem becomes: **count the subsets whose sum equals `target = (totalSum - diff) / 2`**. Each such subset fixes the other one automatically.

Two quick exits first:
- `totalSum - diff < 0`: the difference is bigger than the total, impossible, return 0.
- `(totalSum - diff)` is odd: the target would not be a whole number, return 0.

**State:** `f(ind, sum)` = number of subsets of `arr[0..ind]` with sum exactly `sum`.

**Recurrence:** take or skip the current element:
```
notTake = f(ind - 1, sum)
take    = f(ind - 1, sum - arr[ind])     (only if arr[ind] <= sum)
f(ind, sum) = (notTake + take) % MOD
```

**Base case (`ind == 0`), where zeros matter:**
- `sum == 0` and `arr[0] == 0`: both the empty subset and `{0}` have sum 0, so return **2**.
- `sum == 0` or `sum == arr[0]`: exactly one way (empty subset, or just the first element), return **1**.
- Otherwise return 0.

**Answer:** `f(n - 1, target)`.

Why zeros need care: a zero adds nothing to a sum, so it can sit in either subset without changing the sum. Every zero therefore DOUBLES the count, which is why it is treated specially in the base case and in the sum 0 column.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the take / skip recurrence directly and cache every `(ind, sum)` result so each state is solved once. A `-1` marker for "not computed" is safe here because counts are never negative.

### Steps
- Check the two quick exits and compute `target`.
- Create `dp[n][target + 1]` filled with `-1`.
- Call `f(n - 1, target)`.
- At `ind == 0`, return the base case values above (2, 1 or 0).
- If `dp[ind][sum]` is filled, return it.
- Otherwise compute `notTake` and `take`, store `(notTake + take) % MOD`, return it.

### Complexity
Time: **O(n * target)**         
Space: **O(n * target)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion and fill `dp[ind][sum]` row by row from the first element. Every value reads only the previous row.

### Steps
- Create `dp[n][target + 1]` of zeros.
- Base row: `dp[0][0] = 2` if `arr[0] == 0`, else `1`. If `arr[0] != 0` and `arr[0] <= target`, set `dp[0][arr[0]] = 1`.
- For `ind = 1 .. n - 1`, for `sum = 0 .. target`:
  - `notTake = dp[ind - 1][sum]`.
  - `take = dp[ind - 1][sum - arr[ind]]` if `arr[ind] <= sum`, else `0`.
  - `dp[ind][sum] = (notTake + take) % MOD`.
- Answer is `dp[n - 1][target]`.

Looping `sum` from 0 handles zeros automatically: for a zero element, `take` reads `dp[ind - 1][sum]`, which doubles the value.

### Complexity
Time: **O(n * target)**         
Space: **O(n * target)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `ind` reads only row `ind - 1`, so keep two rows, `prev` and `curr`.

### Steps
- `prev` holds the base row, built exactly as in tabulation.
- For each later element:
  - `curr[0] = 2 * prev[0] % MOD` if the element is `0`, else `prev[0]` (a zero doubles the number of subsets with sum 0).
  - For `sum = 1 .. target`: `curr[sum] = (prev[sum] + prev[sum - arr[ind]]) % MOD`, where the second term is only used if `arr[ind] <= sum`.
- After each row, `prev = curr`.
- Answer is `prev[target]`.

### Complexity
Time: **O(n * target)**         
Space: **O(target)**, two rows of size `target + 1`

---

## Key Observation
The partition-difference problem is "count subsets with sum K" in disguise, with `K = (totalSum - diff) / 2`. The one place it differs from a plain subset-sum count is zeros: they make the sum-0 case count more than once, and the base case plus the `sum = 0` handling have to reflect that. The parity check is a free early exit. Adding two values below `10^9 + 7` stays under `2^31`, so `notTake + take` fits in `int` before the modulo.

## When to use this
If problem involves:
- Splitting an array into two groups with a fixed sum or difference
- Counting the number of ways (not just whether it is possible)
→ Think **convert to "count subsets with sum K" using `S1 + S2 = total` and `S1 - S2 = diff`**, then use take / skip DP and handle zeros in the base case.

## Edge Cases
- `diff > totalSum` (answer 0, caught by the quick exit).
- `totalSum - diff` odd (answer 0).
- `diff = 0` (both subsets have equal sum `total / 2`).
- Array containing zeros (each zero doubles the count).
- `target = 0` (only the zero elements can be chosen, so the count is `2^(number of zeros)`).
- Single element array.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * target) | O(n * target) + O(n) stack |
| Tabulation | O(n * target) | O(n * target) |
| Tabulation + Space Optimization | O(n * target) | O(target) |

where:
- `n` = number of elements
- `target` = `(totalSum - diff) / 2`

## Related Problems
- Count Subsets with Sum K
- Target Sum
- Partition Equal Subset Sum
- Last Stone Weight II