#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Highest Altitude
// Link: https://leetcode.com/problems/find-the-highest-altitude/
// Difficulty: Easy
// Pattern: Prefix Sum

// ------------------------------------------------------------
// Approach: Running Prefix Sum
// ------------------------------------------------------------

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int highest = 0;

        for (int g : gain) {
            
            curr += g;
            highest = max(highest, curr);
        }
        return highest;
    }
};

int main() {
    vector<int> gain = {-5, 1, 5, 0, -7};
    Solution s;

    cout << s.largestAltitude(gain) << "\n";

    return 0;
}