#include <bits/stdc++.h>
using namespace std;

// Problem: Running Sum of 1d Array
// Link: https://leetcode.com/problems/running-sum-of-1d-array/
// Difficulty: Easy
// Pattern: Prefix Sum

// ------------------------------------------------------------
// Approach 1: Extra Prefix Sum Array
// ------------------------------------------------------------

class SolutionExtraArray {
public:
    vector<int> runningSum(vector<int>& nums) {

        int n = nums.size();
        int prefixSum = 0;

        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            res[i] = prefixSum;
        }

        return res;
    }
};

// ------------------------------------------------------------
// Approach 2: In-place Prefix Sum
// ------------------------------------------------------------

class SolutionOptimal {
public:
    vector<int> runningSum(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    SolutionOptimal s;
    vector<int> ans = s.runningSum(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}