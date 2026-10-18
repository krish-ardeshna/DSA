#include <bits/stdc++.h>
using namespace std;

// Problem: Count Partitions with Given Difference
// Link: <paste TakeUForward link here>
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

    int findways(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return f(n - 1, tar, nums, dp);
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = 0;
        for (int x : arr)
            totalSum += x;

        if (totalSum - diff < 0 || (totalSum - diff) % 2 != 0)
            return 0;

        int target = (totalSum - diff) / 2;
        return findways(arr, target);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int findways(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        // Base case: first element
        dp[0][0] = (nums[0] == 0) ? 2 : 1;

        if (nums[0] != 0 && nums[0] <= tar)
            dp[0][nums[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= tar; sum++) {
                int notTake = dp[ind - 1][sum];
                int take = 0;

                if (nums[ind] <= sum)
                    take = dp[ind - 1][sum - nums[ind]];

                dp[ind][sum] = (notTake + take) % MOD;
            }
        }

        return dp[n - 1][tar];
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = 0;
        for (int x : arr)
            totalSum += x;

        if (totalSum - diff < 0 || (totalSum - diff) % 2 != 0)
            return 0;

        int target = (totalSum - diff) / 2;
        return findways(arr, target);
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int findways(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

        // Base case: first element
        if (nums[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (nums[0] != 0 && nums[0] <= tar)
            prev[nums[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            curr[0] = (nums[ind] == 0 ? 2LL * prev[0] % MOD : prev[0]);

            for (int sum = 1; sum <= tar; sum++) {
                int notTake = prev[sum];
                int take = 0;

                if (nums[ind] <= sum)
                    take = prev[sum - nums[ind]];

                curr[sum] = (notTake + take) % MOD;
            }

            prev = curr;
        }

        return prev[tar];
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = 0;
        for (int x : arr)
            totalSum += x;

        if (totalSum - diff < 0 || (totalSum - diff) % 2 != 0)
            return 0;

        int target = (totalSum - diff) / 2;
        return findways(arr, target);
    }
};

int main() {
    vector<int> a1 = {5, 2, 6, 4};
    vector<int> a2 = {1, 1, 1, 1};
    vector<int> a3 = {0, 0, 1};

    SolutionMemo s1;
    cout << s1.countPartitions(4, 3, a1) << " "
         << s1.countPartitions(4, 0, a2) << " "
         << s1.countPartitions(3, 1, a3) << "\n";

    SolutionTabulation s2;
    cout << s2.countPartitions(4, 3, a1) << " "
         << s2.countPartitions(4, 0, a2) << " "
         << s2.countPartitions(3, 1, a3) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.countPartitions(4, 3, a1) << " "
         << s3.countPartitions(4, 0, a2) << " "
         << s3.countPartitions(3, 1, a3) << "\n";

    return 0;
}