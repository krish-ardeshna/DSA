#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Changes to Make K Semi-palindromes
// Link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/
// Difficulty: Hard
// Pattern: Precompute Substring Costs (Divisors of the Length) + Partition DP

const int INF = 1e9;

// ------------------------------------------------------------
// Shared step: cost[l][r] = minimum changes to make s[l..r] a semi-palindrome
// (a substring of length 1 can never be a semi-palindrome, so it stays INF)
// ------------------------------------------------------------
vector<vector<int>> buildCost(const string& s) {
    int n = s.size();

    vector<vector<int>> cost(n, vector<int>(n, INF));

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            // d is the step: positions with the same index modulo d must form a palindrome
            for (int d = 1; d < len; d++) {
                if (len % d != 0)
                    continue;

                int changes = 0;

                for (int r = 0; r < d; r++) {
                    int cnt = (len - 1 - r) / d + 1;

                    for (int p = 0; p < cnt / 2; p++) {
                        int a = l + r + p * d;
                        int b = l + r + (cnt - 1 - p) * d;

                        if (s[a] != s[b])
                            changes++;
                    }
                }

                cost[l][l + len - 1] =
                    min(cost[l][l + len - 1], changes);
            }
        }
    }

    return cost;
}

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // minimum changes to split the first i characters into exactly j semi-palindromes
    int f(int i, int j, vector<vector<int>>& cost, vector<vector<int>>& dp) {
        if (j == 0) return i == 0 ? 0 : INF;

        // each part needs at least 2 characters
        if (i < 2 * j) return INF;

        if (dp[i][j] != -1) return dp[i][j];

        int best = INF;

        // the last part is s[start..i-1], so start is at most i - 2
        for (int start = 2 * (j - 1); start <= i - 2; start++) {
            int before = f(start, j - 1, cost, dp);

            if (before == INF) continue;

            best = min(best, before + cost[start][i - 1]);
        }

        return dp[i][j] = best;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost = buildCost(s);

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return f(n, k, cost, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost = buildCost(s);

        // dp[j][i] = minimum changes to split the first i characters into j semi-palindromes
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 2 * j; i <= n; i++) {
                for (int start = 2 * (j - 1); start <= i - 2; start++) {
                    if (dp[j - 1][start] == INF)
                        continue;

                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][start] + cost[start][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost = buildCost(s);

        // row j only reads row j - 1, so two rows are enough
        vector<int> prev(n + 1, INF), curr(n + 1, INF);
        prev[0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            fill(curr.begin(), curr.end(), INF);

            for (int end = 2 * parts; end <= n; end++) {
                for (int start = 2 * (parts - 1);
                     start <= end - 2; start++) {

                    if (prev[start] == INF)
                        continue;

                    curr[end] = min(
                        curr[end],
                        prev[start] + cost[start][end - 1]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};

int main() {
    SolutionMemo s1;
    cout << s1.minimumChanges("abcac", 2) << " "
         << s1.minimumChanges("abcdef", 2) << " "
         << s1.minimumChanges("aabbaa", 3) << "\n";

    SolutionTabulation s2;
    cout << s2.minimumChanges("abcac", 2) << " "
         << s2.minimumChanges("abcdef", 2) << " "
         << s2.minimumChanges("aabbaa", 3) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.minimumChanges("abcac", 2) << " "
         << s3.minimumChanges("abcdef", 2) << " "
         << s3.minimumChanges("aabbaa", 3) << "\n";

    return 0;
}