# Plus One
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/plus-one/  
Difficulty: Easy  
Pattern: Array - Digit Manipulation (Carry Propagation)

## What I understood
Array represents a large integer, one digit per index, most significant digit first. Add 1 to the number and return result in same digit-array format. No leading zeros in output (except the number itself being represented normally).

## Example
```
Input
digits = [1,2,3]
Output
[1,2,4]
```

## Idea
Adding 1 only affects trailing 9s — they turn to 0 and carry propagates left. First digit less than 9 encountered (from the right) simply increments and stops the carry. If all digits are 9, carry overflows past the front, needing a new leading 1.

## Approach: Reverse Iteration with Carry Handling
- Iterate from last digit to first.
- If current digit `< 9` → increment it, return immediately (no more carry).
- If current digit `== 9` → set to 0, continue carry to next digit left.
- If loop finishes without early return (all digits were 9) → insert `1` at front.

## Key Observation
No need for actual addition/carry arithmetic beyond simple increment — since input digits are single digits (0-9), the only carry case is exactly hitting 9. Early return the moment a non-9 digit is found short-circuits unnecessary work.

## When to use this
If problem involves:
- Large number represented as digit array
- Adding a small constant (like 1) to it
- Need in-place-style carry propagation without converting to actual integer (overflow risk for big numbers)
→ Think **reverse iteration + carry-until-non-9**.

## Edge Cases
- All digits are 9 (`[9,9,9]` → `[1,0,0,0]`).
- Single digit array (`[9]` → `[1,0]`).
- No carry needed (`[1,2,3]` → `[1,2,4]`).
- Leading zero avoided by design (insert happens only when overflow occurs).

## Complexity
### Approach
Time: **O(n)**
Space: **O(1)** extra (excluding output array; insert at front is O(n) worst case due to shifting, but still bounded by digit count)

where:
- `n` = number of digits

## Related Problems
- Add Binary
- Add Strings
- Multiply Strings
- Add Two Numbers