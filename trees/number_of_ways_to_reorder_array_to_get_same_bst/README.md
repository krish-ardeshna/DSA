# Number of Ways to Reorder Array to Get Same BST
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/  
Difficulty: Hard  
Pattern: Divide and Conquer + Combinatorics (Pascal's Triangle for nCr)

## What I understood
`nums` is a permutation of `1..n`. Inserting its elements one by one, in order, into an empty BST produces a specific tree. Count how many OTHER orderings of `nums` produce exactly the same BST (so the original ordering itself is not counted). Return the count modulo `10^9 + 7`.

## Example
```
Input
nums = [2, 1, 3]
Output
1
```
Explanation: `[2, 3, 1]` builds the same tree (root 2, left 1, right 3).

```
Input
nums = [3, 4, 5, 1, 2]
Output
5
```
Explanation: five other orderings give the same tree, such as `[3, 1, 5, 2, 4]` and `[3, 1, 2, 5, 4]`.

```
Input
nums = [1, 2, 3]
Output
0
```
Explanation: a chain tree, every element must come after its parent in one forced order, so no other ordering works.

## Idea
The first element is always the root, so it must stay first in every valid ordering. Everything smaller than the root goes into the left subtree, and everything bigger goes into the right subtree.

The left and right subtrees are built independently, so:
- The elements of the left subtree must appear in an order that builds the same left subtree.
- The elements of the right subtree must appear in an order that builds the same right subtree.
- The two groups can be mixed (interleaved) freely, because left elements never affect where right elements land, and the other way around.

If the left group has `L` elements and the right group has `R` elements (`L + R = n - 1`), the number of ways to interleave two fixed sequences is **C(n - 1, L)**: choose which of the `n - 1` positions after the root belong to the left group.

So for a node:
```
ways(nums) = C(n - 1, L) * ways(left) * ways(right)
```
This counts ALL valid orderings including the original, so the final answer is `ways(nums) - 1`.

## Approach: Split by Root, Interleave Left and Right Orderings With C(n-1, leftSize)
- Precompute Pascal's triangle `comb[i][j] = C(i, j)` modulo `10^9 + 7` for `0 <= j <= i <= n`, using `comb[i][j] = comb[i-1][j-1] + comb[i-1][j]` and `comb[i][0] = comb[i][i] = 1`. This avoids modular inverses and factorial division.
- `solve(nums)`:
  - If `n <= 2`, return 1 (with 0, 1 or 2 elements, only one ordering builds the tree).
  - Split `nums[1..]` into `left` (smaller than `nums[0]`) and `right` (larger), keeping their original order.
  - Recurse on both parts.
  - Return `comb[n - 1][left.size()] * waysLeft * waysRight`, all modulo `10^9 + 7`.
- Final answer: `(solve(nums) - 1 + MOD) % MOD`, adding `MOD` before the modulo so the subtraction never goes negative.

## Key Observation
The two sub-problems are independent, so their counts MULTIPLY, and the only coupling between them is how their elements are interleaved, which is a single binomial coefficient. The Pascal's triangle table is the small DP piece: it fills `n * n` entries once and then gives every `nCr` in O(1), with no modular inverse. Keeping the original relative order inside `left` and `right` while splitting is essential, since the subtrees are defined by that order.

## When to use this
If problem involves:
- Counting orderings that produce the same tree (BST, heap, or similar)
- Independent subproblems that only differ by how they are interleaved
→ Think **split at the root, multiply the subproblem counts, and multiply by `C(total, leftSize)` for the interleavings**.

## Edge Cases
- Chain-like input such as `[1, 2, 3]` or `[3, 2, 1]` (every split has an empty side, so the answer is 0).
- Single element (answer 0).
- Two elements (answer 0, only one ordering exists).
- Perfectly balanced tree (largest answer, many interleavings).
- Subtraction at the end (`- 1` can wrap below zero modulo `10^9 + 7`, so `+ MOD` is added).

## Complexity
### Approach
Time: **O(n^2)**, the Pascal's triangle takes O(n^2), and the recursion splits at most O(n) per level over a depth of at most O(n)              
Space: **O(n^2)** for the `comb` table, plus **O(n)** for the recursion stack and the split vectors

where:
- `n` = number of elements

## Related Problems
- Unique Binary Search Trees
- Unique Binary Search Trees II
- Count Ways to Build Rooms in an Ant Colony
- Pascal's Triangle