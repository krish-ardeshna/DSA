#include <bits/stdc++.h>
using namespace std;

                            // Problem: Maximize Sum of Squares of Digits
// Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
// Difficulty: Not verified (recent problem, check LC page)
// Pattern: Greedy (Concentrate the Digit Sum)

// ------------------------------------------------------------
// Approach: As Many 9s As Possible, One Remainder Digit, Zeros After
// ------------------------------------------------------------
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";

        string ans;

        int nines = sum / 9;
        ans.append(nines, '9');

        sum %= 9;

        if (sum > 0)
            ans.push_back('0' + sum);

        ans.append(num - (int)ans.size(), '0');

        return ans;
    }
};

int main() {
    Solution obj;
    cout << obj.maxSumOfSquares(2, 3) << "\n";
    cout << obj.maxSumOfSquares(2, 17) << "\n";
    cout << obj.maxSumOfSquares(3, 20) << "\n";
    return 0;
}