#include <bits/stdc++.h>
using namespace std;

// Problem: Power of Two
// Link: https://leetcode.com/problems/power-of-two/
// Difficulty: Easy
// Pattern: Recursion (conceptual) / Bit Manipulation (optimal)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 2 != 0) return false;
        return isPowerOfTwo(n / 2);
    }
};

class SolutionOptimal {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    SolutionOptimal opt;

    cout << "Recursion: " << s.isPowerOfTwo(n) << "\n";
    cout << "Optimal: " << opt.isPowerOfTwo(n) << "\n";

    return 0;
}