# First Bad Version

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/first-bad-version/  
Difficulty: Easy  
Pattern: Binary Search

## What I understood
We are given versions from 1 to n, where some version is bad. Once a version becomes bad, all later versions are also bad.

We need to find the first bad version while minimizing API calls.

Example:

n = 5

firstBadVersion = 4

Output = 4

## Idea
The versions form a monotonic sequence:
- Good versions
- Bad versions

Use binary search to locate the first bad version.

## Approach
- Initialize `left = 1` and `right = n`.
- Find the middle version.
- If the middle version is bad, search the left half.
- Otherwise, search the right half.
- Continue until both pointers meet.
- Return the meeting point.

## Key Observation
Since all versions after the first bad version are also bad, the search space is monotonic, making binary search the optimal solution.

## When to use this
If the problem involves:
- first true
- last false
- monotonic condition
- minimizing queries

→ think Binary Search on Answer

## Edge Cases
- First version is bad
- Last version is bad
- Only one version

## Complexity
Time: O(log n)

Space: O(1)

## Related Problems
- Binary Search
- Search Insert Position
- Guess Number Higher or Lower
- Find Peak Element