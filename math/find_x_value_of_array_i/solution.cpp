#include <bits/stdc++.h>
using namespace std;

// Problem: Find X Value of Array I
// Link: https://leetcode.com/problems/find-x-value-of-array-i/
// Difficulty: Medium
// Pattern: DP (Running Product Modulo Distribution)

// ------------------------------------------------------------
// Approach: Track Count of Subarray Products by Remainder, Roll Forward
// ------------------------------------------------------------
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newdp(k, 0);

            int rem = num % k;
            newdp[rem]++;

            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRem = (r * rem) % k;
                    newdp[newRem] += dp[r];
                }
            }

            for (int r = 0; r < k; r++) {
                ans[r] += newdp[r];
            }

            dp = newdp;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    vector<long long> result = obj.resultArray(nums, k);

    for (long long v : result) {
        cout << v << " ";
    }

    return 0;
}