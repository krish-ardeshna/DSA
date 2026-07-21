# Target Sum

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/target-sum/  
Difficulty: Medium  
Pattern: Dynamic Programming / Subset Sum

## What I understood
We are given an array of integers and a target value.

For every number, we can place either:

- '+'
- '-'

before it.

We need to count the number of different expressions whose result equals the target.

Example:

nums = [1,1,1,1,1]

target = 3

Output = 5

## Idea
Instead of assigning '+' and '-' signs directly, transform the problem into a subset sum problem.

Let:

- P = sum of numbers assigned '+'
- N = sum of numbers assigned '-'

Then:

P − N = target

and

P + N = totalSum

Adding both equations:

2 × P = target + totalSum

Therefore:

P = (target + totalSum) / 2

Now the problem becomes counting the number of subsets having sum equal to P.

## Approach
- Compute the total sum
- Check whether a valid subset sum is possible
- Convert the problem into subset sum
- Build a DP table
- Count the number of subsets with the required sum
- Return the final count

## Key Observation
Assigning '+' and '-' signs can be converted into selecting a subset with a specific sum.

This transforms the problem into the classic Count of Subset Sum DP problem.

## When to use this
If the problem involves:
- assigning '+' and '-' signs
- counting expressions
- subset sums
- partitioning an array

→ think Subset Sum Transformation

## Edge Cases
- Target larger than total sum
- Negative target
- Odd value of target + totalSum
- Array containing zeros
- Single element array

## Complexity
Time: O(n × reqSum)  
Space: O(n × reqSum)

where:
- n = number of elements
- reqSum = (target + totalSum) / 2

## Related Problems
- Partition Equal Subset Sum
- Perfect Sum Problem
- Coin Change II
- Count of Subsets with Given Sum