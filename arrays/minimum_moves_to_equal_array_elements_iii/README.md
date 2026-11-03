# Minimum Moves to Equal Array Elements III
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Math (Raise Every Element to the Maximum)

## What I understood
(Reconstructed from the accepted code, recheck against the LC statement.)  
Given an integer array `nums`. In one move you add `1` to ONE element. Return the minimum number of moves needed to make all elements equal.

## Example
(Hand-traced and checked by brute force, not copied from the LC page.)
```
Input
nums = [2,1,3]
Output
3
```
Explanation: the maximum is `3`. The element `2` needs 1 move, the element `1` needs 2 moves, and `3` needs none. Total is 1 + 2 + 0 = 3.

```
Input
nums = [4,4,5]
Output
2
```
Explanation: the maximum is `5`. Each `4` needs 1 move, so the total is 2.

```
Input
nums = [7,7,7]
Output
0
```
Explanation: all elements are already equal.

## Idea
A move can only RAISE an element, never lower it. So the final common value can never be smaller than the current maximum.

- The best final value is exactly the maximum. Any bigger value costs extra moves for every element.
- Each element `x` has to climb up to `mx`, which costs `mx - x` moves.

**Answer:**
```
moves = sum over all x of (mx - x)  =  n * mx - sum(nums)
```

---

## Approach: Math (Sum of Distances to the Maximum)

### Idea
Find the maximum, then add up how far every element is below it.

### Steps
- Find `mx = max(nums)`.
- Start `ans = 0`.
- For every `x`, add `mx - x` to `ans`.
- Return `ans`.

### Complexity
Time: **O(n)**  
Space: **O(1)**

---

## Key Observation
This is the third problem in the family, and the three answers use three different targets. The target depends on what a move can do:
- **I:** a move raises `n - 1` elements, which is the same as lowering one element, so the target is the MINIMUM.
- **II:** a move raises or lowers one element, so the target is the MEDIAN.
- **III:** a move can only raise one element, so the target is the MAXIMUM.

## When to use this
If problem involves:
- Making all elements equal with moves that only go in one direction (only up, or only down)
→ Think **the extreme value is the target**: the maximum if moves only raise, the minimum if moves only lower.

## Edge Cases
- One element (answer `0`).
- All elements equal (answer `0`).
- The maximum appears more than once (those elements add `0`).
- Large values: the answer can grow to `n * max`, so use `long long` if the limits are big.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Math (sum of distances to the maximum) | O(n) | O(1) |

where:
- `n` = number of elements

## Related Problems
- Minimum Moves to Equal Array Elements
- Minimum Moves to Equal Array Elements II
- Minimum Operations to Make the Array Increasing