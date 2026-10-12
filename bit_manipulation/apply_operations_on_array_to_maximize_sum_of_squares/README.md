# Apply Operations on Array to Maximize Sum of Squares
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/  
Difficulty: Hard  
Pattern: Bit Manipulation + Greedy (Per-Bit Counting)

## What I understood
One operation: pick two different indices `i` and `j`, then set `nums[i] = nums[i] AND nums[j]` and `nums[j] = nums[i] OR nums[j]` (both computed from the old values). Any number of operations are allowed. After that, pick `k` elements from the array and maximize the sum of their squares. Return the answer modulo `10^9 + 7`.

## Example
```
Input
nums = [2,6,5,8], k = 2
Output
261
```
Explanation: bits can be regrouped so the array becomes [0,6,0,15]. Picking 15 and 6 gives 225 + 36 = 261.

```
Input
nums = [4,5,4,7], k = 3
Output
90
```
Explanation: pick 7, 5, 4, which gives 49 + 25 + 16 = 90.

## Idea
Look at one bit position across the whole array. For two numbers `a` and `b`, the operation gives `(a AND b, a OR b)`:
- Both have the bit: both results keep it (count stays 2).
- Only one has the bit: AND loses it, OR keeps it, so the bit just lands on one specific side (count stays 1).
- Neither has it: nothing.

So the **number of set bits at each position never changes**, but the operation can push those bits around between elements. That means we can regroup the bits any way we like, as long as one number holds at most one copy of each bit position.

Now the goal becomes: given `cnt[b]` copies of each bit `b`, build `k` numbers maximizing the sum of squares. Squares reward concentration, so make the numbers as large as possible, one at a time.

## Approach: Count Set Bits Per Position, Greedily Build k Largest Numbers
- Build `cnt[b]` = how many array elements have bit `b` set (31 positions is enough since values are below `2^30`).
- Repeat `k` times:
  - Start with `x = 0`.
  - For every bit `b` with `cnt[b] > 0`, set that bit in `x` and use up one copy (`cnt[b]--`).
  - Add `x * x` to the answer (mod `10^9 + 7`).
- Return the answer.

## Key Observation
Each new number takes one copy of every bit that is still available, so the first number is the largest possible, the second is the next largest, and so on. Taking all high bits first is also what the greedy wants, because a high bit is worth more than every lower bit combined. Overflow check: `x < 2^31`, so `x * x < 2^62` fits in `long long`, and the running `ans` is reduced mod `10^9 + 7` each step.

## When to use this
If problem involves:
- An operation that moves bits around but keeps the per-position bit count (AND/OR pair, swap-like bit operations)
- Maximizing a convex objective such as a sum of squares
→ Think **count bits per position, then build the answer greedily from those counts**. Ignore the array shape entirely.

## Edge Cases
- `k = 1` (answer is the single largest number buildable, which takes one copy of every bit that exists).
- `k = n` (all elements chosen, still regroup bits to maximize the squares).
- All elements are 0 (answer 0).
- Many copies of the same bit (leftover copies go into later numbers).

## Complexity
### Approach
Time: **O(31 * (n + k))**, which is O(n + k)        
Space: **O(1)**, one fixed array of 31 counters

where:
- `n` = number of elements
- `k` = number of elements chosen

## Related Problems
- Maximum XOR After Operations
- Maximum OR
- Largest Combination With Bitwise AND Greater Than Zero
- Sort Integers by The Number of 1 Bits