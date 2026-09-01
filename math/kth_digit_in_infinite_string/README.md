# K-th Digit in Infinite String
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/k-th-digit-in-infinite-string/  
Difficulty: Medium (contest problem)  
Pattern: Math - Digit Position Search (Block Counting)

## What I understood
An infinite string is built by some deterministic number-generation rule (each "block" of numbers derived from a base value `b`, expanded to `10*b + offset` pattern based on parity). Given position `k` (1-indexed), find the digit at that position without constructing the string.

## Example
```
Input
k = 15
Output
(digit at position 15 in the infinite string, per generation rule)
```

## Idea
Direct construction is infeasible for large `k`. Instead, work in stages: first handle the small base case (`k <= 9`, directly digits 1-9). Beyond that, digits are grouped into "digit-length blocks" (all `d`-digit `b` values contributing digits in batches of `10*(d+1)` per `b`). Skip entire blocks whose total digit count is less than remaining `k`, narrowing down until the exact block, then exact number, then exact digit index within that number is located.

## Approach: Digit-Length Block Search
- Handle base case `k <= 9` directly (single digit answer).
- Subtract those 9 positions from `k`, then search stage-by-stage:
  - For current digit-length `d`, compute how many `b` values exist in this stage (`start` to `start*10 - 1`), and each contributes `10*(d+1)` digit positions.
  - If total digits in this stage `< k`, subtract and move to next stage (`d++`, `start *= 10`).
  - Otherwise, locate exact `b` (`blockIndex`), exact position within that `b`'s digit range (`pos`), then which generated number (`numberIndex`) and which digit of that number (`digitIndex`).
  - Generated number computed via parity rule: even `b` → `10*b + numberIndex`, odd `b` → `10*b + 9 - numberIndex` (mirrored/reversed order).
  - Convert to string, index into it, return that digit.

## Key Observation
This kind of "find k-th digit without building the string" problem always reduces to the same 3-step narrowing: find the right block/stage, find the right number within that stage, find the right digit within that number — using division/modulo arithmetic on cumulative digit counts rather than iteration.

## When to use this
If problem involves:
- Very large `k` (needs long long, direct construction infeasible)
- Digit-position lookup into an implicitly/infinitely generated sequence
→ Think **stage-by-stage block search with cumulative count subtraction**, narrowing via division/modulo.

## Edge Cases
- `k` within first 9 (base case digits 1-9).
- `k` exactly on a stage boundary.
- Very large `k` requiring multiple stage transitions (`d` growing).
- Odd vs even `b` producing mirrored digit generation — verify parity logic carefully against problem's exact generation rule.

## Complexity
### Approach
Time: **O(log k)** — stage search shrinks geometrically (digit-length grows), few iterations even for huge k            
Space: **O(1)** extra (excluding temporary string conversion)

where:
- `k` = target position (given as long long due to potential magnitude)

## Related Problems
- Nth Digit
- Find the Kth Digit
- Digit Count in Range
- Base 7