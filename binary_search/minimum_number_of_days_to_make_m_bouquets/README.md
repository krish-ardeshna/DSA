# Minimum Number of Days to Make m Bouquets
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/  
Difficulty: Medium  
Pattern: Binary Search on Answer

## What I understood
`bloomDay[i]` is the day flower `i` blooms. Need `m` bouquets, each requiring `k` adjacent (contiguous) bloomed flowers. Find the minimum day on which it becomes possible to make all `m` bouquets; return -1 if impossible (not enough total flowers).

## Example
```
Input
bloomDay = [1,10,3,10,2], m = 3, k = 1
Output
3
```
```
Input
bloomDay = [1,10,3,10,2], m = 3, k = 2
Output
-1
```

## Idea
"Minimum day such that condition X becomes achievable" is a classic binary-search-on-answer setup — feasibility is monotonic (once possible on day `d`, it stays possible on all days `> d`, since more flowers bloom over time). Binary search over possible day values, using a feasibility check that counts how many bouquets can be formed by day `d` using contiguous bloomed-flower runs.

## Approach: Binary Search on Day + Feasibility Check
- Early exit: if `m * k > n` (not enough flowers total), return -1 immediately.
- Binary search `day` between min and max value in `bloomDay`.
- Feasibility check (`possible`): scan flowers, track `cnt` = length of current contiguous bloomed run (`bloomDay[i] <= day`). On hitting an unbloomed flower, convert completed run into bouquets (`cnt / k`), reset `cnt`. After loop, account for trailing run.
- If total bouquets `>= m` → day is feasible, try smaller (`high = mid - 1`).
- Else → day too early, need later (`low = mid + 1`).
- Return `low` (smallest feasible day) after search converges.

## Key Observation
Bouquets require *contiguous* bloomed flowers, not just any k bloomed flowers total — this is why a simple count isn't enough; must track and reset run-length at each break in bloomed sequence, converting each completed run into `run_length / k` bouquets.

## When to use this
If problem involves:
- Finding minimum/maximum value satisfying a monotonic feasibility condition
- Feasibility check itself is O(n) or better
→ Think **binary search on answer**, wrapping an O(n) (or better) feasibility function.

## Edge Cases
- Not enough total flowers (`m * k > n`) → immediate -1.
- `k == 1` (every bloomed flower can be its own bouquet, no adjacency constraint effectively).
- All flowers bloom same day (trivial single feasible day).
- `m` requiring exactly all flowers used with no slack.

## Complexity
### Approach
Time: **O(n log(max_day - min_day))** — binary search over day range, O(n) feasibility check per iteration      
Space: **O(1)** extra

where:
- `n` = number of flowers

## Related Problems
- Koko Eating Bananas
- Capacity To Ship Packages Within D Days
- Split Array Largest Sum
- Minimum Number of Days to Disconnect Island