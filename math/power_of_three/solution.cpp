#include <bits/stdc++.h>
using namespace std;

// Problem: Power of Three
// Link: https://leetcode.com/problems/power-of-three/
// Difficulty: Easy
// Pattern: Recursion (conceptual) / Math (optimal)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 3 != 0) return false;
        return isPowerOfThree(n / 3);
    }
};

class SolutionOptimal {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 = 3^19 (largest power of 3 within 32-bit int)
        return n > 0 && 1162261467 % n == 0;
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    SolutionOptimal opt;

    cout << "Recursion: " << s.isPowerOfThree(n) << "\n";
    cout << "Optimal: " << opt.isPowerOfThree(n) << "\n";

    return 0;
}