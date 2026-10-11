# Sum of Squares of Special Elements
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sum-of-squares-of-special-elements/  
Difficulty: Easy  
Pattern: Math - Divisor Check (1-Indexed Positions)

## What I understood
Array `nums` is 1-indexed for this problem. An element `nums[i]` is "special" if `i` divides `n` (the array length). Return the sum of squares of all special elements.

## Example
```
Input
nums = [1,2,3,4]
Output
21
```
```
Input
nums = [2,7,1,19,18,3]
Output
63
```

## Idea
Positions 1 through n are checked one by one. Position `i` is special exactly when `n % i == 0`. For each special position, add the square of the element there. The only catch is that C++ arrays are 0-indexed, so position `i` lives at `nums[i - 1]`.

## Approach: Linear Scan, Square Elements at Positions Dividing n
- Let `n = nums.size()`.
- Loop `i` from 1 to `n` (1-indexed position).
- If `n % i == 0`, add `nums[i - 1] * nums[i - 1]` to `sum`.
- Return `sum`.

## Key Observation
The loop variable is the 1-indexed position, not the array index. Starting `i` at 1 and reading `nums[i - 1]` keeps the divisibility test faithful to the problem statement. Position 1 and position `n` are always special, since 1 and n always divide n.

## When to use this
If problem involves:
- A condition on a 1-indexed position such as divisibility by n
- Small constraints where a plain scan is enough
→ Think **loop over positions 1..n directly** and convert to 0-index only when reading the array.

## Edge Cases
- Single element array (n = 1, only position 1 is special).
- Prime `n` (only positions 1 and n are special).
- Negative values (squaring makes them positive).
- Highly composite `n` such as 12 (many special positions).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = length of nums

## Related Problems
- Sum of Squares of Special Elements (divisor enumeration variant up to sqrt n)
- Find the Divisibility Array of a String
- Count Special Quadruplets
- Sum of Digits of String After Convert