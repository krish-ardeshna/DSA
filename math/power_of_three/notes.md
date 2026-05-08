# Power of Three

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/power-of-three/  
Difficulty: Easy  
Pattern: Recursion / Math

## What I understood
We need to check if a number can be written as 3 raised to some power.  
So the number should keep dividing by 3 until it becomes 1.

## Idea

### Approach 1 (Recursion)
Keep dividing the number by 3:
- If it becomes 1 → it's a power of 3
- If it becomes non-divisible by 3 before reaching 1 → not a power of 3

### Approach 2 (Math Trick)
There is a largest power of 3 within 32-bit integer:
1162261467 = 3^19  

If a number divides this value exactly, then it must be a power of 3.

## Approach
- If n <= 0 → return false
- Recursion:
  - if n == 1 → true
  - if n % 3 != 0 → false
  - else → call for n / 3
- Math:
  - return n > 0 && 1162261467 % n == 0

## Mistake I made
Initially tried to think of a bit trick like power of 2, but it doesn't work here.

## When to use this
If problem involves:
- checking powers of 3
- repeated division pattern
- no direct bit trick available  

→ think recursion or math trick

## Edge Cases
- n = 0 → false  
- negative numbers → false  
- n = 1 → true  

## Complexity
Recursion:  
Time: O(log n)  
Space: O(log n)

Math Trick:  
Time: O(1)  
Space: O(1)