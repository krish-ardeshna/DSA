#include <bits/stdc++.h>
using namespace std;

// Problem: Stone Game IV
// Link: https://leetcode.com/problems/stone-game-iv/
// Difficulty: Hard
// Pattern: Game Theory + DP

// ------------------------------------------------------------
// Approach: Bottom-Up DP (Perfect Square Removal)
// ------------------------------------------------------------
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution obj;
    cout << obj.winnerSquareGame(1) << "\n";
    cout << obj.winnerSquareGame(2) << "\n";
    cout << obj.winnerSquareGame(4) << "\n";
    return 0;
}