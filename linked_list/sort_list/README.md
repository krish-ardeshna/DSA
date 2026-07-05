# Sort List

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sort-list/  
Difficulty: Medium  
Pattern: Linked List / Merge Sort

## What I understood
We are given the head of a linked list.

We need to sort the linked list in ascending order.

Example:

head = [4,2,1,3]

Output = [1,2,3,4]

## Idea

### Approach 1 (Bubble Sort)
Repeatedly traverse the linked list.

Whenever two adjacent nodes are out of order:
- swap them

Continue until a complete pass occurs without any swaps.

### Approach 2 (Merge Sort)
Use the Divide and Conquer technique.

- Find the middle of the linked list.
- Split it into two halves.
- Recursively sort both halves.
- Merge the sorted halves.

Merge Sort is the optimal algorithm for sorting linked lists because merging can be done efficiently without extra random access.

## Approach
- Find the middle node
- Split the list into two halves
- Recursively sort both halves
- Merge the two sorted linked lists
- Return the merged list

## Key Observation
Unlike arrays, linked lists cannot efficiently perform random access.

Merge Sort works naturally on linked lists because splitting and merging only require pointer manipulation.

## When to use this
If the problem involves:
- sorting linked lists
- divide and conquer
- efficient linked list manipulation

→ think Merge Sort

## Edge Cases
- Empty list
- Single node
- Already sorted list
- Reverse sorted list
- Duplicate values

## Complexity

### Approach 1
Time: O(n²)  
Space: O(1)

### Approach 2
Time: O(n log n)  
Space: O(log n) (recursion stack)

## Related Problems
- Merge Two Sorted Lists
- Merge k Sorted Lists
- Sort an Array
- Insertion Sort List