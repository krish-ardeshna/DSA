# Search in Rotated Sorted Array II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/  
Difficulty: Medium  
Pattern: Binary Search (Modified for Rotated + Duplicates)

## What I understood
Array was originally sorted ascending, then rotated at an unknown pivot, and may contain duplicate values. Determine whether `target` exists in the array. Return true/false.

## Example
```
Input
nums = [2,5,6,0,0,1,2], target = 0
Output
true
```
```
Input
nums = [2,5,6,0,0,1,2], target = 3
Output
false
```

## Idea
Standard rotated-array binary search identifies which half (`low` to `mid` or `mid` to `high`) is properly sorted, then checks if target falls within that sorted half's range to decide direction. Duplicates break this detection when `nums[low] == nums[mid] == nums[high]` — can't tell which half is sorted. In that specific case, shrink both boundaries inward by one and retry (safe since removing one duplicate from each end can't eliminate the target if it exists elsewhere).

## Approach: Modified Binary Search with Duplicate Shrink
- Standard binary search loop; check `nums[mid] == target` first.
- If `nums[low] == nums[mid] && nums[mid] == nums[high]` → ambiguous case, can't determine sorted half; shrink `low++`, `high--`, continue.
- Otherwise, determine sorted half:
  - If `nums[low] <= nums[mid]` → left half is sorted; check if target lies in `[nums[low], nums[mid])`, adjust `high` or `low` accordingly.
  - Else → right half is sorted; check if target lies in `(nums[mid], nums[high]]`, adjust `low` or `high` accordingly.
- Return false if loop exits without match.

## Key Observation
The duplicate-ambiguity shrink step is the only addition over the no-duplicates version of this problem — it degrades worst-case time complexity from O(log n) to O(n) (e.g. array of all identical values except one), since shrinking one element at a time can't be avoided when sortedness can't be determined.

## When to use this
If problem involves:
- Rotated sorted array search, with possible duplicate values
→ Think **modified binary search + linear shrink fallback** for ambiguous duplicate cases; note worst-case degrades to O(n).

## Edge Cases
- All elements identical (`[2,2,2,2,2]`, target present or not) — worst case, degrades to O(n).
- No rotation (already fully sorted).
- Target at rotation pivot point.
- Empty array or single element.

## Complexity
### Approach
Time: **O(log n)** average, **O(n)** worst case (due to duplicate ambiguity shrink)     
Space: **O(1)**

where:
- `n` = number of elements

## Related Problems
- Search in Rotated Sorted Array
- Find Minimum in Rotated Sorted Array II
- Find Peak Element
- Search a 2D Matrix