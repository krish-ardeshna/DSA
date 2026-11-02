#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Moves to Equal Array Elements II
// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Difficulty: Medium
// Pattern: Math + Sorting (Median Minimizes the Sum of Absolute Differences)

// ------------------------------------------------------------
// Approach: Sort + Median
// ------------------------------------------------------------
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        long long ans = 0;

        for (int x : nums)
            ans += abs((long long)x - median);

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> a1 = {1, 2, 3};
    vector<int> a2 = {1, 10, 2, 9};
    vector<int> a3 = {7};

    cout << s.minMoves2(a1) << " " << s.minMoves2(a2) << " " << s.minMoves2(a3) << "\n";

    return 0;
}