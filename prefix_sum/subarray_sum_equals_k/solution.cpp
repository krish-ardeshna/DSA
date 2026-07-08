#include <bits/stdc++.h>
using namespace std;

// Problem: Subarray Sum Equals K
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Medium
// Pattern: Prefix Sum / Hash Map

// ------------------------------------------------------------
// Approach: Prefix Sum with Hash Map
// ------------------------------------------------------------

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int x : nums) {
            sum += x;

            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }
        return count;
    }
};

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution s;
    cout << s.subarraySum(nums, k) << "\n";

    return 0;
}