#include <bits/stdc++.h>
using namespace std;

// Problem: Smallest Index With Digit Sum Equal to Index
// Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
// Difficulty: Easy
// Pattern: Math - Digit Extraction

// ------------------------------------------------------------
// Approach: Linear Scan, Check Digit Sum Against Index
// ------------------------------------------------------------
class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (digitSum(nums[i]) == i) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 3, 2};
    cout << obj.smallestIndex(nums);
    return 0;
}