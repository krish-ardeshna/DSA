# Maximum Gap Between Stations
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-gap-between-stations/  
Difficulty: Medium (contest problem)  
Pattern: String - Two Pointer (Leftmost/Rightmost Match Tracking)

## What I understood
`skill` is a subsequence pattern that must be matched within `station` in order. For each character in `skill`, find its earliest possible matching position in `station` (leftmost greedy match) and its latest possible matching position (rightmost greedy match). Then find the maximum "gap" between a rightmost match of one character and the leftmost match of the previous character.

## Example
```
Input
skill = "abc", station = "xaxbxcx"
Output
(maximum gap between earliest-possible and latest-possible subsequence matches)
```

## Idea
Two separate greedy subsequence matches are computed: one scanning left-to-right (finds earliest position each `skill` character can match), one scanning right-to-left (finds latest position each `skill` character can match). Combining `right[i]` (latest match for current skill char) with `left[i-1]` (earliest match for previous skill char) gives the widest possible span between consecutive matched positions — maximized across all adjacent pairs.

## Approach: Precompute Leftmost and Rightmost Match Positions
- Forward pass: for each `skill[i]` in order, advance `j` in `station` until it matches; record `left[i] = j`, then increment `j` past it.
- Backward pass: for each `skill[i]` from the end, advance `j` backward in `station` until it matches; record `right[i] = j`, then decrement `j` past it.
- Final answer: for each `i` from 1 to n-1, compute `right[i] - left[i-1]`, take the maximum across all `i`.

## Key Observation
Greedy leftmost match and greedy rightmost match are classic techniques for subsequence-position problems — leftmost match always exists if the subsequence is valid, and computing both directions independently (rather than trying to combine into one pass) keeps the logic simple and correct.

## When to use this
If problem involves:
- Subsequence matching within a longer string
- Need earliest AND latest possible match positions for each pattern character
→ Think **two-pass greedy matching (forward for leftmost, backward for rightmost)**.

## Edge Cases
- `skill` length 1 (loop for gap computation doesn't execute, answer defaults to 0).
- `skill` and `station` identical (matches are forced, minimal gap).
- Multiple occurrences of same character in `station` (greedy match rules determine which one gets picked in each pass).
- `station` much longer than `skill` (larger possible gaps).

## Complexity
### Approach
Time: **O(m)** — both passes scan station once (n <= m, total station traversal linear)         
Space: **O(n)** — left/right position arrays

where:
- `n` = length of skill
- `m` = length of station

## Related Problems
- Is Subsequence
- Number of Matching Subsequences
- Shortest Way to Form String
- Longest Common Subsequence