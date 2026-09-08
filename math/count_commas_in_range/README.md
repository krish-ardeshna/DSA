# Count Commas in Range
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-commas-in-range/  
Difficulty: Easy  
Pattern: Math - Direct Formula

## What I understood
Write every integer from 1 to `n` in standard comma-formatted notation (comma inserted every 3 digits from the right). Count the total number of commas used across all these numbers combined. Numbers under 4 digits have zero commas.

## Example
```
Input
n = 1002
Output
3
```
```
Input
n = 998
Output
0
```

## Idea
Given the constraint `n <= 10^5` (max 100000, which is 6 digits), every number with 4, 5, or 6 digits has exactly ONE comma — since comma placement happens every 3 digits, and 4-6 digit numbers only ever split into exactly 2 groups (e.g. "1,234" or "12,345" or "100,000"). This means no need to compute per-number comma counts individually; just count how many numbers in range `[1, n]` have 4 or more digits, since each contributes exactly 1.

## Approach: Count Numbers With 4+ Digits (Each Contributes 1 Comma)
- If `n < 1000`, no number in range has 4+ digits, return 0.
- Otherwise, numbers from 1000 to `n` all have exactly 1 comma each — total count is `n - 999` (i.e., `n - 1000 + 1`).

## Key Observation
This simple formula only works because the problem's constraint caps `n` at 100000 (6 digits) — within this range, digit count never reaches 7+, so multi-comma numbers (which would need more nuanced digit-length-based calculation) never occur. Recognizing constraint-specific shortcuts like this avoids overengineering a general-purpose digit-counting formula when it isn't needed.

## When to use this
If problem involves:
- Counting a per-number property across a range, where the constraint bounds guarantee the property is uniform (e.g., always exactly 1 occurrence) across the relevant sub-range
→ Think **check if constraints simplify the general formula**, avoid unnecessary digit-by-digit computation when a direct arithmetic shortcut applies.

## Edge Cases
- `n` less than 1000 (zero commas).
- `n` exactly 999 (boundary, zero commas).
- `n` exactly 1000 (first number with a comma).
- `n` at the constraint maximum (100000).

## Complexity
### Approach
Time: **O(1)**          
Space: **O(1)**

where:
- Direct arithmetic formula, no iteration needed

## Related Problems
- Count Numbers With Unique Digits
- Add Digits
- Self Dividing Numbers
- Sum of Digits in Base K