#include <bits/stdc++.h>
using namespace std;

// Problem: Partition Array According to Given Pivot
// Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/
// Difficulty: Medium
// Pattern: Arrays

// ------------------------------------------------------------
// Approach 1: Three Traversals
// ------------------------------------------------------------

class SolutionBrute {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> res;

        for (int num : nums) {
            if (num < pivot) {
                res.push_back(num);
            }
        }

        for (int num : nums) {
            if (num == pivot) {
                res.push_back(num);
            }
        }

        for (int num : nums) {
            if (num > pivot) {
                res.push_back(num);
            }
        }

        return res;
    }
};

// ------------------------------------------------------------
// Approach 2: Three Buckets
// ------------------------------------------------------------

class SolutionOptimal {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> mid;
        vector<int> right;

        for (int num : nums) {
            if (num < pivot) {
                left.push_back(num);
            }
            else if (num == pivot) {
                mid.push_back(num);
            }
            else {
                right.push_back(num);
            }
        }

        left.insert(left.end(), mid.begin(), mid.end());
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }
};

int main() {
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    SolutionOptimal s;

    vector<int> ans = s.pivotArray(nums, pivot);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}