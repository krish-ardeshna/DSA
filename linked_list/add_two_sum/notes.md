# Add Two Numbers

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/add-two-numbers/  
Difficulty: Medium  
Pattern: Linked List / Simulation

## What I understood
Two numbers are stored in reverse order using linked lists.

We need to add them digit by digit, just like normal addition, while handling carry.

## Idea
Traverse both linked lists together:
- Add corresponding digits
- Add carry from previous step
- Store result digit in a new linked list

A dummy node helps simplify list construction.

## Approach
- Create a dummy node for result list
- Traverse while:
  - l1 exists
  - l2 exists
  - carry exists
- Calculate:
  - sum = x + y + carry
- Update:
  - carry = sum / 10
  - node value = sum % 10
- Move pointers forward

## Mistake I made
Initially forgot to handle the remaining carry after traversal.

## When to use this
If the problem involves:
- digit-by-digit processing
- linked list simulation
- carry handling

→ think of dummy node + traversal

## Edge Cases
- Different length lists
- Final carry remaining
- One list is empty

## Complexity
Time: O(max(n, m))  
Space: O(max(n, m))