#include <bits/stdc++.h>
using namespace std;

// Problem: Find Greatest Common Divisor of Array
// Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Difficulty: Easy
// Pattern: Math / GCD

// ------------------------------------------------------------
// Approach: Find Minimum and Maximum
// ------------------------------------------------------------

class Solution {
public:
    int findGCD(vector<int>& nums) {

        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        return gcd(smallest, largest);
    }
};

int main() {
    vector<int> nums = {2, 5, 6, 9, 10};
    Solution s;

    cout << s.findGCD(nums) << "\n";
    return 0;
}