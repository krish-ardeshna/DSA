# Ninja's Training
Platform: TakeUForward (Striver's DSA Sheet)  
Problem Link: https://takeuforward.org/practice/dsa/ninja's-training  
Difficulty: Medium  
Pattern: DP on Grid-like States (Day, Last Task)

## What I understood
A ninja trains for `n` days. Each day he picks exactly one of 3 tasks (0, 1, 2), and each task gives some merit points that differ per day (`points[day][task]`). He cannot do the SAME task on two consecutive days. Find the maximum total merit points he can earn over all `n` days.

## Example
```
Input
points = [[10,40,70],
          [20,50,80],
          [30,60,90]]
Output
210
```
Explanation: day 0 task 2 (70), day 1 task 1 (50), day 2 task 2 (90). 70 + 50 + 90 = 210.

```
Input
points = [[18,11,19],
          [4,13,7],
          [1,8,13]]
Output
45
```
Explanation: 19 + 13 + 13 = 45 (tasks 2, 1, 2).

```
Input
points = [[1,2,5],
          [3,1,1],
          [3,3,3]]
Output
11
```
Explanation: 5 + 3 + 3 = 11 (tasks 2, 0, 1).

## Idea (shared by all three techniques)
Greedy fails here: picking the biggest task today can force a poor pick tomorrow. So every choice must be compared against its future consequence, which is exactly what DP does.

**State:** `f(day, last)` = maximum points obtainable from day `0` to day `day`, given that the task done on day `day + 1` (the "next" day) was `last`, so `last` is forbidden today. `last = 3` means no restriction (used for the very first call, since the last day has no day after it).

**Recurrence:**
```
f(day, last) = max over task != last of ( points[day][task] + f(day - 1, task) )
```
**Base case:** `day == 0` has no earlier day, so just take the best `points[0][task]` where `task != last`.

**Answer:** `f(n - 1, 3)`.

There are only `n * 4` distinct states, each doing 3 tries of work. Plain recursion would recompute the same `(day, last)` pairs over and over, which is why the three techniques below all exist to avoid that.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly as a recursive function, then cache each `(day, last)` result in a `dp` table the first time it is computed. Any later call with the same arguments returns instantly.

### Steps
- Create `dp[n][4]` filled with `-1` (meaning "not computed yet").
- Call `f(n - 1, 3, ...)`.
- At `day == 0`: return the max of `points[0][task]` over tasks other than `last`.
- Otherwise, if `dp[day][last] != -1`, return the cached value.
- Else try every `task != last`: `points[day][task] + f(day - 1, task)`, keep the max, store it in `dp[day][last]`, return it.

### Complexity
Time: **O(n * 4 * 3)**, which is O(n)           
Space: **O(n * 4)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion entirely. Fill the same `dp[day][last]` table from day 0 upward, so every value a state needs (`dp[day - 1][...]`) is already computed.

### Steps
- Base row (`day = 0`), computed by hand:
  - `dp[0][0] = max(points[0][1], points[0][2])` (task 0 forbidden)
  - `dp[0][1] = max(points[0][0], points[0][2])` (task 1 forbidden)
  - `dp[0][2] = max(points[0][0], points[0][1])` (task 2 forbidden)
  - `dp[0][3] = max of all three` (nothing forbidden)
- For `day = 1 .. n - 1`, for each `last = 0..3`:
  - Try every `task != last`, take `points[day][task] + dp[day - 1][task]`, keep the max.
- Answer is `dp[n - 1][3]`.

### Complexity
Time: **O(n * 4 * 3)**, which is O(n)           
Space: **O(n * 4)** for the dp table (no recursion stack)

---

## Approach 3: Tabulation with Space Optimization

### Idea
Row `day` of the table only ever reads row `day - 1`. Older rows are never touched again, so storing all `n` rows is wasteful. Keep just one previous row (`prev`) and build the current row (`temp`) from it.

### Steps
- `prev` of size 4 holds the base row exactly as in Approach 2.
- For each `day = 1 .. n - 1`:
  - Build `temp[last]` for `last = 0..3` using `matrix[day][task] + prev[task]` over `task != last`.
  - Copy `prev = temp` before moving to the next day.
- Answer is `prev[3]`.

### Complexity
Time: **O(n * 4 * 3)**, which is O(n)           
Space: **O(1)**, only two arrays of size 4 regardless of `n`

---

## Key Observation
All three techniques solve the exact same recurrence, the only difference is how much memory they spend remembering past results:

- Memoization = natural to write, but pays for recursion stack plus the table.
- Tabulation = same table, no recursion, no stack overflow risk.
- Space optimization = keeps only the single previous row, since the recurrence never looks back further than one day.

The extra `last = 3` slot is a neat trick: it represents "no restriction", so the very first call needs no special case.

## When to use this
If problem involves:
- A choice per step where the choice is restricted by the previous step's choice
- Maximizing or minimizing a total across steps
- A small set of options per step (here 3)
→ Think **DP with state = (step index, previous choice)**, then compress to a rolling row when only the previous step is read.

## Edge Cases
- `n = 1`: no restriction applies, answer is the max of the 3 tasks on that single day (`dp[0][3]`).
- All points equal: answer is `n * value`, any valid alternating pick works.
- One task much larger than the others every day (cannot repeat it, so it is picked on alternate days).
- Large `n`: Approach 1 uses O(n) recursion depth, so prefer Approach 2 or 3 if stack depth is a concern.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n * 4 * 3) | O(n * 4) + O(n) stack |
| Tabulation | O(n * 4 * 3) | O(n * 4) |
| Tabulation + Space Optimization | O(n * 4 * 3) | O(1) |

where:
- `n` = number of days

## Related Problems
- Paint House
- House Robber
- Climbing Stairs
- Minimum Path Sum