#include <bits/stdc++.h>
using namespace std;

// Problem: Find Pivot Index
// Link: https://leetcode.com/problems/find-pivot-index/
// Difficulty: Easy
// Pattern: Prefix Sum

// ------------------------------------------------------------
// Approach: Prefix Sum
// ------------------------------------------------------------

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }
        
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    Solution s;
    cout << s.pivotIndex(nums) << "\n";

    return 0;
}