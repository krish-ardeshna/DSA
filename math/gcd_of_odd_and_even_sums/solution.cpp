#include <bits/stdc++.h>
using namespace std;

// Problem: GCD of Odd and Even Sums
// Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/
// Difficulty: Easy
// Pattern: Math

// ------------------------------------------------------------
// Approach 1: Simulation
// ------------------------------------------------------------

class SolutionSimulation {
public:
    int gcdOfOddEvenSums(int n) {

        int sumOdd = 0;
        int sumEven = 0;

        for (int i = 1; i <= n; i++) {
            sumOdd += (2 * i - 1);
            sumEven += (2 * i);
        }

        return gcd(sumOdd, sumEven);
    }
};

// ------------------------------------------------------------
// Approach 2: Mathematical Formula
// ------------------------------------------------------------

class SolutionFormula {
public:
    int gcdOfOddEvenSums(int n) {

        int sumOdd = n * n;
        int sumEven = n * (n + 1);

        return gcd(sumOdd, sumEven);
    }
};

// ------------------------------------------------------------
// Approach 3: Mathematical Observation (Optimal)
// ------------------------------------------------------------

class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        return n;
    }
};

int main() {
    int n = 4;
    Solution s;

    cout << s.gcdOfOddEvenSums(n) << "\n";
    return 0;
}