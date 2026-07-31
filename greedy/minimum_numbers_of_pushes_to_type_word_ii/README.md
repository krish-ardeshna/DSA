# Minimum Number of Pushes to Type Word II

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/  
Difficulty: Medium  
Pattern: Greedy, Frequency Counting

## What I understood

Each lowercase letter can be assigned to any telephone key.

Unlike Part I, letters may appear multiple times. The goal is to assign letters to keys so that the total number of key presses required to type the given word is minimized.

## Example

```
Input
word = "abcabc"

Output
6
```

## Idea

Letters that appear more frequently should require fewer key presses.

Count the frequency of every character, sort the frequencies in descending order, and assign the highest frequencies to positions requiring the fewest pushes.

## Approach: Greedy + Frequency Counting

- Count the frequency of each letter.
- Sort the frequencies in descending order.
- Assign:
  - First 8 frequencies → 1 push
  - Next 8 frequencies → 2 pushes
  - Remaining frequencies → 3, 4, ... pushes
- Multiply each frequency by its assigned push count and add to the answer.

## Key Observation

To minimize the total pushes, the most frequent letters must receive the smallest push counts.

## When to use this

If the problem involves:
- Frequency optimization
- Greedy assignment
- Cost minimization
- Fixed-capacity grouping

→ Think **Greedy + Frequency Counting**.

## Edge Cases

- Word contains only one distinct character.
- Exactly 8 distinct characters.
- More than 8 distinct characters.
- All 26 letters appear.
- Highly repeated characters.

## Complexity

### Approach

Time: **O(n + 26 log 26)** ≈ **O(n)**

Space: **O(26)** ≈ **O(1)**

where:
- `n` = length of the word

## Related Problems

- Minimum Number of Pushes to Type Word I
- Top K Frequent Elements
- Sort Characters By Frequency
```