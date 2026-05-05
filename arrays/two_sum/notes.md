# Two Sum

Platform: LeetCode  
Pattern: Hashing

## What I understood
We need to find two numbers whose sum equals the target.  
Doing it with two loops works, but it’s slow (O(n^2)), so we need something faster.

## Idea
Instead of checking every pair, I can store numbers I’ve already seen.  
For each number, I check if the "required value" (target - current) is already present.

## Approach
- Traverse the array once
- For each element:
  - Calculate: diff = target - nums[i]
  - Check if diff exists in map
    - If yes → return indices
  - Else → store current number with its index

## Mistake I made
At first, I went with brute force and didn’t think about optimization.

## When to use this
If I see:
- "find pair with given sum"
- "two numbers adding to target"

→ I should immediately think of hashmap

## Complexity
Time: O(n)  
Space: O(n)