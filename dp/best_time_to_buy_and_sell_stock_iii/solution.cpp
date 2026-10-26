#include <bits/stdc++.h>
using namespace std;

// Problem: Best Time to Buy and Sell Stock III
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Difficulty: Hard
// Pattern: DP on Stocks (Buy / Sell State + Transaction Limit)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
        if (idx == n || cap == 0) return 0;
        if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        if (buy == 1) {
            return dp[idx][buy][cap] = max(
                -prices[idx] + f(idx + 1, 0, cap, prices, n, dp),
                0 + f(idx + 1, 1, cap, prices, n, dp)
            );
        }
        return dp[idx][buy][cap] = max(
            prices[idx] + f(idx + 1, 1, cap - 1, prices, n, dp),
            0 + f(idx + 1, 0, cap, prices, n, dp)
        );
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, n, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0))
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 1) {
                        dp[i][buy][cap] = max(
                            -prices[i] + dp[i + 1][0][cap],
                            dp[i + 1][1][cap]
                        );
                    } else {
                        dp[i][buy][cap] = max(
                            prices[i] + dp[i + 1][1][cap - 1],
                            dp[i + 1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Layers)
// ------------------------------------------------------------
class SolutionSpaceOptimized {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 1) {
                        curr[buy][cap] = max(
                            -prices[i] + ahead[0][cap],
                            ahead[1][cap]
                        );
                    } else {
                        curr[buy][cap] = max(
                            prices[i] + ahead[1][cap - 1],
                            ahead[0][cap]
                        );
                    }
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};

int main() {
    vector<int> p1 = {3, 3, 5, 0, 0, 3, 1, 4};
    vector<int> p2 = {1, 2, 3, 4, 5};
    vector<int> p3 = {7, 6, 4, 3, 1};

    SolutionMemo s1;
    cout << s1.maxProfit(p1) << " " << s1.maxProfit(p2) << " " << s1.maxProfit(p3) << "\n";

    SolutionTabulation s2;
    cout << s2.maxProfit(p1) << " " << s2.maxProfit(p2) << " " << s2.maxProfit(p3) << "\n";

    SolutionSpaceOptimized s3;
    cout << s3.maxProfit(p1) << " " << s3.maxProfit(p2) << " " << s3.maxProfit(p3) << "\n";

    return 0;
}