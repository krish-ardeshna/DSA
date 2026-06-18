#include <bits/stdc++.h>
using namespace std;

// Problem: Angle Between Hands of a Clock
// Link: https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Difficulty: Medium
// Pattern: Math / Geometry

// ------------------------------------------------------------
// Approach: Mathematical Angle Calculation
// ------------------------------------------------------------

class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hourAngle = (hour % 12) * 30 + minutes * 0.5;

        double minuteAngle = minutes * 6;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};

int main() {

    int hour = 3;
    int minutes = 30;

    Solution s;
    cout << s.angleClock(hour, minutes) << "\n";

    return 0;
}