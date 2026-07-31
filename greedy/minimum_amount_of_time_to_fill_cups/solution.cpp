#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Amount of Time to Fill Cups
// Link: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
// Difficulty: Easy
// Pattern: Greedy, Heap

// ------------------------------------------------------------
// Approach 1: Max Heap (Simulation)
// ------------------------------------------------------------

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;

        for (int x : amount)
            if (x > 0)
                pq.push(x);

        int ans = 0;

        while (!pq.empty()) {
            int first = pq.top();
            pq.pop();

            if (pq.empty()) {
                ans += first;
                break;
            }

            int second = pq.top();
            pq.pop();

            first--;
            second--;
            ans++;

            if (first > 0) pq.push(first);
            if (second > 0) pq.push(second);
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Mathematical Observation
// ------------------------------------------------------------

class Solution2 {
public:
    int fillCups(vector<int>& amount) {
        int sum = amount[0] + amount[1] + amount[2];
        int mx = max({amount[0], amount[1], amount[2]});

        return max(mx, (sum + 1) / 2);
    }
};

int main() {
    Solution obj;

    vector<int> amount = {1, 4, 2};

    cout << obj.fillCups(amount);

    return 0;
}