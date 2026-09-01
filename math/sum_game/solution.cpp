#include <bits/stdc++.h>
using namespace std;

// Problem: Sum Game
// Link: https://leetcode.com/problems/sum-game/
// Difficulty: Hard
// Pattern: Game Theory + Math

// ------------------------------------------------------------
// Approach: Count Digits/Question Marks Per Half + Parity Case Analysis
// ------------------------------------------------------------
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;
        int leftQ = 0;
        int rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        if ((leftQ + rightQ) % 2 == 1)
            return true;

        return leftSum - rightSum !=
               9 * (rightQ - leftQ) / 2;
    }
};

int main() {
    Solution obj;
    string num = "5023";
    cout << obj.sumGame(num);
    return 0;
}