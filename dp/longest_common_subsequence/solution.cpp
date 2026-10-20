#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Common Subsequence
// Link: https://leetcode.com/problems/longest-common-subsequence/
// Difficulty: Medium
// Pattern: DP on Strings (Two Strings, Match / Skip)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, text1, text2, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            curr[0] = 0;

            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }

        return prev[m];
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.longestCommonSubsequence("abcde", "ace") << " "
         << s1.longestCommonSubsequence("abc", "abc") << " "
         << s1.longestCommonSubsequence("abc", "def") << "\n";

    SolutionTabulation s2;
    cout << s2.longestCommonSubsequence("abcde", "ace") << " "
         << s2.longestCommonSubsequence("abc", "abc") << " "
         << s2.longestCommonSubsequence("abc", "def") << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.longestCommonSubsequence("abcde", "ace") << " "
         << s3.longestCommonSubsequence("abc", "abc") << " "
         << s3.longestCommonSubsequence("abc", "def") << "\n";

    return 0;
}