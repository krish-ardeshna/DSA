#include <bits/stdc++.h>
using namespace std;

// Problem: Wildcard Matching
// Link: https://leetcode.com/problems/wildcard-matching/
// Difficulty: Hard
// Pattern: DP on Strings (Pattern Matching with '?' and '*')

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    bool f(int i, int j, const string &s, const string &p,
           vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return true;
        if (j == 0) return false;

        if (i == 0) {
            for (int jj = 0; jj < j; jj++) {
                if (p[jj] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        }

        if (p[j - 1] == '*') {
            return dp[i][j] = f(i, j - 1, s, p, dp)
                            || f(i - 1, j, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s, p, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && (p[j - 1] == '*');
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = true;

        for (int j = 1; j <= m; j++) {
            prev[j] = prev[j - 1] && (p[j - 1] == '*');
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = false;

            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                }
                else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.isMatch("aa", "a") << " "
         << s1.isMatch("aa", "*") << " "
         << s1.isMatch("cb", "?a") << "\n";

    SolutionTabulation s2;
    cout << s2.isMatch("aa", "a") << " "
         << s2.isMatch("aa", "*") << " "
         << s2.isMatch("cb", "?a") << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.isMatch("aa", "a") << " "
         << s3.isMatch("aa", "*") << " "
         << s3.isMatch("cb", "?a") << "\n";

    return 0;
}