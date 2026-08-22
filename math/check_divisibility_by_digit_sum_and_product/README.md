# Check Divisibility by Digit Sum and Product
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/  
Difficulty: Easy  
Pattern: Math - Digit Extraction

## What I understood
Given integer `n`, compute sum of its digits and product of its digits, add them together, then check if `n` is divisible by that combined value.

## Example
```
Input
n = 23
Output
true
```
```
Input
n = 121
Output
false
```

## Idea
Straightforward digit extraction using repeated `% 10` and `/ 10`. Accumulate both sum (starting at 0) and product (starting at 1) in a single pass, then perform one final divisibility check.

## Approach: Extract Digits, Sum + Product, Check Divisibility
- Init `digitSum = 0`, `digitPro = 1`, `temp = n`.
- While `temp > 0`: extract last digit `t = temp % 10`, add to `digitSum`, multiply into `digitPro`, then `temp /= 10`.
- Compute `sum = digitSum + digitPro`.
- Return `n % sum == 0`.

## Key Observation
Product initialized to 1 (multiplicative identity) is essential — starting at 0 would zero out the entire product regardless of digits. Single pass suffices since sum and product are independent accumulations over the same digit stream.

## When to use this
If problem involves:
- Simple digit-level aggregation (sum, product, count) of a number
→ Think **single-pass digit extraction via `% 10` / `/ 10`**, no need for string conversion.

## Edge Cases
- Single digit number (sum = digit, product = digit, combined = 2*digit).
- Number containing digit 0 (product becomes 0, combined = sum only).
- Large numbers with many digits (product can grow large, potential overflow for very large inputs — verify against constraints).
- Division by combined sum of 0 would cause undefined behavior — verify problem guarantees this never happens (digit 0 alone doesn't zero the sum, since sum still contributes separately).

## Complexity
### Approach
Time: **O(log n)** — number of digits in n      
Space: **O(1)**

where:
- `n` = the input integer

## Related Problems
- Add Digits
- Sum of Digits in Base K
- Digit Count in Range
- Self Dividing Numbers