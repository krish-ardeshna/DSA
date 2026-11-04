#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Operations to Make Elements Within K Subarrays Equal
// Link: https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/
// Difficulty: Hard
// Pattern: Sliding Window Median (Two Multisets) + DP on Choosing K Non-Overlapping Windows

const long long INF = LLONG_MAX / 4;

// ------------------------------------------------------------
// Shared step: cost[s] = min operations to make nums[s..s + x - 1] all equal
// (the best target is the median, so cost = sum of |a - median|)
// ------------------------------------------------------------
vector<long long> windowCosts(vector<int>& nums, int x) {
    int n = nums.size();

    // low holds the smaller half (its max is the median), high holds the larger half
    multiset<int> low, high;
    long long lowSum = 0, highSum = 0;

    vector<long long> cost;

    auto balance = [&]() {
        int need = (low.size() + high.size() + 1) / 2;

        while ((int)low.size() > need) {
            auto it = prev(low.end());
            int val = *it;
            low.erase(it);
            high.insert(val);
            lowSum -= val;
            highSum += val;
        }

        while ((int)low.size() < need) {
            auto it = high.begin();
            int val = *it;
            high.erase(it);
            low.insert(val);
            highSum -= val;
            lowSum += val;
        }
    };

    // calculate the minimum cost for every window of size x
    for (int i = 0; i < n; i++) {
        int val = nums[i];

        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            lowSum += val;
        } else {
            high.insert(val);
            highSum += val;
        }

        if (i >= x) {
            int out = nums[i - x];

            auto it = low.find(out);

            if (it != low.end()) {
                low.erase(it);
                lowSum -= out;
            } else {
                it = high.find(out);
                high.erase(it);
                highSum -= out;
            }
        }

        balance();

        if (i >= x - 1) {
            long long median = *low.rbegin();

            long long operations =
                median * (long long)low.size() - lowSum +
                highSum - median * (long long)high.size();

            cost.push_back(operations);
        }
    }

    return cost;
}

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    // min operations using only the first i elements to build exactly j windows
    long long f(int i, int j, int x, vector<long long>& cost,
                vector<vector<long long>>& dp) {
        if (j == 0) return 0;

        if (i < x) return INF;

        if (dp[i][j] != -1) return dp[i][j];

        // skip element i - 1, or end a window at i - 1 (it starts at i - x)
        long long best = f(i - 1, j, x, cost, dp);

        long long take = f(i - x, j - 1, x, cost, dp);
        if (take != INF)
            best = min(best, take + cost[i - x]);

        return dp[i][j] = best;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost = windowCosts(nums, x);

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));

        return f(n, k, x, cost, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost = windowCosts(nums, x);

        // dp[j][i] = min operations using the first i elements to build exactly j windows
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));

        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];

                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
                }
            }
        }

        return dp[k][n];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost = windowCosts(nums, x);

        // row j only reads row j - 1, so two rows are enough
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};

int main() {
    vector<int> a1 = {5, -2, 1, 3, 7, 3, 6, 4, -1};
    vector<int> a2 = {9, -2, -2, -2, 1, 5};
    vector<int> a3 = {1, 1, 1, 1};

    SolutionMemo s1;
    cout << s1.minOperations(a1, 3, 2) << " "
         << s1.minOperations(a2, 2, 2) << " "
         << s1.minOperations(a3, 2, 2) << "\n";

    SolutionTabulation s2;
    cout << s2.minOperations(a1, 3, 2) << " "
         << s2.minOperations(a2, 2, 2) << " "
         << s2.minOperations(a3, 2, 2) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.minOperations(a1, 3, 2) << " "
         << s3.minOperations(a2, 2, 2) << " "
         << s3.minOperations(a3, 2, 2) << "\n";

    return 0;
}