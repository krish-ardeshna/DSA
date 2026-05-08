# Power of Four

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/power-of-four/  
Difficulty: Easy  
Pattern: Recursion / Bit Manipulation

## What I understood
We need to check if a number can be written as 4 raised to some power.  
So the number should keep dividing by 4 until it becomes 1.

## Idea

### Approach 1 (Recursion)
Keep dividing the number by 4:
- If it becomes 1 → it's a power of 4
- If it becomes non-divisible by 4 before reaching 1 → not a power of 4

### Approach 2 (Bit Manipulation)
A power of 4:
- is also a power of 2 (only one set bit)
- but that bit must be at an even position

Example:
1  → 1  
4  → 100  
16 → 10000  

Use:
- (n & (n - 1)) == 0 → checks power of 2  
- (n & 0x55555555) → checks even position bit  

## Approach
- If n <= 0 → return false
- Recursion:
  - if n == 1 → true
  - if n % 4 != 0 → false
  - else → call for n / 4
- Bit:
  - return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555)

## Mistake I made
At first, I thought checking power of 2 was enough, but it also needs position validation.

## When to use this
If problem involves:
- powers of 4
- checking bit positions
- combination of conditions  

→ think bit manipulation with mask

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