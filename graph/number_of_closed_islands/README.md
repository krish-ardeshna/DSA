# Number of Closed Islands
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/number-of-closed-islands/  
Difficulty: Medium  
Pattern: Graph - Grid DFS (Flood Fill From the Border First)

## What I understood
A grid has land (`0`) and water (`1`). An island is a group of land cells connected up, down, left and right. A **closed island** is an island completely surrounded by water on all four sides, so it never touches the edge of the grid. Return the number of closed islands.

## Example
```
Input
grid = [[0,0,1,0,0],
        [0,1,0,1,0],
        [0,1,1,1,0]]
Output
1
```
Explanation: the land touching the left and right edges is not closed. Only the single `0` in the middle of the top row group is surrounded by water.

```
Input
grid = [[0,0,0],
        [0,1,0],
        [0,0,0]]
Output
0
```
Explanation: the ring of land touches the border everywhere, and the middle cell is water.

## Idea
The word "closed" is the only difficulty: an island is NOT closed if any of its cells sits on the border, because then it can escape off the grid. So deal with the border first.

1. Flood fill (turn into water) every land cell that is connected to a border cell. After this, any land that is left cannot reach the edge.
2. Every remaining island is closed. Count them, flooding each one as it is counted so it is never counted twice.

## Approach: Flood Every Land Cell Touching the Border, Then Count the Remaining Islands
- `dfs(r, c)`: if the cell is outside the grid or is not land (`!= 0`), stop. Otherwise mark it as water (`1`) and visit its four neighbours.
- Run `dfs` from every cell of the first and last column, and every cell of the first and last row. This removes all land connected to the border.
- Scan the whole grid. Each time a land cell is found, it must belong to a closed island: add 1 to the answer and run `dfs` from it to flood the entire island.
- Return the answer.

## Key Observation
Marking visited cells by changing the grid itself (`0` becomes `1`) does two jobs at once: it acts as the visited array, and it makes the final count correct, since a flooded island looks exactly like water. The cost is that the input grid is modified, which is fine here. The recursion goes at most `m * n` levels deep, about 10^4 for the maximum 100 x 100 grid, which is safe.

## When to use this
If problem involves:
- Counting regions that must not touch the border (closed islands, surrounded regions)
→ Think **remove everything connected to the border first, then count or fill what is left**.

## Edge Cases
- No land at all (answer 0).
- All land (one island touching the border, answer 0).
- Island whose only border contact is a single cell (it is still not closed).
- A closed island inside a closed island's water ring (counted separately, since only the `0` cells are islands).
- Tiny grids such as `1 x n` or `m x 1` (every cell is on the border, answer 0).

## Complexity
### Approach
Time: **O(m * n)**, each cell is visited a constant number of times         
Space: **O(m * n)** for the recursion stack in the worst case

where:
- `m` = number of rows
- `n` = number of columns

## Related Problems
- Number of Islands
- Surrounded Regions
- Number of Enclaves
- Max Area of Island