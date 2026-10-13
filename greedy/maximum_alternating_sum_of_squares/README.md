# Maximum Alternating Sum of Squares
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-alternating-sum-of-squares/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Greedy + Sorting

## What I understood
Elements of `nums` can be rearranged in any order. The alternating sum of squares of the final arrangement adds the square at every even index and subtracts the square at every odd index. Find the maximum value this can reach.

## Example
```
Input
nums = [1,2,3]
Output
12
```
Explanation: squares are 1, 4, 9. There are 2 even positions (added) and 1 odd position (subtracted). Put the smallest square (1) on the odd position: 4 + 9 - 1 = 12.

```
Input
nums = [1,-1,2,-2,3,-3]
Output
16
```
Explanation: squares sorted are 1, 1, 4, 4, 9, 9. 3 odd positions get the smallest three (1, 1, 4), 3 even positions get the rest (4, 9, 9): 22 - 6 = 16.

## Idea
Only the squares matter, so the sign of the original number and its original order are irrelevant. The arrangement decides which squares get added and which get subtracted, and the counts are fixed by `n`: exactly `n / 2` odd indices (subtracted) and `n - n / 2` even indices (added). To maximize the total, subtract the smallest squares and add the largest ones.

## Approach: Sort Squares, Subtract the Smallest n/2, Add the Rest
- Replace every element with its square, stored as `long long` (a square of an `int` can overflow `int`).
- Sort the squares ascending.
- The first `n / 2` squares are the smallest, so subtract them.
- The remaining squares are the largest, so add them.
- Return the total.

## Key Observation
The number of odd indices is `n / 2` (rounded down) and the number of even indices is the rest, which is why the cut point is exactly `n / 2`. For odd `n`, the extra slot goes to the added side, which is the favorable side. Any other assignment can only swap a larger square into the subtracted group or a smaller one into the added group, which never helps.

## When to use this
If problem involves:
- Rearranging freely, with a score that adds some positions and subtracts others
- Fixed counts of "add" and "subtract" slots
→ Think **sort, then give the best values to the positive slots and the worst values to the negative slots**.

## Edge Cases
- Single element (`n / 2 = 0`, nothing is subtracted, answer is the square of that element).
- Negative numbers (squaring removes the sign).
- All elements equal (every arrangement gives the same result).
- Large values (squares need `long long`).

## Complexity
### Approach
Time: **O(n log n)**, dominated by sorting          
Space: **O(n)** for the squares array

where:
- `n` = number of elements

## Related Problems
- Maximum Alternating Subsequence Sum
- Maximum Subarray Sum After One Operation
- Sort Array by Parity
- Sum of Squares of Special Elements