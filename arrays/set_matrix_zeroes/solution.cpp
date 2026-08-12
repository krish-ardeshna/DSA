#include <bits/stdc++.h>
using namespace std;

// Problem: Set Matrix Zeroes
// Link: https://leetcode.com/problems/set-matrix-zeroes/
// Difficulty: Medium
// Pattern: Matrix - In-Place Marker (First Row/Col as Flags)

// ------------------------------------------------------------
// Approach: Use First Row/Column as Marker Space
// ------------------------------------------------------------
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // mark the i-th row
                    matrix[i][0] = 0;
                    if (j != 0) {
                        // mark the j-th col
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
        }

        if (col0 == 0) {
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        }
    }
};

int main() {
    Solution obj;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    obj.setZeroes(matrix);

    for (auto& row : matrix) {
        for (int v : row) cout << v << " ";
        cout << "\n";
    }

    return 0;
}