# Reverse Substrings Between Each Pair of Parentheses
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/  
Difficulty: Medium  
Pattern: Stack (String Segment Accumulation)

## What I understood
Given a string with lowercase letters and matched parentheses, reverse the substring inside EVERY pair of parentheses (innermost first, cascading outward), then remove all parentheses from the final result.

## Example
```
Input
s = "(u(love)i)"
Output
"iloveu"
```
```
Input
s = "(ed(et(oc))el)"
Output
"leetcode"
```

## Idea
Maintain a stack where each level represents the string content accumulated WITHIN the current (possibly nested) set of parentheses. On `(`, start a fresh empty string segment (a new nesting level). On `)`, the current segment is complete - reverse it (since everything up to this point inside these parens needs reversing), then MERGE it into the parent level's string (the level below in the stack). This naturally handles nesting: inner reversals happen first and get folded into outer segments, which then get reversed again when THEIR closing paren is hit.

## Approach: Stack of Strings, Reverse and Merge on Closing Bracket
- Initialize stack with one empty string (representing the "outermost" level, no parens).
- For each character:
  - `(`: push a new empty string (start of a new nesting level).
  - `)`: pop the current segment, reverse it, then append (merge) it onto the new stack top (the parent level).
  - Any letter: append directly to the current stack top (current segment).
- Final answer: the single remaining string on the stack after processing (all levels merged back down to the base).

## Key Observation
Merging the reversed segment back into the PARENT level (rather than keeping it separate) is what correctly handles nested parentheses - when the parent's own closing paren is later encountered, it reverses the ALREADY-reversed inner content as PART of its own reversal, which correctly cascades the reversal effect outward exactly as the problem requires.

## When to use this
If problem involves:
- Nested bracket/parenthesis structures requiring an operation (reverse, transform) applied recursively from innermost to outermost
→ Think **stack of accumulating string segments**, merging (with transformation applied) into the parent level upon closing bracket - naturally handles nesting without explicit recursion.

## Edge Cases
- No parentheses at all (single segment, returned as-is).
- Deeply nested parentheses (multiple levels of reversal cascading).
- Multiple separate (non-nested) parenthesized groups.
- Empty parentheses `()` (reverses an empty string, no-op).

## Complexity
### Approach
Time: **O(n²)** worst case - string concatenation/reversal costs can compound with deep nesting, though often better in practice        
Space: **O(n)** - stack storage for string segments

where:
- `n` = length of string s

## Related Problems
- Valid Parentheses
- Decode String
- Basic Calculator
- Minimum Add to Make Parentheses Valid