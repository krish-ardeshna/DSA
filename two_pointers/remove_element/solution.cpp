#include <bits/stdc++.h>
using namespace std;

// Problem: Remove Element
// Link: https://leetcode.com/problems/remove-element/
// Difficulty: Easy
// Pattern: Two Pointers

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;

    Solution s;

    int k = s.removeElement(nums, val);

    cout << "New Length: " << k << "\n";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}