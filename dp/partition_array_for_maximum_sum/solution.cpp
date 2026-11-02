#include <bits/stdc++.h>
using namespace std;

// Problem: Partition Array for Maximum Sum
// Link: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Difficulty: Medium
// Pattern: DP on Partitions (Front Partition, 1D DP, Window of k)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // best sum for arr[idx..n - 1]
    int f(int idx, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();

        if (idx == n) return 0;

        if (dp[idx] != -1) return dp[idx];

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int j = idx; j < min(idx + k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);

            int sum = len * maxi + f(j + 1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[idx] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n, -1);

        return f(0, arr, k, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

            for (int j = idx; j < min(idx + k, n); j++) {
                len++;
                maxi = max(maxi, arr[j]);

                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }

            dp[idx] = maxAns;
        }

        return dp[0];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Circular Buffer of k + 1)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // dp[i % (k + 1)] holds the best sum for the suffix that starts at i.
        // dp[idx] only reads dp[idx + 1 .. idx + k], so k + 1 slots are enough.
        // All slots start at 0, so the base case dp[n] = 0 is already in place.
        vector<int> dp(k + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

            for (int j = idx; j < min(idx + k, n); j++) {
                len++;
                maxi = max(maxi, arr[j]);

                int sum = len * maxi + dp[(j + 1) % (k + 1)];
                maxAns = max(maxAns, sum);
            }

            // this slot held index idx + k + 1, which is no longer needed
            dp[idx % (k + 1)] = maxAns;
        }

        return dp[0];
    }
};

int main() {
    vector<int> a1 = {1, 15, 7, 9, 2, 5, 10};
    vector<int> a2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    vector<int> a3 = {1};

    SolutionMemo s1;
    cout << s1.maxSumAfterPartitioning(a1, 3) << " "
         << s1.maxSumAfterPartitioning(a2, 4) << " "
         << s1.maxSumAfterPartitioning(a3, 1) << "\n";

    SolutionTabulation s2;
    cout << s2.maxSumAfterPartitioning(a1, 3) << " "
         << s2.maxSumAfterPartitioning(a2, 4) << " "
         << s2.maxSumAfterPartitioning(a3, 1) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.maxSumAfterPartitioning(a1, 3) << " "
         << s3.maxSumAfterPartitioning(a2, 4) << " "
         << s3.maxSumAfterPartitioning(a3, 1) << "\n";

    return 0;
}