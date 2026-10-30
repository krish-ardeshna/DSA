# Different Ways to Evaluate a Boolean Expression
Platform: TakeUForward  
Problem Link: https://takeuforward.org/practice/dsa/different-ways-to-evaluate-a-boolean-expression  
Difficulty: Not verified (check the TakeUForward page)  
Pattern: DP on Partitions (Interval DP, Choose the LAST Operator to Evaluate)

## What I understood
(Reconstructed from the problem link and the accepted code, recheck against the TakeUForward statement.)  
The expression is a string of operands `T` (true) and `F` (false) joined by the operators `&` (AND), `|` (OR) and `^` (XOR). Operands and operators alternate, starting and ending with an operand. Count the number of ways to put brackets around the sub-expressions so that the whole expression evaluates to `true`. Return the count modulo `10^9 + 7`.

## Example
(Hand-traced and checked by brute force, not copied from the TakeUForward page.)
```
Input
expression = "F|T^F"
Output
2
```
Explanation: `(F|T)^F = T^F = T` and `F|(T^F) = F|T = T`. Both bracketings give true.

```
Input
expression = "T&F"
Output
0
```
Explanation: there is only one way, and `T&F = F`, so no bracketing gives true.

```
Input
expression = "T|T&F^T"
Output
4
```
Explanation: there are 5 bracketings. `((T|T)&F)^T = T`, `(T|(T&F))^T = F`, `(T|T)&(F^T) = T`, `T|((T&F)^T) = T`, `T|(T&(F^T)) = T`. Four of them give true.

## Idea (shared by both techniques)
Operands sit at even indices and operators at odd indices.

Choose the LAST operator that is evaluated in `exp[i..j]`, at index `idx`:
- The left part `exp[i..idx - 1]` and the right part `exp[idx + 1..j]` are evaluated independently.
- Each part can end up true or false, so count both for each side: `lT`, `lF`, `rT`, `rF`.
- The operator at `idx` decides which combinations give the value we want.

**State:** `f(i, j, isTrue)` = number of ways `exp[i..j]` evaluates to `isTrue` (`1` means True, `0` means False).

**Recurrence:** for every operator position `idx = i + 1, i + 3, ..., j - 1`:

| Operator | Ways to get True | Ways to get False |
|---|---|---|
| `&` | `lT * rT` | `lT * rF + lF * rT + lF * rF` |
| `\|` | `lT * rT + lT * rF + lF * rT` | `lF * rF` |
| `^` | `lT * rF + lF * rT` | `lT * rT + lF * rF` |

`f(i, j, isTrue)` is the sum of the matching column over all `idx`, taken modulo `10^9 + 7`.

**Base case:** `i == j` is a single operand. It gives `1` if the operand equals the wanted value, else `0`.

**Answer:** `f(0, n - 1, 1)`.

Overflow check: `lT`, `lF`, `rT`, `rF` are already below the modulus, so a sum of up to three products is at most about `3 * 10^18`, which fits in `long long`.

The `-1` memo marker is safe because counts are never negative.

---

## Approach 1: Recursion + Memoization (Top-Down)

### Idea
Write the recurrence directly. For each operator position, ask for both true and false counts of both sides, then combine with the operator table.

### Steps
- Create `dp[n][n][2]` filled with `-1`.
- `f(i, j, isTrue)`: return `0` if `i > j`. If `i == j`, return whether the operand matches `isTrue`.
- If `dp[i][j][isTrue]` is filled, return it.
- For each operator `idx` from `i + 1` to `j - 1` step `2`, get `lT`, `lF`, `rT`, `rF` and add the right combination to `ways` (mod `10^9 + 7`).
- Store and return `ways`.
- Call `f(0, n - 1, 1)`.

### Complexity
Time: **O(n^3)**  
Space: **O(n^2)** for the dp table, plus **O(n)** recursion stack

---

## Approach 2: Tabulation (Bottom-Up)

### Idea
Remove the recursion and fill both the true and false counts for every range, shortest ranges first.

### Steps
- Create `dp[n][n][2]` filled with `0`.
- For `i = n - 1` down to `0`, skip odd `i`. For `j = i` up to `n - 1` in steps of `2` (only operand positions can start or end a range).
- If `i == j`: set `dp[i][j][1]` and `dp[i][j][0]` from whether the operand is `T`.
- Otherwise, for both `isTrue = 0` and `isTrue = 1`, loop over every operator `idx` and combine `dp[i][idx - 1]` with `dp[idx + 1][j]` using the table above.
- Answer is `dp[0][n - 1][1]`.

### Complexity
Time: **O(n^3)**  
Space: **O(n^2)**, no recursion stack

---

## Why There Is No Space-Optimized Version
`dp[i][j]` reads `dp[i][idx - 1]` and `dp[idx + 1][j]` for EVERY operator `idx`, so any earlier row or column can be needed. The full `O(n^2)` table has to stay.

## Key Observation
Counting "ways to get true" is not enough on its own. The `^` operator and the false case of `&` need the number of ways each side gives FALSE too. So every range stores two numbers, true and false, and the operator only decides how to mix them. Choosing the LAST operator is what keeps the two sides independent.

## When to use this
If problem involves:
- Counting the ways to bracket an expression
- The result depends on the operator that is evaluated last
→ Think **interval DP on the last operator**, and keep one count per possible result value.

## Edge Cases
- A single operand (`T` gives `1`, `F` gives `0`).
- Expressions where the answer is `0`.
- Long expressions, where counts grow fast, so take the modulus after every addition.
- Odd indices are operators, so ranges must start and end on even indices.

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Recursion + Memoization | O(n^3) | O(n^2) + O(n) stack |
| Tabulation | O(n^3) | O(n^2) |

where:
- `n` = length of the expression

## Related Problems
- Burst Balloons
- Minimum Cost to Cut a Stick
- Different Ways to Add Parentheses
- Matrix Chain Multiplication