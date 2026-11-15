# Number of Sub-arrays With Odd Sum
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/  
Difficulty: Medium  
Pattern: Prefix Sum Parity Counting / DP on Subarrays Ending at Each Index

## What I understood
Given an array of integers `arr`. Return the number of subarrays with an ODD sum. The answer can be large, so return it modulo `10^9 + 7`.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
arr = [1,3,5]
Output
4
```
Explanation: all subarrays and their sums are `[1]` = 1, `[1,3]` = 4, `[1,3,5]` = 9, `[3]` = 3, `[3,5]` = 8, `[5]` = 5. The odd sums are 1, 9, 3, 5, so the answer is 4.

```
Input
arr = [2,4,6]
Output
0
```
Explanation: every element is even, so every subarray sum is even. The answer is 0.

```
Input
arr = [1,2,3,4,5,6,7]
Output
16
```
Explanation: there are 28 subarrays in total, and 16 of them have an odd sum.

## Idea (shared by all approaches)
Only the PARITY (odd or even) of a sum matters. Parity follows simple rules:
```
odd + odd = even     even + even = even     odd + even = odd
```
So the approaches differ only in how they count the subarrays with odd parity.

## Approach 1: Brute Force

### Idea
Fix a start `i`. Extend `j` to the right and keep the parity of the running sum (only `arr[j] & 1` is needed). Count every `j` where the parity is odd.

### Steps
- `ans = 0`.
- For each `i`: `parity = 0`.
- For `j = i` to `n - 1`: `parity ^= arr[j] & 1`. If `parity == 1`, `ans++`.
- Return `ans % MOD`.

### Complexity
Time: **O(n^2)**  
Space: **O(1)**

Too slow for `n = 10^5`.

---

## Approach 2: Prefix Sum Parity Counting

### Idea
The sum of `arr[i..j]` is `pref[j + 1] - pref[i]`. This difference is odd exactly when the two prefix sums have DIFFERENT parity. So for each new prefix, the number of odd subarrays ending here equals the number of earlier prefixes with the opposite parity.

### Steps
- `even = 1` (the empty prefix has sum 0), `odd = 0`, `parity = 0`.
- For each `x`: `parity ^= x & 1`.
- If `parity == 1` (odd prefix): `ans += even`, then `odd++`.
- Otherwise (even prefix): `ans += odd`, then `even++`.
- Take `% MOD` on `ans` each time.
- Return `ans`.

### Complexity
Time: **O(n)**  
Space: **O(1)**

---

## Approach 3: DP (Count Subarrays Ending at Each Index by Parity)

### Idea
Let `oddEnd` and `evenEnd` be the number of subarrays that END at the current index with an odd sum and an even sum. When a new element `x` arrives, every old subarray is extended by `x`, and the new subarray `[x]` is added:
- If `x` is odd, the parity flips: `newOdd = evenEnd + 1` (the `+ 1` is `[x]` itself), `newEven = oddEnd`.
- If `x` is even, the parity stays: `newOdd = oddEnd`, `newEven = evenEnd + 1`.

Add `newOdd` to the answer every step.

### Steps
- `oddEnd = evenEnd = ans = 0`.
- For each `x`, compute `newOdd` and `newEven` with the rules above.
- Set `oddEnd = newOdd`, `evenEnd = newEven`.
- `ans = (ans + oddEnd) % MOD`.
- Return `ans`.

### Complexity
Time: **O(n)**  
Space: **O(1)**

---

## Key Observation
"Odd sum subarray" is the same as "two prefix sums with different parity". The sum values do not matter, only whether each prefix is odd or even, so two counters are enough. Approach 2 counts pairs of prefixes. Approach 3 counts subarrays that end at each index. Both give the same answer.

The number of odd subarrays can reach about `n * (n + 1) / 2 = 5 * 10^9`, so use `long long` and take the modulo.

## When to use this
If problem involves:
- Counting subarrays by the parity of the sum (or the sum modulo a small number)
- Only whether the sum is odd or even
→ Think **prefix sum parity: count earlier prefixes with the opposite parity**.

## Edge Cases
- All elements even (answer `0`).
- All elements odd (every second prefix is odd, so about half of all subarrays are odd).
- One element (answer is `1` if it is odd, else `0`).
- The empty prefix counts as an even prefix (so `even` starts at `1`).
- A very long array (the count passes `10^9 + 7`, so the modulo is needed).
- Use `x & 1` and not `x % 2`, so that a negative value would not break the XOR.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n^2) | O(1) |
| Prefix Sum Parity Counting | O(n) | O(1) |
| DP (Subarrays Ending at Each Index) | O(n) | O(1) |

where:
- `n` = length of `arr`

## Related Problems
- Subarray Sums Divisible by K
- Subarray Sum Equals K
- Continuous Subarray Sum
- Count Number of Nice Subarrays