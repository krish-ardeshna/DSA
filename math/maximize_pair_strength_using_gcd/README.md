# Maximize Pair Strength Using GCD

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximize-pair-strength-using-gcd/  
Difficulty: Easy  
Pattern: Math, Brute Force

## What I understood

Given an array of integers, find the maximum pair strength among all pairs.

The strength of a pair is defined as:

```
(nums[i] × nums[j]) / gcd(nums[i], nums[j])²
```

## Example

```
Input
nums = [6,10,15]

Output
15
```

## Idea

Try every possible pair of numbers.

For each pair:
- Compute their product.
- Compute their GCD.
- Calculate the pair strength.
- Keep track of the maximum value.

## Approach: Brute Force

- Iterate through every unique pair.
- Compute:
  - Product
  - GCD
  - Pair strength
- Update the maximum answer.

## Key Observation

The pair strength depends only on two numbers.

Since every pair must be considered, checking all pairs guarantees the correct answer.

Using the built-in `gcd()` function efficiently computes the greatest common divisor for each pair.

## When to use this

If the problem involves:
- Pair enumeration
- GCD computation
- Mathematical formula evaluation
- Maximum over all pairs

→ Think **Brute Force + GCD**.

## Edge Cases

- Only two numbers.
- All numbers equal.
- Pair with GCD equal to 1.
- Large integer values.

## Complexity

### Approach

Time: **O(n² · log M)**

Space: **O(1)**

where:
- `n` = number of elements
- `M` = maximum value in the array

## Related Problems

- Find Greatest Common Divisor of Array
- Number of Different Subsequences GCDs
- Count Array Pairs Divisible by K