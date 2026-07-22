#include <bits/stdc++.h>
using namespace std;

// Problem: Koko Eating Bananas
// Link: https://leetcode.com/problems/koko-eating-bananas/
// Difficulty: Medium
// Pattern: Binary Search on Answer

// ------------------------------------------------------------
// Approach: Binary Search on Answer
// ------------------------------------------------------------

class Solution {
public:
    bool canEat(vector<int>& piles, int h, int speed) {
        
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution s;

    cout << s.minEatingSpeed(piles, h) << "\n";
    return 0;
}