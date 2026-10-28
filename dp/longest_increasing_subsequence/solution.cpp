#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Increasing Subsequence
// Link: https://leetcode.com/problems/longest-increasing-subsequence/
// Difficulty: Medium
// Pattern: DP on Subsequences (Take / Not Take with Previous Index), Binary Search Shortcut

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int prev_idx, vector<int>& nums, int n,
          vector<vector<int>>& dp) {
        if (idx == n) return 0;

        if (dp[idx][prev_idx + 1] != -1)
            return dp[idx][prev_idx + 1];

        int len = f(idx + 1, prev_idx, nums, n, dp);

        if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            len = max(len, 1 + f(idx + 1, idx, nums, n, dp));
        }

        return dp[idx][prev_idx + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, nums, n, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--) {
                int len = 0 + dp[idx + 1][prev_idx + 1];
                if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
                    len = max(len, 1 + dp[idx + 1][idx + 1]);
                }
                dp[idx][prev_idx + 1] = len;
            }
        }
        return dp[0][0];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--) {
                int len = 0 + next[prev_idx + 1];
                if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
                    len = max(len, 1 + next[idx + 1]);
                }
                curr[prev_idx + 1] = len;
            }
            next = curr;
        }
        return next[0];
    }
};

// ------------------------------------------------------------
// Approach 4: 1D DP (Longest Subsequence Ending at Each Index)
// ------------------------------------------------------------
class Solution1DDP {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

// ------------------------------------------------------------
// Approach 5: Binary Search (Patience Sorting, O(n log n))
// ------------------------------------------------------------
class SolutionBinarySearch {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp;
        temp.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return temp.size();
    }
};

int main() {
    vector<int> a1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> a2 = {0, 1, 0, 3, 2, 3};
    vector<int> a3 = {7, 7, 7, 7, 7, 7, 7};

    SolutionMemo s1;
    cout << s1.lengthOfLIS(a1) << " " << s1.lengthOfLIS(a2) << " " << s1.lengthOfLIS(a3) << "\n";

    SolutionTabulation s2;
    cout << s2.lengthOfLIS(a1) << " " << s2.lengthOfLIS(a2) << " " << s2.lengthOfLIS(a3) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.lengthOfLIS(a1) << " " << s3.lengthOfLIS(a2) << " " << s3.lengthOfLIS(a3) << "\n";

    Solution1DDP s4;
    cout << s4.lengthOfLIS(a1) << " " << s4.lengthOfLIS(a2) << " " << s4.lengthOfLIS(a3) << "\n";

    SolutionBinarySearch s5;
    cout << s5.lengthOfLIS(a1) << " " << s5.lengthOfLIS(a2) << " " << s5.lengthOfLIS(a3) << "\n";

    return 0;
}