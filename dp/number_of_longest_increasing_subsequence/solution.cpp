#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Longest Increasing Subsequence
// Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// Difficulty: Medium
// Pattern: DP on Subsequences (LIS with Count Array)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // returns {length of longest increasing subsequence ENDING at i,
    //          number of such subsequences}
    pair<int, int> f(int i, vector<int>& nums, vector<pair<int, int>>& dp) {
        if (dp[i].first != -1) return dp[i];

        int len = 1, cnt = 1;

        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] < nums[i]) {
                pair<int, int> p = f(prev, nums, dp);

                if (1 + p.first > len) {
                    len = 1 + p.first;
                    cnt = p.second;
                }
                else if (1 + p.first == len) {
                    cnt += p.second;
                }
            }
        }

        return dp[i] = {len, cnt};
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {-1, -1});

        int maxi = 1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, f(i, nums, dp).first);
        }

        int nos = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i].first == maxi) nos += dp[i].second;
        }
        return nos;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int nos = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) nos += cnt[i];
        }
        return nos;
    }
};

int main() {
    vector<int> a1 = {1, 3, 5, 4, 7};
    vector<int> a2 = {2, 2, 2, 2, 2};
    vector<int> a3 = {1, 2, 4, 3, 5, 4, 7, 2};

    SolutionMemo s1;
    cout << s1.findNumberOfLIS(a1) << " " << s1.findNumberOfLIS(a2) << " " << s1.findNumberOfLIS(a3) << "\n";

    SolutionTabulation s2;
    cout << s2.findNumberOfLIS(a1) << " " << s2.findNumberOfLIS(a2) << " " << s2.findNumberOfLIS(a3) << "\n";

    return 0;
}