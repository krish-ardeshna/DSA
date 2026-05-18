#include <bits/stdc++.h>
using namespace std;

// Problem: Find Peak Element
// Link: https://leetcode.com/problems/find-peak-element/
// Difficulty: Medium
// Pattern: Binary Search

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Peak lies on right side
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }

            // Peak lies on left side (including mid)
            else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution s;

    cout << s.findPeakElement(nums) << "\n";
    return 0;
}