#include <bits/stdc++.h>
using namespace std;

// Problem: Coin Change
// Link: https://leetcode.com/problems/coin-change/
// Difficulty: Medium
// Pattern: DP on Subsequences (Unbounded Knapsack, Minimize Count)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (target % nums[0] == 0)
                return target / nums[0];
            return 1e9;
        }

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int notTake = f(idx - 1, target, nums, dp);

        int take = 1e9;
        if (nums[idx] <= target) {
            take = 1 + f(idx, target - nums[idx], nums, dp);
        }

        return dp[idx][target] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        if (amount == 0) return 0;
        if (n == 0) return -1;

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        if (ans >= 1e9) return -1;
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        if (amount == 0) return 0;
        if (n == 0) return -1;

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int tar = 0; tar <= amount; tar++) {
            if (tar % coins[0] == 0)
                dp[0][tar] = tar / coins[0];
            else
                dp[0][tar] = 1e9;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int tar = 0; tar <= amount; tar++) {
                int notTake = dp[idx - 1][tar];
                int take = 1e9;

                if (coins[idx] <= tar) {
                    take = 1 + dp[idx][tar - coins[idx]];
                }

                dp[idx][tar] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= 1e9) return -1;
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        if (amount == 0) return 0;
        if (n == 0) return -1;

        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int tar = 0; tar <= amount; tar++) {
            if (tar % coins[0] == 0)
                prev[tar] = tar / coins[0];
            else
                prev[tar] = 1e9;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int tar = 0; tar <= amount; tar++) {
                int notTake = prev[tar];
                int take = 1e9;

                if (coins[idx] <= tar) {
                    take = 1 + curr[tar - coins[idx]];
                }

                curr[tar] = min(take, notTake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if (ans >= 1e9) return -1;
        return ans;
    }
};

int main() {
    vector<int> c1 = {1, 2, 5};
    vector<int> c2 = {2};
    vector<int> c3 = {1};

    SolutionMemo s1;
    cout << s1.coinChange(c1, 11) << " " << s1.coinChange(c2, 3) << " " << s1.coinChange(c3, 0) << "\n";

    SolutionTabulation s2;
    cout << s2.coinChange(c1, 11) << " " << s2.coinChange(c2, 3) << " " << s2.coinChange(c3, 0) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.coinChange(c1, 11) << " " << s3.coinChange(c2, 3) << " " << s3.coinChange(c3, 0) << "\n";

    return 0;
}