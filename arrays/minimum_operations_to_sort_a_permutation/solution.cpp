#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Operations to Sort a Permutation
// Link: https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Cyclic Rotation Check Around the Position of 0

// ------------------------------------------------------------
// Approach: Check If Array Is a Rotation of Sorted (Forward or Backward) From 0,
//           Then Pick the Cheapest Cost Based on the Index of 0
// ------------------------------------------------------------
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto check = [&](int step) {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[prev] > nums[curr])
                    return false;
            }
            return true;
        };

        int ans = INT_MAX;

        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {0, 1, 2, 3};
    cout << obj.minOperations(nums1) << "\n";

    vector<int> nums2 = {3, 2, 1, 0};
    cout << obj.minOperations(nums2) << "\n";

    vector<int> nums3 = {0, 2, 1, 3};
    cout << obj.minOperations(nums3) << "\n";

    return 0;
}