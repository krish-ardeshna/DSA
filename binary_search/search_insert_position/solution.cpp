#include <bits/stdc++.h>
using namespace std;

// Problem: Search Insert Position
// Link: https://leetcode.com/problems/search-insert-position/
// Difficulty: Easy
// Pattern: Binary Search

// ------------------------------------------------------------
// Approach 1: Linear Search
// ------------------------------------------------------------

class SolutionLinear {
public:
    int searchInsert(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return nums.size();
    }
};

// ------------------------------------------------------------
// Approach 2: Binary Search
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    SolutionOptimal s;

    cout << s.searchInsert(nums, target) << "\n";
    return 0;
}