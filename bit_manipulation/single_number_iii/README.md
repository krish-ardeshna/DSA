# Single Number III

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/single-number-iii/  
Difficulty: Medium  
Pattern: Hashing / Bit Manipulation

## What I understood
Every element appears twice except two numbers.

We need to find the two unique numbers.

## Idea

### Approach 1 (Hash Map)
Store frequency of every number.

- numbers appearing twice → ignore
- numbers appearing once → answer

Simple and easy to understand.

### Approach 2 (XOR + Bit Manipulation)
XOR of duplicate numbers becomes 0.

After XOR of all elements:
xorAll = num1 ^ num2

The two unique numbers differ at some bit position.

Using the rightmost set bit:
- divide numbers into two groups
- XOR separately
- both unique numbers get isolated

## Approach
- Hashing:
  - store frequencies
  - collect numbers with count = 1
- XOR:
  - XOR all numbers
  - find rightmost set bit
  - divide into two groups
  - XOR each group separately

## Key Observation
Duplicate numbers cancel each other during XOR.

The remaining set bit helps separate the two unique numbers into different groups.

## When to use this
If the problem involves:
- duplicate cancellation
- unique elements
- constant space optimization

→ think XOR properties

## Edge Cases
- Negative numbers
- Unique numbers far apart
- Small array size

## Complexity

### Hash Map
Time: O(n)  
Space: O(n)

### XOR + Bit Manipulation
Time: O(n)  
Space: O(1)

## Related Problems
- Single Number
- Missing Number
- Power of Two