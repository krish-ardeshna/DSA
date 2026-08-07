#include <bits/stdc++.h>
using namespace std;

// Problem: Smallest Divisible Digit Product I
// Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/
// Difficulty: Easy
// Pattern: Brute Force (Digit Product Check)

// ------------------------------------------------------------
// Approach: Bounded Linear Search (n to n+9)
// ------------------------------------------------------------
class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int num = n; num <= n + 9; num++) {
            int temp = num;
            int prod = 1;

            while (temp > 0) {
                prod *= temp % 10;
                temp /= 10;
            }

            if (prod % t == 0)
                return num;
        }

        return -1;
    }
};

int main() {
    Solution obj;
    cout << obj.smallestNumber(10, 2);
    return 0;
}