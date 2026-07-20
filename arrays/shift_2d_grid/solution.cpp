#include <bits/stdc++.h>
using namespace std;

// Problem: Shift 2D Grid
// Link: https://leetcode.com/problems/shift-2d-grid/
// Difficulty: Easy
// Pattern: Matrix

// ------------------------------------------------------------
// Approach: 2D to 1D Index Mapping
// ------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        int totalCells = m * n;

        k %= totalCells;
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int oldIdx = i * n + j;
                int newIdx = (oldIdx + k) % totalCells;

                ans[newIdx / n][newIdx % n] = grid[i][j];
            }
        }
        return ans;
    }
};

int main() {

    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k = 1;
    Solution s;
    vector<vector<int>> ans = s.shiftGrid(grid, k);

    for (auto &row : ans) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}