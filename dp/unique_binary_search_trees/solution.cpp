#include <bits/stdc++.h>
using namespace std;

// Problem: Unique Binary Search Trees
// Link: https://leetcode.com/problems/unique-binary-search-trees/
// Difficulty: Medium
// Pattern: Dynamic Programming / Catalan Numbers

// ------------------------------------------------------------
// Approach: Dynamic Programming
// ------------------------------------------------------------

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++) {
            for (int root = 1; root <= nodes; root++) {
                
                int left = root - 1;
                int right = nodes - root;

                dp[nodes] += dp[left] * dp[right];
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 4;
    Solution s;

    cout << s.numTrees(n) << "\n";

    return 0;
}