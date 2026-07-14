#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty: Medium
// Pattern: Hash Set

// ------------------------------------------------------------
// Approach: Hash Set
// ------------------------------------------------------------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (!st.count(num - 1)) {

                int curr = num;
                int len = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution s;

    cout << s.longestConsecutive(nums) << "\n";
    return 0;
}