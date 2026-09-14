#include <bits/stdc++.h>
using namespace std;

// Problem: Online Stock Span
// Link: https://leetcode.com/problems/online-stock-span/
// Difficulty: Medium
// Pattern: Monotonic Stack (Streaming/Online)

// ------------------------------------------------------------
// Approach: Monotonic Decreasing Stack with (price, index) Pairs
// ------------------------------------------------------------
class StockSpanner {
    stack<pair<int, int>> st;
    int idx;
public:
    StockSpanner() {
        idx = -1;
    }

    int next(int price) {
        idx++;

        while (!st.empty() && st.top().first <= price) st.pop();

        int ans = idx - (st.empty() ? -1 : st.top().second);

        st.push({price, idx});

        return ans;
    }
};

int main() {
    StockSpanner obj;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    for (int p : prices) {
        cout << obj.next(p) << " ";
    }

    return 0;
}