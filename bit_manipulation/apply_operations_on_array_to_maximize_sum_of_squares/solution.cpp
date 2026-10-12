#include <bits/stdc++.h>
using namespace std;

// Problem: Apply Operations on Array to Maximize Sum of Squares
// Link: https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/
// Difficulty: Hard
// Pattern: Bit Manipulation + Greedy (Per-Bit Counting)

// ------------------------------------------------------------
// Approach: Count Set Bits Per Position, Greedily Build k Largest Numbers
// ------------------------------------------------------------
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> cnt(31, 0);

        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                if (x & (1 << b)) {
                    cnt[b]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {2, 6, 5, 8};
    cout << obj.maxSum(nums1, 2) << "\n";

    vector<int> nums2 = {4, 5, 4, 7};
    cout << obj.maxSum(nums2, 3) << "\n";

    return 0;
}