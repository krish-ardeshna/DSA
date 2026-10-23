#include <bits/stdc++.h>
using namespace std;

// Problem: Delete Operation for Two Strings
// Link: https://leetcode.com/problems/delete-operation-for-two-strings/
// Difficulty: Medium
// Pattern: DP on Strings (n + m - 2 * LCS)

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

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int lcsLen = f(n, m, word1, word2, dp);

        return n + m - 2 * lcsLen;
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

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return n + m - 2 * dp[n][m];
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

    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * lcs(word1, word2);
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.minDistance("sea", "eat") << " "
         << s1.minDistance("leetcode", "etco") << " "
         << s1.minDistance("abc", "def") << "\n";

    SolutionTabulation s2;
    cout << s2.minDistance("sea", "eat") << " "
         << s2.minDistance("leetcode", "etco") << " "
         << s2.minDistance("abc", "def") << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.minDistance("sea", "eat") << " "
         << s3.minDistance("leetcode", "etco") << " "
         << s3.minDistance("abc", "def") << "\n";

    return 0;
}