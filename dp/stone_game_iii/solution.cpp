#include <bits/stdc++.h>
using namespace std;

// Problem: Stone Game III
// Link: https://leetcode.com/problems/stone-game-iii/
// Difficulty: Hard
// Pattern: Game Theory + DP

// ------------------------------------------------------------
// Approach 1: Recursion (No Memoization)
// ------------------------------------------------------------
class SolutionRecursive {
public:
    int solve(vector<int>& stoneValue, int i) {
        int n = stoneValue.size();

        if (i >= n)
            return 0;

        int take = 0;
        int best = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];
            best = max(best, take - solve(stoneValue, i + k + 1));
        }

        return best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int diff = solve(stoneValue, 0);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};

// ------------------------------------------------------------
// Approach 2: Bottom-Up DP (O(n) space)
// ------------------------------------------------------------
class SolutionDPArray {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            dp[i] = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};

// ------------------------------------------------------------
// Approach 3: Bottom-Up DP (O(1) space, rolling array)
// ------------------------------------------------------------
class SolutionDPRolling {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            int best = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                best = max(best, take - dp[(i + k + 1) % 4]);
            }

            dp[i % 4] = best;
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};

int main() {
    vector<int> stoneValue = {1, 2, 3, 7};

    SolutionRecursive s1;
    cout << s1.stoneGameIII(stoneValue) << "\n";

    SolutionDPArray s2;
    cout << s2.stoneGameIII(stoneValue) << "\n";

    SolutionDPRolling s3;
    cout << s3.stoneGameIII(stoneValue) << "\n";

    return 0;
}