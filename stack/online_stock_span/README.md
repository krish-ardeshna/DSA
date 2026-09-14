# Online Stock Span
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/online-stock-span/  
Difficulty: Medium  
Pattern: Monotonic Stack (Streaming/Online)

## What I understood
Design a class that receives daily stock prices one at a time (streaming, "online" - future prices unknown when processing current one). For each new price, return its "span" - the number of consecutive days (including today) where the price was `<=` today's price, counting backward until a higher price is found.

## Example
```
Input
["StockSpanner","next","next","next","next","next","next","next"]
[[],[100],[80],[60],[70],[60],[75],[85]]
Output
[null,1,1,1,2,1,4,6]
```

## Idea
Maintain a monotonic decreasing stack of `(price, index)` pairs. When a new price arrives, pop all stack entries with price `<=` current price - these represent days that are "absorbed" into today's span (since today's price is high enough to span over them). The span equals the distance back to the nearest remaining day with a HIGHER price (or back to the very start if the stack becomes empty).

## Approach: Monotonic Decreasing Stack with (price, index) Pairs
- Maintain a running `idx` (day counter) and a stack of `(price, index)`.
- On each `next(price)` call: increment `idx`.
- Pop all stack entries where `price <= current price` (they're spanned over).
- Compute span: `idx - (index of new stack top, or -1 if empty)`.
- Push `(price, idx)` onto stack, return computed span.

## Key Observation
Storing `(price, index)` pairs (not just price) lets span be computed via simple index arithmetic once the stack settles - no need to count popped elements directly, since the remaining top's index directly gives the boundary of the span.

## When to use this
If problem involves:
- Streaming/online queries where each new element needs a "how far back does a pattern hold" answer
- Similar to Next Greater Element but processed incrementally rather than batch
→ Think **monotonic stack maintained across calls (as a class member)**, popping elements that are "dominated" by the new arrival.

## Edge Cases
- Strictly increasing prices (span grows each day: 1, 2, 3, ...).
- Strictly decreasing prices (span always 1).
- Repeated identical prices (equal prices get absorbed due to `<=` comparison).
- First price ever received (span = 1, stack starts empty).

## Complexity
### Approach
Time: **O(1)** amortized per call - each price pushed and popped from stack at most once across all calls           
Space: **O(n)** - stack storage across all calls

where:
- `n` = total number of `next()` calls made

## Related Problems
- Next Greater Element I
- Daily Temperatures
- Next Greater Element II
- Maximum Width Ramp