# Unique 3-Digit Even Numbers
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/unique-3-digit-even-numbers/  
Difficulty: Medium  
Pattern: Combinatorics (Frequency Check) / Brute Force Permutation + Set

## What I understood
Given an array `digits` (possibly with repeated digit values as separate array elements), form all possible distinct 3-digit even numbers using digits from the array — each array ELEMENT can be used at most once per number (based on its position, not its value), no leading zero allowed, last digit must be even. Count distinct resulting numbers.

## Example
```
Input
digits = [2,1,3,0]
Output
(count of distinct 3-digit even numbers formable)
```

## Idea
Two fundamentally different strategies to enumerate valid 3-digit combinations:
- **Frequency-based**: since only digit VALUES matter for forming a number (not which array position they came from), count how many of each digit value (0-9) are available, then for every possible 3-digit even number candidate (100-998 step-checked for evenness), verify if enough copies of each required digit exist in the frequency count.
- **Index-based brute force**: directly iterate all ordered triples of ARRAY INDICES (not values), build the number from `digits[i], digits[j], digits[k]`, skip invalid ones (leading zero, odd last digit, reused index), and deduplicate resulting numbers via a set.

## Approach 1: Frequency Count + Combinatorial Digit-Slot Check

### Idea
Instead of enumerating index triples, enumerate candidate DIGIT VALUES directly for each of the 3 positions (hundreds: 1-9, tens: 0-9, units: 0,2,4,6,8), then check feasibility against the original digit frequency count.

### Steps
- Build `freq[0..9]` — count of each digit value in the input array.
- Triple nested loop over candidate digits: `i` (hundreds, 1-9), `j` (tens, 0-9), `k` (units, even 0-8).
- For each candidate triple, build a `used[0..9]` count of how many of each digit this specific candidate number requires.
- Check if `used[d] <= freq[d]` for all digits `d` — if so, this candidate number is formable, increment `ans`.

### Complexity
Time: **O(1)** — fixed iteration count (9 × 10 × 5 = 450 combinations checked, each O(10) verification) regardless of input size, plus O(n) to build frequency array            
Space: **O(1)** — fixed-size frequency/used arrays

---

## Approach 2: Brute Force Index Permutation + Set Deduplication

### Idea
Directly try every ordered triple of distinct ARRAY INDICES (not digit values), constructing a number from each valid triple and relying on a `set` to automatically deduplicate identical resulting numbers (since different index triples can produce the same numeric value if duplicate digit values exist in the array).

### Steps
- Triple nested loop over indices `i, j, k` (all distinct, from array).
- Skip if `digits[i] == 0` (leading zero) or `digits[k]` is odd (must be even).
- Construct `num = digits[i]*100 + digits[j]*10 + digits[k]`.
- Insert into a `set<int>` (automatically deduplicates).
- Return `set.size()`.

### Complexity
Time: **O(n³)** — triple nested loop over array indices         
Space: **O(n³)** worst case for set storage (bounded practically by at most 900 possible 3-digit numbers)

---

## Key Observation
Approach 1 recognizes that only digit VALUES (not positions) matter, converting a potentially large index-based search into a bounded constant-size search over digit-value combinations — a much better scaling strategy when the input array is large, since Approach 2's complexity grows with array size while Approach 1's stays constant.

## When to use this
If problem involves:
- Forming numbers/combinations from a multiset of values with usage-count constraints
- Input size can be large, but the output space (possible numbers) is small/bounded
→ Think **frequency-count + candidate-value enumeration** (Approach 1) for better scaling; use index-based brute force with dedup set (Approach 2) only for smaller inputs or simpler-to-reason-about correctness verification.

## Edge Cases
- Not enough digits to form any valid number (fewer than 3 usable elements, or insufficient specific digit values).
- Multiple duplicate digit values in the input array.
- No valid even digit available (no numbers formable at all).
- All zeros except one (severely limits valid leading digit options).

## Complexity (Overall)
| Approach | Time | Space |
|---|---|---|
| Frequency Check | O(1) fixed + O(n) freq build | O(1) |
| Brute Force Permutation | O(n³) | O(n³) worst case (bounded by ~900) |

where:
- `n` = number of elements in digits array

## Related Problems
- Permutations
- Numbers With Repeated Digits
- Count Numbers with Unique Digits
- Next Greater Numerically Balanced Number