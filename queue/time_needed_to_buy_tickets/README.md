# Time Needed to Buy Tickets

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/time-needed-to-buy-tickets/  
Difficulty: Easy  
Pattern: Queue, Simulation Observation

## What I understood
People stand in a queue to buy tickets.

Each second, the person at the front buys one ticket. If they still need more tickets, they move to the back of the queue. Find the total time until the person at index `k` finishes buying all their tickets.

## Example

```
Input
tickets = [2,3,2], k = 2

Output
6
```

## Idea
Instead of simulating the queue, count how many times each person gets to buy a ticket before person `k` finishes.

People before or at index `k` can buy at most `tickets[k]` tickets, while people after `k` get at most `tickets[k] - 1` turns because the process stops as soon as person `k` buys their last ticket.

## Approach: Counting
- Traverse every person once.
- If the person is before or at index `k`, add `min(tickets[i], tickets[k])`.
- Otherwise, add `min(tickets[i], tickets[k] - 1)`.
- The total gives the required time.

## Key Observation
The queue order never needs to be simulated.

Each person's contribution to the total time depends only on their position relative to `k` and the number of tickets person `k` needs.

## When to use this
If the problem involves:
- Queue simulation
- Counting contributions
- Position-based observations
- Avoiding repeated simulation

→ Think **Simulation Observation**.

## Edge Cases
- Only one person in the queue.
- `k` is the first person.
- `k` is the last person.
- Everyone needs one ticket.

## Complexity

### Approach
Time: **O(n)**

Space: **O(1)**

where:
- `n` = number of people in the queue

## Related Problems
- Number of Students Unable to Eat Lunch
- Dota2 Senate
- Design Circular Queue