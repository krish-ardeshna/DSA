#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Total Subarray Value I
// Link: Contest Problem
// Difficulty: Easy
// Pattern: Arrays / Greedy

// ------------------------------------------------------------
// Approach: Find Minimum and Maximum Element
// ------------------------------------------------------------

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int maxVal = nums[0];
        int minVal = nums[0];

        for (int num : nums) {
            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
        }

        long long singleSubarrayValue = maxVal - minVal;

        return singleSubarrayValue * k;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 2};
    int k = 2;

    Solution s;

    cout << s.maxTotalValue(nums, k) << "\n";

    return 0;
}