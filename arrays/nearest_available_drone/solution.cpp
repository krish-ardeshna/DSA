#include <bits/stdc++.h>
using namespace std;

// Problem: Nearest Available Drone
// Link: https://leetcode.com/problems/nearest-available-drone/
// Difficulty: Easy(contest problem)
// Pattern: Array - Linear Scan (Manhattan Distance + Range Check)

// ------------------------------------------------------------
// Approach: Single Pass, Track Closest Drone Within Range
// ------------------------------------------------------------
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int reachable = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            int dist =
                abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if (dist <= drones[i][2]) {
                if (dist < minDist) {
                    minDist = dist;
                    reachable = i;
                }
            }
        }
        return reachable;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> drones = {{0, 0, 5}, {3, 3, 10}};
    vector<int> target = {2, 2};
    cout << obj.nearestDrone(drones, target);
    return 0;
}