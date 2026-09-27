# Image Overlap
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/image-overlap/  
Difficulty: Medium  
Pattern: Hashing (Shift Vector Frequency Counting)

## What I understood
Two binary square matrices (`img1`, `img2`) of the same size. `img1` can be translated (shifted) by some `(dRow, dCol)` amount (parts moving out of bounds are discarded, not wrapped). Find the translation that maximizes the number of overlapping 1s between the shifted `img1` and `img2`.

## Example
```
Input
img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output
3
```

## Idea
Rather than trying every possible shift explicitly and re-checking the whole grid for each (which would be expensive), observe that for a 1 in `img1` at `(r1, c1)` to overlap with a 1 in `img2` at `(r2, c2)` after a shift, the shift amount must be exactly `(r2 - r1, c2 - c1)`. So, collect the coordinates of every 1 in both images, then for EVERY pair of (one from img1, one from img2), compute the implied shift vector and count how often each specific shift vector occurs — the shift with the highest frequency gives the maximum overlap count directly.

## Approach: All Ones-Pair Shift Vectors + Frequency Map
- Collect all `(row, col)` positions where `img1[i][j] == 1` into `ones1`, similarly `ones2` for `img2`.
- For every pair `(r1,c1)` from `ones1` and `(r2,c2)` from `ones2`: compute `rowDist = r2-r1`, `colDist = c2-c1` (the shift that would align these two specific 1s).
- Increment `freq[{rowDist, colDist}]`, track running maximum.
- Return the maximum frequency found — this directly represents the largest overlap count achievable by that specific shift.

## Key Observation
Each shift-vector frequency count directly equals the number of overlapping 1s for that shift, without needing to actually simulate the shift and rescan the entire grid — because every (img1-one, img2-one) pair that would align under a given shift contributes exactly one match, and the frequency map naturally aggregates all such pairs per shift vector.

## When to use this
If problem involves:
- Finding optimal translation/alignment between two sparse binary grids
→ Think **collect sparse "on" positions, compute pairwise offset vectors, frequency-count offsets** rather than brute-force simulating every possible shift over the full grid.

## Edge Cases
- No 1s in either image (answer is 0, loops don't execute).
- Images already perfectly aligned (shift `(0,0)` has max frequency).
- Sparse images with very few 1s (pairwise approach is efficient here).
- Dense images with many 1s (pairwise approach becomes O(k²) where k = count of 1s, could be large).

## Complexity
### Approach
Time: **O(k1 * k2)** where k1, k2 are counts of 1s in img1 and img2 respectively (worst case O(n⁴) if fully dense)          
Space: **O(k1 * k2)** — frequency map storage in worst case

where:
- `n` = grid dimension
- `k1`, `k2` = number of 1s in img1 and img2

## Related Problems
- Rotate Image
- Set Matrix Zeroes
- Number of Islands
- Convolution-based Image Alignment