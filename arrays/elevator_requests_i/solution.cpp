#include <bits/stdc++.h>
using namespace std;

// Problem: Elevator Requests I
// Link: https://leetcode.com/problems/elevator-requests-i/
// Difficulty: Easy (contest problem)
// Pattern: Array - Linear Scan (Running Distance Sum)

// ------------------------------------------------------------
// Approach: Single Pass Accumulate Absolute Difference
// ------------------------------------------------------------
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int timeTaken = 0;
        int currFloor = 0;

        for (int floor : requests) {
            timeTaken += abs(floor - currFloor);
            currFloor = floor;
        }

        return timeTaken;
    }
};

int main() {
    Solution obj;
    vector<int> requests = {2, 1, 3};
    cout << obj.elevatorRequests(5, requests);
    return 0;
}