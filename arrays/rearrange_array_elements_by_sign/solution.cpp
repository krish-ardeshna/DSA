#include <bits/stdc++.h>
using namespace std;

// Problem: Rearrange Array Elements by Sign
// Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Difficulty: Medium
// Pattern: Array - Two Pointer (Index Placement)

// ------------------------------------------------------------
// Approach: Separate Even/Odd Index Placement
// ------------------------------------------------------------
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            } else {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = obj.rearrangeArray(nums);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}