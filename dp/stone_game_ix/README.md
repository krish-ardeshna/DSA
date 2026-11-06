# Stone Game IX
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/stone-game-ix/  
Difficulty: Medium  
Pattern: Game Theory + Modular Counting

## What I understood
Alice and Bob alternately remove one stone each turn (Alice first). A player loses immediately if, after their removal, the running sum of all removed stones so far is divisible by 3. Both play optimally to avoid losing (and force opponent into losing). Return true if Alice wins.

## Example
```
Input
stones = [2,1]
Output
true
```
```
Input
stones = [2]
Output
false
```

## Idea
Only each stone's value `mod 3` matters for tracking the running sum's divisibility — actual values are irrelevant beyond that. Bucket stones into 3 groups by `value % 3`: `cnt[0]`, `cnt[1]`, `cnt[2]`. Game outcome reduces to pure counting logic based on these bucket sizes and their parity, no simulation needed.

## Approach: Mod-3 Bucket Counting + Parity Case Analysis
- Count stones by `value % 3` into `cnt[0]`, `cnt[1]`, `cnt[2]`.
- Stones with remainder 0 never change the running sum's mod-3 state — they only matter for how many turns get "skipped" without changing danger.
- If `cnt[0]` is even → players must strictly alternate placing remainder-1 and remainder-2 stones; Alice wins only if both `cnt[1] > 0` and `cnt[2] > 0` (both types available to sustain alternation without hitting a multiple of 3).
- If `cnt[0]` is odd → the odd zero-count flips turn parity once, changing the win condition to require an imbalance: Alice wins only if `abs(cnt[1] - cnt[2]) > 2`.

## Key Observation
This is a known derived result for this specific game structure — the "mod 3 bucket + parity of zero-count" reduction comes from analyzing how remainder-0 stones act as parity-flippers while remainder-1/2 stones must alternate to avoid completing a multiple of 3. Not something to re-derive by brute simulation; recognize the pattern for stone-elimination games keyed on a modulus.

## When to use this
If problem involves:
- Turn-based elimination game where losing condition depends on sum divisible by some modulus `m`
- Optimal play from both sides
→ Think **bucket elements by value % m, reduce to counting/parity case analysis** rather than simulating turns.

## Edge Cases
- Single stone (`cnt` mostly empty, likely false since Alice's first move ends game immediately if divisible by 3, otherwise Bob never gets to move meaningfully in this edge case — verify against constraints).
- All stones same remainder bucket.
- `cnt[0]` very large relative to others.
- Stones already balanced (`cnt[1] == cnt[2]`).

## Complexity
### Approach
Time: **O(n)** — single pass to bucket stones       
Space: **O(1)** — fixed 3-element count array

where:
- `n` = number of stones

## Related Problems
- Stone Game
- Stone Game II
- Stone Game III
- Divisible Substring / Subarray problems (mod-based counting)