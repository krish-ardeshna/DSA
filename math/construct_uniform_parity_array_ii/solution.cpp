#include <bits/stdc++.h>
using namespace std;

// Problem: Construct Uniform Parity Array II
// Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Math - Parity + Threshold Check

// ------------------------------------------------------------
// Approach: Find Min Odd, Check No Even is Smaller
// ------------------------------------------------------------
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            }
        }

        if (minOdd == INT_MAX) {
            return true;
        }

        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;
    vector<int> nums1 = {2, 3, 4};
    cout << obj.uniformArray(nums1);
    return 0;
}