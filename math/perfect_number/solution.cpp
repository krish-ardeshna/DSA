#include <bits/stdc++.h>
using namespace std;

// Problem: Perfect Number
// Link: https://leetcode.com/problems/perfect-number/
// Difficulty: Easy
// Pattern: Math

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }

        int sum = 1; // 1 is always a divisor
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;

                // Add paired divisor
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }
        return sum == num;
    }
};

int main() {
    int num;
    cin >> num;

    Solution s;

    cout << s.checkPerfectNumber(num) << "\n";

    return 0;
}