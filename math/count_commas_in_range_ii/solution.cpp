#include <bits/stdc++.h>
using namespace std;

// Problem: Count Commas in Range II
// Link: https://leetcode.com/problems/count-commas-in-range-ii/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Math - Tiered Range Formula

// ------------------------------------------------------------
// Approach: Tiered Digit-Length Ranges with Min-Clamping
// ------------------------------------------------------------
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        if (n >= 1000)
            ans += min(n, 999999LL) - 999;

        if (n >= 1000000)
            ans += (min(n, 999999999LL) - 999999LL) * 2;

        if (n >= 1000000000)
            ans += (min(n, 999999999999LL) - 999999999LL) * 3;

        if (n >= 1000000000000LL)
            ans += (min(n, 999999999999999LL) - 999999999999LL) * 4;

        if (n >= 1000000000000000LL)
            ans += (n - 999999999999999LL) * 5;

        return ans;
    }
};

int main() {
    Solution obj;
    cout << obj.countCommas(1002) << "\n";
    cout << obj.countCommas(1000000) << "\n";
    return 0;
}