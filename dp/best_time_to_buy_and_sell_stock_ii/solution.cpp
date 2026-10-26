#include <bits/stdc++.h>
using namespace std;

// Problem: Best Time to Buy and Sell Stock II
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Difficulty: Medium
// Pattern: DP on Stocks (Buy / Sell State), Greedy Shortcut

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int buy, vector<int> &prices, int n, vector<vector<int>> &dp) {
        if (idx == n) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        if (buy) {
            dp[idx][buy] = max(
                -prices[idx] + f(idx + 1, 0, prices, n, dp),
                0 + f(idx + 1, 1, prices, n, dp)
            );
        }
        else {
            dp[idx][buy] = max(
                prices[idx] + f(idx + 1, 1, prices, n, dp),
                0 + f(idx + 1, 0, prices, n, dp)
            );
        }
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(0, 1, prices, n, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

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
                        prices[idx] + dp[idx + 1][1],
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
class SolutionSpaceArrays {
public:
    int maxProfit(vector<int>& prices) {
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
                        prices[idx] + ahead[1],
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

// ------------------------------------------------------------
// Approach 4: Tabulation with Space Optimization (Four Variables)
// ------------------------------------------------------------
class SolutionSpaceVariables {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        long long aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadBuy = aheadNotBuy = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            currNotBuy = max(prices[idx] + aheadBuy, 0 + aheadNotBuy);
            currBuy = max(-prices[idx] + aheadNotBuy, 0 + aheadBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};

// ------------------------------------------------------------
// Approach 5: Greedy (Sum of Every Upward Step)
// ------------------------------------------------------------
class SolutionGreedy {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                ans += prices[i] - prices[i - 1];
            }
        }

        return ans;
    }
};

int main() {
    vector<int> p1 = {7, 1, 5, 3, 6, 4};
    vector<int> p2 = {1, 2, 3, 4, 5};
    vector<int> p3 = {7, 6, 4, 3, 1};

    SolutionMemo s1;
    cout << s1.maxProfit(p1) << " " << s1.maxProfit(p2) << " " << s1.maxProfit(p3) << "\n";

    SolutionTabulation s2;
    cout << s2.maxProfit(p1) << " " << s2.maxProfit(p2) << " " << s2.maxProfit(p3) << "\n";

    SolutionSpaceArrays s3;
    cout << s3.maxProfit(p1) << " " << s3.maxProfit(p2) << " " << s3.maxProfit(p3) << "\n";

    SolutionSpaceVariables s4;
    cout << s4.maxProfit(p1) << " " << s4.maxProfit(p2) << " " << s4.maxProfit(p3) << "\n";

    SolutionGreedy s5;
    cout << s5.maxProfit(p1) << " " << s5.maxProfit(p2) << " " << s5.maxProfit(p3) << "\n";

    return 0;
}