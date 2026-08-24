# Cinema Seat Allocation
Platform: LeetCode  
Problem Link: https://leetcode.com/problems/cinema-seat-allocation/  
Difficulty: Medium  
Pattern: Bit Manipulation (Bitmask per Row)

## What I understood
Cinema has `n` rows, each with 10 seats (columns 1-10). A family of 4 needs 4 consecutive seats in the same row, and by problem's seating rule, only 3 possible 4-seat windows exist per row: columns [2,3,4,5], [4,5,6,7], [6,7,8,9] (aisle seats 1 and 10 never usable in a 4-block). Given already-reserved seats, find max number of families of 4 that can be seated.

## Example
```
Input
n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output
4
```
```
Input
n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,8]]
Output
6
```

## Idea
Rows with zero reservations always fit exactly 2 families (place in left block [2-5] and right block [6-9] simultaneously, no overlap). Only rows that actually appear in `reservedSeats` need detailed checking — everything else defaults to the "2 families per empty row" rule. For rows with reservations, build a bitmask of occupied seats (only columns 2-9 matter, since 1 and 10 are never part of any valid 4-block) and check which of the 3 fixed windows are fully free.

## Approach: Row Bitmask + Fixed 3-Window Check
- Group reservations by row; build a bitmask per row marking occupied seats in range 2-9.
- Initialize `ans = 2 * (n - number of rows with any reservation)` — untouched rows get 2 families each.
- For each reserved row's bitmask, check three fixed 4-seat windows (left: 2-5, middle: 4-7, right: 6-9) for full availability via bitmask AND against 0.
- If both `left` and `right` are free → they don't overlap (columns 2-5 and 6-9 are disjoint), so 2 families fit; add 2.
- Else if any single window (`left`, `middle`, or `right`) is free → 1 family fits; add 1.
- Return final `ans`.

## Key Observation
Left and right windows never overlap (they're on opposite sides of column 5/6 boundary), so both can be used simultaneously — but middle overlaps both left and right, meaning it can never combine with either for 2 families in a row that has partial reservations. This asymmetry is why the check only considers "left AND right" as the 2-family case, not any other pairing.

## When to use this
If problem involves:
- Fixed-size checks against small bounded ranges (like fixed seat windows here)
- Sparse constraint data (most rows unaffected) alongside per-row detail
→ Think **bitmask per group + fixed window checks**, defaulting unaffected groups to a known baseline.

## Edge Cases
- Row with reservations outside columns 2-9 (e.g. column 1 or 10) — doesn't affect any window, row still gets 2 families.
- Row with reservations blocking all 3 windows → 0 families from that row.
- Multiple reservations in same row across different windows.
- `n` very large but very few actual reservations (most rows default to 2 families).

## Complexity
### Approach
Time: **O(R + n)** — R = number of reservations processed once, plus final row-count subtraction; unordered_map operations are O(1) average         
Space: **O(k)** — k = number of distinct rows with at least one reservation

where:
- `n` = total number of rows
- `R` = number of reserved seat entries
- `k` = number of rows with at least one reservation (k <= R)

## Related Problems
- Number of Ways to Wear Different Hats to Each Other
- Maximum Students Taking Exam
- Broken Calculator
- Bitwise AND of Numbers Range