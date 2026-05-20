# Contains Duplicate

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/contains-duplicate/  
Difficulty: Easy  
Pattern: Hashing

## What I understood
We need to check whether any value appears more than once in the array.

The moment a repeated element is found,
the answer becomes true.

## Idea
Use a hash set to store elements already seen.

While traversing:
- if element already exists in set
  → duplicate found
- otherwise
  → insert element

## Approach
- Create an unordered_set
- Traverse array
- Check:
  - if current element exists
    → return true
- Otherwise insert element
- If traversal finishes:
  → return false

## Key Observation
Hash sets provide fast lookup operations.

That makes duplicate detection possible in a single traversal.

## When to use this
If the problem involves:
- duplicate detection
- fast lookup
- uniqueness checking

→ think hashing

## Edge Cases
- Empty array
- All unique elements
- Multiple duplicates

## Complexity
Time: O(n)  
Space: O(n)

## Related Problems
- Single Number
- Find the Duplicate Number
- Intersection of Two Arrays