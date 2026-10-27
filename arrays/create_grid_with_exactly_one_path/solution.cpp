#include <bits/stdc++.h>
using namespace std;

// Problem: Create Grid With Exactly One Path
// Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Construction (Open an L-Shaped Corridor, Block Everything Else)

// ------------------------------------------------------------
// Approach: Open the First Row and the Last Column, Block All Other Cells
// ------------------------------------------------------------
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        grid[0] = string(n, '.');

        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> tests = {{3, 4}, {1, 3}, {3, 1}};

    for (auto& t : tests) {
        vector<string> g = obj.createGrid(t[0], t[1]);
        for (const string& row : g) cout << row << "\n";
        cout << "\n";
    }

    return 0;
}