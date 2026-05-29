#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Element After Replacement With Digit Sum
// Link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
// Difficulty: Easy
// Pattern: Arrays / Math

// ------------------------------------------------------------
// Approach 1: Helper Function
// ------------------------------------------------------------

class SolutionHelper {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for (int x : nums) {
            ans = min(ans, digitSum(x));
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: In-place Calculation
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for (int x : nums) {
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {10, 12, 13, 14};
    SolutionOptimal s;

    cout << s.minElement(nums) << "\n";

    return 0;
}