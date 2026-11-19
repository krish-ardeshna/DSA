# Minimum Score by Changing Two Elements
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-score-by-changing-two-elements/  
Difficulty: Medium  
Pattern: Greedy + Sorting (Remove Two Extremes, Low Score Is Always 0)

## What I understood
Given an integer array `nums`. Its score is `low + high`, where:
- `low` = the minimum of `|nums[i] - nums[j]|` over all pairs `i < j`,
- `high` = the maximum of `|nums[i] - nums[j]|` over all pairs `i < j`.

You may change the value of at most TWO elements to any value. Return the minimum possible score.

## Example
(Examples 1 and 2 are the LC examples as I remember them, recheck on the LC page. Example 3 is my own. All were hand-traced and checked by brute force.)
```
Input
nums = [1,4,3]
Output
0
```
Explanation: change `nums[1]` to 1 and `nums[2]` to 1, so `nums = [1,1,1]`. Both `low` and `high` are 0.

```
Input
nums = [1,4,7,8,5]
Output
3
```
Explanation: sorted, the array is `[1,4,5,7,8]`. Change the two smallest values (`1` and `4`) to `5`, so `nums = [5,5,5,7,8]`. Now `low = 0` and `high = 8 - 5 = 3`, so the score is 3. The other options give `8 - 5 = 3` (drop two largest... see below) and `5 - 1 = 4`, so 3 is the best.

```
Input
nums = [5,5,5,5]
Output
0
```
Explanation: all elements are equal, so `low = high = 0` and no change is needed.

## Idea (shared by all approaches)
**`low` can always be 0.** After changing two elements, set one of them equal to any other element. Then two elements are equal and `low = 0`. (This needs at least 3 elements, so that two elements are changed and one stays.) So the score is just `high`.

**Minimize `high = max - min`.** Changing an element to a value inside the current range never makes `high` larger, so each change is the same as REMOVING that element. We remove two elements so that `max - min` of the remaining array is as small as possible.

**Which two to remove?** The max and min only depend on the ends of the sorted array. So we remove from the ends. With the array sorted as `a[0..n-1]` there are exactly three options:
- remove the two smallest: `a[n - 1] - a[2]`
- remove the smallest and the largest: `a[n - 2] - a[1]`
- remove the two largest: `a[n - 3] - a[0]`

The answer is the minimum of these three.

## Approach 1: Brute Force

### Idea
Try every pair of elements `(i, j)` to remove. For each pair, scan the other elements to get their min and max, and keep the smallest `max - min`.

### Steps
- `ans = infinity`.
- For every pair `i < j`: scan all `k` except `i` and `j`, and track `mn` and `mx`.
- `ans = min(ans, mx - mn)`.
- Return `ans`.

### Complexity
Time: **O(n^3)**  
Space: **O(1)**

Too slow for `n = 10^5`.

---

## Approach 2: Sort + Three Options

### Idea
Sort the array and evaluate the three end-removal options listed above.

### Steps
- Sort `nums`.
- Return `min(nums[n-1] - nums[2], nums[n-2] - nums[1], nums[n-3] - nums[0])`.

### Complexity
Time: **O(n log n)**  
Space: **O(1)** extra

---

## Approach 3: One Pass (Keep the 3 Smallest and 3 Largest)

### Idea
The three options only need the 3 smallest and the 3 largest values. Find them in one pass, without sorting the whole array.

### Steps
- `small[3]` = the 3 smallest values in increasing order, `large[3]` = the 3 largest values in decreasing order. Start with `INT_MAX` and `INT_MIN`.
- For each `x`, insert it into `small`: for `i = 0..2`, if `x < small[i]`, swap `x` and `small[i]`. Do the same for `large` with `x > large[i]`.
- Return `min(large[0] - small[2], large[1] - small[1], large[2] - small[0])`.

### Complexity
Time: **O(n)**  
Space: **O(1)**

---

## Key Observation
The scary "minimum of low plus high" splits into two easy parts: `low` is always 0 (once you can make two elements equal), and `high` only depends on the two ends of the sorted array. So the answer is one of three differences, and the middle of the array never matters.

## When to use this
If problem involves:
- Changing or removing a small, fixed number of elements to shrink a range (`max - min`)
→ Think **sort, and try every way to cut `k` elements from the two ends**.

## Edge Cases
- `n = 3` (`nums[2]` and `nums[n - 3]` are the same index range, the answer is `0`).
- All elements equal (answer `0`).
- Many duplicates (sorting or the 3-smallest scan still works, equal values are just kept).
- Large values (the difference fits in `int` because all values are positive, up to `10^9`).
- The input needs `n >= 3`, so `nums[2]` always exists.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n^3) | O(1) |
| Sort + Three Options | O(n log n) | O(1) |
| One Pass (3 Smallest / 3 Largest) | O(n) | O(1) |

where:
- `n` = length of `nums`

## Related Problems
- Minimum Difference Between Largest and Smallest Value in Three Moves
- Minimum Moves to Equal Array Elements II
- Maximum Product of Three Numbers
- Smallest Range II