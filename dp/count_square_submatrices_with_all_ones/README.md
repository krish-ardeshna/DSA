# Count Square Submatrices with All Ones
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/  
Difficulty: Medium  
Pattern: DP on Grids (Largest Square Ending at Each Cell)

## What I understood
Given an `m x n` binary matrix, count how many square submatrices (of any size) contain only 1s.

## Example
```
Input
matrix = [[0,1,1,1],[1,1,1,1],[0,1,1,1]]
Output
15
```
Explanation: 10 squares of size 1x1, 4 squares of size 2x2, 1 square of size 3x3.

```
Input
matrix = [[1,0,1],[1,1,0],[1,1,0]]
Output
7
```
Explanation: 6 squares of size 1x1 and 1 square of size 2x2.

## Idea (shared by all three techniques)
Counting every square directly would mean checking every top-left corner and every size, which is slow. The trick is to count squares by their BOTTOM-RIGHT corner instead.

**State:** `dp[i][j]` = side length of the largest all-ones square whose bottom-right corner is at `(i, j)`.

**Key fact:** a largest square of side `k` at `(i, j)` also contains squares of sides `k - 1`, `k - 2`, ..., `1`, all with the same bottom-right corner. So `dp[i][j]` is also **the number of squares ending at `(i, j)`**.

**Recurrence:** a square of side `k` at `(i, j)` needs three neighbouring squares of side `k - 1`: the one ending above, the one ending to the left, and the one ending diagonally up-left. So:
```
if matrix[i][j] == 0:  dp[i][j] = 0
else:                  dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
```

**Base case:** cells in the first row or column (or out of range) can only form a 1x1 square, so they contribute `1` if the cell is `1`.

**Answer:** the sum of `dp[i][j]` over every cell.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Define `f(i, j)` as the value of `dp[i][j]` and compute it recursively from its three neighbours. Out-of-range cells return 0, which naturally makes first-row and first-column cells equal to `1 + 0 = 1`. Cache each result, then sum `f` over every cell.

### Steps
- Create `dp[m][n]` filled with `-1` (not computed yet).
- `f(i, j)`: return 0 if out of range or if the cell is `0`.
- If `dp[i][j]` is already filled, return it.
- Otherwise `dp[i][j] = 1 + min(f(i - 1, j), f(i, j - 1), f(i - 1, j - 1))`.
- Loop over all cells, adding `f(i, j)` to the answer.

### Complexity
Time: **O(m * n)**          
Space: **O(m * n)** for the dp table, plus **O(m + n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Fill the table row by row from the top-left, so the three neighbours (above, left, diagonal) are always ready. Add each cell's value into the running answer as it is filled.

### Steps
- Create `dp[m][n]` of zeros.
- For each cell: if `matrix[i][j] == 1`:
  - First row or first column: `dp = 1`.
  - Otherwise `dp = 1 + min(up, left, diagonal)`.
- Add `dp[i][j]` to `ans` (zero for 0-cells).
- Return `ans`.

### Complexity
Time: **O(m * n)**          
Space: **O(m * n)**, no recursion stack

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `i` only reads row `i - 1` (for up and diagonal) and the cell just filled in the current row (for left). Keep two rows, `prev` and `curr`, instead of the whole table.

### Steps
- `prev` holds the previous row, `curr` is the row being built.
- Same rule as tabulation, with `up = prev[j]`, `left = curr[j - 1]`, `diagonal = prev[j - 1]`.
- Add each `curr[j]` to `ans`.
- After each row, `prev = curr`.

### Complexity
Time: **O(m * n)**          
Space: **O(n)**, two rows of size `n`

---

## Key Observation
Counting squares by bottom-right corner turns a counting problem into the classic "largest square" DP, because the largest square at a corner automatically accounts for every smaller square at that same corner. The `min` of the three neighbours is the bottleneck: the new square can only be as big as the smallest of them plus one. The answer is the sum of the whole table, not just a single cell.

## When to use this
If problem involves:
- Counting or finding the largest square (or rectangle) of identical cells in a grid
- A cell whose answer depends on its up, left and diagonal neighbours
→ Think **DP where `dp[i][j]` = size of the best square ending at this cell**, with `1 + min(up, left, diag)`.

## Edge Cases
- All zeros (answer 0).
- All ones (answer is the sum of `min(i + 1, j + 1)`-style growth, all cells contribute).
- Single row or column (every 1 is its own 1x1 square).
- A hole of one `0` in the middle of ones (limits the squares passing through it).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(m * n) | O(m * n) + O(m + n) stack |
| Tabulation | O(m * n) | O(m * n) |
| Tabulation + Space Optimization | O(m * n) | O(n) |

where:
- `m` = number of rows
- `n` = number of columns

## Related Problems
- Maximal Square
- Maximal Rectangle
- Count Submatrices With All Ones
- Largest Plus Sign