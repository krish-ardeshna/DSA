#include <bits/stdc++.h>
using namespace std;

// Problem: Cherry Pickup II
// Link: https://leetcode.com/problems/cherry-pickup-ii/
// Difficulty: Hard
// Pattern: DP on Grids (3D DP, Two Moving Robots)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
        if (i == r - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = INT_MIN;

        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value = 0;
                if (j1 == j2) value += grid[i][j1];
                else value += grid[i][j1] + grid[i][j2];
                value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

        return f(0, 0, c - 1, r, c, grid, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
                else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if (nj1 < 0 || nj1 >= m || nj2 < 0 || nj2 >= m)
                                continue;

                            int value = 0;
                            if (j1 == j2) value += grid[i][j1];
                            else value += grid[i][j1] + grid[i][j2];

                            value += dp[i + 1][nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (2D Instead of 3D)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) dp[j1][j2] = grid[n - 1][j1];
                else dp[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            vector<vector<int>> curr(m, vector<int>(m, -1e8));

            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;

                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if (nj1 < 0 || nj1 >= m || nj2 < 0 || nj2 >= m)
                                continue;

                            int value = 0;

                            if (j1 == j2) value += grid[i][j1];
                            else value += grid[i][j1] + grid[i][j2];

                            value += dp[nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }

            dp = curr;
        }

        return dp[0][m - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};

    SolutionMemo s1;
    cout << s1.cherryPickup(grid) << "\n";

    SolutionTabulation s2;
    cout << s2.cherryPickup(grid) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.cherryPickup(grid) << "\n";

    return 0;
}