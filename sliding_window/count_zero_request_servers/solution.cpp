#include <bits/stdc++.h>
using namespace std;

// Problem: Count Zero Request Servers
// Link: https://leetcode.com/problems/count-zero-request-servers/
// Difficulty: Medium
// Pattern: Offline Queries + Sorting + Sliding Window (Two Pointers)

// ------------------------------------------------------------
// Approach 1: Brute Force (Check Every Log for Every Query)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {
        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int time = queries[i];

            // seen[id] = true if server id got a request in [time - x, time]
            vector<bool> seen(n + 1, false);
            int active = 0;

            for (auto& log : logs) {
                int id = log[0], t = log[1];

                if (t >= time - x && t <= time && !seen[id]) {
                    seen[id] = true;
                    active++;
                }
            }

            ans[i] = n - active;
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Sort Logs + Sort Queries + Sliding Window
// ------------------------------------------------------------
class SolutionSlidingWindow {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size());

        int left = 0, right = 0, active = 0;

        for (auto [time, idx] : q) {
            // add logs with t <= time
            while (right < logs.size() && logs[right][1] <= time) {
                int id = logs[right][0];

                if (freq[id]++ == 0)
                    active++;

                right++;
            }

            // remove logs with t < time - x
            while (left < right && logs[left][1] < time - x) {
                int id = logs[left][0];

                if (--freq[id] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};

void print(vector<int> v) {
    for (int a : v) cout << a << " ";
    cout << "| ";
}

int main() {
    vector<vector<int>> l1 = {{1, 3}, {2, 6}, {1, 5}};
    vector<int> q1 = {10, 11};

    vector<vector<int>> l2 = {{2, 4}, {2, 1}, {1, 2}, {3, 1}};
    vector<int> q2 = {3, 4};

    SolutionBruteForce s1;
    auto a = l1, b = l2;
    print(s1.countServers(3, a, 5, q1));
    print(s1.countServers(3, b, 2, q2));
    cout << "\n";

    SolutionSlidingWindow s2;
    a = l1; b = l2;
    print(s2.countServers(3, a, 5, q1));
    print(s2.countServers(3, b, 2, q2));
    cout << "\n";

    return 0;
}