#include <bits/stdc++.h>
using namespace std;

// Problem: Process Tasks Using Servers
// Link: https://leetcode.com/problems/process-tasks-using-servers/
// Difficulty: Medium
// Pattern: Two Heaps (Available Servers + Busy Servers) + Time Simulation

// ------------------------------------------------------------
// Approach 1: Brute Force Simulation (Scan All Servers for Every Task)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();

        // freeAt[i] = time when server i becomes free
        vector<long long> freeAt(n, 0);

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            // if every server is busy, jump to the earliest finish time
            long long earliest = *min_element(freeAt.begin(), freeAt.end());
            time = max(time, earliest);

            // pick the free server with the smallest (weight, index)
            int best = -1;

            for (int s = 0; s < n; s++) {
                if (freeAt[s] <= time) {
                    if (best == -1 || servers[s] < servers[best])
                        best = s;
                }
            }

            ans.push_back(best);
            freeAt[best] = time + tasks[i];
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Two Heaps (Available + Busy)
// ------------------------------------------------------------
class SolutionTwoHeaps {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // (weight, index): smallest weight first, then smallest index
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> available;

        // (finish time, weight, index): earliest finish first
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>> busy;

        for (int i = 0; i < servers.size(); i++)
            available.push({servers[i], i});

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            // free every server that has finished by now
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, idx] = busy.top();
                busy.pop();
                available.push({w, idx});
            }

            // no free server: jump to the earliest finish time
            if (available.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [t, w, idx] = busy.top();
                    busy.pop();
                    available.push({w, idx});
                }
            }

            auto [weight, idx] = available.top();
            available.pop();

            ans.push_back(idx);
            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};

void print(vector<int> v) {
    for (int a : v) cout << a << " ";
    cout << "| ";
}

int main() {
    vector<int> s1 = {3, 3, 2}, t1 = {1, 2, 3, 2, 1, 2};
    vector<int> s2 = {5, 1, 4, 3, 2}, t2 = {2, 1, 2, 4, 5, 2, 1};

    SolutionBruteForce b;
    print(b.assignTasks(s1, t1));
    print(b.assignTasks(s2, t2));
    cout << "\n";

    SolutionTwoHeaps h;
    print(h.assignTasks(s1, t1));
    print(h.assignTasks(s2, t2));
    cout << "\n";

    return 0;
}