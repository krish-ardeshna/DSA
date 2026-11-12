#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Strictly Increasing or Strictly Decreasing Subarray
// Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
// Difficulty: Easy
// Pattern: Array + Single Pass (Track Current Increasing and Decreasing Run)

// ------------------------------------------------------------
// Approach 1: Brute Force (Extend From Every Start)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            // longest strictly increasing run starting at i
            int j = i;
            while (j + 1 < n && nums[j + 1] > nums[j])
                j++;
            ans = max(ans, j - i + 1);

            // longest strictly decreasing run starting at i
            j = i;
            while (j + 1 < n && nums[j + 1] < nums[j])
                j++;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Single Pass
// ------------------------------------------------------------
class SolutionSinglePass {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, ans = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            }
            else {
                inc = 1;
                dec = 1;
            }

            ans = max(ans, max(inc, dec));
        }

        return ans;
    }
};

int main() {
    vector<int> a1 = {1, 4, 3, 3, 2};
    vector<int> a2 = {3, 3, 3, 3};
    vector<int> a3 = {3, 2, 1};

    SolutionBruteForce s1;
    cout << s1.longestMonotonicSubarray(a1) << " "
         << s1.longestMonotonicSubarray(a2) << " "
         << s1.longestMonotonicSubarray(a3) << "\n";

    SolutionSinglePass s2;
    cout << s2.longestMonotonicSubarray(a1) << " "
         << s2.longestMonotonicSubarray(a2) << " "
         << s2.longestMonotonicSubarray(a3) << "\n";

    return 0;
}