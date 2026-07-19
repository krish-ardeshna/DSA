#include <bits/stdc++.h>
using namespace std;

// Problem: Best Time to Buy and Sell Stock II
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Difficulty: Medium
// Pattern: Greedy

// ------------------------------------------------------------
// Approach: Greedy
// ------------------------------------------------------------

class Solution {
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
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;

    cout << s.maxProfit(prices) << "\n";
    return 0;
}