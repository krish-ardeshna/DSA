#include <bits/stdc++.h>
using namespace std;

// Problem: Count Commas in Range
// Link: https://leetcode.com/problems/count-commas-in-range/
// Difficulty: Easy
// Pattern: Math - Direct Formula

// ------------------------------------------------------------
// Approach: Count Numbers With 4+ Digits (Each Contributes 1 Comma)
// ------------------------------------------------------------
class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;

        return n - 999;
    }
};

int main() {
    Solution obj;
    cout << obj.countCommas(1002) << "\n";
    cout << obj.countCommas(998) << "\n";
    return 0;
}