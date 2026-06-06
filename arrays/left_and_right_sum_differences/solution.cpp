#include <bits/stdc++.h>
using namespace std;

// Problem: Left and Right Sum Differences
// Link: https://leetcode.com/problems/left-and-right-sum-differences/
// Difficulty: Easy
// Pattern: Arrays / Prefix Sum

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------

class SolutionBrute {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum;
        vector<int> rightSum;

        for (int i = 0; i < nums.size(); i++) {

            int sum_left = 0;
            for (int j = 0; j < i; j++) {
                sum_left += nums[j];
            }

            leftSum.push_back(sum_left);

            int sum_right = 0;
            for (int j = nums.size() - 1; j > i; j--) {
                sum_right += nums[j];
            }
            
            rightSum.push_back(sum_right);
        }

        vector<int> res;

        for (int i = 0; i < leftSum.size(); i++) {
            res.push_back(abs(leftSum[i] - rightSum[i]));
        }

        return res;
    }
};

// ------------------------------------------------------------
// Approach 2: Running Left Sum and Right Sum
// ------------------------------------------------------------

class SolutionOptimal {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightSum = 0;

        for (int num : nums) {
            rightSum += num;
        }

        int leftSum = 0;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {

            rightSum -= nums[i];
            res.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];

        }
        return res;
    }
};

int main() {
    vector<int> nums = {10, 4, 8, 3};
    SolutionOptimal s;

    vector<int> ans = s.leftRightDifference(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}