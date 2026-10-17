#include <bits/stdc++.h>
using namespace std;

// Problem: Count Square Submatrices with All Ones
// Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Difficulty: Medium
// Pattern: DP on Grids (Largest Square Ending at Each Cell)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (matrix[i][j] == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int up = f(i - 1, j, matrix, dp);
        int left = f(i, j - 1, matrix, dp);
        int diag = f(i - 1, j - 1, matrix, dp);

        return dp[i][j] = 1 + min({up, left, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += f(i, j, matrix, dp);
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }
                }
                ans += dp[i][j];
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> prev(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        curr[j] = 1;
                    } else {
                        curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
                    }
                }
                ans += curr[j];
            }

            prev = curr;
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};

    SolutionMemo s1;
    cout << s1.countSquares(matrix) << "\n";

    SolutionTabulation s2;
    cout << s2.countSquares(matrix) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.countSquares(matrix) << "\n";

    return 0;
}