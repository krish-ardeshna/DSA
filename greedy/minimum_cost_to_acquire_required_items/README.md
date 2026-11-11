# Minimum Cost to Acquire Required Items
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/  
Difficulty: Not verified (recent problem, check LC page)  
Pattern: Greedy + Math (Pairs First, Then the Remainder)

## What I understood
(Reconstructed from the accepted code, recheck the exact statement on the LC page.)
Three kinds of items can be bought as many times as needed:
- an item that adds `1` to `total1` and costs `cost1`,
- an item that adds `1` to `total2` and costs `cost2`,
- an item that adds `1` to BOTH `total1` and `total2` and costs `costBoth`.

Return the minimum total cost so that `total1 >= need1` and `total2 >= need2`.

## Example
(These examples are hand-made and hand-traced, they are NOT copied from LC. Replace them with the LC examples before pushing.)
```
Input
cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2
Output
3
```
Explanation: the common part is `min(3, 2) = 2` units. A "both" item (cost 1) is cheaper than buying one of each (3 + 2 = 5), so the common part costs `2 * 1 = 2`. The leftover is `3 - 2 = 1` unit of type 1. A "both" item (cost 1) beats a type 1 item (cost 3), so it adds `1 * 1 = 1`. Total is 3.

```
Input
cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3
Output
22
```
Explanation: the common part is 2 units. Buying separately (5 + 4 = 9) is cheaper than a "both" item (15), so the common part costs `2 * 9 = 18`. The leftover is 1 unit of type 2. A type 2 item (cost 4) beats a "both" item (cost 15), so it adds 4. Total is 22.

```
Input
cost1 = 5, cost2 = 3, costBoth = 1, need1 = 0, need2 = 0
Output
0
```
Explanation: nothing is needed, so nothing is bought.

## Idea (shared by both approaches)
If `b` "both" items are bought, the rest is bought separately:
```
cost(b) = b * costBoth + max(0, need1 - b) * cost1 + max(0, need2 - b) * cost2
```
The answer is the minimum of `cost(b)` over all `b`.

## Approach 1: Brute Force

### Idea
Try every possible number `b` of "both" items from `0` to `max(need1, need2)`, compute `cost(b)`, and keep the smallest.

### Steps
- `best = infinity`.
- For `b = 0` to `max(need1, need2)`: compute `b * costBoth + max(0, need1 - b) * cost1 + max(0, need2 - b) * cost2`.
- Update `best` with the minimum.
- Return `best`.

### Complexity
Time: **O(max(need1, need2))**  
Space: **O(1)**

Too slow when the needs are very large.

---

## Approach 2: Greedy (Common Part + Remainder)

### Idea
Split the needs into two parts:
- The COMMON part: `min(need1, need2)` units where BOTH totals still need items. Each unit costs `min(costBoth, cost1 + cost2)`, because it is either one "both" item or one item of each type.
- The REMAINDER: `|need1 - need2|` units where only the larger total still needs items. Each unit costs `min(costBoth, cost)` of that type, because a "both" item still works (its extra effect is just wasted).

### Steps
- `common = min(need1, need2)`.
- `ans = common * min(costBoth, cost1 + cost2)`.
- If `need1 > need2`, add `(need1 - need2) * min(costBoth, cost1)`.
- Otherwise, add `(need2 - need1) * min(costBoth, cost2)`.
- Return `ans`.

### Complexity
Time: **O(1)**  
Space: **O(1)**

---

## Key Observation
`cost(b)` is a piecewise linear function of `b`, so its minimum is at an end of a piece: `b = 0`, `b = min(need1, need2)`, or `b = max(need1, need2)`. The greedy formula is these cases in one line. Each unit is priced on its own, so there is no need to search.

`cost1 + cost2` and the products are stored as `long long`, because the result can reach about `2 * 10^18`.

## When to use this
If problem involves:
- Buying exact amounts of two things, with a combo that gives one of each
- A cost function that is linear in each piece
→ Think **price the common part and the remainder separately, using the cheaper option for each**.

## Edge Cases
- `need1 == need2` (no remainder).
- `need1 = 0` or `need2 = 0` (all units are remainder, `common = 0`).
- Both needs `0` (answer `0`).
- `costBoth` cheaper than both single items (use only "both" items, the remainder is also bought with them).
- `costBoth` more expensive than `cost1 + cost2` (never buy a "both" item).
- Large costs and needs (use `long long`, including for `cost1 + cost2`).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(max(need1, need2)) | O(1) |
| Greedy | O(1) | O(1) |

where:
- `need1`, `need2` = required amounts of the two kinds of item

## Related Problems
- Coin Change
- Minimum Cost For Tickets
- Min Cost Climbing Stairs
- Climbing Stairs