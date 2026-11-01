# Parsing A Boolean Expression
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/parsing-a-boolean-expression/  
Difficulty: Hard  
Pattern: Expression Parsing (Recursive Descent with Memoization, Stack)

## What I understood
A boolean expression is one of: `t` (true), `f` (false), `!(expr)` (NOT), `&(expr1, expr2, ...)` (AND of all), or `|(expr1, expr2, ...)` (OR of all). The expressions can be nested. Given a valid expression string, return its value.

## Example
```
Input
expression = "&(|(f))"
Output
false
```
Explanation: `|(f)` is `f`, then `&(f)` is `f`.

```
Input
expression = "|(f,f,f,t)"
Output
true
```
Explanation: the OR of `f, f, f, t` is `t` because one operand is true.

```
Input
expression = "!(&(f,t))"
Output
true
```
Explanation: `&(f,t)` is `f`, then `!(f)` is `t`.

## Idea
Every sub-expression is either one letter (`t` / `f`) or `op ( children... )`. That is a nested structure, and the innermost group has to be solved before the group around it. There are two natural ways to do that:

- **Top-down:** recurse into each child, using a table of matching brackets to jump over nested children.
- **Bottom-up with a stack:** read left to right, and every time a `)` closes a group, collapse that group into a single letter.

Both visit every character a constant number of times.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Build a table `match[i]` = index of the `)` that closes the `(` at `i`. Then `f(start)` evaluates the sub-expression that begins at `start`. Results are cached in `dp[start]`. Every start index is evaluated exactly once, so the cache is never actually hit here. It is harmless, and it keeps the solution in the same recursion + memoization style as the other DP problems.

### Steps
- Build `match[]` with a stack of `(` positions.
- Create `dp[n]` filled with `-1`.
- `f(start)`: return the cached value if filled.
- Letter: return `1` for `t`, `0` for `f`.
- `!`: return NOT of `f(open + 1)`.
- `&` / `|`: start with `true` for AND and `false` for OR, then loop over the children and combine.
- To move to the next child: a letter child is 1 character long. Otherwise the child is `op ( ... )`, so jump to `match[idx + 1] + 1`. Skip the `,`.
- Call `f(0)`.

### Complexity
Time: **O(n)**  
Space: **O(n)** for `match`, `dp` and the recursion stack (depth equals the nesting level)

---

## Approach 2: Stack (Iterative)

### Idea
Push every character except `,` and `)`. When a `)` arrives, the top of the stack holds one full group: the operands, then `(`, then the operator. Pop the operands and note whether any `t` and any `f` were seen. That is enough to compute AND, OR and NOT:

- `&` is true only if there is NO `f`.
- `|` is true if there is at least one `t`.
- `!` has one operand, so it is the opposite of that operand.

Push the result (`t` or `f`) back. The collapsed group now acts like a single operand for the group around it.

### Steps
- For each character `c`: skip `,`. If `c != ')'`, push it.
- On `)`: pop until `(`, recording `hasTrue` and `hasFalse`. Pop the `(`, then pop the operator.
- Push `t` or `f` according to the operator rule above.
- At the end the stack holds one letter. Return whether it is `t`.

### Complexity
Time: **O(n)**, every character is pushed and popped at most once  
Space: **O(n)** for the stack, no recursion

---

## Key Observation
The recursive version needs the `match[]` table to jump over nested children in `O(1)`. The stack version needs no table at all, because a closed group is replaced by one letter, so the next level never sees the nesting. The stack version also cannot overflow the call stack on very deep expressions like `!(!(!(...)))`, which the recursive version can.

The only facts needed from a group are "is there a `t`" and "is there an `f`". Counting the operands is never necessary.

## When to use this
If problem involves:
- A string with nested brackets and operators
- Each bracket group is evaluated independently
→ Think **stack: collapse each group when its closing bracket arrives**. Use recursive descent when the grammar has precedence rules or when the structure is easier to follow top-down.

## Edge Cases
- A single letter: `"t"` or `"f"`.
- `!` with a nested expression inside.
- `&` or `|` with a single child.
- Deep nesting, such as `!(!(!(...)))` (safe for the stack version, a risk for deep recursion).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n) | O(n) |
| Stack | O(n) | O(n) |

where:
- `n` = length of the expression

## Related Problems
- Basic Calculator
- Decode String
- Number of Atoms
- Different Ways to Evaluate a Boolean Expression