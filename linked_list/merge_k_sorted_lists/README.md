# Merge k Sorted Lists

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/  
Difficulty: Hard  
Pattern: Linked List / Divide and Conquer

## What I understood
We are given k sorted linked lists.

We need to merge all of them into one sorted linked list.

Example:

lists = [[1,4,5],[1,3,4],[2,6]]

Output = [1,1,2,3,4,4,5,6]

## Idea
Merge the linked lists in pairs.

Initially:
- merge every two adjacent lists

Then:
- merge the resulting larger lists

Repeat until only one merged list remains.

This is similar to Merge Sort and significantly reduces the number of merge operations.

## Approach
- Handle the empty list case
- Initialize the merge interval as 1
- Merge pairs of linked lists
- Double the interval after each round
- Continue until only one list remains
- Return the final merged list

## Key Observation
Instead of repeatedly merging one list with the accumulated result, merging lists in pairs keeps the merge operations balanced.

This reduces the overall time complexity from repeated sequential merges.

## When to use this
If the problem involves:
- merging multiple sorted lists
- divide and conquer
- repeated pairwise merging

→ think Merge Sort strategy

## Edge Cases
- Empty list of lists
- Only one linked list
- Some lists are empty
- Lists of different lengths
- Duplicate values

## Complexity
Time: O(N log k)  
Space: O(1)

where:
- N = total number of nodes
- k = number of linked lists

## Related Problems
- Merge Two Sorted Lists
- Sort List
- Merge Intervals
- Kth Smallest Element in a Sorted Matrix