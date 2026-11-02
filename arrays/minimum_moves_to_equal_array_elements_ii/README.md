# Minimum Moves to Equal Array Elements II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/  
Difficulty: Medium  
Pattern: Math + Sorting (Median Minimizes the Sum of Absolute Differences)

## What I understood
Given an integer array `nums`. In one move you can add `1` to ONE element or subtract `1` from ONE element. Return the minimum number of moves needed to make all elements equal.

## Example
```
Input
nums = [1,2,3]
Output
2
```
Explanation: `[1,2,3]` -> `[2,2,3]` -> `[2,2,2]`. Move 1 up to 2, then move 3 down to 2.

```
Input
nums = [1,10,2,9]
Output
16
```
Explanation: sorted it is `[1,2,9,10]`. With the target `9`, the costs are `8 + 7 + 0 + 1 = 16`.

```
Input
nums = [7]
Output
0
```
Explanation: one element is already equal to itself.

## Idea
Pick a target value `t` and bring every element to `t`. An element `x` needs exactly `|x - t|` moves, so the total is:
```
cost(t) = sum over all x of |x - t|
```
We need the `t` that makes `cost(t)` smallest.

**The best `t` is the median.** Why: move `t` one step to the right.
- Every element on the left of `t` gets 1 farther away (cost goes up by 1 for each).
- Every element on the right of `t` gets 1 closer (cost goes down by 1 for each).

So moving right helps as long as there are more elements on the right than on the left, and it stops helping when both sides have the same count. That balance point is the median.

For an even number of elements, any value between the two middle elements gives the same cost, so picking `nums[n / 2]` is fine.

The target does not have to be one of the original elements, but the median always is, and it is always an optimal choice.

---

## Approach: Sort + Median

### Idea
Sort the array, take the middle element as the target, and add up the distances.

### Steps
- Sort `nums`.
- `median = nums[n / 2]`.
- Start `ans = 0` (use `long long` for the running sum).
- For every `x`, add `|x - median|`, computed in `long long` so the subtraction cannot overflow.
- Return `ans`.

### Complexity
Time: **O(n log n)** for the sort  
Space: **O(1)** extra (the sort works in place)

---

## Key Observation
Minimizing a sum of absolute differences means the median. This is the one fact to remember: the MEAN minimizes the sum of squares, the MEDIAN minimizes the sum of absolute values.

The median can also be found without a full sort using quickselect (`nth_element`), which makes the whole solution `O(n)` on average. The idea stays the same, only the way of finding the middle element changes.

Compare with Minimum Moves to Equal Array Elements (I): there a move raises `n - 1` elements, so the answer is the distance to the MINIMUM. Here a move changes one element up or down, so the answer is the distance to the MEDIAN.

## When to use this
If problem involves:
- Moving many values to ONE common point
- A cost equal to the sum of absolute differences
→ Think **median**: sort (or quickselect) and measure the distances to it.

## Edge Cases
- One element (answer `0`).
- All elements equal (answer `0`).
- Even length (both middle values are fine).
- Negative numbers (only differences matter).
- Large values, such as `[-10^9, 10^9]` (the subtraction needs `long long`; the answer `2 * 10^9` still fits in `int`).
- The answer is returned as `int`, which is safe because LeetCode guarantees it fits in 32 bits.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Sort + Median | O(n log n) | O(1) |

where:
- `n` = number of elements

## Related Problems
- Minimum Moves to Equal Array Elements
- Best Meeting Point
- Minimum Operations to Make a Uni-Value Grid
- Minimum Cost to Make Array Equal