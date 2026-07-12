#include <bits/stdc++.h>
using namespace std;

// Problem: Jump Game
// Link: https://leetcode.com/problems/jump-game/
// Difficulty: Medium
// Pattern: Greedy

// ------------------------------------------------------------
// Approach: Greedy
// ------------------------------------------------------------

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }
        return true;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution s;

    cout << boolalpha << s.canJump(nums) << "\n";
    return 0;
}