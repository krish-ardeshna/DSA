#include <bits/stdc++.h>
using namespace std;

// Problem: Best Time to Buy and Sell Stock IV
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Difficulty: Hard
// Pattern: DP on Stocks (At Most k Transactions, State = Operations Done)

// ------------------------------------------------------------
// Approach 1: Recursion + Memoization (Top-Down)
// ------------------------------------------------------------
class SolutionMemo {
public:
    int f(int idx, int trans, vector<int>& prices, int n, int k, vector<vector<int>>& dp) {
        if (idx == n || trans == 2 * k) return 0;

        if (dp[idx][trans] != -1) return dp[idx][trans];

        if (trans % 2 == 0) {
            return dp[idx][trans] = max(
                -prices[idx] + f(idx + 1, trans + 1, prices, n, k, dp),
                0 + f(idx + 1, trans, prices, n, k, dp)
            );
        }

        return dp[idx][trans] = max(
            prices[idx] + f(idx + 1, trans + 1, prices, n, k, dp),
            0 + f(idx + 1, trans, prices, n, k, dp)
        );
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return f(0, 0, prices, n, k, dp);
    }
};

// ------------------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// ------------------------------------------------------------
class SolutionTabulation {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {
                if (trans % 2 == 0) {
                    dp[i][trans] = max(
                        -prices[i] + dp[i + 1][trans + 1],
                        dp[i + 1][trans]
                    );
                } else {
                    dp[i][trans] = max(
                        prices[i] + dp[i + 1][trans + 1],
                        dp[i + 1][trans]
                    );
                }
            }
        }

        return dp[0][0];
    }
};

// ------------------------------------------------------------
// Approach 3: Tabulation with Space Optimization (Two Rows)
// ------------------------------------------------------------
class SolutionSpaceTwoRows {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(2 * k + 1, 0);
        vector<int> curr(2 * k + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {
                if (trans % 2 == 0) {
                    curr[trans] = max(
                        -prices[i] + ahead[trans + 1],
                        ahead[trans]
                    );
                } else {
                    curr[trans] = max(
                        prices[i] + ahead[trans + 1],
                        ahead[trans]
                    );
                }
            }
            ahead = curr;
        }

        return ahead[0];
    }
};

// ------------------------------------------------------------
// Approach 4 (Extra): Space Optimization with a Single Array (In-Place)
// ------------------------------------------------------------
class SolutionSpaceSingleArray {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<int> dp(2 * k + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            // ascending trans: dp[trans + 1] has not been updated yet today,
            // so it still holds tomorrow's value when it is read
            for (int trans = 0; trans < 2 * k; trans++) {
                if (trans % 2 == 0) {
                    dp[trans] = max(-prices[i] + dp[trans + 1], dp[trans]);
                } else {
                    dp[trans] = max(prices[i] + dp[trans + 1], dp[trans]);
                }
            }
        }

        return dp[0];
    }
};

// ------------------------------------------------------------
// Approach 5 (Extra): Forward Buy/Sell Arrays + k >= n/2 Shortcut
// ------------------------------------------------------------
class SolutionBuySellArrays {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        if (n < 2 || k == 0) return 0;

        // each transaction needs 2 days, so k >= n / 2 means "unlimited"
        if (k >= n / 2) {
            int ans = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    ans += prices[i] - prices[i - 1];
                }
            }
            return ans;
        }

        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);

        for (int p : prices) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - p);
                sell[j] = max(sell[j], buy[j] + p);
            }
        }

        return sell[k];
    }
};

int main() {
    vector<int> p1 = {2, 4, 1};
    vector<int> p2 = {3, 2, 6, 5, 0, 3};
    vector<int> p3 = {7, 6, 4, 3, 1};

    SolutionMemo s1;
    cout << s1.maxProfit(2, p1) << " " << s1.maxProfit(2, p2) << " " << s1.maxProfit(1, p3) << "\n";

    SolutionTabulation s2;
    cout << s2.maxProfit(2, p1) << " " << s2.maxProfit(2, p2) << " " << s2.maxProfit(1, p3) << "\n";

    SolutionSpaceTwoRows s3;
    cout << s3.maxProfit(2, p1) << " " << s3.maxProfit(2, p2) << " " << s3.maxProfit(1, p3) << "\n";

    SolutionSpaceSingleArray s4;
    cout << s4.maxProfit(2, p1) << " " << s4.maxProfit(2, p2) << " " << s4.maxProfit(1, p3) << "\n";

    SolutionBuySellArrays s5;
    cout << s5.maxProfit(2, p1) << " " << s5.maxProfit(2, p2) << " " << s5.maxProfit(1, p3) << "\n";

    return 0;
}