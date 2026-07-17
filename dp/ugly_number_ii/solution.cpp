#include <bits/stdc++.h>
using namespace std;

// Problem: Ugly Number II
// Link: https://leetcode.com/problems/ugly-number-ii/
// Difficulty: Medium
// Pattern: Dynamic Programming

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------

class SolutionBruteForce {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }

        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }

        return num == 1;
    }

    int nthUglyNumber(int n) {

        int count = 0;
        int num = 1;

        while (count < n) {
            if (isUgly(num)) {
                count++;
            }
            num++;
        }
        return num - 1;
    }
};

// ------------------------------------------------------------
// Approach 2: Dynamic Programming (Three Pointers)
// ------------------------------------------------------------

class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> ugly(n);

        ugly[0] = 1;

        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for (int i = 1; i < n; i++) {

            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;

            ugly[i] = min({next2, next3, next5});

            if (ugly[i] == next2) {
                i2++;
            }
            if (ugly[i] == next3) {
                i3++;
            }
            if (ugly[i] == next5) {
                i5++;
            }
        }
        return ugly[n - 1];
    }
};

int main() {

    int n = 10;
    Solution s;

    cout << s.nthUglyNumber(n) << "\n";
    return 0;
}