#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Common Value
// Link: https://leetcode.com/problems/minimum-common-value/
// Difficulty: Easy
// Pattern: Two Pointers

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size()) {

            // Common value found
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }

            // Move smaller value pointer
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            
            else {
                j++;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4};
    Solution s;

    cout << s.getCommon(nums1, nums2) << "\n";

    return 0;
}