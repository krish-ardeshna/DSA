#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Sum of Squared Difference
// Link: https://leetcode.com/problems/minimum-sum-of-squared-difference/
// Difficulty: Medium
// Pattern: Greedy (Shave Largest Differences First, Frequency Buckets)

// ------------------------------------------------------------
// Approach: Bucket Differences by Value, Reduce From the Top Down
// ------------------------------------------------------------
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        int maxDiff = 0;
        long long total = 0;

        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (k >= total)
            return 0;

        vector<long long> freq(maxDiff + 1, 0);

        for (int d : diff)
            freq[d]++;

        for (int d = maxDiff; d > 0 && k > 0; d--) {
            long long reduce = min(k, freq[d]);

            freq[d] -= reduce;
            freq[d - 1] += reduce;

            k -= reduce;
        }

        long long ans = 0;

        for (int d = 1; d <= maxDiff; d++)
            ans += freq[d] * d * d;

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> a1 = {1, 2, 3, 4};
    vector<int> b1 = {2, 10, 20, 19};
    cout << obj.minSumSquareDiff(a1, b1, 0, 0) << "\n";

    vector<int> a2 = {1, 4, 10, 12};
    vector<int> b2 = {5, 8, 6, 9};
    cout << obj.minSumSquareDiff(a2, b2, 1, 1) << "\n";

    return 0;
}