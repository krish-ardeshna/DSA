# Count Islands With Total Value Divisible by K
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/  
Difficulty: Medium  
Pattern: Graph - Grid DFS (Iterative, Sum Per Island)

## What I understood
(Written from memory, recheck against the LC statement.)  
A grid holds non-negative integers. A cell with value `0` is water, and a cell with a positive value is land. An island is a group of land cells connected up, down, left and right (diagonals do not connect). The value of an island is the sum of all its cell values. Return the number of islands whose total value is divisible by `k`.

## Example
```
Input
grid = [[0,2,1,0,0],
        [0,5,0,0,5],
        [0,0,1,0,0],
        [0,1,4,7,0],
        [0,2,0,0,8]], k = 5
Output
2
```
Explanation: the islands have sums 8 (top left group), 5 (the lone 5 on the right), 15 (the group in the lower middle) and 8 (the corner 8). Only the sums 5 and 15 are divisible by 5, so the answer is 2.

```
Input
grid = [[3,0,3,0],
        [0,3,0,3],
        [3,0,3,0]], k = 3
Output
6
```
Explanation: land cells only touch diagonally, so every `3` is its own island, and each has sum 3, which is divisible by 3.

## Idea
This is the standard "count islands" problem with one extra number to carry along: the sum of the island being explored. Scan the grid; each time an unvisited land cell is found, it starts a new island. Explore the whole island, add up its cell values, then check the sum against `k`.

## Approach: Explore Each Island With a Stack, Add Up Its Values, Check Divisibility
- Scan every cell. Skip water (`0`).
- On a land cell, start a new island: `sum = grid[i][j]`, mark the cell as visited by setting it to `0`, and push it on a stack.
- While the stack is not empty, pop a cell and look at its 4 neighbours. For every neighbour that is inside the grid and still land (`> 0`): add its value to `sum`, set it to `0`, push it.
- After the stack empties, the whole island has been summed. If `sum % k == 0`, add 1 to the answer.
- Return the answer.

## Key Observation
Setting a visited cell to `0` turns it into water, so the grid itself is the visited array, and the same island can never be counted twice. The value is added at the moment a cell is marked (not when it is popped), which guarantees every cell is added exactly once. An explicit stack is used instead of recursion, because an island can have up to `m * n` cells and a deep recursion could overflow the call stack. The sum is stored as `long long`, since an island can add up to more than `int` allows.

## When to use this
If problem involves:
- A property of each connected region (sum, size, maximum) rather than just the count of regions
→ Think **flood fill that carries an accumulator**, then test the accumulator once the region is finished.

## Edge Cases
- No land at all (answer 0).
- A single land cell (its own island, divisible only if its value is divisible by `k`).
- Land cells touching only diagonally (separate islands).
- `k = 1` (every island counts, so the answer is the number of islands).
- Very large cell values (the island sum needs `long long`).

## Complexity
### Approach
Time: **O(m * n)**, each cell is pushed and popped at most once         
Space: **O(m * n)** for the stack in the worst case

where:
- `m` = number of rows
- `n` = number of columns

## Related Problems
- Number of Islands
- Max Area of Island
- Number of Closed Islands
- Island Perimeter