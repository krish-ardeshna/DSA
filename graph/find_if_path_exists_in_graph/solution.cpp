#include <bits/stdc++.h>
using namespace std;

// Problem: Find if Path Exists in Graph
// Link: https://leetcode.com/problems/find-if-path-exists-in-graph/
// Difficulty: Easy
// Pattern: Graph Traversal (DFS, BFS)

// ------------------------------------------------------------
// Approach 1: Depth-First Search (DFS)
// ------------------------------------------------------------

class SolutionDFS {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);

        dfs(source, adj, vis);

        return vis[destination];
    }
};

// ------------------------------------------------------------
// Approach 2: Breadth-First Search (BFS)
// ------------------------------------------------------------

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        queue<int> q;

        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = true;
                    q.push(nei);
                }
            }
        }

        return false;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int source = 0;
    int destination = 2;

    Solution s;
    cout << boolalpha << s.validPath(n, edges, source, destination) << endl;

    return 0;
}