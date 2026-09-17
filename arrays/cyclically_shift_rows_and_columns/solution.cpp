#include <bits/stdc++.h>
using namespace std;

// Problem: Cyclically Shift Rows and Columns
// Link: https://leetcode.com/problems/cyclically-shift-rows-and-columns/
// Difficulty: Easy
// Pattern: Matrix - Modular Index Shifting

// ------------------------------------------------------------
// Approach: Row Shift Pass Then Column Shift Pass, Using Modular Indexing
// ------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        vector<vector<int>> temp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            int k = rowShift[i] % n;
            for (int j = 0; j < n; j++) {
                temp[i][j] = grid[i][(j + k) % n];
            }
        }

        vector<vector<int>> ans(n, vector<int>(n));

        for (int j = 0; j < n; j++) {
            int k = colShift[j] % n;
            for (int i = 0; i < n; i++) {
                ans[i][j] = temp[(i + k) % n][j];
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    int n = 3;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> rowShift = {1, 0, 2};
    vector<int> colShift = {0, 1, 2};

    vector<vector<int>> result = obj.cyclicShift(n, grid, rowShift, colShift);

    for (auto& row : result) {
        for (int v : row) cout << v << " ";
        cout << "\n";
    }

    return 0;
}