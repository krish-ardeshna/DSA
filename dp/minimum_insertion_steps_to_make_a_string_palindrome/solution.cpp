#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Insertion Steps to Make a String Palindrome
// Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Difficulty: Hard
// Pattern: DP on Strings (n - Longest Palindromic Subsequence)

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

    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int lps = f(n, n, s, t, dp);

        return n - lps;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int minInsertions(string s) {
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

        return n - dp[n][n];
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

    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.minInsertions("zzazz") << " "
         << s1.minInsertions("mbadm") << " "
         << s1.minInsertions("leetcode") << "\n";

    SolutionTabulation s2;
    cout << s2.minInsertions("zzazz") << " "
         << s2.minInsertions("mbadm") << " "
         << s2.minInsertions("leetcode") << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.minInsertions("zzazz") << " "
         << s3.minInsertions("mbadm") << " "
         << s3.minInsertions("leetcode") << "\n";

    return 0;
}