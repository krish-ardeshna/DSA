# Count Shadow Pairs I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/count-shadow-pairs-i/  
Difficulty: Not verified (recent problem, check LC page directly)  
Pattern: Monotonic Stack + Binary Search

## What I understood
Count pairs based on some "shadow" relationship between array elements — appears to involve counting, for each element, how many previously-seen elements in a maintained monotonic structure are strictly less than it (via binary search count), while continuously maintaining that structure as monotonic non-decreasing by popping larger trailing elements before inserting the current one.

## Example
```
Input
nums = [3,1,4,1,5]
Output
(count of shadow pairs based on problem's specific pairing rule)
```

## Idea
Maintain a vector `st` that stays sorted (monotonic non-decreasing) as elements are processed. For each new element `x`, use binary search (`lower_bound`) to count how many existing elements in `st` are strictly less than `x` — this count contributes to the answer. Then, to keep `st` valid as a sorted structure for future binary searches, remove any trailing elements greater than `x` before inserting `x` itself (since a plain `push_back` would break sortedness if `x` is smaller than the current last element).

## Approach: Maintain Monotonic Vector, Binary Search for Count
- For each element `x` in `nums`: use `lower_bound(st.begin(), st.end(), x) - st.begin()` to count elements in `st` strictly less than `x`; add this count to `ans`.
- Pop trailing elements from `st` that are greater than `x` (maintains sortedness for the vector going forward).
- Push `x` onto the end of `st`.
- Return final `ans`.

## Key Observation
The combination of "binary search count" + "pop-then-push to maintain sorted order" allows `st` to function as an efficient sorted running structure without needing a full sort/insert each time — popping only removes elements that would violate the sorted invariant relative to the new element, keeping insertion amortized efficient similar to monotonic stack techniques.

## When to use this
If problem involves:
- Counting relational pairs (less-than, greater-than) as elements are processed sequentially
- Need to maintain a queryable sorted structure efficiently
→ Think **monotonic vector/stack + binary search for count queries**, popping elements that would break the required order before each insertion.

## Edge Cases
- All elements identical (no strictly-less-than pairs contribute).
- Strictly increasing array (every new element is greater than everything before, likely maximizes contribution each step).
- Strictly decreasing array (each new element pops most/all of the stack before insertion).
- Single element array (no pairs possible).

## Complexity
### Approach
Time: **O(n log n)** — binary search per element, amortized O(1) per pop/push across the whole run          
Space: **O(n)** — auxiliary vector storage

where:
- `n` = number of elements

## Related Problems
- Count of Smaller Numbers After Self
- Reverse Pairs
- Count Number of Teams
- Number of Pairs Satisfying Inequality