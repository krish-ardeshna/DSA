#include <bits/stdc++.h>
using namespace std;

// Problem: Search in Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Difficulty: Medium
// Pattern: Binary Search

// ------------------------------------------------------------
// Approach 1: Linear Search (Brute Force)
// ------------------------------------------------------------

class SolutionBrute {
public:
    int search(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

// ------------------------------------------------------------
// Approach 2: Modified Binary Search
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    SolutionOptimal s;

    cout << s.search(nums, target) << "\n";

    return 0;
}