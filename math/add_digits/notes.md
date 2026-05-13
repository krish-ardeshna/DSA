# Add Digits

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/add-digits/  
Difficulty: Easy  
Pattern: Recursion / Math

## What I understood
We need to repeatedly add digits of a number until only one digit remains.

Example:  
38 → 3 + 8 = 11  
11 → 1 + 1 = 2  

Final answer = 2

## Idea

### Approach 1 (Recursion)
Keep calculating digit sum:
- Extract digits using modulo
- Add them
- Recursively repeat until number becomes single digit

### Approach 2 (Math Trick - Digital Root)
A number's repeated digit sum follows a mathematical pattern called Digital Root.

This works because digital roots repeat in a cycle of 1 to 9.

Formula:
- if num == 0 → return 0
- otherwise:
  1 + (num - 1) % 9

### Approach 3 (Modulo Observation)
If a number is divisible by 9,
its digital root is always 9.

Example:  
18 → 1 + 8 = 9  
27 → 2 + 7 = 9  

Logic:
- if num == 0 → return 0
- if num % 9 == 0 → return 9
- otherwise → return num % 9

## Approach
- Recursive:
  - calculate sum of digits
  - call function again
- Math:
  - directly return digital root formula
- Modulo:
  - use divisibility property of 9

## Mistake I made
Initially thought recursion was the only way and didn’t know a mathematical shortcut exists.

## When to use this
If the problem involves:
- repeated digit sums
- digit reduction
- constant-time optimization

→ think digital root property

## Edge Cases
- num = 0
- single digit numbers

## Complexity

### Recursive
Time: O(log n)  
Space: O(log n)

### Math Approaches
Time: O(1)  
Space: O(1)

## Related Problems
- Power of Two
- Power of Three
- Factorial Trailing Zeroes