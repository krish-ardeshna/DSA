# Count Primes

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-primes/  
Difficulty: Medium  
Pattern: Math / Sieve of Eratosthenes

## What I understood
We need to count how many prime numbers exist strictly less than n.

Checking every number individually for primality would be slow for large inputs.

## Idea
Use the Sieve of Eratosthenes.

Start by assuming every number is prime.
Then repeatedly mark multiples of prime numbers as non-prime.

## Approach
- Create a boolean array:
  isPrime[i] = true
- Mark:
  - 0 as non-prime
  - 1 as non-prime
- Traverse from 2 to √n
- If current number is prime:
  - mark all its multiples as non-prime
- Count remaining prime numbers

## Key Observation
A composite number gets marked by its smallest prime factor.

Also,
starting from i * i avoids unnecessary work because smaller multiples are already processed.

## When to use this
If the problem involves:
- prime numbers
- counting primes in range
- repeated primality checks

→ think sieve technique

## Edge Cases
- n <= 2
- small values of n

## Complexity
Time: O(n log log n)  
Space: O(n)

## Related Problems
- Ugly Number
- Prime Number of Set Bits
- Sieve of Eratosthenes