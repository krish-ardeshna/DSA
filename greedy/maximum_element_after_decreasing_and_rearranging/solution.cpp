#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Element After Decreasing and Rearranging
// Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
// Difficulty: Medium
// Pattern: Greedy / Sorting

// ------------------------------------------------------------
// Approach: Greedy with Sorting
// ------------------------------------------------------------

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr.back();
    }
};

int main() {
    
    vector<int> arr = {2, 2, 1, 2, 1};

    Solution s;

    cout << s.maximumElementAfterDecrementingAndRearranging(arr) << "\n";

    return 0;
}