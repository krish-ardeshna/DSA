#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Ways to Reorder Array to Get Same BST
// Link: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
// Difficulty: Hard
// Pattern: Divide and Conquer + Combinatorics (Pascal's Triangle for nCr)

// ------------------------------------------------------------
// Approach: Split by Root, Interleave Left and Right Orderings With C(n-1, leftSize)
// ------------------------------------------------------------
class Solution {
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long waysLeft = solve(left);
        long long waysRight = solve(right);

        long long ways = comb[n - 1][left.size()];
        ways = ways * waysLeft % MOD;
        ways = ways * waysRight % MOD;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {2, 1, 3};
    cout << obj.numOfWays(nums1) << "\n";

    vector<int> nums2 = {3, 4, 5, 1, 2};
    cout << obj.numOfWays(nums2) << "\n";

    vector<int> nums3 = {1, 2, 3};
    cout << obj.numOfWays(nums3) << "\n";

    return 0;
}