#include <bits/stdc++.h>
using namespace std;

// Problem: Sliding Window Maximum
// Link: https://leetcode.com/problems/sliding-window-maximum/
// Difficulty: Hard
// Pattern: Sliding Window / Monotonic Queue

// ------------------------------------------------------------
// Approach 1: Max Heap (Priority Queue)
// ------------------------------------------------------------

class SolutionHeap {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            
            pq.push({nums[i], i});

            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            if (i >= k - 1) {
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Monotonic Deque
// ------------------------------------------------------------

class SolutionOptimal {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    SolutionOptimal s;
    vector<int> ans = s.maxSlidingWindow(nums, k);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}