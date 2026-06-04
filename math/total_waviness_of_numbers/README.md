# Total Waviness of Numbers

Platform: Contest Problem  
Problem Link: N/A  
Difficulty: Medium  
Pattern: Math / Digit Manipulation

## What I understood
For every number in the given range, we need to examine its digits.

A digit contributes to waviness if it is:
- greater than both adjacent digits
- smaller than both adjacent digits

The total waviness is the sum of all such positions across all numbers in the range.

Example:

131

3 > 1 and 3 > 1

Waviness = 1

## Idea

### Approach 1 (Vector of Digits)
Extract all digits into a vector.

For every middle digit:
- compare with left digit
- compare with right digit
- increase answer if it forms a peak or valley

### Approach 2 (String Conversion)
Convert each number into a string.

Traverse all middle positions:
- compare current character with adjacent characters
- count peaks and valleys

This makes digit access straightforward.

### Approach 3 (Direct Digit Processing)
Process digits directly using modulo and division.

Maintain:
- left digit
- middle digit
- right digit

Check waviness while traversing digits without storing them.

This avoids any extra data structure.

## Approach
- Traverse every number in the range
- Identify all middle digits
- Check whether the digit is:
  - greater than both neighbors
  - smaller than both neighbors
- Count every valid occurrence
- Return total waviness

## Key Observation
A digit contributes to waviness only when it acts as a local peak or local valley.

We only need information about three consecutive digits at a time.

## When to use this
If the problem involves:
- digit manipulation
- local peaks and valleys
- processing numbers digit by digit

→ focus on neighboring digit relationships

## Edge Cases
- Numbers with fewer than 3 digits
- All digits equal
- Strictly increasing digits
- Strictly decreasing digits
- Multiple waviness positions in the same number

## Complexity

### Approach 1
Time: O(r × d)  
Space: O(d)

### Approach 2
Time: O(r × d)  
Space: O(d)

### Approach 3
Time: O(r × d)  
Space: O(1)

where:
- r = num2 - num1 + 1
- d = number of digits

## Related Problems
- Add Digits
- Reverse Integer
- Palindrome Number
- Digit DP Problems