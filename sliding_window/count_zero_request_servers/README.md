# Count Zero Request Servers
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-zero-request-servers/  
Difficulty: Medium  
Pattern: Offline Queries + Sorting + Sliding Window (Two Pointers)

## What I understood
There are `n` servers numbered `1` to `n`. `logs[i] = [server_id, time]` means server `server_id` received a request at `time`. Given an integer `x` and an array `queries`, for each `queries[i]` return how many servers did NOT receive any request in the time interval `[queries[i] - x, queries[i]]` (both ends included).

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
Output
[1,2]
```
Explanation: for query `10`, the interval is `[5,10]`. Server `1` (time 5) and server `2` (time 6) got requests, so only server `3` is idle, answer 1. For query `11`, the interval is `[6,11]`. Only server `2` (time 6) got a request, so servers `1` and `3` are idle, answer 2.

```
Input
n = 3, logs = [[2,4],[2,1],[1,2],[3,1]], x = 2, queries = [3,4]
Output
[0,1]
```
Explanation: for query `3`, the interval is `[1,3]`. Servers `2` (time 1), `1` (time 2) and `3` (time 1) all got requests, answer 0. For query `4`, the interval is `[2,4]`. Server `2` (time 4) and server `1` (time 2) got requests, so only server `3` is idle, answer 1.

## Idea (shared by both approaches)
For one query `t`, the answer is `n - (number of different servers with a log time in [t - x, t])`. So the real task is counting different server ids inside a time window.

## Approach 1: Brute Force

### Idea
For every query, scan all logs. Mark every server that has a log inside the interval, and count how many different servers were marked.

### Steps
- For each query `t`, create `seen[n + 1]` and `active = 0`.
- For each log `[id, time]`, if `t - x <= time <= t` and `seen[id]` is false, set `seen[id] = true` and `active++`.
- `ans[i] = n - active`.

### Complexity
Time: **O(q * (L + n))**  
Space: **O(n)**

Too slow for the largest inputs (this is the approach that times out on LC).

---

## Approach 2: Sort Logs + Sort Queries + Sliding Window

### Idea
Answer the queries OFFLINE in increasing order of time. Then the interval `[t - x, t]` only moves to the right, so one sliding window over the time-sorted logs is enough. Keep `freq[id]` = number of logs of server `id` inside the window, and `active` = number of servers with `freq > 0`.

### Steps
- Sort `logs` by time.
- Store queries as `(time, original index)` and sort them by time.
- `left = right = active = 0`.
- For each query `(time, idx)` in sorted order:
  - Move `right` forward while `logs[right].time <= time`. When `freq[id]` goes from `0` to `1`, do `active++`.
  - Move `left` forward while `logs[left].time < time - x`. When `freq[id]` goes from `1` to `0`, do `active--`.
  - `ans[idx] = n - active`.
- Return `ans`.

### Complexity
Time: **O(L log L + q log q)**  
Space: **O(n + q)**

Each log enters the window once and leaves it once, so the pointer movement is O(L) in total.

---

## Key Observation
The queries do not need to be answered in the given order. Sorting them makes the window boundaries monotone, so each log is added once and removed once. The `freq` array turns "count different servers" into a counter that updates in O(1).

## When to use this
If problem involves:
- Many queries, each asking about a time window or range
- Queries that can be answered in any order (offline)
→ Think **sort the queries, then sweep with a sliding window**.

## Edge Cases
- No logs at all (every query answers `n`).
- A server with many logs in the window (`freq` counts them, so `active` is not counted twice).
- Logs with the same time (all are added together by the `<=` condition).
- Logs exactly at `t - x` or `t` (both ends are inside the window, so removal uses `<` and not `<=`).
- Duplicate queries (sorting keeps both with their own index).
- All logs before `t - x` (they are all removed, answer `n`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(q * (L + n)) | O(n) |
| Sort + Sliding Window | O(L log L + q log q) | O(n + q) |

where:
- `n` = number of servers
- `L` = number of logs
- `q` = number of queries

## Related Problems
- Longest Substring with At Most K Distinct Characters
- Number of Flowers in Full Bloom
- Minimum Interval to Include Each Query
- Fruit Into Baskets