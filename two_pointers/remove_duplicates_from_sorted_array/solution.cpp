#include <bits/stdc++.h>
using namespace std;

// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy
// Pattern: Two Pointers

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    vector<int> nums = {1,1,2,2,3,4,4};
    Solution s;

    int k = s.removeDuplicates(nums);
    cout << "Unique count: " << k << "\n";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}