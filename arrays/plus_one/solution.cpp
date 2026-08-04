#include <bits/stdc++.h>
using namespace std;

// Problem: Plus One
// Link: https://leetcode.com/problems/plus-one/
// Difficulty: Easy
// Pattern: Array - Digit Manipulation (Carry Propagation)

// ------------------------------------------------------------
// Approach: Reverse Iteration with Carry Handling
// ------------------------------------------------------------
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution obj;
    vector<int> digits = {9, 9, 9};
    vector<int> result = obj.plusOne(digits);

    for (int d : result) {
        cout << d << " ";
    }

    return 0;
}