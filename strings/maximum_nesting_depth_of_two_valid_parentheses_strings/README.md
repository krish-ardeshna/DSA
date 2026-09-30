# Maximum Nesting Depth of Two Valid Parentheses Strings
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/  
Difficulty: Medium  
Pattern: String - Depth Parity Split

## What I understood
Given a valid parentheses string `seq`, split its characters into two subsequences A and B (each character assigned to exactly one, via a returned 0/1 array) such that both A and B are themselves valid parentheses strings, and the MAXIMUM nesting depth across both A and B is as SMALL as possible.

## Example
```
Input
seq = "(()())"
Output
[0,1,1,1,1,0]
```
```
Input
seq = "()(())()"
Output
[0,0,0,1,1,0,1,0]
```

## Idea
Assign each bracket to a group (0 or 1) based on the PARITY of the current nesting depth at that point. Alternating group assignment by depth naturally caps each group's own maximum depth at roughly half the original depth, since consecutive depth levels always alternate between the two groups.

## Approach: Alternate Groups by Depth Parity
- Track `depth`, starting at 0.
- On `(`: increment `depth` FIRST, then assign group `depth % 2`.
- On `)`: assign group `depth % 2` FIRST (using the depth level this closing bracket is closing FROM), then decrement `depth`.
- Return the resulting group assignment array.

## Key Observation
The order of increment/assign (for `(`) versus assign/decrement (for `)`) matters, an opening bracket's group is decided by the depth it's ENTERING, while a closing bracket's group is decided by the depth it's LEAVING, since both refer to the same nesting level, this keeps matched pairs in the same group automatically.

## When to use this
If problem involves:
- Splitting a valid bracket sequence into balanced subsequences to minimize peak depth
→ Think **assign by depth parity**, alternating groups level by level is enough, no need to track matched pairs explicitly.

## Edge Cases
- Fully flat sequence like `()()()` (all same depth level 1, all go to the same group).
- Single deeply nested group like `(((())))` (alternates group every level).
- Empty string (empty result).
- Sequence where max depth is already even or odd (parity split still balances correctly either way).

## Complexity
### Approach
Time: **O(n)**          
Space: **O(n)** - output array

where:
- `n` = length of string seq

## Related Problems
- Maximum Nesting Depth of the Parentheses
- Valid Parentheses
- Remove Outermost Parentheses
- Minimum Add to Make Parentheses Valid