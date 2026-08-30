# Removing Minimum and Maximum From Array
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/  
Difficulty: Medium  
Pattern: Array - Greedy (Three Removal Strategies)

## What I understood
Elements can only be removed from the front or the back of the array (one at a time, either end). Find the minimum number of removals needed so that both the array's minimum value AND maximum value have been removed.

## Example
```
Input
nums = [2,10,7,5,4,1,8,6]
Output
5
```
```
Input
nums = [0,-4,19,1,8,-2,-3,5]
Output
3
```

## Idea
Since removals only happen from front or back, only 3 possible strategies exist to eliminate both min and max positions: remove everything up through the rightmost of the two (from front), remove everything from the leftmost of the two onward (from back), or remove from both ends simultaneously (front up through the left one, back up through the right one). Compute cost for all 3, take the minimum.

## Approach: Find Min/Max Positions, Compare 3 Removal Strategies
- Find index of minimum value (`mn`) and maximum value (`mx`) via single pass.
- Let `left = min(mn, mx)`, `right = max(mn, mx)` (positions regardless of which is actually min or max).
- Strategy 1 (`front`): remove from front through `right` → costs `right + 1` removals.
- Strategy 2 (`back`): remove from back through `left` → costs `n - left` removals.
- Strategy 3 (`both`): remove front through `left` AND back through `right` → costs `(left + 1) + (n - right)`.
- Return minimum of all 3 strategies.

## Key Observation
Only these 3 strategies are ever optimal — removing "extra" from one end beyond what's needed to reach the target position never helps, and any valid removal sequence covering both target positions must correspond to one of these three prefix/suffix combinations, since removals are restricted to the two ends only.

## When to use this
If problem involves:
- Removing elements only from front/back ends
- Need to guarantee removal of specific target position(s)
→ Think **enumerate the small fixed set of prefix/suffix combinations covering all target positions, take the minimum cost one**.

## Edge Cases
- Min and max are the same element (only possible if array has 1 element, or all elements equal — though then min==max value but could still be different positions if duplicates exist).
- Min and max adjacent to each other.
- Min and max at opposite ends of array.
- Single element array (trivially both min and max, 1 removal).

## Complexity
### Approach
Time: **O(n)** — single pass to find min/max positions          
Space: **O(1)**

where:
- `n` = number of elements

## Related Problems
- Minimum Number of Operations to Move All Balls to Each Box
- Maximum Number of Removable Characters
- Remove Elements to Minimize Array Value
- Shortest Subarray to be Removed to Make Array Sorted