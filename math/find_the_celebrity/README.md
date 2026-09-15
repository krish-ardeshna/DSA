# Find the Celebrity
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/find-the-celebrity/  
Difficulty: Medium  
Pattern: Two Pointer Elimination / Brute Force Degree Counting

## What I understood
Given an `n x n` matrix `mat` where `mat[i][j] == 1` means person `i` knows person `j`, find the "celebrity" — someone known by everyone else but who knows no one else. Return their index, or -1 if no such person exists. Assume at most one celebrity can exist.

## Example
```
Input
mat = [[1,1,0],[0,1,0],[1,1,1]]
Output
1
```
```
Input
mat = [[1,0,1],[1,1,0],[0,1,1]]
Output
-1
```

---

## Approach 1: Two Pointer Elimination (O(n))

### Idea
A celebrity, if one exists, is UNIQUE — so instead of checking every person, eliminate non-candidates efficiently. Compare two candidates at a time: if `top` knows `bottom`, `top` cannot be the celebrity (celebrity knows no one) → eliminate `top`. Otherwise (`top` doesn't know `bottom`), `bottom` cannot be the celebrity (celebrity must be known by everyone, but `top` doesn't know them) → eliminate `bottom`. Repeat until one candidate remains, then verify that candidate against everyone else.

### Steps
- Two pointers `top = 0`, `bottom = n-1`.
- While `top < bottom`: if `mat[top][bottom] == 1` (top knows bottom) → `top++`; else → `bottom--`.
- After loop, `top` (== `bottom`) is the sole remaining candidate.
- Verify: for every other person `i`, if candidate knows `i` (`mat[candidate][i]==1`) OR `i` doesn't know candidate (`mat[i][candidate]==0`) → candidate fails, return -1.
- If verification passes for all, return candidate.

### Complexity
Time: **O(n)** — O(n) elimination + O(n) verification       
Space: **O(1)** 

---

## Approach 2: Brute Force Degree Counting (O(n²))

### Idea
Directly compute, for every person, how many people know them (`knowMe[i]`) and how many people they know (`Iknow[i]`). A celebrity must have `knowMe[i] == n-1` (known by everyone else) and `Iknow[i] == 0` (knows no one).

### Steps
- Double loop over the full matrix: for every `mat[i][j] == 1`, increment `knowMe[j]` and `Iknow[i]`.
- Scan all people: return the first `i` where `knowMe[i] == n-1 && Iknow[i] == 0`.
- Return -1 if no such person found.

### Complexity
Time: **O(n²)** — full matrix scan              
Space: **O(n)** — two count arrays

---

## Key Observation
Approach 1 exploits celebrity uniqueness to eliminate one candidate per comparison, reducing work from O(n²) to O(n) — a classic "candidate elimination" pattern. Approach 2 is more straightforward/brute-force, directly computing the degree-based definition without any cleverness, at the cost of scanning the entire matrix regardless.

## When to use this
If problem involves:
- Finding a unique element satisfying a "known by all, knows none" (or similar mutual-relation) property in a relation matrix
→ Think **two-pointer elimination** for O(n) when uniqueness is guaranteed; use **brute-force degree counting** when simplicity/clarity matters more or uniqueness isn't guaranteed upfront.

## Edge Cases
- No celebrity exists (verification/degree check fails for everyone, return -1).
- Single person (`n=1`, trivially the celebrity regardless of matrix content, since no one else to fail the check against).
- Everyone knows everyone (no celebrity, since celebrity must know no one).
- Celebrity is the last remaining candidate after elimination (verification confirms).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Two Pointer Elimination | O(n) | O(1) |
| Brute Force Degree Counting | O(n²) | O(n) |

where:
- `n` = number of people

## Related Problems
- Find All People With Secret
- Course Schedule
- Evaluate Division
- Minimum Number of Vertices to Reach All Nodes