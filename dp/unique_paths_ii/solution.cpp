#include <bits/stdc++.h>
using namespace std;

// Problem: Unique Paths II
// Link: https://leetcode.com/problems/unique-paths-ii/
// Difficulty: Medium
// Pattern: DP on Grids (With Obstacles)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (i >= 0 && j >= 0 && mat[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        long long up = f(i - 1, j, mat, dp);
        long long left = f(i, j - 1, mat, dp);

        return dp[i][j] = static_cast<int>(up + left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    long long up = 0;
                    long long left = 0;
                    if (i > 0) up = dp[i - 1][j];
                    if (j > 0) left = dp[i][j - 1];
                    dp[i][j] = static_cast<int>(up + left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Single Row)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) curr[j] = 0;
                else if (i == 0 && j == 0) curr[j] = 1;
                else {
                    long long up = 0;
                    long long left = 0;
                    if (i > 0) up = prev[j];
                    if (j > 0) left = curr[j - 1];
                    curr[j] = static_cast<int>(up + left);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    SolutionMemo s1;
    cout << s1.uniquePathsWithObstacles(grid) << "\n";

    SolutionTabulation s2;
    cout << s2.uniquePathsWithObstacles(grid) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.uniquePathsWithObstacles(grid) << "\n";

    return 0;
}