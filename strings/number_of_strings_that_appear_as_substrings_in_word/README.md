# Number of Strings That Appear as Substrings in Word

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/  
Difficulty: Easy  
Pattern: Strings

## What I understood
We are given a list of strings and another string called word.

We need to count how many strings from the list appear as a substring of word.

Example:

patterns = ["a","abc","bc","d"]

word = "abc"

Output = 3

## Idea
Traverse every string in the patterns array.

For each pattern, use the built-in find() function to check whether it exists inside word.

If the pattern is found, increase the answer.

## Approach
- Initialize count as 0
- Traverse every pattern
- Check whether the pattern exists in word using find()
- If found, increment count
- Return the final count

## Key Observation
The C++ find() function returns:

- the starting index if the substring exists
- string::npos if it does not exist

This makes substring checking simple and efficient.

## When to use this
If the problem involves:
- substring search
- string matching
- checking occurrence of strings

→ think string::git find()

## Edge Cases
- Empty patterns array
- Empty word
- Duplicate patterns
- No matching substring
- Every pattern is present

## Complexity
Time: O(n × m)

where:
- n = number of patterns
- m = average substring search cost

Space: O(1)

## Related Problems
- Implement strStr()
- Find the Index of the First Occurrence in a String
- Repeated Substring Pattern
- Is Subsequence