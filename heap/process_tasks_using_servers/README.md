# Process Tasks Using Servers
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/process-tasks-using-servers/  
Difficulty: Medium  
Pattern: Two Heaps (Available Servers + Busy Servers) + Time Simulation

## What I understood
There are `n` servers with weights `servers[i]` and `m` tasks. Task `j` is added to a queue at second `j`, and `tasks[j]` is the number of seconds it needs to run. At each second, assign waiting tasks (in queue order) to free servers. Always pick the free server with the smallest weight, and on a tie the smallest index. A server that starts a task at second `t` becomes free again at second `t + tasks[j]`. If no server is free, wait until one becomes free. Return `ans`, where `ans[j]` is the index of the server that processes task `j`.

## Example
(Hand-traced and checked by simulation. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
servers = [3,3,2], tasks = [1,2,3,2,1,2]
Output
[2,2,0,2,1,2]
```
Explanation: at second 0, task 0 goes to server 2 (weight 2, free until 1). At second 1, server 2 is free again, so task 1 goes to server 2 (free until 3). At second 2, task 2 goes to server 0 (weight 3, smallest index, free until 5). At second 3, server 2 is free again, so task 3 goes to server 2 (free until 5). At second 4, task 4 goes to server 1 (free until 5). At second 5, all servers are free, so task 5 goes to server 2.

```
Input
servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
Output
[1,4,1,4,1,3,2]
```
Explanation: task 0 starts at 0 on server 1 (weight 1, free at 2). Task 1 starts at 1 on server 4 (weight 2, free at 2). Task 2 starts at 2 on server 1 again (free at 4). Task 3 starts at 3 on server 4 (free at 7). Task 4 starts at 4 on server 1 (free at 9). Task 5 starts at 5 on server 3 (weight 3, free at 7). Task 6 starts at 6 on server 2 (weight 4, free at 7).

## Idea (shared by both approaches)
Track the current `time`. For each task `i` in order:
- The task cannot start before second `i`, so `time = max(time, i)`.
- If no server is free at `time`, jump `time` forward to the earliest finish time.
- Among the free servers, choose the smallest `(weight, index)`.
- The chosen server becomes free again at `time + tasks[i]`.

`time` never goes backwards, because tasks are handled in order.

## Approach 1: Brute Force

### Idea
Keep `freeAt[s]` for every server. For each task, scan all servers to find the free ones, and pick the best `(weight, index)`.

### Steps
- `freeAt[s] = 0` for all servers, `time = 0`.
- For each task `i`: `time = max(time, i)`.
- Find `earliest = min(freeAt)`. If every server is busy, `time = max(time, earliest)`.
- Scan all servers. Among those with `freeAt[s] <= time`, choose the smallest weight (the first one scanned wins a tie, so the index is the smallest).
- Save the index in `ans`, and set `freeAt[best] = time + tasks[i]`.

### Complexity
Time: **O(m * n)**  
Space: **O(n)**

Too slow when both `n` and `m` are large.

---

## Approach 2: Two Heaps (Available + Busy)

### Idea
Use two min-heaps so that every choice costs O(log n):
- `available`: free servers, ordered by `(weight, index)`.
- `busy`: running servers, ordered by `(finish time, weight, index)`.

### Steps
- Push every server into `available`.
- For each task `i`: `time = max(time, i)`.
- Pop from `busy` every server with `finish <= time` and push it back into `available`.
- If `available` is empty, set `time = busy.top().finish`, then free every server finished by that time.
- Pop the best server from `available`, record its index, and push `(time + tasks[i], weight, index)` into `busy`.

### Complexity
Time: **O((n + m) log n)**  
Space: **O(n + m)** (heaps hold `n` servers, `ans` holds `m` results)

---

## Key Observation
Two things are needed quickly: "which free server is best" and "which busy server finishes first". A heap fits each one. The time jump when every server is busy means the simulation never loops second by second, so large task times cost nothing extra. Finish times can reach about `m + max(tasks)` times several tasks in a row, so keep time in `long long`.

## When to use this
If problem involves:
- Simulating an event over time, where each step needs the best resource that is currently free
- Resources that become free again at a known time
→ Think **two heaps: one for available resources, one for busy resources keyed by finish time**.

## Edge Cases
- More servers than tasks (the busy heap never needs to be emptied).
- One server (tasks run one after another, the time jump matters a lot).
- All servers have the same weight (the smallest index decides every choice).
- A server that finishes exactly at `time` is free (so the comparison is `<=`).
- A long task makes every server busy, and the next tasks must wait (time jump to the earliest finish).
- Large finish times (use `long long`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(m * n) | O(n) |
| Two Heaps | O((n + m) log n) | O(n + m) |

where:
- `n` = number of servers
- `m` = number of tasks

## Related Problems
- Meeting Rooms II
- Single-Threaded CPU
- Meeting Rooms III
- Task Scheduler