# Next Greater Element I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/next-greater-element-i/  
Difficulty: Easy  
Pattern: Monotonic Stack

## What I understood
`nums1` is a subset of `nums2` (all elements distinct). For each element in `nums1`, find its "next greater element" in `nums2` — the first element to its right (in `nums2`'s order) that is strictly greater. If none exists, answer is -1.

## Example
```
Input
nums1 = [4,1,2], nums2 = [1,3,4,2]
Output
[-1,3,-1]
```
```
Input
nums1 = [2,4], nums2 = [1,2,3,4]
Output
[3,-1]
```

## Idea
Precompute next-greater-element for EVERY value in `nums2` once (using a monotonic stack), store results in a hashmap, then simply look up each `nums1` element — avoids recomputing next-greater search separately for each `nums1` query.

## Approach: Monotonic Decreasing Stack (Right to Left) + Hashmap
- Traverse `nums2` from right to left, maintaining a stack that stays monotonically decreasing (top to bottom).
- At each element: pop stack elements `<=` current value (they can never be a "next greater" for anything further left, since current value is a better/closer candidate).
- After popping, stack top (if any) IS the next greater element for current value; store in map. If stack empty, next greater is -1.
- Push current value onto stack, continue leftward.
- Finally, build result for `nums1` by looking up each element in the precomputed map.

## Key Observation
Building the map from `nums2` once — rather than doing a separate linear/brute-force next-greater search per `nums1` element — turns what could be O(n1 * n2) into O(n1 + n2), since the monotonic stack processes `nums2` in a single O(n2) pass regardless of how many `nums1` queries follow.

## When to use this
If problem involves:
- Finding "next greater/smaller element" for each item in a sequence
→ Think **monotonic stack**, traverse in the direction opposite to "next" (right to left for "next greater to the right"), maintaining stack invariant by popping elements that can never serve as an answer for future queries.

## Edge Cases
- Element in `nums1` with no greater element anywhere to its right in `nums2` (-1).
- Element at the very end of `nums2` (automatically -1, nothing to its right).
- All elements in `nums2` strictly increasing (every element's next greater is the one immediately after it).
- All elements in `nums2` strictly decreasing (every element's next greater is -1).

## Complexity
### Approach
Time: **O(n1 + n2)** — O(n2) to build map via monotonic stack, O(n1) for lookups            
Space: **O(n2)** — stack and hashmap storage

where:
- `n1` = size of nums1
- `n2` = size of nums2

## Related Problems
- Next Greater Element II
- Next Greater Element III
- Daily Temperatures
- Online Stock Span