#include <bits/stdc++.h>
using namespace std;

// Problem: Keys and Rooms
// Link: https://leetcode.com/problems/keys-and-rooms/
// Difficulty: Medium
// Pattern: Graph Traversal (DFS, BFS)

// ------------------------------------------------------------
// Approach 1: Depth-First Search (DFS)
// ------------------------------------------------------------

class SolutionDFS {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room] = true;

        for (int key : rooms[room]) {
            if (!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for (bool room : visited) {
            if (!room)
                return false;
        }

        return true;
    }
};

// ------------------------------------------------------------
// Approach 2: Breadth-First Search (BFS)
// ------------------------------------------------------------

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int room = q.front();
            q.pop();

            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }

        for (bool room : visited) {
            if (!room)
                return false;
        }

        return true;
    }
};

int main() {
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};

    Solution s;
    cout << boolalpha << s.canVisitAllRooms(rooms) << endl;

    return 0;
}