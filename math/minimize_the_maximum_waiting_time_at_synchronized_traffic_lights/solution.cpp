#include <bits/stdc++.h>
using namespace std;

// Problem: Minimize the Maximum Waiting Time at Synchronized Traffic Lights
// Link: https://leetcode.com/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/
// Difficulty: Medium (contest problem)  
// Pattern: Math - Modular Arithmetic

// ------------------------------------------------------------
// Approach: Modular Offset Check Against Max Light
// ------------------------------------------------------------
class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {

        int maxLight = *max_element(lights.begin(), lights.end());
        int ans = 0;

        for (int time : arrivalTime) {
            int r = time % period;

            if (r >= maxLight) {
                ans = max(ans, period - r);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    int period = 10;
    vector<int> lights = {2, 5};
    vector<int> arrivalTime = {3, 8, 12};
    cout << obj.minPenalty(period, lights, arrivalTime);
    return 0;
}