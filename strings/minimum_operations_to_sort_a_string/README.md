# Minimum Operations to Sort a String
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Greedy Case Analysis (Answer Is Always 0, 1, 2, 3 or -1)

## What I understood
(Reconstructed from the accepted logic, recheck against the LC statement.)  
In one operation, choose a substring that is NOT the entire string and sort it in non-decreasing order. Find the minimum number of operations needed to make the whole string sorted. Return `-1` if it is impossible.

## Example
```
Input
s = "ba"
Output
-1
```
Explanation: the only proper substrings have length 1, and sorting a single character changes nothing.

```
Input
s = "acb"
Output
1
```
Explanation: sort the substring "cb" to get "abc".

```
Input
s = "bca"
Output
2
```
Explanation: sort "ca" to get "bac", then sort "ba" to get "abc". One operation is not enough.

```
Input
s = "cba"
Output
3
```
Explanation: sort "cb" to get "bca", sort "ca" to get "bac", sort "ba" to get "abc".

## Idea
The answer depends only on WHERE the smallest and largest characters sit, not on the rest of the string. Let `mn` be the smallest character and `mx` the largest.

Whatever the last operation is, it sorts a proper substring, so it leaves either the first or the last character untouched. That untouched character must already be in its final place, meaning `s[0]` is `mn` or `s[n-1]` is `mx`. This one fact drives every case.

- **0 operations:** the string is already sorted.
- **-1:** `n == 2` and unsorted. The only proper substrings are single characters.
- **1 operation:** `s[0] == mn` (sort everything after the first character) or `s[n-1] == mx` (sort everything before the last character). Conversely, one operation can only work in these two situations, by the fact above.
- **2 operations:** some interior character (index `1..n-2`) equals `mn` or `mx`.
  - Interior `mn` at index `i`: sort `s[0..i]` to bring `mn` to the front, then sort `s[1..n-1]`.
  - Interior `mx` at index `i`: sort `s[i..n-1]` to bring `mx` to the end, then sort `s[0..n-2]`.
  - Two operations are needed (and enough) only here: after the first operation, `s[0]` must be `mn` or `s[n-1]` must be `mx`. Sorting a proper substring `[0..j]` with `j <= n-2` can bring `mn` to the front only if `mn` already sits at an index in `1..n-2`. The same argument works for `mx` and the end of the string.
- **3 operations:** otherwise. Here `mn` appears only at the last index and `mx` only at the first index. No single proper-substring sort can move either to its final end, so 2 operations are impossible. Three always work: sort `s[0..n-2]` (pushes `mx` to index `n-2`), sort `s[1..n-1]` (pushes `mx` to the end), then sort `s[0..n-2]`.

## Approach: Check Where the Min and Max Characters Sit
- If `s` is already sorted, return 0.
- If `n == 2`, return -1.
- Find `mn` and `mx`.
- If `s[0] == mn` or `s[n-1] == mx`, return 1.
- If any interior character equals `mn` or `mx`, return 2.
- Otherwise return 3.

## Key Observation
Because the operation can never touch the whole string, the min must reach the front or the max must reach the back through a proper substring that covers it. That is why the check is only "is `mn` or `mx` at an end, in the interior, or stuck at the opposite end". The answer is always at most 3 for `n >= 3`, so no search or DP is needed. The check uses character values, so duplicates of `mn` or `mx` are handled automatically: any copy at a useful position is enough.

## When to use this
If problem involves:
- An operation that sorts or rearranges a restricted piece of the string
- A small bounded answer (0 to 3) decided by the positions of extreme elements
→ Think **ask what the final operation must look like, then classify by where the min and max sit**.

## Edge Cases
- Already sorted string (answer 0).
- Single character (answer 0).
- Length 2, unsorted (answer -1).
- Length 3 or more, always possible (answer at most 3).
- All characters equal (already sorted, answer 0).
- `mx` at index 0 and `mn` at the last index, with nothing extreme in the middle (answer 3).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = length of the string

## Related Problems
- Check if Array Is Sorted and Rotated
- Minimum Number of Operations to Sort a Binary Array
- Sort Array by Parity
- Sort Colors