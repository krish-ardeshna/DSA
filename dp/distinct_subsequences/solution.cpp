#include <bits/stdc++.h>
using namespace std;

// Problem: Distinct Subsequences
// Link: https://leetcode.com/problems/distinct-subsequences/
// Difficulty: Hard
// Pattern: DP on Strings (Count Subsequence Matches)

const int MOD = 1e9 + 7;

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, const string &s, const string &t,
          vector<vector<long long>>& dp) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] =
                (f(i - 1, j - 1, s, t, dp) +
                 f(i - 1, j, s, t, dp)) % MOD;
        }

        return dp[i][j] = f(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        if (m > n) return 0;

        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int j = 1; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
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
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = (prev[j - 1] + prev[j]) % MOD;
                }
                else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.numDistinct("rabbbit", "rabbit") << " "
         << s1.numDistinct("babgbag", "bag") << " "
         << s1.numDistinct("a", "ab") << "\n";

    SolutionTabulation s2;
    cout << s2.numDistinct("rabbbit", "rabbit") << " "
         << s2.numDistinct("babgbag", "bag") << " "
         << s2.numDistinct("a", "ab") << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.numDistinct("rabbbit", "rabbit") << " "
         << s3.numDistinct("babgbag", "bag") << " "
         << s3.numDistinct("a", "ab") << "\n";

    return 0;
}