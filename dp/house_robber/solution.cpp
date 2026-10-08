#include <bits/stdc++.h>
using namespace std;

// Problem: House Robber
// Link: https://leetcode.com/problems/house-robber/
// Difficulty: Medium
// Pattern: DP (Take / Not Take, Rolling Variables)

// ------------------------------------------------------------
// Approach: Space-Optimized DP With Two Rolling Values
// ------------------------------------------------------------
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int take = nums[i];

            if (i > 1)
                take += prev2;

            int notTake = prev1;

            int curi = max(take, notTake);

            prev2 = prev1;
            prev1 = curi;
        }

        return prev1;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << obj.rob(nums);
    return 0;
}