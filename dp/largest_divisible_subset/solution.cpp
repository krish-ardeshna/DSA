#include <bits/stdc++.h>
using namespace std;

// Problem: Largest Divisible Subset
// Link: https://leetcode.com/problems/largest-divisible-subset/
// Difficulty: Medium
// Pattern: DP on Subsequences (LIS Variant, Divisibility Instead of Greater-Than)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down), Then Rebuild
// ------------------------------------------------------------
class SolutionMemo {
public:
    // longest divisible chain that ENDS exactly at index i (nums must be sorted)
    int f(int i, vector<int>& nums, vector<int>& dp, vector<int>& hash) {
        if (dp[i] != -1) return dp[i];

        int best = 1;
        hash[i] = i;

        for (int prev = 0; prev < i; prev++) {
            if (nums[i] % nums[prev] == 0) {
                int len = 1 + f(prev, nums, dp, hash);
                if (len > best) {
                    best = len;
                    hash[i] = prev;
                }
            }
        }

        return dp[i] = best;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, -1), hash(n);
        int maxi = 0;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            f(i, nums, dp, hash);
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up) with Parent Tracking
// ------------------------------------------------------------
class SolutionTabulation {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int lastIndex = 0;

        vector<int> dp(n, 1), hash(n);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

int main() {
    vector<int> a1 = {1, 2, 3};
    vector<int> a2 = {1, 2, 4, 8};

    SolutionMemo s1;
    for (int v : s1.largestDivisibleSubset(a1)) cout << v << " ";
    cout << "\n";
    for (int v : s1.largestDivisibleSubset(a2)) cout << v << " ";
    cout << "\n";

    SolutionTabulation s2;
    for (int v : s2.largestDivisibleSubset(a1)) cout << v << " ";
    cout << "\n";
    for (int v : s2.largestDivisibleSubset(a2)) cout << v << " ";
    cout << "\n";

    return 0;
}