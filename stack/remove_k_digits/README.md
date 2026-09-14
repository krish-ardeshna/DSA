# Remove K Digits
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/remove-k-digits/  
Difficulty: Medium  
Pattern: Monotonic Stack (Greedy Digit Removal)

## What I understood
Given a non-negative integer string `num`, remove exactly `k` digits to make the resulting number as small as possible (while preserving relative digit order). Remove leading zeros in the result; if the result is empty, return "0".

## Example
```
Input
num = "1432219", k = 3
Output
"1219"
```
```
Input
num = "10200", k = 1
Output
"200"
```

## Idea (shared by both approaches)
To minimize the number, greedily remove digits that are LARGER than the digit immediately following them — a larger digit followed by a smaller one means removing the larger digit always helps (shifts a smaller digit into a more significant position). A monotonic increasing stack naturally implements this. Both approaches below share this exact core logic — they only differ in HOW leading zeros are stripped from the final result.

---

## Approach 1: Strip Leading Zeros AFTER Reversing

### Idea
Build the answer by popping the stack (which yields reverse order), reverse it back to correct order, THEN strip leading zeros from the front of the correctly-ordered string using a simple index scan.

### Steps
- Build stack greedily as described above; handle leftover `k` by popping from the end (top of stack).
- Pop stack into `ans` (this yields reversed order), then `reverse(ans)` to restore correct digit order.
- Scan from the front of `ans`, skip over `'0'` characters, take substring from first non-zero digit onward.
- Return "0" if the result is empty after stripping.

### Complexity
Time: **O(n)**      
Space: **O(n)**

---

## Approach 2: Strip Trailing Zeros BEFORE Reversing (Equivalent Trick)

### Idea
Same stack-building logic, but exploits a neat property: right after popping the stack into `ans` (before reversing), `ans` is exactly the REVERSE of the final answer. This means `ans.back()` at that point corresponds to the FIRST digit of the eventual result — so stripping trailing `'0'`s from `ans` at this stage is mathematically equivalent to stripping leading zeros from the final number, just performed before the reverse step instead of after.

### Steps
- Build stack identically to Approach 1.
- Pop stack into `ans` (reversed order, not yet flipped back).
- While `ans.back() == '0'`, pop from the back of `ans` — this removes what will become LEADING zeros once reversed.
- If `ans` becomes empty, return "0".
- Reverse `ans` to get the final correctly-ordered answer, return it.

### Complexity
Time: **O(n)**      
Space: **O(n)**

---

## Key Observation
Both approaches are functionally identical in the stack-building phase — the only difference is a clever timing trick in Approach 2: since `ans` is temporarily in reversed form right after popping, its BACK end temporarily represents the FRONT of the real answer. Stripping from that back end before reversing achieves the same leading-zero removal as scanning the front after reversing, just via a different (arguably more elegant, single-pass) mechanism.

## When to use this
If problem involves:
- Removing k elements from a sequence to minimize (or maximize) the resulting value while preserving relative order
→ Think **monotonic stack, greedily remove elements that violate the desired monotonic property**. For leading-zero (or similar edge) cleanup, consider whether stripping can be done more efficiently by exploiting a temporarily-reversed intermediate state, rather than always reversing first.

## Edge Cases
- `k` equals `num`'s length (result is "0", everything removed).
- Already non-decreasing string (all removals happen from the end).
- Leading zeros appearing after removal (must be stripped) — verified correct under both stripping strategies.
- Result becomes empty after stripping leading zeros (return "0") — verified correct under both approaches (e.g. `num="100", k=1` → both correctly return "0").

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Strip After Reverse | O(n) | O(n) |
| Strip Before Reverse | O(n) | O(n) |

where:
- `n` = length of the number string

## Related Problems
- Remove Duplicate Letters
- Create Maximum Number
- Monotonic Stack based problems (Next Greater Element series)
- Smallest Subsequence of Distinct Characters