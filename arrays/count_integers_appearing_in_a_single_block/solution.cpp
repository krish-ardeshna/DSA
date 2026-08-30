#include <bits/stdc++.h>
using namespace std;
// Problem: Count Integers Appearing in a Single Block
// Link: https://leetcode.com/problems/count-integers-appearing-in-a-single-block/
// Difficulty: Easy (contest problem)
// Pattern: Array - Block Detection + Bounded Counting
// ------------------------------------------------------------
// Approach: Detect Contiguous Blocks, Count Values Appearing in Exactly One Block
// ------------------------------------------------------------
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> blocks(101, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                blocks[nums[i]]++;
            }
        }
        int ans = 0;

        for (int x = 1; x <= 100; x++) {
            if (blocks[x] == 1) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 1, 2, 2, 1, 3};
    cout << obj.countSpecialIntegers(nums);
    return 0;
}