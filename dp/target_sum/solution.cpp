#include <bits/stdc++.h>
using namespace std;

// Problem: Target Sum
// Link: https://leetcode.com/problems/target-sum/
// Difficulty: Medium
// Pattern: Dynamic Programming / Subset Sum

// ------------------------------------------------------------
// Approach: DP using Subset Sum Transformation
// ------------------------------------------------------------

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        if (abs(target) > totalSum) {
            return 0;
        }
        if ((target + totalSum) % 2 != 0) {
            return 0;
        }

        int reqSum = (target + totalSum) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(reqSum + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= reqSum; j++) {

                dp[i][j] = dp[i - 1][j];

                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][reqSum];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution s;
    cout << s.findTargetSumWays(nums, target) << "\n";

    return 0;
}