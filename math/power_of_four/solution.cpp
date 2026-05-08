#include <bits/stdc++.h>
using namespace std;

// Problem: Power of Four
// Link: https://leetcode.com/problems/power-of-four/
// Difficulty: Easy
// Pattern: Recursion / Bit Manipulation

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 4 != 0) return false;
        return isPowerOfFour(n / 4);
    }
};

class SolutionOptimal {
public:
    bool isPowerOfFour(int n) {
        // must be power of 2 AND the set bit must be at even position
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    SolutionOptimal opt;

    cout << "Recursion: " << s.isPowerOfFour(n) << "\n";
    cout << "Optimal: " << opt.isPowerOfFour(n) << "\n";

    return 0;
}