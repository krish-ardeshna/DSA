#include <bits/stdc++.h>
using namespace std;

// Problem: Merge Sorted Array
// Link: https://leetcode.com/problems/merge-sorted-array/
// Difficulty: Easy
// Pattern: Two Pointers

// ------------------------------------------------------------
// Approach 1: Erase + Append + Sort
// ------------------------------------------------------------

class SolutionBruteForce {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin() + m, nums1.end());

        for(int x : nums2) {
            nums1.push_back(x);
        }

        sort(nums1.begin(), nums1.end());
    }
};

// ------------------------------------------------------------
// Approach 2: Three Pointers from End
// ------------------------------------------------------------

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;

    Solution s;
    s.merge(nums1, m, nums2, n);

    for(int x : nums1) {
        cout << x << " ";
    }

    return 0;
}