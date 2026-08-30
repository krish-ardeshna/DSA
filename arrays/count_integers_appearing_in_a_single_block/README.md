# Count Integers Appearing in a Single Block
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-integers-appearing-in-a-single-block/  
Difficulty: Easy (contest problem) 
Pattern: Array - Block Detection + Bounded Counting

## What I understood
A "block" is a maximal run of consecutive equal elements in the array (e.g. `[1,1,2,2,1]` has 3 blocks: `1,1` / `2,2` / `1`). A value is counted if it appears as exactly one such block total across the whole array (not one occurrence — one distinct contiguous block). Values are bounded (1-100 per constraint), enabling a fixed-size counting array.

## Example
```
Input
nums = [1,1,2,2,1,3]
Output
2
```

## Idea
Rather than counting raw occurrences, count how many separate contiguous blocks each value forms. A new block starts whenever the current element differs from the previous one (or it's the very first element). Track block-count per value using a fixed array (bounded 1-100), then scan for values with exactly 1 block.

## Approach: Detect Contiguous Blocks, Count Values Appearing in Exactly One Block
- Single pass through `nums`: whenever `i == 0` or `nums[i] != nums[i-1]` (start of a new block), increment `blocks[nums[i]]`.
- This correctly counts distinct blocks per value, not raw element occurrences.
- Scan values 1 to 100, count how many have `blocks[x] == 1`.
- Return that count.

## Key Observation
The condition `nums[i] != nums[i-1]` (or first index) is the key block-boundary detector — it ensures each contiguous run of the same value increments its block-count exactly once, regardless of how long that run is, correctly distinguishing "appears in one block" from "appears once" or "appears in one contiguous group of any length."

## When to use this
If problem involves:
- Detecting contiguous runs/blocks/groups within an array
- Values bounded to a small fixed range
→ Think **boundary-detection via previous-element comparison + fixed-size counting array**.

## Edge Cases
- Value appearing in multiple separate blocks (not counted, since `blocks[x] > 1`).
- Value appearing in exactly one long contiguous block (counted).
- Value never appearing at all (`blocks[x] == 0`, not counted).
- Single element array (trivially one block per its single value).

## Complexity
### Approach
Time: **O(n)** — single pass plus fixed 100-value scan      
Space: **O(1)** — fixed 101-size array regardless of input size

where:
- `n` = number of elements

## Related Problems
- Max Consecutive Ones
- Find the Largest Almost Missing Integer
- Count Number of Homogenous Substrings
- Count Subarrays With Fixed Bounds