#include <bits/stdc++.h>
using namespace std;

// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty: Easy
// Pattern: Arrays / Greedy

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {

            // Track minimum buying price
            mini = min(mini, prices[i]);

            // Calculate maximum profit
            profit = max(profit, prices[i] - mini);
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;

    cout << s.maxProfit(prices) << "\n";

    return 0;
}