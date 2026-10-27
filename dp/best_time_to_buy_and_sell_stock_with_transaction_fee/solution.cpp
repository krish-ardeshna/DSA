#include <bits/stdc++.h>
using namespace std;
// Problem: Best Time to Buy and Sell Stock with Transaction Fee
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Difficulty: Medium
// Pattern: DP on Stocks (Buy / Sell State, Fee Charged on Sell)
// ------------------------------------------------------------

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int buy, vector<int>& prices, int n, int fee, vector<vector<int>>& dp) {
        if (idx == n) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        if (buy) {
            return dp[idx][buy] = max(
                -prices[idx] + f(idx + 1, 0, prices, n, fee, dp),
                0 + f(idx + 1, 1, prices, n, fee, dp)
            );
        }

        return dp[idx][buy] = max(
            prices[idx] - fee + f(idx + 1, 1, prices, n, fee, dp),
            0 + f(idx + 1, 0, prices, n, fee, dp)
        );
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, fee, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[idx][buy] = max(
                        -prices[idx] + dp[idx + 1][0],
                        0 + dp[idx + 1][1]
                    );
                }
                else {
                    dp[idx][buy] = max(
                        prices[idx] - fee + dp[idx + 1][1],
                        0 + dp[idx + 1][0]
                    );
                }
            }
        }

        return dp[0][1];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Small Arrays)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(
                        -prices[idx] + ahead[0],
                        0 + ahead[1]
                    );
                }
                else {
                    profit = max(
                        prices[idx] - fee + ahead[1],
                        ahead[0]
                    );
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};

int main() {
    vector<int> p1 = {1, 3, 2, 8, 4, 9};
    vector<int> p2 = {1, 3, 7, 5, 10, 3};
    vector<int> p3 = {5, 4, 3};

    SolutionMemo s1;
    cout << s1.maxProfit(p1, 2) << " " << s1.maxProfit(p2, 3) << " " << s1.maxProfit(p3, 1) << "\n";

    SolutionTabulation s2;
    cout << s2.maxProfit(p1, 2) << " " << s2.maxProfit(p2, 3) << " " << s2.maxProfit(p3, 1) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.maxProfit(p1, 2) << " " << s3.maxProfit(p2, 3) << " " << s3.maxProfit(p3, 1) << "\n";

    return 0;
}