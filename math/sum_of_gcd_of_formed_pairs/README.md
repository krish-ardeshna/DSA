# Sum of GCD of Formed Pairs

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/  
Difficulty: Medium  
Pattern: Math / GCD

## What I understood
We are given an integer array.

First, construct a new array where each element is the GCD of the current number and the maximum value seen so far.

Sort this new array.

Then, repeatedly form pairs using:

- smallest with largest
- second smallest with second largest

Add the GCD of every formed pair and return the total sum.

## Idea
Build the prefix GCD array while tracking the maximum value seen so far.

After sorting the array, pair elements from both ends.

For every pair:
- calculate their GCD
- add it to the answer

## Approach
- Traverse the array
- Build the prefix GCD array
- Sort the prefix GCD array
- Use two pointers to form pairs
- Add the GCD of each pair
- Return the final sum

## Key Observation
Sorting the generated GCD values makes it easy to form the required smallest-largest pairs using two pointers.

The answer is obtained without explicitly creating pair objects.

## When to use this
If the problem involves:
- GCD
- pair formation
- sorting
- two pointers

→ think GCD preprocessing + Sorting

## Edge Cases
- Two elements
- All elements equal
- Already sorted array
- Large values

## Complexity
Time: O(n log n)

Space: O(n)

## Related Problems
- Find Greatest Common Divisor of Array
- GCD of Odd and Even Sums
- Sort an Array
- Two Sum II