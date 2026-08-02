#include <bits/stdc++.h>
using namespace std;

// Problem: Maximize Pair Strength Using GCD
// Link: https://leetcode.com/problems/maximize-pair-strength-using-gcd/
// Difficulty: Easy
// Pattern: Math, Brute Force

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long maxStrength = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long product = 1LL * nums[i] * nums[j];
                long long g = gcd(nums[i], nums[j]);

                maxStrength = max(maxStrength, product / (g * g));
            }
        }

        return maxStrength;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {6, 10, 15};

    cout << obj.maxPairStrength(nums);

    return 0;
}