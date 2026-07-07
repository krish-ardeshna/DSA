#include <bits/stdc++.h>
using namespace std;

// Problem: Self Dividing Numbers
// Link: https://leetcode.com/problems/self-dividing-numbers/
// Difficulty: Easy
// Pattern: Math

// ------------------------------------------------------------
// Approach: Helper Function
// ------------------------------------------------------------

class Solution {
public:
    bool isSelfDividing(int num) {
        int temp = num;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit == 0 || num % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> ans;

        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    int left = 1;
    int right = 22;

    Solution s;
    vector<int> ans = s.selfDividingNumbers(left, right);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}