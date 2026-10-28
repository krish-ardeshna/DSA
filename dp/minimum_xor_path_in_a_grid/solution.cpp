#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum XOR Path in a Grid
// Link: https://leetcode.com/problems/minimum-xor-path-in-a-grid/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: DP on Grids (State = Cell + XOR So Far, Bitset of Reachable Values)

const int X = 1024;

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // standing at (i, j) with xor 'cur' collected BEFORE this cell,
    // returns the minimum final xor reachable from here
    int f(int i, int j, int cur, vector<vector<int>>& grid, int m, int n,
          vector<vector<vector<int>>>& dp) {
        cur ^= grid[i][j];

        if (i == m - 1 && j == n - 1) return cur;

        if (dp[i][j][cur] != -1) return dp[i][j][cur];

        int best = INT_MAX;

        if (i + 1 < m)
            best = min(best, f(i + 1, j, cur, grid, m, n, dp));

        if (j + 1 < n)
            best = min(best, f(i, j + 1, cur, grid, m, n, dp));

        return dp[i][j][cur] = best;
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(X, -1)));

        return f(0, 0, 0, grid, m, n, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up, Full Table of Bitsets)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<X>>> dp(m, vector<bitset<X>>(n));

        dp[0][0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int x = 0; x < X; x++) {
                    if ((i > 0 && dp[i - 1][j][x]) || (j > 0 && dp[i][j - 1][x])) {
                        dp[i][j].set(x ^ grid[i][j]);
                    }
                }
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[m - 1][n - 1][x])
                return x;
        }

        return -1;
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bitset<X>> dp(n);
        dp[0].set(0);

        for (int i = 0; i < m; i++) {
            vector<bitset<X>> curr(n);

            for (int j = 0; j < n; j++) {
                for (int x = 0; x < X; x++) {
                    if (dp[j][x] || (j > 0 && curr[j - 1][x])) {
                        curr[j].set(x ^ grid[i][j]);
                    }
                }
            }

            dp = move(curr);
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> g1 = {{1, 2}, {3, 4}};
    vector<vector<int>> g2 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> g3 = {{5, 5, 5}};

    SolutionMemo s1;
    cout << s1.minCost(g1) << " " << s1.minCost(g2) << " " << s1.minCost(g3) << "\n";

    SolutionTabulation s2;
    cout << s2.minCost(g1) << " " << s2.minCost(g2) << " " << s2.minCost(g3) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.minCost(g1) << " " << s3.minCost(g2) << " " << s3.minCost(g3) << "\n";

    return 0;
}