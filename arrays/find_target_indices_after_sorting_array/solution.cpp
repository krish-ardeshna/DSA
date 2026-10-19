#include <bits/stdc++.h>
using namespace std;

// Problem: Find Target Indices After Sorting Array
// Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Difficulty: Easy
// Pattern: Sorting + Linear Scan

// ------------------------------------------------------------
// Approach: Sort the Array, Collect Indices Where Value Equals Target
// ------------------------------------------------------------
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 5, 2, 3};
    vector<int> r1 = obj.targetIndices(nums1, 2);
    for (int v : r1) cout << v << " ";
    cout << "\n";

    vector<int> nums2 = {1, 2, 5, 2, 3};
    vector<int> r2 = obj.targetIndices(nums2, 3);
    for (int v : r2) cout << v << " ";
    cout << "\n";

    vector<int> nums3 = {1, 2, 5, 2, 3};
    vector<int> r3 = obj.targetIndices(nums3, 4);
    cout << r3.size() << "\n";

    return 0;
}