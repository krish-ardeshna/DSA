#include <bits/stdc++.h>
using namespace std;

// Problem: Factorial Trailing Zeroes
// Link: https://leetcode.com/problems/factorial-trailing-zeroes/
// Difficulty: Medium
// Pattern: Math

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        while (n > 0) {
            n /= 5;
            count += n;
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    cout << s.trailingZeroes(n) << "\n";

    return 0;
}