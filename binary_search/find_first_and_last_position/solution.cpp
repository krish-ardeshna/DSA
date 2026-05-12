#include <bits/stdc++.h>
using namespace std;

// Problem: Find First and Last Position of Element in Sorted Array
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Difficulty: Medium
// Pattern: Binary Search

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------

class SolutionBruteForce {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                temp.push_back(i);
            }
        }
        if (temp.empty()) {
            return {-1, -1};
        }
        return {temp.front(), temp.back()};
    }
};

// ------------------------------------------------------------
// Approach 2: Binary Search (Optimal)
// ------------------------------------------------------------

class SolutionOptimal {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;

        int low = 0;
        int high = nums.size() - 1;

        // Find first occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if (nums[mid] == target) {
                first = mid;
            }
        }

        low = 0;
        high = nums.size() - 1;

        // Find last occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            if (nums[mid] == target) {
                last = mid;
            }
        }
        return {first, last};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    SolutionOptimal s;

    vector<int> res = s.searchRange(nums, target);
    cout << res[0] << " " << res[1] << "\n";

    return 0;
}