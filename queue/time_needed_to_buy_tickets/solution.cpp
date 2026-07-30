#include <bits/stdc++.h>
using namespace std;

// Problem: Time Needed to Buy Tickets
// Link: https://leetcode.com/problems/time-needed-to-buy-tickets/
// Difficulty: Easy
// Pattern: Queue, Simulation Observation

// ------------------------------------------------------------
// Approach: Counting
// ------------------------------------------------------------

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;

        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k)
                ans += min(tickets[i], tickets[k]);
            else
                ans += min(tickets[i], tickets[k] - 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> tickets = {2, 3, 2};
    int k = 2;

    cout << obj.timeRequiredToBuy(tickets, k);

    return 0;
}