#include <bits/stdc++.h>
using namespace std;

// Problem: Product of Array Except Self
// Link: https://leetcode.com/problems/product-of-array-except-self/
// Difficulty: Medium
// Pattern: Prefix Sum

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------

class SolutionBruteForce {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int product = 1;

            for (int j = 0; j < nums.size(); j++) {
                if (i == j) {
                    continue;
                }
                product *= nums[j];
            }
            ans.push_back(product);
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Prefix and Suffix Products
// ------------------------------------------------------------

class SolutionOptimal {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    SolutionOptimal s;
    vector<int> ans = s.productExceptSelf(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}