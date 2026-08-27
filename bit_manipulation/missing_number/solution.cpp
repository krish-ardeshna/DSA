#include <bits/stdc++.h>
using namespace std;

// Problem: Missing Number
// Link: https://leetcode.com/problems/missing-number/
// Difficulty: Easy
// Pattern: Bit Manipulation (XOR)

// ------------------------------------------------------------
// Approach: XOR All Indices, Values, and n Together
// ------------------------------------------------------------
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3, 0, 1};
    cout << obj.missingNumber(nums);
    return 0;
}