# Maximize Sum of Squares of Digits
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Greedy (Concentrate the Digit Sum)

## What I understood
Build a string of exactly `num` digits whose digits add up to exactly `sum`, such that the sum of the squares of its digits is as large as possible. If several strings tie, return the largest one. Return an empty string if no valid string exists.

## Example
```
Input
num = 2, sum = 3
Output
"30"
```
Explanation: options are "30", "21", "12", "03". Squares: 9, 5, 5, 9. The largest string among the best is "30".

```
Input
num = 2, sum = 17
Output
"98"
```

```
Input
num = 3, sum = 20
Output
"992"
```

```
Input
num = 1, sum = 10
Output
""
```
Explanation: one digit can be at most 9, so a digit sum of 10 is impossible.

## Idea
Squaring rewards large digits. For two digits `a` and `b` with a fixed total, `a^2 + b^2` grows as they move apart (for example 4 + 4 gives 32, but 8 + 0 gives 64). So to maximize the sum of squares, make the digits as unequal as possible: use as many 9s as possible, one digit for the leftover, and 0 everywhere else.

The best arrangement is therefore fixed (only the order of digits is free). To get the largest string among those, place the digits in descending order: 9s first, then the leftover digit, then the zeros.

## Approach: As Many 9s As Possible, One Remainder Digit, Zeros After
- If `sum > 9 * num`, even all 9s cannot reach the sum, return `""`.
- `nines = sum / 9`, append that many `'9'`.
- `sum % 9` is the leftover. If it is above 0, append it as one digit.
- Fill the remaining positions with `'0'` until the length is `num`.

## Key Observation
Both goals point the same way: maximizing the squares wants the digits concentrated, and maximizing the string wants big digits first. So the single greedy construction satisfies both, and no search is needed. The length never overflows `num`: when `sum <= 9 * num`, the number of 9s plus the optional remainder digit is at most `num`.

## When to use this
If problem involves:
- A fixed total split among several slots, with a convex objective such as a sum of squares
→ Think **concentrate the total into as few slots as possible** (fill slots to their maximum, one partial slot, the rest empty).

## Edge Cases
- `sum > 9 * num` (answer is an empty string).
- `sum` exactly divisible by 9 (no remainder digit).
- `sum = 9 * num` (all 9s, no zeros).
- `sum` smaller than 9 (one digit, then zeros).
- `sum = 0` (all zeros, if the constraints allow it).

## Complexity
### Approach
Time: **O(num)**        
Space: **O(num)** for the output string

where:
- `num` = required number of digits

## Related Problems
- Largest Number
- Maximum Swap
- Add Digits
- Digit Sum of a String