# Evaluate the Bracket Pairs of a String
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/  
Difficulty: Medium  
Pattern: String - Hashmap Lookup + Single Pass Parsing

## What I understood
String `s` contains some substrings wrapped in `(key)` brackets. Given a `knowledge` list of `[key, value]` pairs, replace every `(key)` occurrence in `s` with its corresponding `value`. If a key isn't found in `knowledge`, replace it with `"?"` instead. Characters outside brackets remain unchanged.

## Example
```
Input
s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
Output
"bobistwoyearsold"
```
```
Input
s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
Output
"yesyesyesaaa"
```

## Idea
Build a hashmap from `knowledge` for O(1) key-to-value lookup, then do a single pass through `s`: whenever a `(` is encountered, extract everything until the matching `)` as the key, look it up in the map (or use `"?"` if missing), and append the result. Characters outside brackets are copied directly.

## Approach: Build Key-Value Map, Single Pass Replace Bracketed Keys
- Build `mp[key] = value` from the `knowledge` list.
- Single pass through `s` using index `i`.
- On `(`: advance past it, accumulate characters into `key` until hitting `)`, then look up `key` in `mp` - append its value if found, else append `"?"`.
- On any other character: append it directly to `ans` unchanged.
- Return final `ans`.

## Key Observation
Since brackets in this problem are guaranteed to be well-formed and non-nested (each `(key)` is a simple, flat bracket pair), a straightforward linear scan with manual index advancement inside the bracket-handling branch is sufficient - no need for a stack or more complex bracket-matching logic.

## When to use this
If problem involves:
- Substituting bracketed/marked tokens in a string using a lookup table
→ Think **hashmap for O(1) lookup + single linear pass**, extracting bracketed content manually via index advancement when brackets are simple/non-nested.

## Edge Cases
- Key not found in `knowledge` (replaced with `"?"`).
- Multiple occurrences of the same key.
- String with no brackets at all (returned unchanged).
- Empty key inside brackets `()` (would look up empty string in map, likely resulting in `"?"` unless explicitly defined).

## Complexity
### Approach
Time: **O(n)** - single pass through s, plus O(1) average hashmap lookups       
Space: **O(n)** - output string, plus O(k) for the knowledge hashmap

where:
- `n` = length of string s
- `k` = number of knowledge pairs

## Related Problems
- Parse Lisp Expression
- Ternary Expression Parser
- Decode String
- Basic Calculator