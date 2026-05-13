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
Keep calculating the sum of digits:
- Extract digits using modulo
- Add them
- Repeat the same process until the number becomes a single digit

### Approach 2 (Digital Root Formula)
The repeated digit sum follows a mathematical pattern called Digital Root.

Instead of recalculating again and again, the answer can be directly found using:

1 + (num - 1) % 9

### Approach 3 (Modulo Observation)
If a number is divisible by 9,
its final reduced digit is always 9.

Example:  
18 → 1 + 8 = 9  
27 → 2 + 7 = 9  

Logic:
- if num == 0 → return 0
- if num % 9 == 0 → return 9
- otherwise → return num % 9

## Approach
- Recursive:
  - calculate digit sum
  - call function again
- Math Formula:
  - directly compute digital root
- Modulo Observation:
  - use divisibility property of 9

## Key Observation
The answer follows a repeating mathematical cycle instead of requiring repeated computation.

## When to use this
If the problem involves:
- repeated digit reduction
- digit sums
- mathematical patterns
- constant-time optimization

→ think digital root property

## Edge Cases
- num = 0
- single digit numbers
- numbers divisible by 9

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