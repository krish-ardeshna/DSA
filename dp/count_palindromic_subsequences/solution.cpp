#include <bits/stdc++.h>
using namespace std;

// Problem: Count Palindromic Subsequences
// Link: https://leetcode.com/problems/count-palindromic-subsequences/
// Difficulty: Hard
// Pattern: DP on Strings (Distinct Subsequences, Run for Each of 1000 Patterns)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
    static const int MOD = 1e9 + 7;

    // ways the first j chars of t appear as a subsequence of the first i chars of s
    int f(int i, int j, const string& s, const string& t,
          vector<vector<int>>& dp) {
        if (j == 0) return 1;
        if (i == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int skip = f(i - 1, j, s, t, dp);
        int take = 0;
        if (s[i - 1] == t[j - 1])
            take = f(i - 1, j - 1, s, t, dp);

        return dp[i][j] = (skip + take) % MOD;
    }

    int countWays(const string& s, const string& t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s, t, dp);
    }

public:
    int countPalindromes(string s) {
        long long ans = 0;

        for (int a = 0; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 9; c++) {
                    string t = "00000";
                    t[0] = t[4] = '0' + a;
                    t[1] = t[3] = '0' + b;
                    t[2] = '0' + c;

                    ans = (ans + countWays(s, t)) % MOD;
                }
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
    static const int MOD = 1e9 + 7;

    int countWays(const string& s, const string& t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][m];
    }

public:
    int countPalindromes(string s) {
        long long ans = 0;

        for (int a = 0; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 9; c++) {
                    string t = "00000";
                    t[0] = t[4] = '0' + a;
                    t[1] = t[3] = '0' + b;
                    t[2] = '0' + c;

                    ans = (ans + countWays(s, t)) % MOD;
                }
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
    static const int MOD = 1e9 + 7;

    int countWays(const string& s, const string& t) {
        int n = s.size();
        int m = t.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = (prev[j - 1] + prev[j]) % MOD;
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[m];
    }

public:
    int countPalindromes(string s) {
        long long ans = 0;

        for (int a = 0; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 9; c++) {
                    string t = "00000";
                    t[0] = t[4] = '0' + a;
                    t[1] = t[3] = '0' + b;
                    t[2] = '0' + c;

                    ans = (ans + countWays(s, t)) % MOD;
                }
            }
        }

        return ans;
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.countPalindromes("103301") << " "
         << s1.countPalindromes("0000000") << " "
         << s1.countPalindromes("9999900000") << "\n";

    SolutionTabulation s2;
    cout << s2.countPalindromes("103301") << " "
         << s2.countPalindromes("0000000") << " "
         << s2.countPalindromes("9999900000") << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.countPalindromes("103301") << " "
         << s3.countPalindromes("0000000") << " "
         << s3.countPalindromes("9999900000") << "\n";

    return 0;
}