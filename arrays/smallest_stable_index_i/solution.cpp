#include <bits/stdc++.h>
using namespace std;

// Problem: Smallest Stable Index I
// Link: https://leetcode.com/problems/smallest-stable-index-i/
// Difficulty: Easy
// Pattern: Array - Prefix Max + Suffix Min / Brute Force

// ------------------------------------------------------------
// Approach 1: Precomputed Suffix Min + Running Prefix Max
// ------------------------------------------------------------
class SolutionOptimized {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        int prefixMax = nums[0];

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            if (prefixMax - suffixMin[i] <= k)
                return i;
        }
        return -1;
    }
};

// ------------------------------------------------------------
// Approach 2: Brute Force (max_element / min_element per index)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        for (int i = 0; i < nums.size(); i++) {
            int maxi = *max_element(nums.begin(), nums.begin() + i + 1);
            int mini = *min_element(nums.begin() + i, nums.end());

            int instability_score = maxi - mini;
            if (instability_score <= k) return i;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {5, 2, 8, 1, 9};
    int k = 3;

    SolutionOptimized s1;
    cout << s1.firstStableIndex(nums, k) << "\n";

    SolutionBruteForce s2;
    cout << s2.firstStableIndex(nums, k) << "\n";

    return 0;
}