# Brace Expansion II
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/brace-expansion-ii/  
Difficulty: Hard  
Pattern: Recursive Descent Parsing (Union + Concatenation)

## What I understood
Given an expression with nested braces `{}`, commas `,` (meaning union/OR of alternatives), and implicit concatenation (adjacent terms combine as cross-product), expand it into the full sorted, DEDUPLICATED list of resulting strings.

## Example
```
Input
expression = "{a,b}{c,{d,e}}"
Output
["ac","ad","ae","bc","bd","be"]
```
```
Input
expression = "{a,b,c}{d,e,f}"
Output
["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

## Idea
Two operations need distinct handling: UNION (comma-separated alternatives, results simply combine via set union) and CONCATENATION (adjacent terms multiply together via cross-product, every combination of left-term-result with right-term-result). A recursive descent parser naturally handles nested braces — `parseExpression` handles a sequence of comma-separated OR-groups, `parseTerm` handles either a nested braced sub-expression or a single literal character.

## Approach: Recursive Parser, Set Union for Comma, Cross-Product for Concatenation
- **`parseExpression`**: loops through characters until hitting `}` (end of current scope) or string end.
  - On `,`: advance past it, recursively parse the NEXT expression, UNION its results into `result` (comma means alternatives, so just combine).
  - Otherwise: parse a TERM, then CONCATENATE it with existing `result` via cross-product (every string in `result` + every string in the new term's results) — this is implicit adjacency-means-concatenation.
- **`parseTerm`**: if current char is `{`, recursively parse the nested expression (skip the matching braces); else, treat the single character as a literal one-string set.
- `set<string>` is used throughout for automatic deduplication and sorted order (required since output must be sorted with no duplicates).

## Key Observation
The critical distinction is WHEN to union vs WHEN to concatenate — comma triggers union, but the DEFAULT (no comma, just adjacent terms) triggers concatenation via cross-product. Using `set<string>` throughout means both deduplication and final sorted order come for free, without needing separate cleanup steps.

## When to use this
If problem involves:
- Parsing nested bracket/brace expressions with mixed union and concatenation semantics
→ Think **recursive descent parser**, with a class-level position index (`i`) shared across recursive calls, using set operations (union, cross-product) that naturally match the grammar's semantics.

## Edge Cases
- Deeply nested braces (recursion handles arbitrary nesting depth).
- Single character expression (no braces at all).
- Duplicate resulting strings from different expansion paths (handled via `set` deduplication).
- Multiple commas in sequence (multiple union branches).

## Complexity
### Approach
Time: **O(n * m log m)** roughly, where cross-products can grow the result set size significantly; exact bound depends on expression structure          
Space: **O(m)** — result set storage, where m = number of distinct final strings

where:
- `n` = length of input expression string
- `m` = number of resulting expanded strings

## Related Problems
- Brace Expansion
- Letter Combinations of a Phone Number
- Generate Parentheses
- Word Break II