#include <bits/stdc++.h>
using namespace std;

// Problem: Max Consecutive Ones
// Link: https://leetcode.com/problems/max-consecutive-ones/
// Difficulty: Easy
// Pattern: Array - Linear Scan (Running Counter)

// ------------------------------------------------------------
// Approach: Single Pass Counter Reset
// ------------------------------------------------------------
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxConsecutive = 0;

        for (int num : nums) {
            if (num == 1) {
                cnt++;
                maxConsecutive = max(maxConsecutive, cnt);
            }
            else {
                cnt = 0;
            }
        }
        return maxConsecutive;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << obj.findMaxConsecutiveOnes(nums);
    return 0;
}