#include <bits/stdc++.h>
using namespace std;

// Problem: Calculate Digit Sum of a String
// Link: https://leetcode.com/problems/calculate-digit-sum-of-a-string/
// Difficulty: Easy
// Pattern: String Simulation (Group by k, Sum, Repeat)

// ------------------------------------------------------------
// Approach: Simulation
// ------------------------------------------------------------
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string temp = "";

            for (int i = 0; i < s.size(); i += k) {
                int sum = 0;

                for (int j = i; j < i + k && j < s.size(); j++)
                    sum += s[j] - '0';

                temp += to_string(sum);
            }

            s = temp;
        }

        return s;
    }
};

int main() {
    Solution s;

    cout << s.digitSum("11111222223", 3) << " "
         << s.digitSum("00000000", 3) << " "
         << s.digitSum("9", 2) << "\n";

    return 0;
}