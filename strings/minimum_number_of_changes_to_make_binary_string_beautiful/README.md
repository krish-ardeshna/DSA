# Minimum Number of Changes to Make Binary String Beautiful
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/  
Difficulty: Medium  
Pattern: Partition DP (Brute Force) + Greedy on Pairs

## What I understood
Given a 0-indexed binary string `s` of EVEN length. A string is beautiful if it can be split into one or more substrings such that each substring has EVEN length and contains only `1`s or only `0`s. In one step you may change any character to `0` or `1`. Return the minimum number of changes to make `s` beautiful.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
s = "1001"
Output
2
```
Explanation: change `s[1]` to `1` and `s[3]` to `0`. Then `s = "1100"`, which splits into `"11"` and `"00"`. It cannot be done with fewer than 2 changes.

```
Input
s = "10"
Output
1
```
Explanation: change `s[1]` to `1` (or `s[0]` to `0`). Then `s = "11"` (or `"00"`), a single block of even length.

```
Input
s = "0000"
Output
0
```
Explanation: the string is already one block of `0`s with even length, so no change is needed.

## Idea (shared by both approaches)
A beautiful string is a list of even-length blocks, and every block holds one repeated character. Any even-length block of one repeated character is the same as a list of pairs where both characters match. So the string is beautiful exactly when every aligned pair `(s[0], s[1])`, `(s[2], s[3])`, ... has two equal characters. Blocks of length 4, 6, ... never help, because they can always be cut into pairs.

## Approach 1: Partition DP (Try Every Even-Length Block)

### Idea
Follow the definition directly. `dp[i]` = minimum changes to make the first `i` characters beautiful, for even `i`. The last block is `s[j..i-1]` with `j` even. To make it uniform, change either all the `1`s to `0` or all the `0`s to `1`, so its cost is `min(ones, zeros)` in the block. A prefix count of `1`s gives `ones` in O(1).

### Steps
- Build `ones[i]` = number of `1`s in the first `i` characters.
- `dp[0] = 0`, other values `INF`.
- For `i = 2, 4, ..., n`, for `j = 0, 2, ..., i - 2`:
  - `one = ones[i] - ones[j]`, `zero = (i - j) - one`.
  - `dp[i] = min(dp[i], dp[j] + min(one, zero))`.
- Return `dp[n]`.

### Complexity
Time: **O(n^2)**  
Space: **O(n)**

Too slow for `n = 10^5`.

---

## Approach 2: Greedy (Every Pair Must Match)

### Idea
By the shortcut above, only the pairs matter. Each pair with two different characters needs exactly one change. Pairs are independent, so the answer is the number of mismatched pairs.

### Steps
- `ans = 0`.
- For `i = 0, 2, 4, ...`: if `s[i] != s[i + 1]`, `ans++`.
- Return `ans`.

### Complexity
Time: **O(n)**  
Space: **O(1)**

---

## Key Observation
Longer blocks add no power: a uniform block of length `2m` is just `m` matching pairs. So the whole DP collapses to counting mismatched pairs. The even length of `s` guarantees that `s[i + 1]` always exists when `i` is even, so there is no out-of-range read.

## When to use this
If problem involves:
- Splitting a string into blocks where each block has a simple "all the same" rule and an even (or fixed) size
→ Think **reduce the block to its smallest unit (a pair) and count the units that break the rule**.

## Edge Cases
- Length `2` (one pair, the answer is `0` or `1`).
- The whole string is already one block (answer `0`).
- Alternating string like `"101010"` (every pair is a mismatch, answer is `n / 2`).
- Pairs that are already equal but different from the neighbour pair (`"0011"` is fine, answer `0`).
- Odd positions never start a pair (the loop steps by `2`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Partition DP | O(n^2) | O(n) |
| Greedy on Pairs | O(n) | O(1) |

where:
- `n` = length of `s`

## Related Problems
- Minimum Number of Flips to Make the Binary String Alternating
- Minimum Changes To Make Alternating Binary String
- Palindrome Partitioning II
- Minimum Changes to Make K Semi-palindromes