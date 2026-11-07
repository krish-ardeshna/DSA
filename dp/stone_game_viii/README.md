# Stone Game VIII
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/stone-game-viii/  
Difficulty: Hard  
Pattern: Game Theory + DP (Prefix Sum + Suffix Max)

## What I understood
`n` stones in a row. Each turn, current player picks an integer `x >= 2`, removes the first `x` stones, and gains a score equal to the sum of those `x` stones. Game ends when fewer than 2 stones remain. Both play optimally (Alice first) to maximize their own score minus opponent's. Return the final score difference (Alice's total - Bob's total) under optimal play.

## Example
```
Input
stones = [-1,2,-3,4,-5]
Output
5
```
```
Input
stones = [7,-6,5,10,5,-2,-6]
Output
13
```

## Idea
A player's move (taking first `x` stones) always corresponds to taking `prefix[x-1]` as their score — since every "take" must start from the current front, the only real choice each turn is the prefix boundary. This transforms the problem into: for a fixed set of possible prefix sums, alternate choosing one from the largest possible to work backward, deciding at each step whether taking the current prefix (netting `prefix[i] - dp`) beats the best result found so far.

## Approach: Prefix Sum + Right-to-Left DP on Prefix Values
- Build prefix sum array of stones.
- Initialize `dp = prefix[n-1]` (base case: taking everything, only valid if it's the last remaining choice).
- Iterate `i` from `n-2` down to `1` (since `x >= 2` means smallest usable prefix index is 1): `dp = max(dp, prefix[i] - dp)` — either keep the best score found so far, or take up through index `i` and let the opponent get `dp` from the remaining state.
- Return final `dp` (Alice's optimal score difference from the start).

## Key Observation
The DP works backward over prefix values, not forward over turns — because the "state" that matters is which prefix boundary is chosen, and later (smaller-index) choices can always fall back to a later-computed (larger-index) result. This backward formulation avoids needing explicit turn tracking.

## When to use this
If problem involves:
- Turn-based scoring games where each move consumes a prefix/contiguous block from one end
- Score difference optimization (not absolute score)
→ Think **prefix sum + backward DP comparing "take now" vs "best found so far"**.

## Edge Cases
- All negative stone values.
- Minimum valid array size (`n = 2`, forces a single possible move).
- Large arrays with alternating signs.
- All identical stone values.

## Complexity
### Approach
Time: **O(n)**      
Space: **O(n)** — prefix sum array

where:
- `n` = number of stones

## Related Problems
- Stone Game
- Stone Game II
- Stone Game III
- Stone Game IX