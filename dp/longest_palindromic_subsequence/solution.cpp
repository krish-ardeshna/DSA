#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Palindromic Subsequence
// Link: https://leetcode.com/problems/longest-palindromic-subsequence/
// Difficulty: Medium
// Pattern: DP on Strings (LCS of a String and Its Reverse)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, const string& s1, const string& s2, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(n, n, s, t, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int lcs(const string& text1, const string& text2) {
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

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.longestPalindromeSubseq("bbbab") << " "
         << s1.longestPalindromeSubseq("cbbd") << " "
         << s1.longestPalindromeSubseq("a") << "\n";

    SolutionTabulation s2;
    cout << s2.longestPalindromeSubseq("bbbab") << " "
         << s2.longestPalindromeSubseq("cbbd") << " "
         << s2.longestPalindromeSubseq("a") << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.longestPalindromeSubseq("bbbab") << " "
         << s3.longestPalindromeSubseq("cbbd") << " "
         << s3.longestPalindromeSubseq("a") << "\n";

    return 0;
}