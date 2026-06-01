#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Cost of Buying Candies With Discount
// Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
// Difficulty: Easy
// Pattern: Greedy

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.rbegin(), cost.rend());
        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {

            // Every third candy becomes free
            if (i % 3 != 2) {
                ans += cost[i];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> cost = {6, 5, 7, 9, 2, 2};
    Solution s;

    cout << s.minimumCost(cost) << "\n";

    return 0;
}