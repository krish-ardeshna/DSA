# Valid Sudoku

Platform: LeetCode  
Problem Link: https://leetcode.com/problems/valid-sudoku/  
Difficulty: Medium  
Pattern: Hash Set

## What I understood
We are given a partially filled 9 × 9 Sudoku board.

We need to determine whether it is valid according to Sudoku rules.

A digit must not appear more than once in:

- the same row
- the same column
- the same 3 × 3 sub-box

Empty cells are represented by '.'.

## Idea
Maintain three hash sets for every:

- row
- column
- 3 × 3 box

While traversing the board:

- if the current digit already exists in its row, column or box, the board is invalid
- otherwise insert it into all three sets

## Approach
- Create hash sets for rows, columns and boxes
- Traverse every cell
- Ignore empty cells
- Compute the corresponding box index
- Check for duplicates
- Insert the digit into the sets
- Return true if no duplicates are found

## Key Observation
Every digit only needs to be checked once.

Using separate hash sets allows constant-time duplicate detection.

## When to use this
If the problem involves:
- duplicate detection
- rows and columns
- matrix validation
- fixed-size grids

→ think Hash Set

## Edge Cases
- Empty board
- Duplicate in a row
- Duplicate in a column
- Duplicate in a 3 × 3 box
- Completely valid board

## Complexity
Time: O(1)

Space: O(1)

The board size is fixed (9 × 9), so both time and space remain constant.

## Related Problems
- Sudoku Solver
- Valid Anagram
- Contains Duplicate
- Set Matrix Zeroes