#include <bits/stdc++.h>
using namespace std;

// Problem: Find Servers That Handled Most Number of Requests
// Link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Difficulty: Hard
// Pattern: Simulation + Ordered Set (Next Free Server, Circular) + Min-Heap (Busy Servers)

// ------------------------------------------------------------
// Approach 1: Brute Force Simulation (Scan Servers Circularly)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // freeAt[s] = time when server s becomes free
        vector<long long> freeAt(k, 0);
        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            // try servers i % k, (i + 1) % k, ... until a free one is found
            for (int j = 0; j < k; j++) {
                int s = (i + j) % k;

                if (freeAt[s] <= arrival[i]) {
                    count[s]++;
                    freeAt[s] = (long long)arrival[i] + load[i];
                    break;
                }
            }
        }

        int mx = *max_element(count.begin(), count.end());
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == mx)
                ans.push_back(i);
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Ordered Set (Free Servers) + Min-Heap (Busy Servers)
// ------------------------------------------------------------
class SolutionSetHeap {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // free servers, sorted by index
        set<int> available;

        // (finish time, server): earliest finish first
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < k; i++)
            available.insert(i);

        for (int i = 0; i < arrival.size(); i++) {
            // free every server that has finished by arrival[i]
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // no free server: the request is dropped
            if (available.empty())
                continue;

            // first free server with index >= i % k, else wrap to the smallest
            int target = i % k;
            auto it = available.lower_bound(target);

            if (it == available.end())
                it = available.begin();

            int server = *it;
            available.erase(it);

            count[server]++;
            busy.push({(long long)arrival[i] + load[i], server});
        }

        int mx = *max_element(count.begin(), count.end());
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == mx)
                ans.push_back(i);
        }

        return ans;
    }
};

void print(vector<int> v) {
    for (int a : v) cout << a << " ";
    cout << "| ";
}

int main() {
    vector<int> a1 = {1, 2, 3, 4, 5}, l1 = {5, 2, 3, 3, 3};
    vector<int> a2 = {1, 2, 3, 4}, l2 = {1, 2, 1, 2};
    vector<int> a3 = {1, 2, 3}, l3 = {10, 12, 11};

    SolutionBruteForce b;
    print(b.busiestServers(3, a1, l1));
    print(b.busiestServers(3, a2, l2));
    print(b.busiestServers(3, a3, l3));
    cout << "\n";

    SolutionSetHeap s;
    print(s.busiestServers(3, a1, l1));
    print(s.busiestServers(3, a2, l2));
    print(s.busiestServers(3, a3, l3));
    cout << "\n";

    return 0;
}