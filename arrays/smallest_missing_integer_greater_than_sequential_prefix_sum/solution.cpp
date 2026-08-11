#include <bits/stdc++.h>
using namespace std;

// Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
// Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
// Difficulty: Easy
// Pattern: Array - Prefix Sum + Hash Set

// ------------------------------------------------------------
// Approach: Sequential Prefix Sum + Set Lookup
// ------------------------------------------------------------
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(sum)) {
            sum++;
        }
        return sum;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 2, 5};
    cout << obj.missingInteger(nums);
    return 0;
}