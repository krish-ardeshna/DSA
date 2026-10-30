#include <bits/stdc++.h>
using namespace std;

// Problem: Shortest Path With At Most K Consecutive Identical Characters
// Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Graph (Dijkstra on an Expanded State Graph: Node + Current Run Length)

// ------------------------------------------------------------
// Approach: Dijkstra over states (node, run length)
// ------------------------------------------------------------
class Solution {
public:
    long long shortestPath(int n, vector<vector<int>>& edges,
                           string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX;

        // dist[u][cnt] = shortest distance to reach u when the path currently ends
        // with exactly `cnt` equal labels in a row (1 <= cnt <= k)
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // the start node already counts as a run of length 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt])
                continue;

            // the first time the target is popped, d is the best over every run length
            if (u == n - 1)
                return d;

            for (auto [v, w] : adj[u]) {
                int nextCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (nextCnt > k)
                    continue;

                if (d + w < dist[v][nextCnt]) {
                    dist[v][nextCnt] = d + w;
                    pq.push({d + w, v, nextCnt});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution s;

    // 0 -> 1 -> 2 costs 2 (labels a, a, b), the direct edge 0 -> 2 costs 5 (labels a, b)
    vector<vector<int>> e1 = {{0, 1, 1}, {1, 2, 1}, {0, 2, 5}};
    cout << s.shortestPath(3, e1, "aab", 2) << " "     // 2: run "aa" is allowed
         << s.shortestPath(3, e1, "aab", 1) << "\n";   // 5: "aa" is not allowed, use the direct edge

    // the only edge joins two equal labels, but k = 1 forbids it
    vector<vector<int>> e2 = {{0, 1, 4}};
    cout << s.shortestPath(2, e2, "aa", 1) << " ";     // -1

    // one node: start is already the target
    vector<vector<int>> e3 = {};
    cout << s.shortestPath(1, e3, "a", 1) << "\n";     // 0

    return 0;
}