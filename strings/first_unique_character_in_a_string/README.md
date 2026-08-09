# First Unique Character in a String

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string/  
Difficulty: Easy  
Pattern: String, Frequency Counting

## What I understood
Given a string, return the index of the first character that appears exactly once. If no such character exists, return `-1`.

Example:
```
s = "leetcode"
Output = 0
```

## Idea
A character is unique if its frequency is exactly one.

Count character frequencies first, then identify the first unique character. For streaming scenarios, maintain the current first unique character using a queue.

## Approach 1: Hash Map Frequency
- Count the frequency of every character using a hash map.
- Traverse the string again.
- Return the first index whose frequency is `1`.

## Approach 2: Frequency Array
- Count frequencies using an array of size `26`.
- Traverse the string again.
- Return the first index whose frequency is `1`.

## Approach 3: Queue + Frequency (Streaming)
- Traverse the string once.
- Maintain character frequencies and a queue of candidate unique characters.
- Remove characters from the front while their frequency becomes greater than `1`.
- The front of the queue always represents the current first unique character.

## Key Observation
The first unique character depends entirely on character frequencies.

When processing characters one by one, a queue efficiently maintains the current first unique character without rescanning previous characters.

## When to use this
If the problem involves:
- Character frequencies
- First unique element
- Streaming characters
- First non-repeating character

→ Think **Frequency Counting** or **Queue + Frequency** for streaming problems.

## Edge Cases
- Empty string.
- All characters are unique.
- No unique character exists.
- Repeated occurrences of the first character.

## Complexity

### Approach 1
Time: **O(n)**  
Space: **O(k)**

### Approach 2
Time: **O(n)**  
Space: **O(26)** ≈ **O(1)**

### Approach 3
Time: **O(n)**  
Space: **O(n)**

where:
- `n` = length of the string
- `k` = number of distinct characters

## Related Problems
- First Non-Repeating Character in a Stream
- Ransom Note
- Valid Anagram