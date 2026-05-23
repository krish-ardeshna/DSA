#include <bits/stdc++.h>
using namespace std;

// Problem: Check if Array Is Sorted and Rotated
// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Difficulty: Easy
// Pattern: Arrays

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            // Count places where order breaks
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
};

int main() {
    vector<int> nums = {3,4,5,1,2};
    Solution s;

    cout << s.check(nums) << "\n";

    return 0;
}