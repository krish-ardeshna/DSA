# Longest Consecutive Sequence

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/  
Difficulty: Medium  
Pattern: Hash Set

## What I understood
We are given an unsorted array of integers.

We need to find the length of the longest sequence of consecutive integers.

The numbers do not need to be adjacent in the array.

Example:

nums = [100,4,200,1,3,2]

Output = 4

because the longest consecutive sequence is:

[1,2,3,4]

## Idea
Store all numbers in a hash set for O(1) lookup.

A number can start a sequence only if its previous number does not exist.

From every valid starting number:
- keep checking the next consecutive numbers
- count the sequence length
- update the maximum length

## Approach
- Insert all numbers into a hash set
- Traverse every unique number
- Start counting only if the previous number is absent
- Extend the sequence while consecutive numbers exist
- Update the maximum sequence length
- Return the answer

## Key Observation
Every sequence is traversed only once.

By starting only from sequence beginnings, we avoid counting the same sequence multiple times.

## When to use this
If the problem involves:
- consecutive numbers
- fast lookups
- duplicate removal
- sequence detection

→ think Hash Set

## Edge Cases
- Empty array
- Single element
- Duplicate numbers
- All numbers consecutive
- No consecutive numbers

## Complexity
Time: O(n) (average)  
Space: O(n)

## Related Problems
- Longest Increasing Subsequence
- Contains Duplicate
- Two Sum
- Happy Number