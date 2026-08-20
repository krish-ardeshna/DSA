#include <bits/stdc++.h>
using namespace std;

// Problem: Distribute Elements Into Two Arrays I
// Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
// Difficulty: Easy
// Pattern: Array - Greedy Simulation

// ------------------------------------------------------------
// Approach: Greedy Last-Element Comparison
// ------------------------------------------------------------
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        for (int x : arr2) {
            arr1.push_back(x);
        }

        return arr1;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 1, 3, 4, 5};
    vector<int> result = obj.resultArray(nums);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}