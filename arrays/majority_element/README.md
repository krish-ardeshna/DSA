# Majority Element

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/majority-element/  
Difficulty: Easy  
Pattern: Arrays / Hashing / Boyer-Moore Voting Algorithm

## What I understood
A majority element appears more than:
n / 2 times

The problem guarantees that such an element always exists.

## Idea

### Approach 1 (Hashmap Counting)
Count frequency of every element using hashmap.

The element with maximum frequency becomes the majority element.

### Approach 2 (Boyer-Moore Voting Algorithm)
Maintain:
- a candidate
- a count

If current element matches candidate:
- increase count

Otherwise:
- decrease count

When count becomes 0:
- choose a new candidate

At the end,
the remaining candidate becomes the majority element.

## Approach
- Hashmap:
  - store frequencies
  - find maximum frequency
- Boyer-Moore:
  - cancel out different elements
  - keep updating candidate
  - return final candidate

## Key Observation
Since the majority element appears more than half the time,
it survives even after cancelling all other elements.

## When to use this
If the problem involves:
- majority frequency
- dominant elements
- pair cancellation logic

→ think Boyer-Moore Voting Algorithm

## Edge Cases
- Single element array
- Majority element repeated continuously
- Majority element spread across array

## Complexity

### Hashmap
Time: O(n)  
Space: O(n)

### Boyer-Moore
Time: O(n)  
Space: O(1)

## Related Problems
- Majority Element II
- Top K Frequent Elements
- Find the Duplicate Number