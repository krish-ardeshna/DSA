# Merge Two Sorted Lists

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/  
Difficulty: Easy  
Pattern: Linked List

## What I understood
We are given the heads of two sorted linked lists.

We need to merge them into one sorted linked list by reusing the existing nodes.

Example:

list1 = [1,2,4]

list2 = [1,3,4]

Output = [1,1,2,3,4,4]

## Idea

### Approach 1 (Recursive Merge)
Compare the first nodes of both lists.

Attach the smaller node to the result and recursively merge the remaining nodes.

The recursion naturally builds the merged list.

### Approach 2 (Iterative Merge using Dummy Node)
Create a dummy node to simplify list construction.

Compare the current nodes of both lists:
- attach the smaller node
- move the corresponding pointer forward

After one list ends, attach the remaining nodes of the other list.

## Approach
- Compare the current nodes of both lists
- Choose the smaller node
- Add it to the merged list
- Move the corresponding pointer
- Repeat until one list becomes empty
- Attach the remaining nodes
- Return the merged list

## Key Observation
Since both lists are already sorted, we only need to compare their current nodes to maintain sorted order.

A dummy node simplifies handling the head of the merged list.

## When to use this
If the problem involves:
- merging sorted linked lists
- ordered traversal
- pointer manipulation

→ think two pointers

## Edge Cases
- One list is empty
- Both lists are empty
- Lists of different lengths
- Duplicate values
- All elements of one list are smaller

## Complexity

### Approach 1
Time: O(n + m)  
Space: O(n + m) (recursion stack)

### Approach 2
Time: O(n + m)  
Space: O(1)

where:
- n = length of list1
- m = length of list2

## Related Problems
- Merge k Sorted Lists
- Sort List
- Remove Duplicates from Sorted List
- Partition List