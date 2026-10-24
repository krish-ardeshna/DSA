#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum K to Sort a Permutation
// Link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
// Difficulty: Medium
// Pattern: Bit Manipulation (AND of All Misplaced Values)

// ------------------------------------------------------------
// Approach: AND Together Every Value That Is Not at Its Own Index
// ------------------------------------------------------------
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }

        return max(ans, 0);
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {0, 3, 2, 1};
    cout << obj.sortPermutation(nums1) << "\n";

    vector<int> nums2 = {0, 1, 3, 2};
    cout << obj.sortPermutation(nums2) << "\n";

    vector<int> nums3 = {2, 1, 0};
    cout << obj.sortPermutation(nums3) << "\n";

    return 0;
}