#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Falling Path Sum
// Link: https://leetcode.com/problems/minimum-falling-path-sum/
// Difficulty: Medium
// Pattern: DP on Grids (Variable Start / Variable End)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix[0].size();
        if (j < 0 || j >= m) return 1e9;
        if (i == 0) return matrix[0][j];

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int up = f(i - 1, j, matrix, dp);
        int leftDiag = f(i - 1, j - 1, matrix, dp);
        int rightDiag = f(i - 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({up, leftDiag, rightDiag});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, f(n - 1, j, matrix, dp));
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = dp[i - 1][j];
                int leftDiag = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                int rightDiag = (j < m - 1) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Single Row)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> curr(m, 0);

            for (int j = 0; j < m; j++) {
                int up = prev[j];
                int leftDiag = (j > 0) ? prev[j - 1] : 1e9;
                int rightDiag = (j < m - 1) ? prev[j + 1] : 1e9;

                curr[j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};

int main() {
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    SolutionMemo s1;
    cout << s1.minFallingPathSum(matrix) << "\n";

    SolutionTabulation s2;
    cout << s2.minFallingPathSum(matrix) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.minFallingPathSum(matrix) << "\n";

    return 0;
}