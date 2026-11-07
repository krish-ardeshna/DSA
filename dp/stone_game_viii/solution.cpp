#include <bits/stdc++.h>
using namespace std;

// Problem: Stone Game VIII
// Link: https://leetcode.com/problems/stone-game-viii/
// Difficulty: Hard
// Pattern: Game Theory + DP (Prefix Sum + Suffix Max)

// ------------------------------------------------------------
// Approach: Prefix Sum + Right-to-Left DP on Prefix Values
// ------------------------------------------------------------
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);

        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        long long dp = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};

int main() {
    Solution obj;
    vector<int> stones = {-1, 2, -3, 4, -5};
    cout << obj.stoneGameVIII(stones);
    return 0;
}