#include <bits/stdc++.h>
using namespace std;

// Problem: Sum of GCD of Formed Pairs
// Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
// Difficulty: Medium
// Pattern: Math / GCD

// ------------------------------------------------------------
// Approach: Prefix GCD + Sorting + Two Pointers
// ------------------------------------------------------------

class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        int mx = 0;
        
        vector<int> prefixGcd;

        for (int num : nums) {
            mx = max(mx, num);
            prefixGcd.push_back(gcd(mx, num));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {

            ans += gcd(prefixGcd[left], prefixGcd[right]);
            
            left++;
            right--;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 6, 4, 8};
    Solution s;

    cout << s.gcdSum(nums) << "\n";
    return 0;
}