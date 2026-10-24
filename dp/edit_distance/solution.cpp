#include <bits/stdc++.h>
using namespace std;

// Problem: Edit Distance
// Link: https://leetcode.com/problems/edit-distance/
// Difficulty: Medium
// Pattern: DP on Strings (Two Strings, Replace / Delete / Insert)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int i, int j, const string &s1, const string &s2,
          vector<vector<int>> &dp) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = 1 + min({
            f(i - 1, j - 1, s1, s2, dp), // Replace
            f(i - 1, j, s1, s2, dp),     // Delete
            f(i, j - 1, s1, s2, dp)      // Insert
        });
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(n, m, word1, word2, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]
                    });
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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                }
                else {
                    curr[j] = 1 + min({
                        prev[j], curr[j - 1], prev[j - 1]
                    });
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.minDistance("horse", "ros") << " "
         << s1.minDistance("intention", "execution") << " "
         << s1.minDistance("", "ab") << "\n";

    SolutionTabulation s2;
    cout << s2.minDistance("horse", "ros") << " "
         << s2.minDistance("intention", "execution") << " "
         << s2.minDistance("", "ab") << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.minDistance("horse", "ros") << " "
         << s3.minDistance("intention", "execution") << " "
         << s3.minDistance("", "ab") << "\n";

    return 0;
}