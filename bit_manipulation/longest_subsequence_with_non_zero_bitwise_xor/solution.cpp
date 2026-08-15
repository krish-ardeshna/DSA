#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Subsequence With Non-Zero Bitwise XOR
// Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
// Difficulty: Medium
// Pattern: Bit Manipulation (XOR Properties)

// ------------------------------------------------------------
// Approach: Total XOR Check + Non-Zero Element Check
// ------------------------------------------------------------
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;

        bool hasNonZero = false;

        for (int num : nums) {
            xorr ^= num;

            if (num != 0) {
                hasNonZero = true;
            }
        }

        if (xorr != 0) {
            return n;
        }

        if (hasNonZero) {
            return n - 1;
        }

        return 0;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};
    cout << obj.longestSubsequence(nums);
    return 0;
}