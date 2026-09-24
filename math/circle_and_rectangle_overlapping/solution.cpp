#include <bits/stdc++.h>
using namespace std;

// Problem: Circle and Rectangle Overlapping
// Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Difficulty: Medium
// Pattern: Math - Closest Point Clamping

// ------------------------------------------------------------
// Approach: Find Closest Point on Rectangle to Circle Center, Check Distance
// ------------------------------------------------------------
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
};

int main() {
    Solution obj;
    cout << obj.checkOverlap(1, 0, 0, 1, -1, 3, 1);
    return 0;
}