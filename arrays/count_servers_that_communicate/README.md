# Count Servers that Communicate
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-servers-that-communicate/  
Difficulty: Medium  
Pattern: Matrix + Row/Column Counting

## What I understood
Given an `m x n` grid where `1` is a server and `0` is an empty cell. Two servers communicate if they are in the same row or in the same column. Return the number of servers that can communicate with at least one other server.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
grid = [[1,0],[0,1]]
Output
0
```
Explanation: the two servers are in different rows and different columns, so no server communicates.

```
Input
grid = [[1,0],[1,1]]
Output
3
```
Explanation: the servers at `(0,0)` and `(1,0)` share column 0. The servers at `(1,0)` and `(1,1)` share row 1. All 3 servers communicate.

```
Input
grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output
4
```
Explanation: the servers at `(0,0)` and `(0,1)` share row 0. The servers at `(1,2)` and `(2,2)` share column 2. The server at `(3,3)` is alone. So 4 servers communicate.

## Idea (shared by both approaches)
A server at `(i, j)` communicates if its row has another server, or its column has another server. That is the same as `rowCount[i] > 1` or `colCount[j] > 1`. Only these two counts matter. The path between servers does not matter, because any two servers in the same row or column are directly connected.

## Approach 1: Brute Force

### Idea
For every server, scan its whole row and its whole column to look for another server.

### Steps
- `ans = 0`.
- For each cell `(i, j)` with `grid[i][j] == 1`:
  - Scan row `i`. If any other cell `(i, c)` with `c != j` is `1`, the server communicates.
  - If not found, scan column `j`. If any other cell `(r, j)` with `r != i` is `1`, the server communicates.
  - If it communicates, `ans++`.
- Return `ans`.

### Complexity
Time: **O(m * n * (m + n))**  
Space: **O(1)**

---

## Approach 2: Row Count + Column Count

### Idea
Count the servers in every row and every column once. Then each server can answer the question in O(1).

### Steps
- Create `rows[m]` and `cols[n]`, all `0`.
- First pass: for every server `(i, j)`, do `rows[i]++` and `cols[j]++`.
- Second pass: for every server `(i, j)`, if `rows[i] > 1` or `cols[j] > 1`, do `ans++`.
- Return `ans`.

### Complexity
Time: **O(m * n)**  
Space: **O(m + n)**

---

## Key Observation
Communication is only "same row or same column", so a server never needs to know WHERE the other server is, only whether one exists. Two small count arrays answer this for the whole grid. No graph search is needed.

## When to use this
If problem involves:
- A grid where cells interact only through their row or their column
- Questions like "is there another one in my row or column?"
→ Think **count per row and per column, then check the counts**.

## Edge Cases
- No servers (answer `0`).
- One server (answer `0`, its row and column counts are both `1`).
- A full row of servers (all of them communicate).
- A server whose row is alone but whose column has others (still counts).
- `m = 1` or `n = 1` (all servers in the line communicate when there are at least 2).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(m * n * (m + n)) | O(1) |
| Row Count + Column Count | O(m * n) | O(m + n) |

where:
- `m` = number of rows
- `n` = number of columns

## Related Problems
- Number of Islands
- Lonely Pixel I
- Set Matrix Zeroes
- Most Stones Removed with Same Row or Column