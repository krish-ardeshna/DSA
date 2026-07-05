#include <bits/stdc++.h>
using namespace std;

// Problem: Binary Search
// Link: https://leetcode.com/problems/binary-search/
// Difficulty: Easy
// Pattern: Binary Search

// ------------------------------------------------------------
// Approach: Iterative Binary Search
// ------------------------------------------------------------

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            // int mid = (low + high) / 2; 
            int mid = low + (high - low) / 2;

            if (target < nums[mid]) {
                high = mid - 1;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    Solution s;
    cout << s.search(nums, target) << "\n";

    return 0;
}