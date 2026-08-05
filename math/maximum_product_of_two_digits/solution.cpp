#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Product of Two Digits
// Link: https://leetcode.com/problems/maximum-product-of-two-digits/
// Difficulty: Easy
// Pattern: Math

// ------------------------------------------------------------
// Approach: One Pass
// ------------------------------------------------------------

class Solution {
public:
    int maxProduct(int n) {
        int largest = -1;
        int secondLargest = -1;

        while(n > 0) {
            int digit = n % 10;

            if(digit >= largest) {
                secondLargest = largest;
                largest = digit;
            } else if(digit > secondLargest) {
                secondLargest = digit;
            }

            n /= 10;
        }

        return largest * secondLargest;
    }
};

int main() {
    int n = 43152;

    Solution s;
    cout << s.maxProduct(n) << "\n";

    return 0;
}