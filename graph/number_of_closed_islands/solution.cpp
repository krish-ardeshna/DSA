#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Closed Islands
// Link: https://leetcode.com/problems/number-of-closed-islands/
// Difficulty: Medium
// Pattern: Graph - Grid DFS (Flood Fill From the Border First)

// ------------------------------------------------------------
// Approach: Flood Every Land Cell Touching the Border, Then Count the Remaining Islands
// ------------------------------------------------------------
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n ||
            grid[r][c] != 0)
            return;

        grid[r][c] = 1;

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> g1 = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0}
    };
    cout << obj.closedIsland(g1) << "\n";

    vector<vector<int>> g2 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << obj.closedIsland(g2) << "\n";

    return 0;
}