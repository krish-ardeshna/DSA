# Pascal's Triangle
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/pascals-triangle/  
Difficulty: Easy  
Pattern: Math (Combinatorics) / DP (Build from Previous Row)

## What I understood
Generate first `numRows` rows of Pascal's Triangle. Each number is the sum of the two numbers directly above it (from the previous row); edges of each row are always 1.

## Example
```
Input
numRows = 5
Output
[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```
```
Input
numRows = 1
Output
[[1]]
```

---

## Approach 1: Combinatorics Formula (nCr Incremental)

### Idea
Row `r`'s elements are binomial coefficients `C(r, 0), C(r, 1), ..., C(r, r)`. Rather than computing full factorials (expensive, overflow-prone), compute each coefficient incrementally from the previous one using the identity `C(r, k) = C(r, k-1) * (r-k+1) / k`.

### Steps
- For each row `r` from 0 to `numRows-1`, start with `ans = 1` (first element, `C(r,0)`).
- For `col` from 1 to `r`: `ans = ans * (r - col + 1) / col` — gives next binomial coefficient.
- Push each computed value into row's result vector.

### Complexity
Time: **O(numRows²)** — each row takes O(row length) to build
Space: **O(numRows²)** — output storage (required)

---

## Approach 2: DP (Build from Previous Row)

### Idea
Directly apply Pascal's Triangle recurrence: each interior element equals sum of the two elements above it from the previous row. First and last element of every row are always 1.

### Steps
- For each row `i`, initialize a vector of size `i+1`, all values pre-filled with 1 (handles both edges automatically).
- For interior positions `j` from 1 to `i-1`: `row[j] = res[i-1][j-1] + res[i-1][j]`.
- Push completed row into result.

### Complexity
Time: **O(numRows²)**
Space: **O(numRows²)** — output storage (required)

---

## Key Observation
Both approaches are O(n²) overall since total elements across all rows is O(n²) — the real distinction is combinatorics avoids storing/depending on previous row (each row computed independently), while DP explicitly reuses the previous row's stored values. DP approach is more intuitive and directly mirrors the triangle's visual construction.

## When to use this
If problem involves:
- Building rows/values based on binomial coefficients or combinatorial structure
- Sequential dependency where each step builds on the prior result
→ Think **DP building from previous state** (simpler, avoids incremental division/overflow concerns) or **direct formula** (useful if only a single row/value is needed without building all prior rows).

## Edge Cases
- `numRows = 1` → output is just `[[1]]`.
- Row 0 and Row 1 (smallest non-trivial rows).
- Combinatorics approach: division must happen after multiplication each step to avoid precision loss (careful with integer division order).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Combinatorics Formula | O(numRows²) | O(numRows²) |
| DP (Previous Row) | O(numRows²) | O(numRows²) |

where:
- `numRows` = number of rows to generate

## Related Problems
- Pascal's Triangle II
- Unique Paths
- Combination Sum
- Sum of Digits in Base K