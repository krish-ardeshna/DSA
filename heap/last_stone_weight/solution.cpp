#include <bits/stdc++.h>
using namespace std;

// Problem: Last Stone Weight
// Link: https://leetcode.com/problems/last-stone-weight/
// Difficulty: Easy
// Pattern: Heap (Priority Queue)

// ------------------------------------------------------------
// Approach: Max Heap
// ------------------------------------------------------------

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();

            int x = pq.top();
            pq.pop();

            if (y != x)
                pq.push(y - x);
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    Solution obj;

    vector<int> stones = {2, 7, 4, 1, 8, 1};

    cout << obj.lastStoneWeight(stones);

    return 0;
}