#include <bits/stdc++.h>
using namespace std;

// Problem: Distinct Subsequences
// Link: https://leetcode.com/problems/distinct-subsequences/
// Difficulty: Hard
// Pattern: DP (1D Rolling Array, Right-to-Left Update)

// ------------------------------------------------------------
// Approach: Space-Optimized DP (1D Array, Reverse Inner Loop)
// ------------------------------------------------------------
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = min((long long)INT_MAX,
                                dp[j] + dp[j - 1]);
                }
            }
        }

        return dp[m];
    }
};

int main() {
    Solution obj;
    string s = "rabbbit";
    string t = "rabbit";
    cout << obj.numDistinct(s, t);
    return 0;
}