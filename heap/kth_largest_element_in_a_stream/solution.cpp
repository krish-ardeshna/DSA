#include <bits/stdc++.h>
using namespace std;

// Problem: Kth Largest Element in a Stream
// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Difficulty: Easy
// Pattern: Heap (Priority Queue)

// ------------------------------------------------------------
// Approach: Min Heap
// ------------------------------------------------------------

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            pq.push(num);

            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > k)
            pq.pop();

        return pq.top();
    }
};

int main() {
    cout << "This is a design problem. Test cases are handled by LeetCode's driver code." << endl;
    return 0;
}