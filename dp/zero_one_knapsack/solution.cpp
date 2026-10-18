#include <bits/stdc++.h>
using namespace std;

// Problem: 0 and 1 Knapsack
// Link: <paste TakeUForward link here>
// Difficulty: Medium
// Pattern: DP on Subsequences (0/1 Knapsack, Take / Not Take)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }

        if (dp[idx][W] != -1) return dp[idx][W];

        int notTake = 0 + f(idx - 1, W, wt, val, dp);
        int take = INT_MIN;

        if (wt[idx] <= W) {
            take = val[idx] + f(idx - 1, W - wt[idx], wt, val, dp);
        }

        return dp[idx][W] = max(take, notTake);
    }
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, wt, val, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int w = wt[0]; w <= W; w++) dp[0][w] = val[0];

        for (int idx = 1; idx < n; idx++) {
            for (int w = 0; w <= W; w++) {
                int notTake = 0 + dp[idx - 1][w];
                int take = INT_MIN;
                if (wt[idx] <= w) {
                    take = val[idx] + dp[idx - 1][w - wt[idx]];
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
class SolutionSpaceTwoRows {
public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {

        vector<int> prev(W + 1, 0), curr(W + 1, 0);

        for (int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int w = 0; w <= W; w++) {
                int notTake = prev[w];
                int take = INT_MIN;

                if (wt[idx] <= w) {
                    take = val[idx] + prev[w - wt[idx]];
                }

                curr[w] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[W];
    }
};

// ------------------------------------------------------------
// Approach 4: Tabulation with Space Optimization (Single Row, Reverse Loop)
// ------------------------------------------------------------
class SolutionSpaceOneRow {
public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {

        vector<int> prev(W + 1, 0);

        for (int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int w = W; w >= 0; w--) {
                int notTake = prev[w];
                int take = INT_MIN;

                if (wt[idx] <= w) {
                    take = val[idx] + prev[w - wt[idx]];
                }

                prev[w] = max(take, notTake);
            }
        }

        return prev[W];
    }
};

int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int n = 4, W = 5;

    SolutionMemo s1;
    cout << s1.knapsack01(wt, val, n, W) << "\n";

    SolutionTabulation s2;
    cout << s2.knapsack01(wt, val, n, W) << "\n";

    SolutionSpaceTwoRows s3;
    cout << s3.knapsack01(wt, val, n, W) << "\n";

    SolutionSpaceOneRow s4;
    cout << s4.knapsack01(wt, val, n, W) << "\n";

    return 0;
}