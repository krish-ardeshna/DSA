#include <bits/stdc++.h>
using namespace std;
// Problem: Best Time to Buy and Sell Stock with Cooldown
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Difficulty: Medium
// Pattern: DP on Stocks (Buy / Sell State, One-Day Cooldown After Sell)
// ------------------------------------------------------------

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int buy, int n, vector<int> &prices, vector<vector<int>> &dp) {
        if (idx >= n) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        if (buy == 1) {
            return dp[idx][buy] = max(
                -prices[idx] + f(idx + 1, 0, n, prices, dp),
                0 + f(idx + 1, 1, n, prices, dp)
            );
        }

        return dp[idx][buy] = max(
            prices[idx] + f(idx + 2, 1, n, prices, dp),
            0 + f(idx + 1, 0, n, prices, dp)
        );
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        return f(0, 1, n, prices, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {

                if (buy == 1)
                    dp[i][buy] = max(
                        -prices[i] + dp[i + 1][0],
                        0 + dp[i + 1][1]
                    );
                else
                    dp[i][buy] = max(
                        prices[i] + dp[i + 2][1],
                        0 + dp[i + 1][0]
                    );
            }
        }
        return dp[0][1];
    }
};

// ------------------------------------------------------------
// Approach 3a: Tabulation with Space Optimization (Three Small Arrays)
// ------------------------------------------------------------
class SolutionSpaceArrays {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> f1(2, 0);
        vector<int> f2(2, 0);
        vector<int> cur(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            cur[1] = max(-prices[i] + f1[0], f1[1]);
            cur[0] = max(prices[i] + f2[1], f1[0]);

            f2 = f1;
            f1 = cur;
        }

        return f1[1];
    }
};

// ------------------------------------------------------------
// Approach 3b: Tabulation with Space Optimization (Five Variables)
// ------------------------------------------------------------
class SolutionSpaceVariables {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int aheadBuy, aheadNotBuy, ahead2Buy;
        int currBuy, currNotBuy;
        aheadBuy = aheadNotBuy = ahead2Buy = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            currNotBuy = max(prices[idx] + ahead2Buy, 0 + aheadNotBuy);
            currBuy = max(-prices[idx] + aheadNotBuy, 0 + aheadBuy);

            ahead2Buy = aheadBuy;
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};

int main() {
    vector<int> p1 = {1, 2, 3, 0, 2};
    vector<int> p2 = {1};
    vector<int> p3 = {6, 1, 3, 2, 4, 7};

    SolutionMemo s1;
    cout << s1.maxProfit(p1) << " " << s1.maxProfit(p2) << " " << s1.maxProfit(p3) << "\n";

    SolutionTabulation s2;
    cout << s2.maxProfit(p1) << " " << s2.maxProfit(p2) << " " << s2.maxProfit(p3) << "\n";

    SolutionSpaceArrays s3;
    cout << s3.maxProfit(p1) << " " << s3.maxProfit(p2) << " " << s3.maxProfit(p3) << "\n";

    SolutionSpaceVariables s4;
    cout << s4.maxProfit(p1) << " " << s4.maxProfit(p2) << " " << s4.maxProfit(p3) << "\n";

    return 0;
}