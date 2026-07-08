# Palindrome Linked List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/palindrome-linked-list/  
Difficulty: Easy  
Pattern: Linked List

## What I understood
We are given the head of a singly linked list.

We need to determine whether the linked list forms a palindrome.

A palindrome reads the same forward and backward.

Example:

head = [1,2,2,1]

Output = true

## Idea
Split the problem into three steps:

- Find the middle of the linked list.
- Reverse the second half.
- Compare both halves node by node.

If every corresponding value matches, the linked list is a palindrome.

## Approach
- Find the middle using fast and slow pointers
- Reverse the second half of the list
- Compare the first half with the reversed second half
- If any values differ, return false
- Otherwise return true

## Key Observation
Instead of storing values in another data structure, reversing the second half allows comparison in-place with constant extra space.

## When to use this
If the problem involves:
- checking palindrome in a linked list
- reversing part of a linked list
- comparing two linked list halves

→ think find middle + reverse + compare

## Edge Cases
- Empty list
- Single node
- Even length list
- Odd length list
- Non-palindrome list

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Reverse Linked List
- Reorder List
- Middle of the Linked List
- Linked List Cycle