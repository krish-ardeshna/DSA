#include <bits/stdc++.h>
using namespace std;

// Problem: First Bad Version
// Link: https://leetcode.com/problems/first-bad-version/
// Difficulty: Easy
// Pattern: Binary Search

// ------------------------------------------------------------
// Approach: Binary Search
// ------------------------------------------------------------

// Mock API for testing
int badVersion = 4;

bool isBadVersion(int version) {
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    int n = 5;

    Solution s;
    cout << s.firstBadVersion(n) << "\n";

    return 0;
}