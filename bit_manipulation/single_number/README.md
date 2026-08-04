# Single Number
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/single-number/  
Difficulty: Easy  
Pattern: Hashing / Bit Manipulation (XOR)

## What I understood
Every element in array appears exactly twice, except one element which appears exactly once. Find that single element. Must run in linear time, and ideally without extra space.

## Example
```
Input
nums = [4,1,2,1,2]
Output
4
```
---

## Approach 1: Hashmap Frequency Count

### Idea
Count occurrences of every number. The one with frequency 1 is the answer.

### Steps
- Build frequency map over all elements.
- Iterate map, return key where value equals 1.

### Complexity
Time: **O(n)**
Space: **O(n)** — hashmap storage

---

## Approach 2: XOR Bit Trick

### Idea
XOR of a number with itself is 0, and XOR with 0 leaves the number unchanged (`a ^ a = 0`, `a ^ 0 = a`). XOR-ing entire array cancels out every duplicate pair, leaving only the single number.

### Steps
- Initialize `ans = 0`.
- XOR every element into `ans`.
- Duplicates cancel to 0, only unique element survives.
- Return `ans`.

### Complexity
Time: **O(n)**
Space: **O(1)** — no extra storage

---

## Key Observation
XOR trick exploits self-inverse property (`a ^ a = 0`) to eliminate pairs without tracking counts — turns an O(n) space problem into O(1) space. Hashmap is more intuitive but wasteful for this specific "appears twice" constraint.

## When to use this
If problem involves:
- Every element repeats exactly twice except one (or similar parity pattern)
- Need O(1) space, O(n) time constraint
→ Think **XOR bit trick**.

## Edge Cases
- Single element array (trivially the answer).
- Negative numbers (XOR works fine on two's complement).
- Large array size.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Hashmap | O(n) | O(n) |
| XOR | O(n) | O(1) |

where:
- `n` = number of elements

## Related Problems
- Single Number II
- Single Number III
- Missing Number
- Find the Duplicate Number