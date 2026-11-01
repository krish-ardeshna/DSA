#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Moves to Equal Array Elements
// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Difficulty: Medium
// Pattern: Math (Reverse the Move: Decrease One Element Instead of Increasing n - 1)

// ------------------------------------------------------------
// Approach: Math (Sum of Distances to the Minimum)
// ------------------------------------------------------------
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        long long ans = 0;

        for (int x : nums) {
            ans += x - mn;
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> a1 = {1, 2, 3};
    vector<int> a2 = {1, 1, 1};
    vector<int> a3 = {5, 1, 1};

    cout << s.minMoves(a1) << " " << s.minMoves(a2) << " " << s.minMoves(a3) << "\n";

    return 0;
}