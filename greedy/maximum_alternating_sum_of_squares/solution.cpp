#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Alternating Sum of Squares
// Link: https://leetcode.com/problems/maximum-alternating-sum-of-squares/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Greedy + Sorting

// ------------------------------------------------------------
// Approach: Sort Squares, Subtract the Smallest n/2, Add the Rest
// ------------------------------------------------------------
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares;

        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                ans -= squares[i];
            else
                ans += squares[i];
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 3};
    cout << obj.maxAlternatingSum(nums1) << "\n";

    vector<int> nums2 = {1, -1, 2, -2, 3, -3};
    cout << obj.maxAlternatingSum(nums2) << "\n";

    return 0;
}