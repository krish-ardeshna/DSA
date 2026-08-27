# Shortest and Lexicographically Smallest Beautiful String
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/  
Difficulty: Medium  
Pattern: Sliding Window (Fixed Count via Index Tracking)

## What I understood
A substring is "beautiful" if it contains exactly `k` `'1'` characters. Find the shortest such substring; if multiple substrings tie for shortest, return the lexicographically smallest one. Return empty string if no beautiful substring exists.

## Example
```
Input
s = "100011001", k = 3
Output
"11001"
```
```
Input
s = "1011", k = 2
Output
"11"
```

## Idea
Record positions of every `'1'` in the string. Any beautiful substring (exactly `k` ones) must start at some `'1'` position and end at another `'1'` position exactly `k-1` steps later in the `ones` array — since including/excluding any `0`s at the boundaries beyond that would either add extra ones (if extending to next one) or leave zero-padding that doesn't help minimize length (trimming to exactly start/end at the k-th one gives shortest possible span). Sliding a fixed-size window of size `k` over the `ones` index array directly gives all candidate substrings.

## Approach: Track '1' Positions + Window Between K-th Apart Ones
- Collect all indices where `s[i] == '1'` into `ones`.
- If fewer than `k` ones exist total, no beautiful substring possible, return `""`.
- Slide a window of size `k` over `ones`: for each starting position `i`, the substring spans from `ones[i]` to `ones[i+k-1]` (inclusive).
- Extract that substring, compare its length against current best (`minLen`); update if shorter, or if equal length but lexicographically smaller.
- Return the best found substring after all windows checked.

## Key Observation
Substring must start and end exactly at `'1'` positions to be minimal-length — any leading/trailing `0`s would only increase length without adding to the count of ones, so the tightest possible span between the i-th and (i+k-1)-th one is always the shortest valid beautiful substring starting at that i-th one.

## When to use this
If problem involves:
- Finding shortest/optimal substring containing exactly k occurrences of a specific character
→ Think **index-tracking of target character positions + fixed-size window over those indices**, rather than sliding window directly over the string.

## Edge Cases
- Fewer than `k` ones total in string → return `""`.
- Exactly `k` ones total (only one possible window).
- Multiple substrings of same minimum length → lexicographic tie-break required.
- String with no zeros between relevant ones (tightest possible substring, all 1s).

## Complexity
### Approach
Time: **O(n * L)** where L is average substring length (due to substr + string comparison costs); positions collection is O(n)      
Space: **O(n)** — ones index array plus substring storage

where:
- `n` = length of string s

## Related Problems
- Length of Longest Subarray With at Most K Frequency
- Maximum Length Substring With Two Occurrences
- Minimum Window Substring
- Grumpy Bookstore Owner