#include <bits/stdc++.h>
using namespace std;

// Problem: Ugly Number
// Link: https://leetcode.com/problems/ugly-number/
// Difficulty: Easy
// Pattern: Math

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false
        
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

        return n == 1;
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;

    cout << s.isUgly(n) << "\n";

    return 0;
}