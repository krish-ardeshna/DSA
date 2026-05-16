# Move Zeroes

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/move-zeroes/  
Difficulty: Easy  
Pattern: Two Pointers (in-place rearrangement)

## What I understood
We need to move all zeros to the end of the array while keeping the order of non-zero elements the same.  
Doing shifts or extra arrays works, but we can do it in-place.

## Idea
Maintain a pointer `j` that marks where the next non-zero element should go.  
Traverse with `i`, and whenever we see a non-zero, swap it with position `j` and move `j` forward.

## Approach
- Initialize `j = 0`
- Traverse array with `i`
  - If `nums[i] != 0`:
    - swap(nums[i], nums[j])
    - increment `j`
- End result: all non-zeros compacted at front, zeros naturally move to the end

## Mistake I made
Initially thought about shifting elements or using another array, which increases space complexity.

## When to use this
If the problem involves:
- moving certain elements (like 0s) to one side
- keeping relative order intact

→ think **two pointers with in-place swapping**

## Edge Cases
- All elements are zero
- No zero present
- Single element array

## Complexity
Time: O(n)  
Space: O(1)