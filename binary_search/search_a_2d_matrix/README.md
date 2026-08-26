# Search a 2D Matrix
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/search-a-2d-matrix/  
Difficulty: Medium  
Pattern: Binary Search (2D Matrix, Two-Level Search)

## What I understood
Matrix has each row sorted ascending, and the first element of each row is greater than the last element of the previous row (making the whole matrix effectively one sorted sequence). Determine if `target` exists anywhere in the matrix.

## Example
```
Input
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output
true
```
```
Input
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output
false
```

---

## Approach 1: Binary Search on Rows + Binary Search within Row

### Idea
Since rows are ordered relative to each other (last element of row `i` < first element of row `i+1`), binary search can locate the correct row in O(log n), then binary search within that row in O(log m) — achieving true O(log(n*m)) overall.

### Steps
- Binary search over row indices: check if `target` falls within `[matrix[mid][0], matrix[mid][m-1]]`.
- If it fits, binary search within that specific row for the exact value.
- If `target` is beyond the row's range, adjust `low`/`high` to search other rows.

### Complexity
Time: **O(log n + log m) = O(log(n*m))**
Space: **O(1)**

---

## Approach 2: Linear Scan Rows + Binary Search within Row

### Idea
Simpler but less optimal — scan rows one by one (not exploiting the row-to-row ordering via binary search), and once the correct row range is found, binary search within it.

### Steps
- Linearly iterate rows, checking if `target` falls within `[matrix[i][0], matrix[i][m-1]]`.
- Once found, binary search within that row.
- Return false if no row's range contains target.

### Complexity
Time: **O(n + log m)** — linear row scan dominates for large n
Space: **O(1)**

---

## Key Observation
The matrix's special property (rows fully ordered end-to-end) is what allows treating row-selection itself as a binary search problem — without that property, linear row scanning (Approach 2) would be necessary regardless. Approach 1 fully exploits the structure for optimal complexity; Approach 2 only partially exploits it (within-row search only).

## When to use this
If problem involves:
- 2D matrix with strict full ordering (not just row-wise and column-wise sorted, but end-to-end sorted like a flattened 1D array)
→ Think **binary search on row, then binary search within row** for O(log(n*m)).

## Edge Cases
- Single row or single column matrix.
- Target smaller than the smallest element or larger than the largest element.
- Target exactly at a row boundary (first or last element of a row).
- Single element matrix.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Binary Search Rows | O(log(n*m)) | O(1) |
| Linear Scan Rows | O(n + log m) | O(1) |

where:
- `n` = number of rows
- `m` = number of columns

## Related Problems
- Search a 2D Matrix II
- Find Minimum in Rotated Sorted Array
- Search in Rotated Sorted Array
- Kth Smallest Element in a Sorted Matrix