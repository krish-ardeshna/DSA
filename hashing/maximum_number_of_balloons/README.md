# Maximum Number of Balloons

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-number-of-balloons/  
Difficulty: Easy  
Pattern: Hash Map / Counting

## What I understood
We need to determine how many times the word "balloon" can be formed using the characters of the given string.

Each character can be used only once.

Example:

text = "loonbalxballpoon"

Answer = 2 because the word "balloon" can be formed exactly two times.  

## Idea
Count the frequency of every character in the string.

The word "balloon" requires:

- b → 1 time
- a → 1 time
- l → 2 times
- o → 2 times
- n → 1 time

The maximum number of balloons that can be formed depends on the character with the smallest available count after considering these requirements.

## Approach
- Count frequency of all characters
- Check the frequency of:
  - b
  - a
  - l
  - o
  - n
- Divide counts of:
  - l by 2
  - o by 2
- Return the minimum among all required character counts

## Key Observation
The characters 'l' and 'o' appear twice in the word "balloon".

Therefore their frequencies must be divided by 2 before determining how many complete words can be formed.

## When to use this
If the problem involves:
- character frequencies
- counting occurrences
- forming words from characters

→ think frequency map

## Edge Cases
- Empty string
- Missing required characters
- Only one balloon can be formed
- Large frequency of some characters but shortage of one character

## Complexity
Time: O(n)  
Space: O(1)

## Related Problems
- Ransom Note
- Valid Anagram
- Find Words That Can Be Formed by Characters
- First Unique Character in a String