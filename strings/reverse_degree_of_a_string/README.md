# Reverse Degree of a String
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/reverse-degree-of-a-string/  
Difficulty: Easy  
Pattern: String - Weighted Character Value Sum

## What I understood
For each character in string `s` (1-indexed position), compute a "reverse alphabet value" — 'z' maps to 1, 'y' to 2, ..., 'a' to 26 (i.e., `26 - (char - 'a')`, equivalently `'z' - char + 1`). Multiply this value by the character's 1-indexed position, and sum across the entire string.

## Example
```
Input
s = "abc"
Output
148
```

## Idea
Direct single-pass computation — for each character, compute its reverse-alphabet value using simple char arithmetic (`'z' - s[i-1] + 1`), multiply by the 1-indexed position `i`, and accumulate into a running sum.

## Approach: Single Pass, Reverse-Alphabet Value Weighted by Position
- Iterate `i` from 1 to `s.size()` (1-indexed positions).
- For each character `s[i-1]`, compute `tmp = 'z' - s[i-1] + 1` — this gives 'a'→26, 'b'→25, ..., 'z'→1.
- Add `tmp * i` to running `sum`.
- Return `sum` after processing all characters.

## Key Observation
Using char arithmetic directly (`'z' - c + 1`) avoids needing a lookup table or extra conversion — since characters are just small integers under the hood, the reverse mapping falls out naturally from a simple subtraction.

## When to use this
If problem involves:
- Per-character value computation weighted by position, summed across a string
→ Think **single pass with direct char arithmetic**, no need for auxiliary lookup structures for simple linear alphabet mappings.

## Edge Cases
- Single character string.
- String containing 'a' (maximum reverse value, 26) or 'z' (minimum reverse value, 1).
- All same character repeated (position weighting still varies the contribution).
- Empty string (sum = 0, loop doesn't execute).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = length of string s

## Related Problems
- Sum of Digits in Base K
- Check Divisibility by Digit Sum and Product
- Count Commas in Range
- Number of Days in a Month