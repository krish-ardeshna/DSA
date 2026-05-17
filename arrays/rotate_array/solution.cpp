#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate Array
// Link: https://leetcode.com/problems/rotate-array/
// Difficulty: Medium
// Pattern: Arrays / Reversal Technique

// ------------------------------------------------------------
// Approach 1: Reverse Parts First
// ------------------------------------------------------------

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        // Reverse first part
        reverse(nums.begin(), nums.end() - k);

        // Reverse second part
        reverse(nums.end() - k, nums.end());

        // Reverse entire array
        reverse(nums.begin(), nums.end());
    }
};

// ------------------------------------------------------------
// Approach 2: Reverse Whole Array First
// ------------------------------------------------------------

class SolutionAlternative {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;

        // Reverse complete array
        reverse(nums.begin(), nums.end());

        // Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution s;

    s.rotate(nums, k);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}