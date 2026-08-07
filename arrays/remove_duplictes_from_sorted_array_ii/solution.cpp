#include <bits/stdc++.h>
using namespace std;

// Problem: Remove Duplicates from Sorted Array II
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Difficulty: Medium
// Pattern: Two Pointers

// ------------------------------------------------------------
// Approach: Two Pointers
// ------------------------------------------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int k = 2;

        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};

    Solution s;
    int k = s.removeDuplicates(nums);

    cout << k << "\n";

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}