# Minimum Number of Pushes to Type Word I

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/  
Difficulty: Easy  
Pattern: Greedy

## What I understood
Given a word with distinct lowercase English letters, assign the letters to telephone keypad buttons so that the total number of key presses required to type the word is minimized.

## Example

```
Input
word = "abcde"

Output
5
```

## Idea
Each keypad button can hold up to 8 letters.

The first 8 assigned letters require 1 push each, the next 8 require 2 pushes each, the next 8 require 3 pushes each, and so on.

Since every character appears exactly once, simply assign letters in this order.

## Approach: Greedy
- Traverse the characters of the word.
- For each position `i`, compute the required pushes as `(i / 8) + 1`.
- Add the pushes to the answer.
- Return the total.

## Key Observation
Every group of 8 assigned letters increases the required key presses by one.

The minimum number of pushes depends only on the position of each distinct letter after assignment.

## When to use this
If the problem involves:
- Greedy assignment
- Group-based costs
- Fixed-capacity allocation
- Minimizing total operations

→ Think **Greedy Grouping**.

## Edge Cases
- Word with one character.
- Word with exactly 8 characters.
- Word with 9 characters.
- Word with all 26 distinct letters.

## Complexity

### Approach
Time: **O(n)**

Space: **O(1)**

where:
- `n` = length of the word.

## Related Problems
- Minimum Number of Pushes to Type Word II
- Assign Cookies
- Boats to Save People