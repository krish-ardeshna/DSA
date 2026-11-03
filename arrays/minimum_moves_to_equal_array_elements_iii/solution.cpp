#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Moves to Equal Array Elements III
// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Math (Raise Every Element to the Maximum)

// ------------------------------------------------------------
// Approach: Math (Sum of Distances to the Maximum)
// ------------------------------------------------------------
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;

        for (int x : nums) {
            ans += mx - x;
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> a1 = {2, 1, 3};
    vector<int> a2 = {4, 4, 5};
    vector<int> a3 = {7, 7, 7};

    cout << s.minMoves(a1) << " " << s.minMoves(a2) << " " << s.minMoves(a3) << "\n";

    return 0;
}