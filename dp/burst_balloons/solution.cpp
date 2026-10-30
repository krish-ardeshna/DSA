#include <bits/stdc++.h>
using namespace std;

// Problem: Burst Balloons
// Link: https://leetcode.com/problems/burst-balloons/
// Difficulty: Hard
// Pattern: DP on Partitions (Interval DP, Choose the LAST Balloon to Burst)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // max coins from balloons i..j, with nums[i - 1] and nums[j + 1] still alive as neighbours
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;

        for (int idx = i; idx <= j; idx++) {
            int cost = nums[i - 1] * nums[idx] * nums[j + 1]
                     + f(i, idx - 1, nums, dp)
                     + f(idx + 1, j, nums, dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(1, n, nums, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (i > j) continue;

                int maxi = INT_MIN;

                for (int idx = i; idx <= j; idx++) {
                    int cost = nums[i - 1] * nums[idx] * nums[j + 1]
                             + dp[i][idx - 1]
                             + dp[idx + 1][j];
                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};

int main() {
    vector<int> a1 = {3, 1, 5, 8};
    vector<int> a2 = {1, 5};

    // maxCoins changes nums, so pass a fresh copy each time
    SolutionMemo s1;
    vector<int> t1 = a1, t2 = a2;
    cout << s1.maxCoins(t1) << " " << s1.maxCoins(t2) << "\n";

    SolutionTabulation s2;
    vector<int> t3 = a1, t4 = a2;
    cout << s2.maxCoins(t3) << " " << s2.maxCoins(t4) << "\n";

    return 0;
}