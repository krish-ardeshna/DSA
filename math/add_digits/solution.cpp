#include <bits/stdc++.h>
using namespace std;

// Problem: Add Digits
// Link: https://leetcode.com/problems/add-digits/
// Difficulty: Easy
// Pattern: Recursion / Math

// ------------------------------------------------------------
// Approach 1: Recursive Digit Sum
// ------------------------------------------------------------

class SolutionRecursive {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};

// ------------------------------------------------------------
// Approach 2: Digital Root Formula (Optimal)
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};

// ------------------------------------------------------------
// Approach 3: Digital Root using Modulo
// ------------------------------------------------------------

class SolutionModulo {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        int t = num % 9;
        return (t == 0) ? 9 : t;
    }
};

int main() {
    int num;
    cin >> num;

    SolutionRecursive s1;
    SolutionOptimal s2;
    SolutionModulo s3;

    cout << "Recursive: " << s1.addDigits(num) << "\n";
    cout << "Optimal: " << s2.addDigits(num) << "\n";
    cout << "Modulo: " << s3.addDigits(num) << "\n";

    return 0;
}