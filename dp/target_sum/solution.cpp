#include <bits/stdc++.h>
using namespace std;

// Problem: Target Sum
// Link: https://leetcode.com/problems/target-sum/
// Difficulty: Medium
// Pattern: DP on Subsequences (Count Subsets with Sum K, Zeros Handled)

const int MOD = 1e9 + 7;

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (sum == 0 && nums[0] == 0) return 2;
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int notTake = f(ind - 1, sum, nums, dp);

        int take = 0;
        if (nums[ind] <= sum)
            take = f(ind - 1, sum - nums[ind], nums, dp);

        return dp[ind][sum] = (notTake + take) % MOD;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        if (abs(target) > totalSum)
            return 0;

        int sum = totalSum + target;

        if (sum % 2 != 0)
            return 0;

        int tar = sum / 2;

        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return f(n - 1, tar, nums, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        if (abs(target) > totalSum)
            return 0;

        int sum = totalSum + target;

        if (sum % 2 != 0)
            return 0;

        int tar = sum / 2;

        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        // Base row: first element
        dp[0][0] = (nums[0] == 0) ? 2 : 1;

        if (nums[0] != 0 && nums[0] <= tar)
            dp[0][nums[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int s = 0; s <= tar; s++) {
                int notTake = dp[ind - 1][s];
                int take = 0;

                if (nums[ind] <= s)
                    take = dp[ind - 1][s - nums[ind]];

                dp[ind][s] = (notTake + take) % MOD;
            }
        }

        return dp[n - 1][tar];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Single Row, Reverse Loop)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        if (abs(target) > totalSum)
            return 0;

        int sum = totalSum + target;

        if (sum % 2 != 0)
            return 0;

        int tar = sum / 2;

        vector<int> dp(tar + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int s = tar; s >= num; s--) {
                dp[s] = (dp[s] + dp[s - num]) % MOD;
            }
        }

        return dp[tar];
    }
};

int main() {
    vector<int> a1 = {1, 1, 1, 1, 1};
    vector<int> a2 = {1};
    vector<int> a3 = {0, 0, 0, 0, 0, 0, 0, 0, 1};

    SolutionMemo s1;
    cout << s1.findTargetSumWays(a1, 3) << " "
         << s1.findTargetSumWays(a2, 1) << " "
         << s1.findTargetSumWays(a3, 1) << "\n";

    SolutionTabulation s2;
    cout << s2.findTargetSumWays(a1, 3) << " "
         << s2.findTargetSumWays(a2, 1) << " "
         << s2.findTargetSumWays(a3, 1) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.findTargetSumWays(a1, 3) << " "
         << s3.findTargetSumWays(a2, 1) << " "
         << s3.findTargetSumWays(a3, 1) << "\n";

    return 0;
}