#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Sets of K Non-Overlapping Line Segments
// Link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Difficulty: Medium
// Pattern: Combinatorics (Pascal's Triangle DP)

// ------------------------------------------------------------
// Approach: Reduce to C(n+k-1, 2k) via Pascal's Triangle
// ------------------------------------------------------------
class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        vector<vector<long long>> dp(N + 1, vector<long long>(R + 1, 0));

        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;

            for (int j = 1; j <= min(i, R); j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }

        return dp[N][R];
    }
};

int main() {
    Solution obj;
    int n = 4, k = 2;
    cout << obj.numberOfSets(n, k);
    return 0;
}