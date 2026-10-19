#include <bits/stdc++.h>
using namespace std;

// Problem: Coin Change II
// Link: https://leetcode.com/problems/coin-change-ii/
// Difficulty: Medium
// Pattern: DP on Subsequences (Unbounded Knapsack, Count Combinations)

const long long LIMIT = INT_MAX;

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx == 0) {
            return (target % arr[0] == 0);
        }

        if (dp[idx][target] != -1)
            return dp[idx][target];

        long long notTake = f(idx - 1, target, arr, dp);
        long long take = 0;
        if (arr[idx] <= target)
            take = f(idx, target - arr[idx], arr, dp);

        return dp[idx][target] = (int)min(LIMIT, take + notTake);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        if (amount == 0) return 1;
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        if (amount == 0) return 1;
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int tar = 0; tar <= amount; tar++)
            dp[0][tar] = (tar % coins[0] == 0);

        for (int idx = 1; idx < n; idx++) {
            for (int tar = 0; tar <= amount; tar++) {
                long long notTake = dp[idx - 1][tar];
                long long take = 0;

                if (coins[idx] <= tar)
                    take = dp[idx][tar - coins[idx]];

                dp[idx][tar] = (int)min(LIMIT, take + notTake);
            }
        }

        return dp[n - 1][amount];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        if (amount == 0) return 1;
        if (n == 0) return 0;

        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int tar = 0; tar <= amount; tar++)
            prev[tar] = (tar % coins[0] == 0);

        for (int idx = 1; idx < n; idx++) {
            for (int tar = 0; tar <= amount; tar++) {
                long long notTake = prev[tar];
                long long take = 0;

                if (coins[idx] <= tar)
                    take = curr[tar - coins[idx]];

                curr[tar] = (int)min(LIMIT, take + notTake);
            }
            prev = curr;
        }

        return prev[amount];
    }
};

int main() {
    vector<int> c1 = {1, 2, 5};
    vector<int> c2 = {2};
    vector<int> c3 = {10};

    SolutionMemo s1;
    cout << s1.change(5, c1) << " " << s1.change(3, c2) << " " << s1.change(10, c3) << "\n";

    SolutionTabulation s2;
    cout << s2.change(5, c1) << " " << s2.change(3, c2) << " " << s2.change(10, c3) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.change(5, c1) << " " << s3.change(3, c2) << " " << s3.change(10, c3) << "\n";

    return 0;
}