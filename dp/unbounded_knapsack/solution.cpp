#include <bits/stdc++.h>
using namespace std;

// Problem: Unbounded Knapsack
// Link: https://takeuforward.org/practice/dsa/unbounded-knapsack
// Difficulty: Medium
// Pattern: DP on Subsequences (Unbounded Knapsack, Take Stays on Same Index)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {

        if (idx == 0) return ((int)(W / wt[0])) * val[0];

        if (dp[idx][W] != -1) return dp[idx][W];

        int notTake = 0 + f(idx - 1, W, wt, val, dp);
        int take = 0;

        if (wt[idx] <= W) {
            take = val[idx] + f(idx, W - wt[idx], wt, val, dp);
        }

        return dp[idx][W] = max(take, notTake);
    }
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, wt, val, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int w = 0; w <= W; w++) {
            dp[0][w] = (w / wt[0]) * val[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int w = 0; w <= W; w++) {
                int notTake = dp[idx - 1][w];
                int take = 0;

                if (wt[idx] <= w) {
                    take = val[idx] + dp[idx][w - wt[idx]];
                }

                dp[idx][w] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> prev(W + 1, 0), curr(W + 1, 0);

        for (int w = 0; w <= W; w++) {
            prev[w] = (w / wt[0]) * val[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int w = 0; w <= W; w++) {
                int notTake = prev[w];
                int take = 0;

                if (wt[idx] <= w) {
                    take = val[idx] + curr[w - wt[idx]];
                }

                curr[w] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};

int main() {
    vector<int> wt1 = {2, 4, 6}, val1 = {5, 11, 13};
    vector<int> wt2 = {1, 3, 4}, val2 = {1, 4, 5};
    vector<int> wt3 = {5}, val3 = {10};

    SolutionMemo s1;
    cout << s1.unboundedKnapsack(wt1, val1, 3, 10) << " "
         << s1.unboundedKnapsack(wt2, val2, 3, 7) << " "
         << s1.unboundedKnapsack(wt3, val3, 1, 4) << "\n";

    SolutionTabulation s2;
    cout << s2.unboundedKnapsack(wt1, val1, 3, 10) << " "
         << s2.unboundedKnapsack(wt2, val2, 3, 7) << " "
         << s2.unboundedKnapsack(wt3, val3, 1, 4) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.unboundedKnapsack(wt1, val1, 3, 10) << " "
         << s3.unboundedKnapsack(wt2, val2, 3, 7) << " "
         << s3.unboundedKnapsack(wt3, val3, 1, 4) << "\n";

    return 0;
}