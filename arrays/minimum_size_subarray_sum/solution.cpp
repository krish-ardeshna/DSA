#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Size Subarray Sum
// Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Difficulty: Medium
// Pattern: Sliding Window

// ------------------------------------------------------------
// Approach: Sliding Window
// ------------------------------------------------------------

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int right = 0; right < n; right++) {
            sum += nums[right];

            while(sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    Solution s;
    cout << s.minSubArrayLen(target, nums) << "\n";

    return 0;
}