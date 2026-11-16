# Calculate Digit Sum of a String
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/calculate-digit-sum-of-a-string/  
Difficulty: Easy  
Pattern: String Simulation (Group by k, Sum, Repeat)

## What I understood
Given a string `s` of digits and an integer `k`. While the length of `s` is greater than `k`, do one round:
- Split `s` into consecutive groups of size `k` (the last group may be shorter).
- Replace every group with the sum of its digits (written as a string).
- Join the results in order to make the new `s`.

Return `s` when its length is at most `k`.

## Example
(Hand-traced and checked against a reference. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
s = "11111222223", k = 3
Output
"135"
```
Explanation: round 1 splits `s` into `111`, `112`, `222`, `23`, with sums 3, 4, 6, 5, so `s = "3465"`. The length 4 is greater than 3, so round 2 splits it into `346` and `5`, with sums 13 and 5, so `s = "135"`. The length 3 is not greater than 3, so we stop.

```
Input
s = "00000000", k = 3
Output
"000"
```
Explanation: round 1 splits `s` into `000`, `000`, `00`, all with sum 0, so `s = "000"`. The length 3 is not greater than 3, so we stop.

```
Input
s = "9", k = 2
Output
"9"
```
Explanation: the length 1 is already at most 2, so no round runs.

## Idea
Do exactly what the statement says. Each round turns the string into a shorter one (every group of at most `k` digits becomes a sum of at most a few digits), so the loop ends.

## Approach: Simulation

### Idea
Keep a `while` loop that runs while `s.size() > k`. In each round, walk `s` in steps of `k`, add up each group, and append the sum to a new string.

### Steps
- While `s.size() > k`:
  - `temp = ""`.
  - For `i = 0, k, 2k, ...`: `sum = 0`, add `s[j] - '0'` for `j` from `i` to `min(i + k, n) - 1`.
  - Append `to_string(sum)` to `temp`.
  - `s = temp`.
- Return `s`.

### Complexity
Time: **O(n)** per round, and the number of rounds is small (the length drops by about a factor of `k / 2` or more each round), so the total is about **O(n)** for the constraints here  
Space: **O(n)** for the temporary string

---

## Key Observation
A group of `k` digits has a sum of at most `9 * k`, which has at most 3 digits for `k <= 100`. For `k >= 2` the new string is shorter than the old one, so the loop always terminates. A sum can have more than one digit (for example `13`), so use `to_string` and not a single character.

## When to use this
If problem involves:
- Repeating a process on a string or array until a size condition holds
- A small fixed rule per round (group, sum, join)
→ Think **plain simulation**, and check that every round makes the input shorter.

## Edge Cases
- `s.size() <= k` at the start (return `s` unchanged).
- The last group is shorter than `k` (the inner loop stops at `s.size()`).
- A group sum with 2 or 3 digits (for example `13` is appended as `"13"`).
- A group of all zeros (its sum is `0`, appended as `"0"`).
- `s.size() == k` exactly (no round runs, because the condition is `>`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Simulation | O(n) (a few rounds) | O(n) |

where:
- `n` = length of `s`

## Related Problems
- Add Digits
- Sum of Digits of String After Convert
- Add Strings
- Happy Number