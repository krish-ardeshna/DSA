#include <bits/stdc++.h>
using namespace std;

// Problem: Partition Equal Subset Sum
// Link: https://leetcode.com/problems/partition-equal-subset-sum/
// Difficulty: Medium
// Pattern: DP on Subsequences (Subset Sum / 0-1 Knapsack Style)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return arr[0] == target;

        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTake = f(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, nums, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int tar = 1; tar <= target; tar++) {
                bool notTake = dp[ind - 1][tar];
                bool take = false;

                if (nums[ind] <= tar)
                    take = dp[ind - 1][tar - nums[ind]];

                dp[ind][tar] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);

        prev[0] = curr[0] = true;

        if (arr[0] <= target)
            prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            curr[0] = true;

            for (int tar = 1; tar <= target; tar++) {
                bool notTake = prev[tar];
                bool take = false;

                if (arr[ind] <= tar)
                    take = prev[tar - arr[ind]];

                curr[tar] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;

        return isSubsetSum(nums, target);
    }
};

int main() {
    vector<int> nums1 = {1, 5, 11, 5};
    vector<int> nums2 = {1, 2, 3, 5};

    SolutionMemo s1;
    cout << s1.canPartition(nums1) << " " << s1.canPartition(nums2) << "\n";

    SolutionTabulation s2;
    cout << s2.canPartition(nums1) << " " << s2.canPartition(nums2) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.canPartition(nums1) << " " << s3.canPartition(nums2) << "\n";

    return 0;
}