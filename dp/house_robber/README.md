# House Robber
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/house-robber/  
Difficulty: Medium  
Pattern: DP (Take / Not Take, Rolling Variables)

## What I understood
Houses are in a row, each with some money. Robbing two adjacent houses triggers an alarm, so no two adjacent houses can both be robbed. Find the maximum total money that can be robbed.

## Example
```
Input
nums = [1,2,3,1]
Output
4
```
```
Input
nums = [2,7,9,3,1]
Output
12
```

## Idea
At each house there are only two choices. Take it, which adds its value to the best total up to TWO houses back (the previous house must be skipped). Or skip it, which keeps the best total up to the previous house. The best of the two is the answer for this position. Since each step only looks back at the last two results, no full dp array is needed.

## Approach: Space-Optimized DP With Two Rolling Values
- `prev1` holds the best total up to the previous house, `prev2` holds the best total up to two houses back.
- Start with `prev1 = nums[0]` and `prev2 = 0`.
- For each house `i` from 1 onward:
  - `take = nums[i] + prev2` (the `prev2` term is only added from `i > 1`, for `i = 1` there is no house two back to add).
  - `notTake = prev1`.
  - `curi = max(take, notTake)`.
- Shift forward: `prev2 = prev1`, `prev1 = curi`.
- Return `prev1`.

## Key Observation
Skipping a house does not mean the next one MUST be robbed, it only means the best total carries forward unchanged. That is why `notTake` simply reuses `prev1`, and why the recurrence stays correct even when several houses in a row are skipped.

## When to use this
If problem involves:
- Choosing elements from a sequence with a "no two adjacent" restriction
- Maximizing a total where each position is a take / not-take decision
→ Think **take = value + result two steps back, not take = result one step back**, then roll the two variables.

## Edge Cases
- Single house (answer is that house's money, loop does not run).
- Two houses (answer is the larger of the two).
- All houses with equal money.
- Large value sitting between two small ones (skipping both neighbors beats taking either).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(1)**

where:
- `n` = number of houses

## Related Problems
- House Robber II
- House Robber III
- Climbing Stairs
- Delete and Earn