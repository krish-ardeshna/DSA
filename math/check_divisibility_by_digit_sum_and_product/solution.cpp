#include <bits/stdc++.h>
using namespace std;

// Problem: Check Divisibility by Digit Sum and Product
// Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
// Difficulty: Easy
// Pattern: Math - Digit Extraction

// ------------------------------------------------------------
// Approach: Extract Digits, Sum + Product, Check Divisibility
// ------------------------------------------------------------
class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digitSum = 0;
        int digitPro = 1;

        while (temp > 0) {
            int t = temp % 10;

            digitSum += t;
            digitPro *= t;

            temp /= 10;
        }

        int sum = digitSum + digitPro;

        return n % sum == 0;
    }
};

int main() {
    Solution obj;
    cout << obj.checkDivisibility(23);
    return 0;
}