#include <bits/stdc++.h>
using namespace std;

// Problem: Fibonacci Number
// Link: https://leetcode.com/problems/fibonacci-number/
// Difficulty: Easy
// Pattern: Recursion / Dynamic Programming

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};

class SolutionOptimal {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int prev2 = 0, prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    SolutionOptimal opt;

    cout << "Recursion: " << s.fib(n) << "\n";
    cout << "Optimal: " << opt.fib(n) << "\n";

    return 0;
}