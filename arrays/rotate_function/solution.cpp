#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate Function
// Link: https://leetcode.com/problems/rotate-function/
// Difficulty: Medium
// Pattern: Array / Mathematical Observation

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long F = 0;

        // Calculate total sum and initial rotation value
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += 1LL * i * nums[i];
        }

        long long maxx = F;

        // Use recurrence relation to compute next rotations
        for (int k = 1; k < n; k++) {
            F = F + sum - 1LL * n * nums[n - k];
            maxx = max(maxx, F);
        }

        return maxx;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 6};

    Solution s;
    cout << s.maxRotateFunction(nums) << "\n";

    return 0;
}