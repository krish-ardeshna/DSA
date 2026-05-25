#include <bits/stdc++.h>
using namespace std;

// Problem: Sqrt(x)
// Link: https://leetcode.com/problems/sqrtx/
// Difficulty: Easy
// Pattern: Binary Search

class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;

        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // Perfect square found
            if (mid * mid == x) {
                return mid;
            }

            // Mid can be possible answer
            else if (mid * mid < x) {
                ans = mid;
                low = mid + 1;
            }

            // Search left half
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int x;
    cin >> x;

    Solution s;

    cout << s.mySqrt(x) << "\n";

    return 0;
}