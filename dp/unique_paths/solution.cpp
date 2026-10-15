#include <bits/stdc++.h>
using namespace std;

// Problem: Unique Paths
// Link: https://leetcode.com/problems/unique-paths/
// Difficulty: Medium
// Pattern: DP on Grids

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int up = f(i - 1, j, dp);
        int left = f(i, j - 1, dp);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if (i > 0) up = dp[i - 1][j];
                    if (j > 0) left = dp[i][j - 1];
                    dp[i][j] = up + left;
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
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int up = 0;
                    int left = 0;

                    if (i > 0) up = prev[j];
                    if (j > 0) left = curr[j - 1];

                    curr[j] = up + left;
                }
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};

int main() {
    int m = 3, n = 7;

    SolutionMemo s1;
    cout << s1.uniquePaths(m, n) << "\n";

    SolutionTabulation s2;
    cout << s2.uniquePaths(m, n) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.uniquePaths(m, n) << "\n";

    return 0;
}