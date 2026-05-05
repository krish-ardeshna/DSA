#include <bits/stdc++.h>
using namespace std;

// Problem: Two Sum
// Platform: LeetCode
// Pattern: Hashing

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (auto it = mp.find(diff); it != mp.end()) {
                return {it->second, i};
            }

            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 13, 15};
    int target = 9;

    auto res = s.twoSum(nums, target);

    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}