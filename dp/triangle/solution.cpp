#include <bits/stdc++.h>
using namespace std;

// Problem: Triangle
// Link: https://leetcode.com/problems/triangle/
// Difficulty: Medium
// Pattern: DP on Grids (Fixed Start, Variable End)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == n - 1) return triangle[n - 1][j];

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int down = triangle[i][j] + f(i + 1, j, n, triangle, dp);
        int diagonal = triangle[i][j] + f(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return f(0, 0, n, triangle, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) dp[n - 1][j] = triangle[n - 1][j];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Single Row)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> front(n, 0), curr(n, 0);

        for (int j = 0; j < n; j++) front[j] = triangle[n - 1][j];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j + 1];
                curr[j] = min(down, diagonal);
            }
            front = curr;
        }

        return front[0];
    }
};

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    SolutionMemo s1;
    cout << s1.minimumTotal(triangle) << "\n";

    SolutionTabulation s2;
    cout << s2.minimumTotal(triangle) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.minimumTotal(triangle) << "\n";

    return 0;
}