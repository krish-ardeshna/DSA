#include <bits/stdc++.h>
using namespace std;

// Problem: Removing Minimum and Maximum From Array
// Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Difficulty: Medium
// Pattern: Array - Greedy (Three Removal Strategies)       

// ------------------------------------------------------------
// Approach: Find Min/Max Positions, Compare 3 Removal Strategies
// ------------------------------------------------------------
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn]) mn = i;

            if (nums[i] > nums[mx]) mx = i;
        }

        int left = min(mn, mx);
        int right = max(mn, mx);

        int front = right + 1;
        int back = n - left;
        int both = left + 1 + n - right;

        return min({front, back, both});
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    cout << obj.minimumDeletions(nums);
    return 0;
}