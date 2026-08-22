#include <bits/stdc++.h>
using namespace std;

// Problem: Capacity To Ship Packages Within D Days
// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Difficulty: Medium
// Pattern: Binary Search on Answer

// ------------------------------------------------------------
// Approach: Binary Search on Capacity + Greedy Day Simulation
// ------------------------------------------------------------
class Solution {
public:
    int findDays(const vector<int>& weights, int cap) {
        int days = 1, load = 0;
        for (int x : weights) {
            if (load + x > cap) {
                days += 1;
                load = x;
            } else {
                load += x;
            }
        }
        return days;
    }

    int totalWeights(const vector<int>& weights) {
        int sum = 0;
        for (int x : weights) {
            sum += x;
        }
        return sum;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = totalWeights(weights);

        while (low <= high) {
            int mid = (low + high) / 2;

            if (findDays(weights, mid) <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution obj;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << obj.shipWithinDays(weights, days);
    return 0;
}