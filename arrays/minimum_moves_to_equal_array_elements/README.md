# Minimum Moves to Equal Array Elements
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/  
Difficulty: Medium  
Pattern: Math (Reverse the Move: Decrease One Element Instead of Increasing n - 1)

## What I understood
Given an integer array `nums` of size `n`. In one move you add `1` to exactly `n - 1` elements (every element except one that you choose). Return the minimum number of moves needed to make all elements equal.

## Example
```
Input
nums = [1,2,3]
Output
3
```
Explanation: `[1,2,3]` -> `[2,3,3]` -> `[3,4,3]` -> `[4,4,4]`. Each move skips one element, and it takes 3 moves.

```
Input
nums = [1,1,1]
Output
0
```
Explanation: all elements are already equal.

```
Input
nums = [5,1,1]
Output
4
```
Explanation: the distances to the minimum `1` are `4, 0, 0`, so the total is 4.

## Idea
Adding `1` to `n - 1` elements changes the DIFFERENCES between elements in exactly the same way as subtracting `1` from the one element that was skipped. Equal elements stay equal in both views, so we can think of the move this way:

**One move = decrease ONE element by 1** (everything else is unchanged, relatively).

Now the question is simple: what is the least number of "decrease one element by 1" steps to make all elements equal?

- The final value can never be below the minimum, because the smallest element is never decreased if we want to use as few steps as possible.
- So every element `x` has to come down to `min`, which costs `x - min` steps.

**Answer:**
```
moves = sum over all x of (x - min)  =  sum(nums) - n * min
```

---

## Approach: Math (Sum of Distances to the Minimum)

### Idea
Find the minimum, then add up how far every element is above it.

### Steps
- Find `mn = min(nums)`.
- Start `ans = 0` (use `long long` for the running sum).
- For every `x`, add `x - mn` to `ans`.
- Return `ans`.

### Complexity
Time: **O(n)**  
Space: **O(1)**

---

## Key Observation
The trick is to change the point of view: "raise `n - 1` elements" is the same as "lower one element" when we only care about the elements becoming equal. After that the problem is just the sum of distances to the minimum.

The running sum is stored in `long long`, because the values can be large (`-10^9` to `10^9`) and many differences are added together. LeetCode guarantees that the final answer fits in a 32-bit integer.

## When to use this
If problem involves:
- A move that changes all elements except one
- The goal is to make elements equal
→ Think **flip the move**: changing `n - 1` elements up is the same as changing 1 element down. Then use the sum of distances to the minimum.

## Edge Cases
- All elements equal (answer `0`).
- One element (answer `0`).
- Negative numbers (the formula still works, only differences matter).
- Large differences, such as `[-10^9, 10^9]` (the answer is `2 * 10^9`, which still fits in `int`).
- Minimum appears more than once (those elements add `0`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Math (sum of distances to the minimum) | O(n) | O(1) |

where:
- `n` = number of elements

## Related Problems
- Minimum Moves to Equal Array Elements II
- Minimum Cost to Move Chips to The Same Position
- Minimum Operations to Make the Array Increasing