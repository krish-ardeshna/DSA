#include <bits/stdc++.h>
using namespace std;

// Problem: Valid Sudoku
// Link: https://leetcode.com/problems/valid-sudoku/
// Difficulty: Medium
// Pattern: Hash Set

// ------------------------------------------------------------
// Approach: Hash Set
// ------------------------------------------------------------

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                char num = board[i][j];
                int box = (i / 3) * 3 + (j / 3);

                if (row[i].count(num) ||
                    col[j].count(num) ||
                    boxes[box].count(num)) {

                    return false;
                }

                row[i].insert(num);
                col[j].insert(num);
                boxes[box].insert(num);
            }
        }
        return true;
    }
};

int main() {
    
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    cout << boolalpha << s.isValidSudoku(board) << "\n";

    return 0;
}