#include <bits/stdc++.h>
using namespace std;

// Problem: Find Minimum in Rotated Sorted Array II
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Difficulty: Hard
// Pattern: Binary Search

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Minimum lies in right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }

            // Minimum lies in left half (including mid)
            else if (nums[mid] < nums[high]) {
                high = mid;
            }

            // Duplicate case
            else {
                high--;
            }
        }
        return nums[low];
    }
};

int main() {
    vector<int> nums = {2, 2, 2, 0, 1};
    Solution s;

    cout << s.findMin(nums) << "\n";

    return 0;
}