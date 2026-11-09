# Find Servers That Handled Most Number of Requests
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/  
Difficulty: Hard  
Pattern: Simulation + Ordered Set (Next Free Server, Circular) + Min-Heap (Busy Servers)

## What I understood
There are `k` servers numbered `0` to `k - 1`. Request `i` arrives at `arrival[i]` and needs `load[i]` time units. Arrival times are strictly increasing. The rules for request `i` are:
- If every server is busy, the request is dropped.
- Otherwise, try server `i % k`. If it is busy, try `(i + 1) % k`, `(i + 2) % k`, and so on (wrapping around), until a free server is found. That server handles the request.

Return the list of servers (indices) that handled the most requests, in any order.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3]
Output
[1]
```
Explanation: request 0 goes to server 0 (busy until 6). Request 1 goes to server 1 (busy until 4). Request 2 goes to server 2 (busy until 6). Request 3 wants server 0 (busy), then server 1 (free at 4), so server 1 handles it (busy until 7). Request 4 wants server 1 (busy), server 2 (busy), server 0 (busy), so it is dropped. Counts are `[1,2,1]`, so server 1 is the busiest.

```
Input
k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
Output
[0]
```
Explanation: request 0 goes to server 0 (free at 2). Request 1 goes to server 1 (free at 4). Request 2 wants server 2 and it is free, so server 2 takes it (free at 4). Request 3 wants server 0 (free at 2, so free now), so server 0 takes it. Counts are `[2,1,1]`, so server 0 is the busiest.

```
Input
k = 3, arrival = [1,2,3], load = [10,12,11]
Output
[0,1,2]
```
Explanation: each request goes to a different server and none is dropped. Every server handled 1 request, so all of them are returned.

## Idea (shared by both approaches)
Process the requests in order. For request `i`, the question is: which free server comes first when scanning from `i % k` and wrapping around? Count how many requests every server handles. At the end, return all servers with the maximum count.

## Approach 1: Brute Force

### Idea
Keep `freeAt[s]` for every server. For each request, try the servers `i % k`, `(i + 1) % k`, ... in order, and take the first one with `freeAt[s] <= arrival[i]`.

### Steps
- `freeAt[s] = 0` and `count[s] = 0` for all servers.
- For each request `i`, for `j = 0` to `k - 1`: let `s = (i + j) % k`.
- If `freeAt[s] <= arrival[i]`, do `count[s]++`, set `freeAt[s] = arrival[i] + load[i]`, and stop the scan.
- If no server was free, the request is dropped.
- Find the maximum count and return every server with it.

### Complexity
Time: **O(n * k)**  
Space: **O(k)**

Too slow when `n` and `k` are both large.

---

## Approach 2: Ordered Set (Free Servers) + Min-Heap (Busy Servers)

### Idea
Replace the scan with two structures:
- `available`: a `set<int>` of free server indices. `lower_bound(i % k)` gives the first free server at index `>= i % k`. If there is none, wrap around to `available.begin()`.
- `busy`: a min-heap of `(finish time, server)`. Before each request, move every server with `finish <= arrival[i]` back into `available`.

### Steps
- Put all servers `0..k-1` into `available`. `busy` is empty.
- For each request `i`:
  - While `busy.top().finish <= arrival[i]`, pop it and insert its server into `available`.
  - If `available` is empty, skip the request (it is dropped).
  - `it = available.lower_bound(i % k)`. If `it == end`, use `begin()`.
  - Take `server = *it`, erase it from `available`, do `count[server]++`.
  - Push `(arrival[i] + load[i], server)` into `busy`.
- Find the maximum count and return every server with it.

### Complexity
Time: **O(n log k)**  
Space: **O(k)**

Each server moves between the set and the heap at most once per request it handles, and every move costs O(log k).

---

## Key Observation
The hard part is "first free server at or after `i % k`, wrapping around". A sorted set answers this in O(log k) with one `lower_bound`, and the wrap-around is just `begin()` when `lower_bound` finds nothing. The heap makes "release the servers that finished" cheap, because only the earliest finish time needs to be checked.

`arrival[i] + load[i]` can reach about `2 * 10^9`, which does not fit in `int`. The finish time is stored as `long long`.

## When to use this
If problem involves:
- Assigning each event to "the next available resource from a starting position, wrapping around"
- Resources that become free at known times
→ Think **ordered set for the free resources (`lower_bound` + wrap), min-heap for the busy ones**.

## Edge Cases
- `k = 1` (a request is either handled or dropped, the answer is `[0]`).
- More servers than requests (some servers handle `0`, the answer still comes from the maximum count).
- Every server busy at some arrival (the request is dropped, no count changes).
- A server that finishes exactly at `arrival[i]` is free (so the comparison is `<=`).
- A tie for the maximum (return all of them).
- Large `arrival` and `load` values (use `long long` for finish times).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n * k) | O(k) |
| Ordered Set + Min-Heap | O(n log k) | O(k) |

where:
- `n` = number of requests
- `k` = number of servers

## Related Problems
- Process Tasks Using Servers
- Meeting Rooms III
- Meeting Rooms II
- Single-Threaded CPU