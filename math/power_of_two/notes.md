# Power of Two

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/power-of-two/  
Difficulty: Easy  
Pattern: Recursion / Bit Manipulation

## What I understood
We need to check if a number can be written as 2 raised to some power.  
So basically, the number should keep dividing by 2 until it becomes 1.

## Idea

### Approach 1 (Recursion)
Keep dividing the number by 2:
- If it becomes 1 → it's a power of 2
- If it becomes odd (before reaching 1) → not a power of 2

### Approach 2 (Bit Manipulation)
A power of 2 has only one set bit in binary.

Example:
1 → 1  
2 → 10  
4 → 100  
8 → 1000  

Using:
(n & (n - 1)) == 0

removes the lowest set bit.  
If result is 0 → only one bit was present.

## Approach
- Check if n <= 0 → return false
- Recursion:
  - if n == 1 → true
  - if n % 2 != 0 → false
  - else → call for n / 2
- Bit:
  - return n > 0 && (n & (n - 1)) == 0

## Mistake I made
Initially only thought about division, didn’t consider bit manipulation.

## When to use this
If problem involves:
- powers of 2
- checking binary properties
- numbers with single set bit  

→ think bit manipulation

## Edge Cases
- n = 0 → false  
- negative numbers → false  
- n = 1 → true  

## Complexity
Recursion:  
Time: O(log n)  
Space: O(log n)

Bit Manipulation:  
Time: O(1)  
Space: O(1)