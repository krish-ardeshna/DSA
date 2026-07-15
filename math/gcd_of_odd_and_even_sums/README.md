# GCD of Odd and Even Sums

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/  
Difficulty: Easy  
Pattern: Math

## What I understood
We are given an integer n.

Consider:

- the sum of the first n odd numbers
- the sum of the first n even numbers

We need to return the GCD of these two sums.

Example:

n = 4

Odd sum = 1 + 3 + 5 + 7 = 16

Even sum = 2 + 4 + 6 + 8 = 20

Answer = 4

## Idea

### Approach 1 (Simulation)
Generate the first n odd and even numbers.

Compute both sums and calculate their GCD.

### Approach 2 (Mathematical Formula)
Use the formulas:

- Sum of first n odd numbers = n²
- Sum of first n even numbers = n(n + 1)

Then compute their GCD.

### Approach 3 (Mathematical Observation)
Using:

GCD(n², n(n + 1))

= n × GCD(n, n + 1)

Since consecutive numbers are always coprime:

GCD(n, n + 1) = 1

Therefore:

Answer = n

## Approach
- Observe the mathematical relationship between the two sums
- Simplify the GCD expression
- Return n directly

## Key Observation
The GCD always simplifies to:

n

No calculations or loops are required.

## When to use this
If the problem involves:
- number theory
- GCD
- mathematical simplification
- identifying formulas

→ think Math

## Edge Cases
- n = 1
- Large values of n

## Complexity

### Approach 1
Time: O(n)  
Space: O(1)

### Approach 2
Time: O(log n)  
Space: O(1)

### Approach 3
Time: O(1)  
Space: O(1)

## Related Problems
- Greatest Common Divisor of Strings
- Find Greatest Common Divisor of Array
- Add Digits
- Power of Two