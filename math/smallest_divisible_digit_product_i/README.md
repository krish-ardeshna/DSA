# Smallest Divisible Digit Product I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/  
Difficulty: Easy  
Pattern: Brute Force (Digit Product Check)

## What I understood
Find smallest integer `>= n` whose digit product is divisible by `t`. Digit product = product of all digits of that number.

## Example
```
Input
n = 10, t = 2
Output
10
```

## Idea
Search stays bounded because within any 10 consecutive integers, last digit cycles through 0-9 — guaranteeing at least one number where last digit is 0, making digit product 0 (divisible by any `t`). So answer always found within `n` to `n+9`, no need for unbounded search.

## Approach: Bounded Linear Search (n to n+9)
- Loop `num` from `n` to `n+9`.
- For each `num`, compute digit product by repeated `% 10` and `/ 10`.
- If `prod % t == 0` → return `num` immediately.
- Guaranteed to find answer within this range (fallback `-1` never actually triggers given constraints).

## Key Observation
Bounding the search to 10 iterations avoids worst-case unbounded loop — since a digit `0` (product = 0) is guaranteed to appear within any 10 consecutive integers, cutting off search early is both correct and efficient.

## When to use this
If problem involves:
- Searching nearest integer satisfying a digit-based property
- Property guaranteed within a small fixed window (like last-digit cycling)
→ Think **bounded brute force**, don't search unbounded.

## Edge Cases
- `t = 1` → any number works, returns `n` immediately.
- `n` itself already satisfies condition.
- Digit `0` present in `n` itself → product is 0, returns `n` immediately.
- Large `t` requiring product of multiple large digits.

## Complexity
### Approach
Time: **O(1)** — bounded to at most 10 iterations, each O(log num) for digit extraction
Space: **O(1)**

where:
- search window fixed at 10 numbers regardless of `n`

## Related Problems
- Smallest Divisible Digit Product II
- Count Numbers with Unique Digits
- Sum of Digits in Base K
- Add Digits