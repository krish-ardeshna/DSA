#include <bits/stdc++.h>
using namespace std;

// Problem: Find Minimum in Rotated Sorted Array
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Difficulty: Medium
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
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution s;

    cout << s.findMin(nums) << "\n";

    return 0;
}