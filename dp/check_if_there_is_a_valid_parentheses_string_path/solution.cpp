#include <bits/stdc++.h>
using namespace std;

// Problem: Check if There Is a Valid Parentheses String Path
// Link: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
// Difficulty: Hard
// Pattern: Grid DP (Reachable Balance Values, Row-Rolling Array)

// ------------------------------------------------------------
// Approach: DP Over (Column, Balance) Rolled Row by Row
// ------------------------------------------------------------
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<bool>> dp(n, vector<bool>(m + n, false));
        dp[0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                vector<bool> cur(m + n, false);
                int change = grid[i][j] == '(' ? 1 : -1;

                for (int balance = 0; balance < m + n; balance++) {
                    int prev = balance - change;

                    if (prev < 0)
                        continue;

                    bool reachable = false;

                    if (i > 0)
                        reachable |= dp[j][prev];

                    if (j > 0)
                        reachable |= dp[j - 1][prev];

                    cur[balance] = reachable;
                }

                dp[j] = cur;
            }
        }

        return dp[n - 1][0];
    }
};

int main() {
    Solution obj;
    vector<vector<char>> grid = {
        {'(', '(', '('},
        {')', '(', ')'},
        {'(', '(', ')'}
    };
    cout << obj.hasValidPath(grid);
    return 0;
}