# Trapping Rain Water
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/trapping-rain-water/  
Difficulty: Hard  
Pattern: Two Pointer / Prefix Max + Suffix Max

## What I understood
Given an elevation map (`height` array), compute how much water it can trap after raining. Water above each bar is bounded by the shorter of the tallest bar to its left and tallest bar to its right, minus its own height.

## Example
```
Input
height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output
6
```
```
Input
height = [4,2,0,3,2,5]
Output
9
```

---

## Approach 1: Two Pointer (O(1) Space)

### Idea
Water trapped at any position depends on `min(leftMax, rightMax) - height[i]`. Two pointers from both ends let you decide which side's max is smaller WITHOUT knowing the other side's exact max — if `height[l] < height[r]`, then whatever `rightMax` currently is, it's guaranteed to be `>= height[l]`'s relevant bound, so it's safe to process the left side using only `leftMax`.

### Steps
- Two pointers `l = 0`, `r = n-1`, track `leftMax` and `rightMax` incrementally.
- If `height[l] < height[r]`: process left side — if `height[l] >= leftMax`, update `leftMax`; else add `leftMax - height[l]` to water. Move `l++`.
- Else: process right side symmetrically using `rightMax`, move `r--`.
- Continue until pointers meet.

### Complexity
Time: **O(n)**      
Space: **O(1)**

---

## Approach 2: Prefix Max + Suffix Max Arrays

### Idea
Directly compute, for every index, the maximum height to its left (inclusive) and maximum height to its right (inclusive) using two separate passes. Water at each index is then simply `min(prefixMax[i], suffixMax[i]) - height[i]`.

### Steps
- Build `prefixMax[i]` = max height from index 0 to i, computed left to right.
- Build `suffixMax[i]` = max height from index i to n-1, computed right to left.
- Final pass: sum `min(prefixMax[i], suffixMax[i]) - height[i]` for every index.

### Complexity
Time: **O(n)**      
Space: **O(n)** — two auxiliary arrays

---

## Key Observation
Both approaches rely on the same core formula (`min(leftMax, rightMax) - height[i]`) — the two-pointer version cleverly avoids needing to know the EXACT leftMax/rightMax at every point, only needing to know which side's max is currently smaller, letting it operate in O(1) space instead of storing full prefix/suffix arrays.

## When to use this
If problem involves:
- Per-element bound depending on both left-side and right-side aggregate (max, min, etc.)
→ Think **two pointer with running max on both sides** for O(1) space, or **prefix/suffix precomputed arrays** for a simpler-to-reason-about O(n) space version.

## Edge Cases
- Strictly increasing or decreasing elevation (no water trapped).
- Single bar or empty array (no water possible).
- All bars same height (no water trapped).
- V-shaped or W-shaped elevation profiles.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Two Pointer | O(n) | O(1) |
| Prefix Max + Suffix Max | O(n) | O(n) |

where:
- `n` = number of bars in height array

## Related Problems
- Trapping Rain Water II
- Container With Most Water
- Product of Array Except Self
- Candy