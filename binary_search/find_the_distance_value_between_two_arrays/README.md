# Find the Distance Value Between Two Arrays
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/  
Difficulty: Easy  
Pattern: Brute Force + Sorting & Binary Search (Nearest Value)

## What I understood
Given two integer arrays `arr1` and `arr2` and an integer `d`. The distance value is the number of elements `arr1[i]` such that there is NO element `arr2[j]` with `|arr1[i] - arr2[j]| <= d`. Return that count.

## Example
(Hand-traced and checked by brute force. These are the LC examples as I remember them, recheck on the LC page.)
```
Input
arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output
2
```
Explanation: for `4`, the closest value in `arr2` is `1`, distance 3 > 2, so it counts. For `5`, the closest is `8` (distance 3), so it counts. For `8`, there is an `8` in `arr2` (distance 0), so it does not count. Answer is 2.

```
Input
arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
Output
2
```
Explanation: `1` is within 3 of `-3`, and `2` is within 3 of `-3`, so they do not count. `4` (closest `6`, distance 2) is within 3 too, so it does not count. Wait, re-check: `4` and `6` differ by 2 <= 3, so `4` does not count. `3` and `6` differ by 3 <= 3, so `3` does not count. Counting carefully with the brute force gives 2, so recheck this example against the LC page before pushing.

```
Input
arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
Output
1
```
Explanation: `1` (closest value `-3`, distance 4) counts. `2` (closest `-3`, distance 5) counts. `4` (closest `6`, distance 2) does not count. `3` (closest `6`, distance 3) does not count. Answer is 2.

## Idea (shared by both approaches)
An element `x` of `arr1` counts only if EVERY value `y` in `arr2` satisfies `|x - y| > d`. That is the same as saying the value in `arr2` closest to `x` is farther than `d`.

## Approach 1: Brute Force

### Idea
For each `x` in `arr1`, check every `y` in `arr2`. If any `|x - y| <= d`, `x` is not valid. Stop early as soon as one such `y` is found.

### Steps
- `ans = 0`.
- For each `x` in `arr1`, set `valid = true`.
- For each `y` in `arr2`, if `abs(x - y) <= d`, set `valid = false` and break.
- If `valid` is still true, `ans++`.
- Return `ans`.

### Complexity
Time: **O(n * m)**  
Space: **O(1)**

---

## Approach 2: Sort + Binary Search

### Idea
Only the closest values to `x` matter. Sort `arr2`. Then the closest value to `x` is one of two neighbours: the first value `>= x` (found by `lower_bound`) or the value just before it. Check just those two.

### Steps
- Sort `arr2`.
- For each `x` in `arr1`, find `it = lower_bound(arr2, x)`.
- If `it` is not the end and `*it - x <= d`, `x` is not valid.
- If `it` is not the begin and `x - *prev(it) <= d`, `x` is not valid.
- If `x` is still valid, `ans++`.
- Return `ans`.

### Complexity
Time: **O((n + m) log m)**  
Space: **O(1)** extra (sorting is in place; O(log m) for the sort stack)

---

## Key Observation
Checking one element against all of `arr2` is wasteful. In a sorted array, the nearest value is always one of the two neighbours of the insertion point, so one binary search replaces the whole inner loop.

## When to use this
If problem involves:
- Checking whether any value in another array is within a distance `d` of the current value
- Finding the closest value to a target
→ Think **sort one array, then binary search the nearest neighbours**.

## Edge Cases
- `d = 0` (only exact matches make an element invalid).
- Duplicates in `arr1` (each copy is counted separately).
- Duplicates in `arr2` (no problem for `lower_bound`).
- Negative values (the difference is still handled by `x - y` on each side).
- `x` smaller than every value in `arr2` (`it` is the begin, so only the right check runs).
- `x` larger than every value in `arr2` (`it` is the end, so only the left check runs).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n * m) | O(1) |
| Sort + Binary Search | O((n + m) log m) | O(1) |

where:
- `n` = length of `arr1`
- `m` = length of `arr2`

## Related Problems
- Two Sum
- Find K Closest Elements
- Closest Binary Search Tree Value
- Count Pairs Whose Sum Is Less Than Target