#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/
// Difficulty: Medium
// Pattern: Dynamic Programming / Kadane's Algorithm

// ------------------------------------------------------------
// Approach: Kadane's Algorithm
// ------------------------------------------------------------

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSoFar = nums[0];
        int currSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSoFar = max(maxSoFar, currSum);
        }

        return maxSoFar;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;

    cout << s.maxSubArray(nums) << "\n";
    return 0;
}