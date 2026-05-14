#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Product Subarray
// Link: https://leetcode.com/problems/maximum-product-subarray/
// Difficulty: Medium
// Pattern: Arrays / Kadane Variation

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // Negative value can flip max and min
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);
            
            ans = max(ans, currMax);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution s;

    cout << s.maxProduct(nums) << "\n";

    return 0;
}