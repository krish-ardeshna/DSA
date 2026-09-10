# Next Greater Element II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/next-greater-element-ii/  
Difficulty: Medium  
Pattern: Monotonic Stack (Circular Array via Double Pass)

## What I understood
Given a CIRCULAR array `nums` (last element wraps around to the first), find the next greater element for every element — searching circularly means the search can continue from the beginning if not found before reaching the end normally. If no greater element exists even after wrapping fully around, answer is -1.

## Example
```
Input
nums = [1,2,1]
Output
[2,-1,2]
```
```
Input
nums = [1,2,3,4,3]
Output
[2,3,4,-1,4]
```

## Idea
Simulate circularity without physically duplicating the array — traverse indices from `2n-1` down to `0`, using `i % n` to wrap the actual index back into valid range. This effectively processes the array twice (conceptually), letting the monotonic stack "see" elements from the wrap-around before committing final answers for the first pass's indices, but answers are ONLY recorded when `i < n` (the real, non-duplicated indices).

## Approach: Monotonic Decreasing Stack, Double-Length Traversal
- Traverse `i` from `2n-1` down to `0` (conceptually two full passes over the array, using modulo indexing).
- Standard monotonic stack maintenance: pop elements `<= nums[i % n]` (they can never be the next-greater for anything appearing before current position in this reversed traversal).
- Only record `ans[i]` when `i < n` — this is the "real" first pass, and by now the stack already reflects the state as if the circular wrap had been considered (built up during the `i >= n` second-pass phase).
- Push `nums[i % n]` onto stack regardless, continue.

## Key Observation
Running the traversal for `2n` iterations (not `n`) is what simulates circularity — during the first half of this reversed loop (`i` from `2n-1` down to `n`), the stack is being "primed" with wrap-around context, so by the time real answers are recorded (`i < n`), the stack already accounts for elements that would be encountered by wrapping around the circular array.

## When to use this
If problem involves:
- Next greater/smaller element in a CIRCULAR array (not linear)
→ Think **monotonic stack with double-length traversal using modulo indexing**, avoiding actual array duplication while still correctly simulating the wrap-around.

## Edge Cases
- Single element array (no greater element possible even circularly, answer is [-1]).
- All elements identical (no strictly greater element anywhere, all -1).
- Strictly increasing array (wraps around, first element's next greater might come from early in the array again after wrap).
- Array where max element appears multiple times.

## Complexity
### Approach
Time: **O(n)** — each index processed at most twice (2n total iterations), each element pushed/popped from stack at most twice          
Space: **O(n)** — stack storage

where:
- `n` = number of elements

## Related Problems
- Next Greater Element I
- Next Greater Element III
- Daily Temperatures
- Circular Array Loop