#include <bits/stdc++.h>
using namespace std;

// Problem: Distinct Subsequences II
// Link: https://leetcode.com/problems/distinct-subsequences-ii/
// Difficulty: Hard
// Pattern: DP (Running Total + Last-Occurrence Correction)

// ------------------------------------------------------------
// Approach: DP with Duplicate Removal via Last Character Tracking
// ------------------------------------------------------------
class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        long long dp = 1;
        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';

            long long newDp = (2 * dp - last[idx] + MOD) % MOD;

            last[idx] = dp;
            dp = newDp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};

int main() {
    Solution obj;
    string s = "abc";
    cout << obj.distinctSubseqII(s);
    return 0;
}