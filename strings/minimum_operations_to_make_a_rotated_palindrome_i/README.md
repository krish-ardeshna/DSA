# Minimum Operations to Make a Rotated Palindrome I
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/  
Difficulty: Medium (contest problem)    
Pattern: String - Brute Force Rotation + Palindrome Cost

## What I understood
String `s` can be rotated by some amount `i`, then characters can be changed (each change costing 1 operation, presumably cyclic character shift cost) to make the rotated string a palindrome. Find the minimum total operations (rotation cost `i` + character-change cost) across all possible rotations.

## Example
```
Input
s = "abcd"
Output
(minimum operations across all rotations to reach a palindrome)
```

## Idea
Brute force over every possible rotation starting point `i` (cost `i` itself counts toward total, matching problem's rotation-cost rule). For each rotation, check palindrome symmetry pairs `(left, right)` using modular indexing to simulate the rotated string without physically rotating it. Cost to make each pair match is the minimum cyclic distance between their characters (since characters can wrap around the alphabet).

## Approach: Try Every Rotation, Compute Min Char-Change Cost
- For each starting rotation `i` from 0 to n-1:
  - Base cost = `i` (cost of that rotation amount).
  - For each symmetric pair `j` from 0 to n/2-1: compute `left`/`right` indices via modular offset from `i`.
  - Cost to equalize that pair = minimum of forward/backward cyclic distance between the two characters (`min((a-b+26)%26, (b-a+26)%26)`).
  - Accumulate pair costs into `operations`.
  - Track global minimum across all rotations.
- Return the overall minimum.

## Key Observation
Modular indexing (`(i + j) % n`, `(i + n - 1 - j) % n`) lets you evaluate a "virtual rotation" without actually rotating the string in memory — saves the O(n) rotation construction cost per iteration, keeping each rotation check at O(n) total instead of O(n) rotate + O(n) check.

## When to use this
If problem involves:
- Trying all rotations of a string/array and evaluating a cost function per rotation
- Palindrome-style symmetric pair costs, possibly with cyclic/wraparound character distance
→ Think **brute force over rotation offset with modular indexing**, avoid physically rotating.

## Edge Cases
- Already palindromic string (character cost 0 for `i=0`, still check if rotation cost outweighs benefit).
- Single character string (trivially palindrome, 0 operations).
- Even vs odd length strings (middle character in odd-length has no pair, naturally skipped by `n/2` loop bound).
- Strings requiring wraparound character distance (e.g. 'a' to 'z' costs 1 via cyclic distance, not 25).

## Complexity
### Approach
Time: **O(n²)** — outer loop over rotations O(n), inner palindrome check O(n)           
Space: **O(1)** extra

where:
- `n` = length of string

## Related Problems
- Minimum Operations to Make a Rotated Palindrome II
- Palindrome Partitioning
- Shortest Palindrome
- Minimum Insertions to Make String Palindrome