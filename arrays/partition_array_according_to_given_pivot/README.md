# Partition Array According to Given Pivot

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/  
Difficulty: Medium  
Pattern: Arrays

## What I understood
We need to rearrange the array such that:

- all elements smaller than the pivot come first
- all elements equal to the pivot come next
- all elements greater than the pivot come last

The relative order of elements in each group must remain unchanged.

Example:

nums = [9,12,5,10,14,3,10]

pivot = 10

Answer = [9,5,3,10,10,12,14]

## Idea

### Approach 1 (Three Traversals)
Traverse the array three times.

During:
- first traversal collect elements smaller than pivot
- second traversal collect elements equal to pivot
- third traversal collect elements greater than pivot

Append all groups into the result array.

### Approach 2 (Three Buckets)
Create three separate arrays:
- left
- mid
- right

Traverse the array once and place each element into its appropriate bucket.

Merge all three buckets at the end.

## Approach
- Create containers for elements
- Separate elements based on comparison with pivot
- Preserve insertion order
- Combine the groups in the order:
  - smaller elements
  - pivot elements
  - greater elements
- Return the final array

## Key Observation
The relative order inside each group must remain unchanged.

Instead of sorting, we can simply collect elements into groups and merge them.

## When to use this
If the problem involves:
- stable partitioning
- grouping elements by condition
- preserving relative order

→ think separate buckets

## Edge Cases
- All elements smaller than pivot
- All elements greater than pivot
- All elements equal to pivot
- Pivot appears only once
- Pivot does not appear multiple times

## Complexity

### Approach 1
Time: O(3n) ≈ O(n)  
Space: O(n)

### Approach 2
Time: O(n)  
Space: O(n)

## Related Problems
- Sort Colors
- Move Zeroes
- Partition Labels
- Rearrange Array Elements by Sign