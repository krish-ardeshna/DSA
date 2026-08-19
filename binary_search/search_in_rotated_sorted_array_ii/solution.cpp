#include <bits/stdc++.h>
using namespace std;

// Problem: Search in Rotated Sorted Array II
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Difficulty: Medium
// Pattern: Binary Search (Modified for Rotated + Duplicates)

// ------------------------------------------------------------
// Approach: Modified Binary Search with Duplicate Shrink
// ------------------------------------------------------------
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    cout << obj.search(nums, 0);
    return 0;
}