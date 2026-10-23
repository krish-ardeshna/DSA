#include <bits/stdc++.h>
using namespace std;

// Problem: Shortest Common Supersequence
// Link: https://leetcode.com/problems/shortest-common-supersequence/
// Difficulty: Hard
// Pattern: DP on Strings (LCS Table + Traceback to Build the String)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down), Then Traceback
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

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        f(n, m, str1, str2, dp);

        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--; j--;
            }
            else if (f(i - 1, j, str1, str2, dp) > f(i, j - 1, str1, str2, dp)) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up), Then Traceback
// ------------------------------------------------------------
class SolutionTabulation {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--; j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.shortestCommonSupersequence("abac", "cab") << " "
         << s1.shortestCommonSupersequence("aaaaaaaa", "aaaaaaaa") << " "
         << s1.shortestCommonSupersequence("abc", "def") << "\n";

    SolutionTabulation s2;
    cout << s2.shortestCommonSupersequence("abac", "cab") << " "
         << s2.shortestCommonSupersequence("aaaaaaaa", "aaaaaaaa") << " "
         << s2.shortestCommonSupersequence("abc", "def") << "\n";

    return 0;
}