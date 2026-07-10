#include <bits/stdc++.h>
using namespace std;

// Problem: Subarray Product Less Than K
// Link: https://leetcode.com/problems/subarray-product-less-than-k/
// Difficulty: Medium
// Pattern: Sliding Window

// ------------------------------------------------------------
// Approach: Sliding Window
// ------------------------------------------------------------

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        long long product = 1;
        int count = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            product *= nums[end];

            while (product >= k && start <= end) {
                product /= nums[start];
                start++;
            }
            count += (end - start + 1);
        }
        return count;
    }
};

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    Solution s;
    cout << s.numSubarrayProductLessThanK(nums, k) << "\n";

    return 0;
}